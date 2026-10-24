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



void func_8003BA58(void *arg0) {
    s32 var_v0;
    void *var_v1;

    var_v1 = *(void * *)((char *)arg0 + 0xA8);
    var_v0 = *(s32 *)((char *)var_v1 + 0x24);
    if (var_v0 != 0) {
        var_v0 = *(s32 *)((char *)var_v1 + 0x20);
        var_v1 = (void *)0x880000;
        var_v0 &= 0x880000;
        var_v1 = (void *)-5;
        if (var_v0 != 0) {
            var_v0 = *(s32 *)((char *)arg0 + 0x80);
            var_v0 &= ~4;
        } else {
            var_v0 = *(s32 *)((char *)arg0 + 0x80);
            var_v0 |= 4;
        }
        *(s32 *)((char *)arg0 + 0x80) = var_v0;
    }
}
