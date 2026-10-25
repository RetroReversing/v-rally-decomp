#include "common.h"

s32 func_8002FA8C();
s32 func_80098180();
extern char D_800A4774[];
extern char D_800A477C[];
extern char D_800A4784[];
extern char D_800A478C[];
extern char D_800A4794[];
extern char D_800A479C[];
extern char D_800A47A4[];
extern char D_800AE850[];
extern char D_800C02AE[];

void func_8001CCA4(s32 arg0) {
    s32 temp_s0;

    if (*(u16 *)((u8 *)*(void **)(D_800C02AE + 0x32F2) + 0xE) < 3U) {
        temp_s0 = arg0 + 0x4C;
        if (func_80098180(temp_s0, &D_800A4774) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 1);
            return;
        }
        if (func_80098180(temp_s0, &D_800A477C) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 0);
            return;
        }
        if (func_80098180(temp_s0, &D_800A4784) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 2);
            return;
        }
        if (func_80098180(temp_s0, &D_800A478C) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 3);
            return;
        }
        if (func_80098180(temp_s0, &D_800A4794) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 4);
            return;
        }
        if (func_80098180(temp_s0, &D_800A479C) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 5);
            return;
        }
        if (func_80098180(temp_s0, &D_800A47A4) == 0) {
            func_8002FA8C(arg0, **(s32 **)(D_800AE850 + 0x73F0), 6);
        }
    }
}
