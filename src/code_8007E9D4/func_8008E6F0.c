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



void *func_8008EBEC();

void func_8008E6F0(void *arg0, void *arg1) {
    s32 (*var_v0)(void *, s32, void *);
    s32 var_a1;
    s32 var_v1;
    void *var_a0;
    void *var_a2;
    void *var_s0;
    void *var_s1;

    var_s0 = arg1;
    var_v0 = M2C_FIELD(var_s0, s32 (**)(void *, s32, void *), 8);
    var_s1 = arg0;
    if (var_v0 != NULL) {
        var_a2 = func_8008EBEC();
        if (var_a2 != NULL) {
            var_v0 = M2C_FIELD(var_s0, s32 (**)(void *, s32, void *), 8);
            var_v1 = *(s32 *)((char *)var_s1 + 0x1C);
            var_a0 = *(void * *)((char *)var_v0 + 0xD8);
            var_v0 = (s32 (*)(void *, s32, void *))0xF;
            *(s16 *)((char *)var_a2 + 8) = 0xF;
            *(s32 *)((char *)var_a2 + 0) = 0;
            var_v1 += var_a0;
            *(s32 *)((char *)var_a2 + 4) = var_v1;
            var_v0 = M2C_FIELD(var_s0, s32 (**)(void *, s32, void *), 8);
            var_a0 = *(void * *)((char *)var_v0 + 0xC);
            var_v0 = M2C_FIELD(var_a0, s32 (**)(void *, s32, void *), 8);
            var_a1 = 3;
            var_v0(var_a0, 3, var_a2);
        }
    }
}
