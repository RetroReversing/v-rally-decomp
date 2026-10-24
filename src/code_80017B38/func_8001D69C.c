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

extern int D_800AE868;


extern char D_800AE850[];

void func_8001D69C(void *arg0) {
    s32 temp_a0;
    s32 var_a1;

    if (D_800AE868 != 0) {
        var_a1 = 0;
        do {
            temp_a0 = var_a1 & 0xFF;
            M2C_FIELD((D_800AE868 + temp_a0), s8 *, 0x40) = (s8) *(s32 *)((char *)arg0 + 0x90);
            M2C_FIELD((D_800AE868 + temp_a0), s8 *, 0x44) = (s8) *(s32 *)((char *)arg0 + 0xDC);
            M2C_FIELD((D_800AE868 + temp_a0), s8 *, 0x48) = (s8) *(s32 *)((char *)arg0 + 0x128);
            var_a1 += 1;
            M2C_FIELD((D_800AE868 + temp_a0), s8 *, 0x4C) = (s8) *(s32 *)((char *)arg0 + 0x174);
        } while ((u32) (var_a1 & 0xFF) < 4U);
    }
}
