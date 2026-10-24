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



s32 func_80028D74(void *arg0, void *arg1) {
    s32 var_a0;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;
    void *var_a2;

    var_a2 = *(void * *)((char *)arg0 + 0x5C);
    if (((var_a2 != NULL) && (var_v0 = *(s32 *)((char *)var_a2 + 0x34), var_v1 = *(s32 *)((char *)arg1 + 0), var_v0 = var_v0 < var_v1, (var_v0 != 0)) && (var_v0 = *(s32 *)((char *)var_a2 + 0x3C), var_v0 = var_v1 < var_v0, (var_v0 != 0)) && (var_v0 = *(s32 *)((char *)var_a2 + 0x44), var_v1 = *(s32 *)((char *)arg1 + 8), var_v0 = var_v0 < var_v1, (var_v0 != 0)) && (var_v0 = *(s32 *)((char *)var_a2 + 0x48), var_v0 = var_v1 < var_v0, (var_v0 != 0))) || ((var_a2 = *(void * *)((char *)arg0 + 0x58), var_v0 = (s32) arg0, (var_a2 != NULL)) && (var_v1 = *(s32 *)((char *)var_a2 + 0x34), var_a0 = *(s32 *)((char *)arg1 + 0), var_v1 = var_v1 < var_a0, (var_v1 != 0)) && (var_v1 = *(s32 *)((char *)var_a2 + 0x3C), var_v1 = var_a0 < var_v1, (var_v1 != 0)) && (var_v1 = *(s32 *)((char *)var_a2 + 0x44), var_a1 = *(s32 *)((char *)arg1 + 8), var_v1 = var_v1 < var_a1, (var_v1 != 0)) && (var_v1 = *(s32 *)((char *)var_a2 + 0x48), var_v1 = var_a1 < var_v1, (var_v1 != 0)))) {
        var_v0 = (s32) var_a2;
    }
    return var_v0;
}
