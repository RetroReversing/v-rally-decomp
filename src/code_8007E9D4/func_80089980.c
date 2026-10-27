#include "common.h"

extern u8 D_800A73E0[];
extern u8 D_800AE850[];
void func_80089980(void) {
    register u8 i;
    u32 *p;
    i = 0;
    p = (u32 *)((u8 *)D_800A73E0 + 0x4598);
    do {
        p[i] = 0;
        i++;
    } while (i < 4);
    *(u32 *)((u8 *)D_800A73E0 + 0x4590) = 0;
    *(u32 *)((u8 *)D_800A73E0 + 0x4594) = 0;
    *(u32 *)((u8 *)D_800AE850 + 0x1204) = 0x80;
}
