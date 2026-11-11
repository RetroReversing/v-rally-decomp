typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} OSPifRam;
typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 addrh;
    u8 addrl;
    u8 data[32];
    u8 datacrc;
} __OSContRamReadFormat;
extern u8 D_800C3520;
extern s32 D_800A3B40;
extern OSPifRam D_800C8130;
s32 __osContAddressCrc(u32);
u8 __osContDataCrc(void *);
s32 pif_lock();
s32 pif_unlock();
s32 __osSiRawStartDma();
s32 __osCopyBytes();
u32 getPakStatus();
s32 osRecvMesg(s32, s32, s32);

/* Reads one 32-byte block from controller-pak RAM at 'address' into 'buffer',
 * building the PIF command block in D_800C8130 (reused when the same channel
 * was used last). Retries up to 3 times on a bad data CRC, then returns the
 * result (0 ok, 1 error, 4 retry exhausted, or the error from getPakStatus). */
u32 __osContRamRead(s32 mq, s32 channel, u16 address, s32 buffer)
{
    u32 res;
    s32 i;
    u8 *cmd;
    s32 tries;

    res = 0;
    cmd = (u8 *)&D_800C8130;
    tries = 2;
    pif_lock();
    if (D_800C3520 != 2 || D_800A3B40 != channel) {
        D_800C3520 = 2;
        D_800A3B40 = channel;
        for (i = 0; i < channel; i++) {
            *cmd++ = 0;
        }
        D_800C8130.pifstatus = 1;
        ((__OSContRamReadFormat *)cmd)->dummy = 0xFF;
        ((__OSContRamReadFormat *)cmd)->txsize = 3;
        ((__OSContRamReadFormat *)cmd)->rxsize = 0x21;
        ((__OSContRamReadFormat *)cmd)->cmd = 2;
        ((__OSContRamReadFormat *)cmd)->datacrc = 0xFF;
        cmd[sizeof(__OSContRamReadFormat)] = 0xFE;
    } else {
        cmd += channel;
    }
    ((__OSContRamReadFormat *)cmd)->addrh = address >> 3;
    ((__OSContRamReadFormat *)cmd)->addrl = __osContAddressCrc(address) | (address << 5);
    __osSiRawStartDma(1, &D_800C8130);
    osRecvMesg(mq, 0, 1);
    do {
        __osSiRawStartDma(0, &D_800C8130);
        osRecvMesg(mq, 0, 1);
        res = (((__OSContRamReadFormat *)cmd)->rxsize & 0xC0) >> 4;
        if (res == 0) {
            if (__osContDataCrc(((__OSContRamReadFormat *)cmd)->data) != ((__OSContRamReadFormat *)cmd)->datacrc) {
                res = getPakStatus(mq, channel);
                if (res != 0) {
                    break;
                }
                res = 4;
            } else {
                __osCopyBytes(((__OSContRamReadFormat *)cmd)->data, buffer, 0x20);
            }
        } else {
            res = 1;
        }
    } while (res == 4 && tries-- >= 0);
    pif_unlock();
    return res;
}
