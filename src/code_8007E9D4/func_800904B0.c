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

extern unsigned char D_800C3520;


s32 func_8008D090();
s32 func_8008D8B4();
s32 func_8008D920();
s32 func_800905D4();
s32 func_80090DC0();
extern char D_800AE850[];
extern char D_800C02AE[];

s32 func_800904B0(s32 arg0) {
    s32 temp_v0;

    func_8008D8B4();
    if (D_800C3520 != 1) {
        func_800905D4();
        func_80090DC0(1, D_800AE850 + 0x1250);
        func_8008D090(arg0, 0, 1);
    }
    temp_v0 = func_80090DC0(0, D_800AE850 + 0x1250);
    D_800C3520 = 1U;
    func_8008D920();
    return temp_v0;
}
