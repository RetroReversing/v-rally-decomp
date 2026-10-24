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

extern int D_800B0C20;


s32 func_80022E24();
s32 func_80023F58();
extern char D_800AE850[];

void func_8001CA48(s32 arg0) {
    func_80022E24(D_800B0C20, 4);
    func_80023F58(arg0, D_800B0C20);
}
