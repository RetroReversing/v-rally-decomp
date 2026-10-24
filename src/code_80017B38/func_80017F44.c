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



extern f32 D_8009CEC0;
extern f32 D_8009CEC4;
extern f32 D_8009CEC8;

void func_80017F44(void **arg0) {
    void *temp_v0;

    temp_v0 = *arg0;
    *(s32 *)((char *)temp_v0 + 0) = (s32) ((f32) *(s32 *)((char *)temp_v0 + 0) * D_8009CEC0);
    *(s32 *)((char *)temp_v0 + 4) = (s32) ((f32) *(s32 *)((char *)temp_v0 + 4) * D_8009CEC4);
    *(s32 *)((char *)temp_v0 + 8) = (s32) ((f32) *(s32 *)((char *)temp_v0 + 8) * D_8009CEC8);
}
