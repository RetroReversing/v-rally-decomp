#include "checkpoint_common.h"

#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

extern int D_800ADF80;


s32 func_800056FC();
s32 func_8000C22C();
s32 func_8000C244();
extern void *D_800A1468;
extern char D_800A51A8[];
extern char D_800A51B0[];
extern char D_800A51B8[];
extern char D_800A51BC[];
extern char D_800A51C0[];
extern char D_800A51C8[];
extern char D_800A51D0[];
extern char D_800A51D8[];
extern char D_800A51DC[];
extern char D_800A51E4[];
extern char D_800A51EC[];
extern char D_800A73E0[];

void func_80057334(s16 arg0, s16 arg1, s32 arg2) {
    s32 *var_s0;

    var_s0 = &D_800A51A8;
    if (arg2 != 0) {
        goto block_2;
    }
    var_s0 = &D_800A51B0;
    goto block_20;
block_2:
    if (arg2 != 1) {
        goto block_4;
    }
    var_s0 = &D_800A51B8;
    goto block_20;
block_4:
    if (arg2 != 2) {
        goto block_6;
    }
    var_s0 = &D_800A51BC;
    goto block_20;
block_6:
    if (arg2 != 3) {
        goto block_8;
    }
    var_s0 = &D_800A51C0;
    goto block_20;
block_8:
    if (arg2 != 4) {
        goto block_10;
    }
    var_s0 = &D_800A51C8;
    goto block_20;
block_10:
    if (arg2 != 5) {
        goto block_12;
    }
    var_s0 = &D_800A51D0;
    goto block_20;
block_12:
    if (arg2 != 6) {
        goto block_14;
    }
    var_s0 = &D_800A51D8;
    goto block_20;
block_14:
    if (arg2 != 7) {
        goto block_16;
    }
    var_s0 = &D_800A51DC;
    goto block_20;
block_16:
    if (arg2 != 8) {
        goto block_18;
    }
    var_s0 = &D_800A51E4;
    goto block_20;
block_18:
    if (arg2 != 9) {
        goto block_20;
    }
    var_s0 = &D_800A51EC;
block_20:
    func_8000C22C(*(s32 *)((char *)D_800A1468 + 0xE4), 0xFF, 0, 0, 0xFF);
    func_8000C244(*(s32 *)((char *)D_800A1468 + 0xE4), func_800056FC(D_800ADF80), arg0, arg1, var_s0, 0);
    return;
}
