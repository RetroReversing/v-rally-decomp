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

extern int D_800C35C0;


s32 func_80005718();
extern s32 D_8009B5A4;
extern char D_800C02AE[];

void func_800425B8(void *arg0) {
    func_80005718(D_8009B5A4, *(s32 *)((char *)arg0 + 0x178));
    D_800C35C0 = (s32) (D_800C35C0 + 1);
}
