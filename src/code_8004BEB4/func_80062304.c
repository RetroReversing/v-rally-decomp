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

extern unsigned short D_800C34FC;
extern unsigned short D_800C836E;
extern short D_800B6FF0;


extern char D_800AE850[];
extern char D_800C02AE[];

void func_80062304(void) {
    u16 var_a0;
    u16 var_v1;
    void *var_v0;

    var_v0 = D_800C02AE + 0x32F2;
    var_v0 = *(void * *)(D_800C02AE + 0x32F2);
    var_v1 = *(u16 *)((char *)var_v0 + 0x1E);
    var_a0 = *(u16 *)((char *)var_v0 + 0x20);
    var_v0 = (void *) *(u16 *)((char *)var_v0 + 0x22);
    D_800C34FC = var_v1;
    D_800C836E = var_a0;
    D_800B6FF0 = (s16) var_v0;
}
