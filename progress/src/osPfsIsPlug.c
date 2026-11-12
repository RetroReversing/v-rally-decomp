typedef struct { u16 type; u8 status; u8 errno; } CS;
extern u8 __osMaxControllers;
extern char stream_state[];
s32 __osPfsRequestData(s32);
void func_8008CE60();
void pif_lock();
void pif_unlock();
s32 __osSiRawStartDma();
s32 osRecvMesg(s32, s32 *, s32);

/* Polls the controller pak status for every channel until all of them report
 * ready, then stores a bitmask of the channels with a pak plugged in. */
s32 osPfsIsPlug(s32 queue, u8 *pattern) {
    s32 ret;
    s32 dummy;
    s32 channel;
    s32 cntrlrs = 0;
    u8 bitpattern;
    CS data[4];
    s32 crap = 3;
    u8 *pif;
    pif_lock();
    pif = (u8*)(stream_state + 0x7E82);
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, pif);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, pif);
        osRecvMesg(queue, &dummy, 1);
        func_8008CE60(&bitpattern, data);
        for (channel = 0; channel < __osMaxControllers; channel++) {
            if (!(data[channel].status & 4)) { crap--; break; }
        }
        if (channel != __osMaxControllers) continue;
        crap = 0;
    } while (crap > 0);
    for (channel = 0; channel < __osMaxControllers; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1)) cntrlrs |= 1 << channel;
    }
    pif_unlock();
    *pattern = cntrlrs;
    return ret;
}
