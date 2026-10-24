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



extern char D_800C02AE[];

void func_80020D58(void **arg0) {
    void **temp_v0;
    void *var_a0;

    var_a0 = *arg0;
    if (var_a0 != NULL) {
        do {
            if (M2C_FIELD(*(void * *)((char *)var_a0 + 0x5C), s32 *, 0x6C) == 1) {
                temp_v0 = (*(u16 *)(D_800C02AE + 0x5A4A) * 4) + (D_800C02AE + 0x5A4A + 4);
                *(u16 *)(D_800C02AE + 0x5A4A) = (u16) (*(u16 *)(D_800C02AE + 0x5A4A) + 1);
                *temp_v0 = var_a0;
            }
            var_a0 = *(void * *)((char *)var_a0 + 4);
        } while (var_a0 != NULL);
    }
}
