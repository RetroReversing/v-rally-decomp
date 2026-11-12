extern void pif_lock(void);
extern void pif_unlock(void);
extern void pfs_build_write_cmd(u8, u8 *);
extern s32 pakQueryStatus(s32, u8 *);
extern s32 __osSiRawStartDma(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 stream_state[];
extern u8 gOrderState[];
typedef struct { u8 b[12]; } Blk12;

/* Writes an 8-byte block (data) to controller pak channel ch through the PIF
 * command buffer. Returns 0 on success, or the pak's error code. */
s32 pfs_write_block(s32 mq, u8 ch, u8 *data)
{
    s32 ret = 0;
    u16 type;
    u8 *pif = gOrderState + 0x8660;
    Blk12 reply;
    u8 status[4];

    pif_lock();
    ret = pakQueryStatus(mq, status);
    type = *(u16 *)status & 0xC000;
    if (ret == 0) {
        switch (type) {
        case 0x8000:
            if (ch >= 0x40) {
                ret = -1;
            }
            break;
        case 0xC000:
            break;
        default:
            ret = 8;
            break;
        }
    }
    if (ret != 0) {
        pif_unlock();
        return ret;
    }
    while (status[2] & 0x80) {
        pakQueryStatus(mq, status);
    }
    pfs_build_write_cmd(ch, data);
    ret = __osSiRawStartDma(1, gOrderState + 0x8660);
    osRecvMesg(mq, 0, 1);
    ret = __osSiRawStartDma(0, gOrderState + 0x8660);
    stream_state[0x3272] = 5;
    osRecvMesg(mq, 0, 1);
    pif += 4;
    reply = *(Blk12 *)pif;
    ret = (reply.b[1] & 0xC0) >> 4;
    pif_unlock();
    return ret;
}
