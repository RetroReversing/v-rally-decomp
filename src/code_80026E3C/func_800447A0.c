#include "decompdecomp_terminal_800447a0.h"
#line 1 "func.c"
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

M2C_UNK func_8000C188(s32);                         /* extern */
void *func_80022318(void **, u8 *);                /* extern */
M2C_UNK func_800225BC(void **);                     /* extern */
M2C_UNK func_800803C0(void *, s32);                 /* extern */
extern M2C_UNK D_800A4E20;

void func_800447A0(s32 arg0) {
    s32 temp_s1;
    void *temp_v0;

    temp_s1 = arg0 + 0x28;
    temp_v0 = func_80022318((void **)(temp_s1), (u8 *)(&D_800A4E20));
    if (temp_v0 != NULL) {
        func_8000C188(M2C_FIELD(*M2C_FIELD(temp_v0, void ***, 0x10), s32 *, 0x10));
        func_800225BC(M2C_FIELD(temp_v0, void ***, 0x10));
        func_800803C0(temp_v0, temp_s1);
    }
}

