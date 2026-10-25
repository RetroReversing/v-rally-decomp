#include "common.h"

extern s32 D_800AE850[];
s32 func_80005CB8(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_80005E3C(s32 a);
s32 func_80005EB0(void);

s32 func_8000DC70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    s32 s0;
    s32 s5;
    s32 s6 = 0;
    s32 v;
    u16 s1 = arg4;

    s0 = func_80005CB8(s1, arg2, arg3, 1, 6);
    s5 = s0;
    if (s0 != 0) {
        v = func_80005CB8(s1, arg2, arg3, 1, 6);
        if (v != 0) {
            *(s32 *)((u8 *)D_800AE850 + 0x7400) = s0;
            *(s32 *)((u8 *)D_800AE850 + 0x12EC) = v;
            s6 = 1;
            func_80005EB0();
        } else {
            func_80005E3C(s5);
        }
    }
    return s6;
}
