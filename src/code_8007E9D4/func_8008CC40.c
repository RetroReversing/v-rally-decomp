#include "snapshot29_0433f7af8f6d.h"

typedef struct { u16 type; u8 status; u8 errno; } CS;
extern u8 D_800B60E0;
extern char D_800C02AE[];
s32 __osPfsRequestData(s32);
void func_8008CE60();
void func_8008D8B4();
void func_8008D920();
s32 func_80090DC0();
s32 osRecvMesg(s32, s32 *, s32);

s32 func_8008CC40(s32 queue, u8 *pattern) {
    s32 ret;
    s32 dummy;
    s32 channel;
    s32 cntrlrs = 0;
    u8 bitpattern;
    CS data[4];
    s32 crap = 3;
    u8 *pif;
    func_8008D8B4();
    pif = (u8*)(D_800C02AE + 0x7E82);
    do {
        __osPfsRequestData(0);
        func_80090DC0(1, pif);
        osRecvMesg(queue, &dummy, 1);
        ret = func_80090DC0(0, pif);
        osRecvMesg(queue, &dummy, 1);
        func_8008CE60(&bitpattern, data);
        for (channel = 0; channel < D_800B60E0; channel++) {
            if (!(data[channel].status & 4)) { crap--; break; }
        }
        if (channel != D_800B60E0) continue;
        crap = 0;
    } while (crap > 0);
    for (channel = 0; channel < D_800B60E0; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1)) cntrlrs |= 1 << channel;
    }
    func_8008D920();
    *pattern = cntrlrs;
    return ret;
}
