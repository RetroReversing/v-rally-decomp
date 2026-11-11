typedef struct OSMesgQueue_s {
    void    *mtqueue;
    void    *fullqueue;
    s32      validCount;
    s32      first;
    s32      msgCount;
    void   **msg;
} OSMesgQueue;

typedef struct {
    s32          status;
    OSMesgQueue *queue;
    int          channel;
    u8           id[32];
    u8           label[32];
    int          version;
    int          dir_size;
    int          inode_table;
    int          minode_table;
    int          dir_table;
    int          inode_start_page;
    u8           banks;
    u8           activebank;
} OSPfs;

typedef struct {
    u32 repaired;
    u32 random;
    u64 serial_mid;
    u64 serial_low;
    u16 deviceid;
    u8  banks;
    u8  version;
    u16 checksum;
    u16 inverted_checksum;
} __OSPackId;

extern void  pif_lock(void);
extern void  pif_unlock(void);
extern s32   getPakStatus(OSMesgQueue *queue, int channel);
extern void  __osCopyBytes(const void *, void *, int);
extern s32   __osPfsSelectBank(OSPfs *pfs, u8 bank);
extern s32   __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
extern s32   __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum);
extern s32   __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
extern s32   __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);
extern s32   osPfsChecker(OSPfs *pfs);

/* Initialises the controller pak on a channel: reads the pak ID block (page 1),
 * checks its checksums and repairs the ID when they are bad, fills in the pfs
 * layout (banks, inode and directory tables), then reads the label (page 7). */
s32 osPfsInitPak(OSMesgQueue* queue, OSPfs* pfs, int channel) {

    s32 ret = 0;
    u16 sum;
    u16 isum;
    u8 temp[32 ];
    __OSPackId* id;
    __OSPackId newid;

    pif_lock();

    ret = getPakStatus(queue, channel);

    pif_unlock();

    if (ret != 0) {
        return ret;
    }

    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;

    ret =  __osPfsSelectBank(( pfs ), (  0 ))  ; if (ret != 0) return ret ;
    ret =  __osContRamRead(pfs->queue, pfs->channel, 1 , temp) ; if (ret != 0) return ret ;

    __osIdCheckSum((u16*)temp, &sum, &isum);
    id = (__OSPackId*)temp;

    if ((id->checksum != sum) || (id->inverted_checksum != isum)) {
        ret = __osCheckPackId(pfs, id);

        if (ret != 0) {

            pfs->status |= 0x4 ;

            return ret;
        }


    }

    if (!(id->deviceid & 1)) {
        ret = __osRepairPackId(pfs, id, &newid);

        if (ret != 0) {

            if (ret == 10 ) {
                pfs->status |= 0x4 ;
            }

            return ret;
        }

        id = &newid;

        if (!(id->deviceid & 1)) {
            return 11 ;
        }
    }


    __osCopyBytes(id, pfs->id, 32 );


    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + 2  + (2 * pfs->banks);
    pfs->dir_size = 2  * 8 ;
    pfs->inode_table = 1 * 8 ;
    pfs->minode_table = (1 + pfs->banks) * 8 ;
    pfs->dir_table = pfs->minode_table + (pfs->banks * 8 );

    ret =  __osContRamRead(pfs->queue, pfs->channel, 7 , pfs->label) ; if (ret != 0) return ret ;

    ret = osPfsChecker(pfs);
    pfs->status |= 0x1 ;

    return ret;
}
