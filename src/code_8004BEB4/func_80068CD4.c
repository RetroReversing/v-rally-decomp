#include "common.h"

extern u32 D_800A1634[];
extern u8 D_800A167C[16];
#define D_800A1684 (D_800A167C + 8)

s32 func_80068CD4(s32 arg0, s32 arg1)
{
    u8 i;
    u32 temp;

    temp = D_800A1634[D_800A167C[arg1]];
    for (i = 0; i < 8; i++) {
        if (D_800A1634[D_800A1684[i]] == temp) {
            break;
        }
    }
    if (i != 8) {
        D_800A167C[i] = D_800A1684[arg1];
        D_800A1684[i] = D_800A1684[arg1];
    }
    D_800A1684[arg1] = D_800A167C[arg1];
    return 0;
}
