extern s32 __osPackRequestData(s32);
extern s32 osRecvMesg(s32, s32, s32);
extern s32 pif_lock();
extern s32 pif_unlock();
extern s32 __osSiRawStartDma(s32, void *);
extern u8 __osContPifRam[];
extern u8 D_800C3520;

/* Starts a controller status query on the message queue mq. If D_800C3520 is set, it first
 * packs and writes a request to PIF RAM and waits for the reply on mq. Then it reads the
 * PIF RAM result, clears D_800C3520, and returns the read's status. */
s32 osContStartQuery(s32 mq)
{
    s32 result;

    pif_lock();
    if (D_800C3520 != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, __osContPifRam);
        osRecvMesg(mq, 0, 1);
    }
    result = __osSiRawStartDma(0, __osContPifRam);
    D_800C3520 = 0;
    pif_unlock();
    return result;
}
