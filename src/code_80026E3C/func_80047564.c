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



s32 func_800221D4();
s32 func_80080440();
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_80047C78;

void func_80047564(void) {
    *(s32 *)(D_800C02AE + 0x7672) = func_80080440();
    func_800221D4(D_800AE850 + 0x7380, &func_80047C78);
}
