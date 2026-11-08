typedef struct OSMesgQueue_s OSMesgQueue;

typedef struct {
    int         status;
    OSMesgQueue *queue;
    int         channel;
    u8          id[32];
    u8          label[32];
    int         version;
    int         dir_size;
    int         inode_table;
    int         minode_table;
    int         dir_table;
    int         inode_start_page;
    u8          banks;
    u8          activebank;
} OSPfs;

typedef struct {
    u16 fixed1;
    u16 start_address;
    u8  nintendo_chr[0x30];
    u8  game_title[16];
    u16 company_code;
    u8  body_code;
    u8  cart_type;
    u8  rom_size;
    u8  ram_size;
    u8  country_code;
    u8  fixed2;
    u8  version;
    u8  isum;
    u16 sum;
} OSGbpakId;

typedef union {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ipage;
} __OSInodeUnit;

typedef struct {
    u32 game_code;
    u16 company_code;
    __OSInodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    u8 ext_name[4];
    u8 game_name[16];
} __OSDir;

typedef struct {
    __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct {
    __OSInode inode;
    u8 bank;
    u8 map[(8 * 32)];
} __OSInodeCache;

extern s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
extern s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);
extern s32 __osCheckId(OSPfs *pfs);
extern s32 __osGetId(OSPfs *pfs);
extern s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
extern s32 __osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force);
extern s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
extern s32 __osPfsSelectBank(OSPfs *pfs, u8 bank);
extern void func_80091920(void *, int);

s32 osPfsChecker(OSPfs* pfs) {
    int idx;
    s32 ret;
    __OSInodeUnit page;
    __OSInode checked_inode;
    __OSInode tmp_inode;
    __OSDir tmp_dir;
    __OSInodeUnit file_next_node[16];
    __OSInodeCache cache;
    int fixed = 0;
    u8 bank;
    u8 oldbank = 254;
    s32 diff;
    s32 expected;
    int keep;

    ret = __osCheckId(pfs);
    if (ret == 2) {
        ret = __osGetId(pfs);
    }
    if (ret != 0) {
        return ret;
    }

    ret = corrupted_init(pfs, &cache);
    if (ret != 0) return ret;

    for (idx = 0; idx < pfs->dir_size; idx++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + idx, (u8*)&tmp_dir);
        if (ret != 0) return ret;

        if (tmp_dir.company_code != 0 || tmp_dir.game_code != 0) {
            if (tmp_dir.company_code == 0 || tmp_dir.game_code == 0) {
                diff = -1;
            } else {
                page = tmp_dir.start_page;
                expected = diff = 0;
                bank = 255;

                while (page.ipage >= pfs->inode_start_page
                       && page.inode_t.bank < pfs->banks
                       && page.inode_t.page >= 0x01
                       && page.inode_t.page < 0x80) {
                    if (bank != page.inode_t.bank) {
                        bank = page.inode_t.bank;

                        if (oldbank != bank) {
                            ret = __osPfsRWInode(pfs, &tmp_inode, 0, bank);
                            oldbank = bank;
                        }

                        if (ret != 0 && ret != 3) {
                            return ret;
                        }
                    }

                    if ((diff = corrupted(pfs, page, &cache) - expected) != 0) {
                        break;
                    }

                    expected = 1;
                    page = tmp_inode.inode_page[page.inode_t.page];
                }
            }

            if (diff != 0 || page.ipage != 1) {
                /* chain is broken: wipe the directory entry and write it back */
                func_80091920(&tmp_dir, sizeof(__OSDir));

                if (pfs->activebank != 0) {
                    ret = __osPfsSelectBank(pfs, 0);
                    if (ret != 0) return ret;
                }
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + idx, (u8*)&tmp_dir, 0);
                if (ret != 0) return ret;
                fixed++;
            }
        }
    }

    for (idx = 0; idx < pfs->dir_size; idx++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + idx, (u8*)&tmp_dir);
        if (ret != 0) return ret;

        if (tmp_dir.company_code != 0 && tmp_dir.game_code != 0 &&
            tmp_dir.start_page.ipage >= (u16)pfs->inode_start_page) {
            file_next_node[idx].ipage = tmp_dir.start_page.ipage;
        } else {
            file_next_node[idx].ipage = 0;
        }
    }

    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &tmp_inode, 0, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }

        keep = (bank > 0) ? 1 : pfs->inode_start_page;

        for (idx = 0; idx < keep; idx++) {
            checked_inode.inode_page[idx].ipage = tmp_inode.inode_page[idx].ipage;
        }
        for (; idx < 128; idx++) {
            checked_inode.inode_page[idx].ipage = 3;
        }

        for (idx = 0; idx < pfs->dir_size; idx++) {
            while (file_next_node[idx].inode_t.bank == bank &&
                   file_next_node[idx].ipage >= (u16)pfs->inode_start_page) {
                u8 pg = file_next_node[idx].inode_t.page;
                file_next_node[idx] = checked_inode.inode_page[pg] = tmp_inode.inode_page[pg];
            }
        }
        ret = __osPfsRWInode(pfs, &checked_inode, 1, bank);
        if (ret != 0) return ret;
    }

    if (fixed) {
        pfs->status |= 0x2;
    } else {
        pfs->status &= ~0x2;
    }

    return 0;
}
