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







extern char D_800AE850[];
extern char D_800C02AE[];

void func_80086DE8(s16 arg0) {
    char pad[8];
    s32 var_a1;
    void *var_a2;
    void *var_v0;
    void *var_v1;

    var_v0 = D_800C02AE + 0x757E;
    var_v0 = *(void * *)(D_800C02AE + 0x757E);
    var_v1 = D_800AE850 + 0x80A0;
    var_v1 = *(void * *)(D_800AE850 + 0x80A0);
    var_a1 = 0;
    if ((s32) var_v0 > 0) {
        var_a2 = var_v0;
        var_v1 += 0x96;
        do {
            var_v0 = (void *) *(u16 *)((char *)var_v1 + 8);
            if (var_v0 == NULL) {
                *(s16 *)((char *)var_v1 + 0) = arg0;
            }
            var_a1 += 1;
            var_v0 = (void *) (var_a1 < (s32) var_a2);
            var_v1 += 0x134;
        } while (var_v0 != NULL);
    }
}
