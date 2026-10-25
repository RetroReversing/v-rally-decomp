#include "common.h"

extern char D_800AE850[];

typedef struct {
    u8 b[12];
} Blk12;

void func_8008F978(s8 arg0, u8 *arg1)
{
    Blk12 buf;
    u8 *p;
    s32 i;
    u8 *src;

    p = (u8 *)D_800AE850 + 0x8660;
    *(s32 *)(D_800AE850 + 0x869C) = 1;
    buf.b[0] = 10;
    buf.b[1] = 1;
    buf.b[2] = 5;
    buf.b[3] = arg0;
    src = arg1;
    for (i = 4; i < 12; i++) {
        buf.b[i] = *src++;
    }
    for (i = 3; i >= 0; i--) {
        *p++ = 0;
    }
    *(Blk12 *)p = buf;
    p[12] = 0xFE;
}
