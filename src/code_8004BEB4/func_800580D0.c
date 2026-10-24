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



void *func_800592AC();
void *func_800592D0();
void *func_8005A744();
extern void *D_800A1468;

void func_800580D0(s32 arg0, s8 arg1) {
    s32 var_a0;
    s32 var_a0_2;
    void *temp_v0;
    void *var_a1;
    void *var_a1_2;

    temp_v0 = func_8005A744(arg0 & 0xFF, *(s32 *)((char *)D_800A1468 + 0x24));
    if (*(s8 *)((char *)temp_v0 + 9) != 0) {
        var_a1 = func_800592D0(*(u8 *)((char *)temp_v0 + 8));
        var_a0 = 0;
        if (*(s8 *)((char *)temp_v0 + 9) > 0) {
            do {
                *(s8 *)((char *)var_a1 + 0x1A) = arg1;
                var_a1 = *(void * *)((char *)var_a1 + 0);
                var_a0 += 1;
            } while ((var_a0 & 0xFF) < *(s8 *)((char *)temp_v0 + 9));
        }
    }
    var_a1_2 = func_800592AC(*(u16 *)((char *)temp_v0 + 4));
    var_a0_2 = 0;
    if (*(u16 *)((char *)temp_v0 + 6) != 0) {
        do {
            *(s8 *)((char *)var_a1_2 + 0x41) = arg1;
            var_a1_2 = *(void * *)((char *)var_a1_2 + 0);
            var_a0_2 += 1;
        } while ((u32) (var_a0_2 & 0xFF) < (u16) *(u16 *)((char *)temp_v0 + 6));
    }
    *(s8 *)((char *)temp_v0 + 0xA) = arg1;
}
