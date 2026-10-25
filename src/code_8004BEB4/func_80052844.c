#include "common.h"

extern char D_800AE850[];

void func_80052844(void)
{
    u8 i;
    u8 j;
    u32 off;
    u32 row;
    u32 base;

    base = (u32)(D_800AE850 + 0x7DB0);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            off = j << 4;
            row = off + base;
            row = row + 0x118;
            *(s32 *)(row + i * 4) = 0;
        }
    }
}
