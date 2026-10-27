#include "common.h"

extern char D_800AE850[];
extern u8 D_800B60E0;

typedef struct {
    u8 b[6];
    s8 tail[2];
} Buf8;

void __osPackReadData(void)
{
    Buf8 pat;
    register s32 i;
    s32 n;
    s32 *q;
    u8 *dst;
    u8 count;

    dst = (u8 *)(D_800AE850 + 0x1250);
    i = 0xE;
    q = (s32 *)(dst + 0x38);
    do {
        *q = 0;
        i -= 1;
        q -= 1;
    } while (i >= 0);

    count = D_800B60E0;
    n = 0;
    *(s32 *)(D_800AE850 + 0x128C) = 1;

    pat.b[0] = 0xFF;
    pat.b[1] = 1;
    pat.b[2] = 4;
    *(u16 *)&pat.b[4] = 0xFFFF;
    pat.b[3] = 1;
    pat.tail[0] = -1;
    pat.tail[1] = -1;

    for (i = 0; i < D_800B60E0; i++) {
        *(Buf8 *)dst = pat;
        dst += 8;
    }
    *dst = 0xFE;
}
