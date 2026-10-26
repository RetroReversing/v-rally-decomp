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



s32 func_800056FC();
s32 func_80005C48();
void *func_80006008();
s32 func_80006014();
s32 osVirtualToPhysical();
extern void *D_8009B5A4;
extern s32 D_8009B5A8;

void func_8000F04C(void) {
    s32 temp_a0;
    s32 var_s2;
    void *var_s0;
    void *var_s1;

    var_s2 = func_800056FC();
    var_s0 = func_80006008(var_s2);
    var_s1 = var_s0;
    var_s0 += 8;
    temp_a0 = func_80005C48(D_8009B5A8);
    *(s32 *)((char *)var_s1 + 0) = (s32) (((*(s16 *)((char *)D_8009B5A4 + 4) - 1) & 0xFFF) | 0xFF100000);
    *(s32 *)((char *)var_s1 + 4) = osVirtualToPhysical(temp_a0);
    func_80006014(var_s2, var_s0);
}
