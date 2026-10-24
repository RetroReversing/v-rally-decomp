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

extern int D_800C81D4;
extern float D_800C35DC;


s32 func_800899DC();
extern char D_800C02AE[];

void func_80038AE4(s32 arg0) {
    func_800899DC(D_800C81D4 + ((arg0 & 0xFF) * 0xC), (s32) (D_800C35DC * 128.0f));
}
