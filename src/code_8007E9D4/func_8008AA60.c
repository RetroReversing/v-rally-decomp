#include "common.h"

extern char D_800AE850[];
extern u8 D_800B60E0;

typedef struct {
    u8 b[8];
} Pkt;

void func_8008AA60(u8 arg0)
{
    Pkt sp;
    s32 i;
    s32 *var_v0;
    Pkt *var_a3;

    i = 0xE;
    var_v0 = (s32 *) (D_800AE850 + 0x1288);
    do {
        *var_v0 = 0;
        i -= 1;
        var_v0 -= 1;
    } while (i >= 0);
    *(s32 *) (D_800AE850 + 0x128C) = 1;
    var_a3 = (Pkt *) (D_800AE850 + 0x128C - 0x3C);
    sp.b[0] = 0xFF;
    sp.b[1] = 1;
    sp.b[2] = 3;
    sp.b[3] = arg0;
    sp.b[4] = 0xFF;
    sp.b[5] = 0xFF;
    sp.b[6] = 0xFF;
    sp.b[7] = 0xFF;
    for (i = 0; i < D_800B60E0; i++) {
        *var_a3 = sp;
        var_a3 += 1;
    }
    *(u8 *) var_a3 = 0xFE;
}
