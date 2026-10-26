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

extern signed char D_800C5E54;


s32 func_8000DA84();
s32 func_8000E2B0();
s32 osViBlack();
extern s32 D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5AC;
extern char D_800C02AE[];

s32 func_80005948(void) {
    osViBlack(1);
    D_800C5E54 = 4;
    func_8000DA84();
    if (D_8009B5A4 != 0) {
        func_8000E2B0(D_8009B5A4);
        D_8009B5A4 = 0;
    }
    if (D_8009B5A8 != 0) {
        func_8000E2B0(D_8009B5A8);
        D_8009B5A8 = 0;
    }
    if (D_8009B5AC != 0) {
        func_8000E2B0(D_8009B5AC);
        D_8009B5AC = 0;
    }
    return 1;
}
