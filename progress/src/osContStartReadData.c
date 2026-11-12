extern char __osContPifRam[];
extern u8 __osPfsLastCmd;
s32 osRecvMesg(s32, s32, s32);
void pif_lock(void);
void pif_unlock(void);
void __osPackReadData(void);
s32 __osSiRawStartDma(s32, void *);

/* Starts a controller read: if the last PIF command was not a button read, sends the
   packed command first and waits for the reply. Then starts the PIF read DMA and
   returns its result. Holds the PIF lock for the whole sequence. */
s32 osContStartReadData(s32 mq)
{
    s32 ret;

    pif_lock();
    if (__osPfsLastCmd != 1) {
        __osPackReadData();
        __osSiRawStartDma(1, __osContPifRam);
        osRecvMesg(mq, 0, 1);
    }
    ret = __osSiRawStartDma(0, __osContPifRam);
    __osPfsLastCmd = 1;
    pif_unlock();
    return ret;
}
