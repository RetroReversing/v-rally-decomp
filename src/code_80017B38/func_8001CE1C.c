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

extern short D_800ADFB8;
extern short D_800ADFBA;
extern short D_800ADFBE;
extern short D_800ADFBC;
extern short D_800ADFC2;
extern short D_800ADFC4;
extern short D_800ADFB4;


extern char D_800A73E0[];

void func_8001CE1C(void *arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = *(s32 *)((char *)arg0 + 0x90);
    D_800ADFB8 = (s16) var_v0;
    var_v0 = *(s32 *)((char *)arg0 + 0xDC);
    D_800ADFBA = (s16) var_v0;
    var_v1 = *(s32 *)((char *)arg0 + 0x128);
    var_v0 = 0xFF;
    D_800ADFBE = 0xFF;
    D_800ADFBC = (s16) var_v1;
    var_v0 = *(s32 *)((char *)arg0 + 0x174);
    D_800ADFC2 = 0;
    D_800ADFC4 = 0;
    D_800ADFB4 = (s16) var_v0;
}
