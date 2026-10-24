#include "common.h"

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



extern signed char D_800C35C9;
extern signed char D_800C35CA;
extern signed char D_800C35CB;
extern signed char D_800C35CC;
extern signed char D_800C35CD;
extern signed char D_800C35CE;
extern signed char D_800C35CF;
extern short D_800C35D0;
extern short D_800C35D2;
extern short D_800C35D4;


s32 func_80098180();
extern char D_800A4AFC[];
extern char D_800A4B04[];
extern char D_800A4B0C[];
extern char D_800A4B14[];
extern char D_800C02AE[];

void func_800386B4(s32 arg0) {
    s32 temp_s0;
    s8 var_v0;

    temp_s0 = arg0 + 0x4C;
    if (func_80098180(temp_s0, &D_800A4AFC) == 0) {
        D_800C35C9 = 3;
        D_800C35CA = 0x22;
        D_800C35CB = 0x21;
        D_800C35CC = 0x20;
        D_800C35CD = 0x60;
        D_800C35CE = 0x5E;
        D_800C35CF = 0x5C;
        D_800C35D0 = 0x32;
        D_800C35D2 = 0x64;
        D_800C35D4 = 0x78;
        return;
    }
    if (func_80098180(temp_s0, &D_800A4B04) == 0) {
        D_800C35C9 = 3;
        D_800C35CA = 0x1B;
        D_800C35CB = 0x1C;
        D_800C35CC = 0x1D;
        D_800C35CD = 0x60;
        D_800C35CE = 0x5E;
        D_800C35CF = 0x5C;
        D_800C35D0 = 0x64;
        D_800C35D2 = 0x8C;
        D_800C35D4 = 0x50;
        return;
    }
    if (func_80098180(temp_s0, &D_800A4B0C) == 0) {
        D_800C35C9 = 1;
        var_v0 = 0x1F;
        goto block_8;
    }
    if (func_80098180(temp_s0, &D_800A4B14) == 0) {
        D_800C35C9 = 1;
        var_v0 = 0x1E;
block_8:
        D_800C35CA = var_v0;
        D_800C35CD = 0x60;
        D_800C35D0 = 0x96;
    }
}
