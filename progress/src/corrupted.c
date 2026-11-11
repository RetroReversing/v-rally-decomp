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

/* Looks up fpage (an inode page reference) in the inode cache of the pack. Loads
   the bank's inode table into the cache when needed, counts how many inode entries
   in the cached banks point at fpage, and returns 2 once it has found two copies. */
s32 corrupted(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache) {
    int inode_index;
    int map_index;
    int hits;
    u8 bank;
    int first_entry;
    s32 status;

    hits = 0;
    status = 0;
    map_index = (fpage.inode_t.page / (128 / 32)) + (fpage.inode_t.bank % 8) * 32;

    for (bank = 0; bank < pfs->banks; bank++) {
        first_entry = bank > 0 ? 1 : pfs->inode_start_page;

        if (bank == fpage.inode_t.bank || cache->map[map_index] & (1 << (bank % 8))) {
            if (bank != cache->bank) {
                status = __osPfsRWInode(pfs, &cache->inode, 0, bank);

                if (status != 0 && status != 3) {
                    return status;
                }

                cache->bank = bank;
            }

            for (inode_index = first_entry; hits < 2 && (inode_index < ((s32) (sizeof(cache->inode.inode_page) / sizeof(cache->inode.inode_page[0])))); inode_index++) {
                if (cache->inode.inode_page[inode_index].ipage == fpage.ipage) {
                    hits++;
                }
            }

            if (hits >= 2) {
                return 2;
            }
        }
    }
    return hits;
}
