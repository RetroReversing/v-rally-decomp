typedef struct {
	int		status;
	void	*queue;
	int		channel;
	u8		id[32];
	u8		label[32];
	int		version;
	int		dir_size;
	int		inode_table;
	int		minode_table;
	int		dir_table;
	int		inode_start_page;
	u8		banks;
	u8		activebank;
} OSPfs;

typedef union {
      struct
    {
          u8 bank;
          u8 page;
    } inode_t;
      u16 ipage;
} __OSInodeUnit;

typedef struct
{
      __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct
{
      __OSInode inode;
      u8 bank;
      u8 map[(8  * 32 ) ];
} __OSInodeCache;

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

/* Fills in the inode cache for the pack: clears the map, then for each bank reads its
   inode table and sets, in the map, one bit per bank that holds an inode pointing to
   a page in another bank. Returns 0, or the error from the read. */
s32 corrupted_init(OSPfs* pfs, __OSInodeCache* cache) {
    int i;
    int n;
    int offset;
    u8 bank;
    __OSInodeUnit tpage;
    __OSInode tmp_inode;
    s32 ret;

    for (i = 0; i < (8 * 32); i++) {
        cache->map[i] = 0;
    }

    cache->bank = -1;
    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        ret = __osPfsRWInode(pfs, &tmp_inode, 0, bank);

        if (ret != 0 && ret != 3) {
            return ret;
        }

        for (i = offset; i < ((s32) (sizeof(tmp_inode.inode_page) / sizeof(tmp_inode.inode_page[0]))); i++) {
            tpage = tmp_inode.inode_page[i];

            if (tpage.ipage >= pfs->inode_start_page && tpage.inode_t.bank != bank) {

                n = ((tpage.inode_t.page) / (128 / 32)) +
                    ((tpage.inode_t.bank % 8) * 32);

                cache->map[n] |= 1 << (bank % 8);
            }
        }
    }
    return 0;
}
