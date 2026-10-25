#include "common.h"

extern u32 D_800AFA6C;
extern f32 D_800C35E0;
extern s32 D_8009F640;
extern char D_800AE850[];
s32 func_80038A8C(s32, s32, s32);
s32 func_80086854(void *);
s32 func_80086A34(s32);
s32 func_80086DE8(s32);

void func_8003A594(void *arg0, s16 arg1, s32 arg2)
{
    *(u8 *)((char *)arg0 + 0x90) = 0xFF;
    *(u8 *)((char *)arg0 + 0x91) = 0xFF;
    *(u8 *)((char *)arg0 + 0x92) = 0xFF;
    *(u8 *)((char *)arg0 + 0x93) = 0xFF;
    if (arg1 == 0) {
        *(s32 *)((char *)arg0 + 0x80) |= 4;
        func_80086A34(1);
        return;
    }
    *(s32 *)((char *)arg0 + 0x80) &= ~4;
    if (arg1 >= 0xA) {
        return;
    }
    *(u8 *)((char *)arg0 + 0x90) = 0xFF;
    *(u8 *)((char *)arg0 + 0x91) = 0;
    *(u8 *)((char *)arg0 + 0x92) = 0;
    if (!((D_800AFA6C >> 3) & 1)) {
        return;
    }
    if (arg1 < 5) {
        *(s32 *)((char *)arg0 + 0x80) |= 4;
        if (arg2 == 0) {
            return;
        }
        if ((D_800AFA6C & 0xF) != 0xF) {
            return;
        }
        func_80038A8C(0x17, arg1, arg2);
        return;
    }
    if (arg2 == 0) {
        return;
    }
    if ((D_800AFA6C & 0xF) != 0xF) {
        return;
    }
    func_80038A8C(0x16, arg1, arg2);
    if (D_8009F640 & 0x10) {
        return;
    }
    D_8009F640 |= 0x10;
    func_80086A34(1);
    func_80086854(D_800AE850 + 0x8830);
    func_80086DE8((s32)(D_800C35E0 * 80.0f));
}
