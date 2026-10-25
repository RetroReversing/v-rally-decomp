#include "common.h"

extern char D_800AE850[];

s32 func_80084DD4(s32);
s32 func_800857C0(s32, s32);
s32 func_800858A4(s32, s32, s32);

void func_8002FE78(void) {
    u8 i;
    u32 n;

    i = 0;
    do {
        n = i;
        *(s32 *)(D_800AE850 + 0x2394 + (n << 4)) = 0;
        if (func_80084DD4(n) != 0) {
            if (func_800857C0(n, 2) != 0) {
                func_800858A4(n, 2, 1);
            }
        }
        i++;
    } while (i < 4);
}
