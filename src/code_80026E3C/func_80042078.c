#include "common.h"

typedef struct { u8 b[8]; } Buf8;
typedef struct { s32 w[4]; } Quad;

extern int D_800B5B4C;
extern char D_800AE850[];
extern char D_8009FFF0[];

s32 func_800051B4();
s32 func_80022184();
s32 func_80041E0C();
void *func_800801D0();

void *func_80042078(void *arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    u16 var_s3;
    char *var_a2;
    char *temp_s0;
    char *var_a3;
    char *end;

    var_s3 = arg4;
    if (func_80022184(D_800AE850 + 0x7338) != 0) {
        goto block_2;
    }
    func_80041E0C();
block_2:
    temp_s0 = func_800801D0(D_800B5B4C, 0x198);
    if (arg2 == 0) {
        goto block_6;
    }
    *(s32 *)(temp_s0 + 0x178) = func_800051B4(arg0, arg1 & 0xFFFF, 0, 0, var_s3);
    *(Buf8 *)(temp_s0 + 0x17C) = *(Buf8 *)arg0;
    var_a3 = temp_s0 + 0x38;
    var_a2 = D_8009FFF0;
    end = var_a2 + 0x140;
    *(s16 *)(temp_s0 + 0x184) = arg1;
    *(s16 *)(temp_s0 + 0x186) = arg2;
    *(s16 *)(temp_s0 + 0x188) = arg3;
    *(u16 *)(temp_s0 + 0x18A) = var_s3;
    *(s32 *)(temp_s0 + 0x18C) = 0;
    *(s32 *)(temp_s0 + 0x190) = 0;
    do {
        *(Quad *)var_a3 = *(Quad *)var_a2;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != end);
    return temp_s0;
block_6:
    *(s32 *)(temp_s0 + 0x178) = 0;
    return temp_s0;
}
