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

extern int D_800C8328;


s32 func_8000C188();
s32 func_8004C7B8();
s32 func_800578E0();
s32 func_8007EE9C();
s32 func_80081B28();
extern void *D_800A0384;
extern char D_800C02AE[];

void func_8004BFEC(void) {
    func_80081B28(*(s32 *)((char *)D_800A0384 + 0));
    func_8000C188(*(s32 *)((char *)D_800A0384 + 4));
    func_8007EE9C(D_800A0384);
    D_800A0384 = NULL;
    func_800578E0(D_800C8328);
    func_8004C7B8();
}
