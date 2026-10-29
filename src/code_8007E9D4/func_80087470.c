#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800A1BA0;
extern u32 D_800A1BA4;
extern s32 D_800A1BB4;
extern u8 D_800C02AE[];
extern s32 D_800B0AD4[];
extern void func_8008743C(void);
extern s32 func_8007F4E4(s32, s32, s32);
extern void *func_8007F6E0(s32);
extern s32 func_800871FC(s32, s32);
extern void handleAudioUnderrun(s32);
extern void osSetThreadPri(s32, s32);

void func_80087470(void) {
    s32 s4;
    s32 old;
    s32 s2;
    void *s0;

    s4 = 0;
    *(s32 *)(D_800C02AE + 0x8072) = func_8007F4E4(4, 0, 1);
    old = *(s32 *)(D_800C02AE + 0x7DA6);
    *(s32 *)(D_800C02AE + 0x7DA6) = (s32)func_8008743C;
    D_800A1BA0 = old;
    s2 = func_8007F4E4(0x26, 1, 1);
    do {
        if (func_800871FC(D_800B0AD4[D_800A1BA4 % 3], D_800A1BB4)) {
            s0 = func_8007F6E0(s2);
            handleAudioUnderrun(*(s32 *)((u8 *)s0 + 4));
            D_800A1BB4 = *(s32 *)((u8 *)s0 + 4);
        } else {
            func_8007F6E0(*(s32 *)(D_800C02AE + 0x8072));
            osSetThreadPri(D_800B0AD4[3], 6);
        }
    } while (s4 == 0);
}
