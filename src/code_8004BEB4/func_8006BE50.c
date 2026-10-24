#include "common.h"

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

void func_8006BE50(void *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 0xFF;
    switch (temp_a1) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, s8 *, 0x2C) = 0;
        M2C_FIELD(arg0, s8 *, 0x1C) = 0;
        M2C_FIELD(arg0, u8 *, 0x26) = (u8) M2C_FIELD(arg0, u8 *, 0x16);
        M2C_FIELD(arg0, u8 *, 0x27) = (u8) M2C_FIELD(arg0, u8 *, 0x17);
        M2C_FIELD(arg0, u8 *, 0x28) = (u8) M2C_FIELD(arg0, u8 *, 0x18);
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(arg0, u8 *, 0x24) = (u8) M2C_FIELD(arg0, u8 *, 0x14);
        M2C_FIELD(arg0, u8 *, 0x2A) = (u8) M2C_FIELD(arg0, u8 *, 0x1A);
        M2C_FIELD(arg0, u8 *, 0x2B) = (u8) M2C_FIELD(arg0, u8 *, 0x1B);
        M2C_FIELD(arg0, u8 *, 0x16) = (u8) M2C_FIELD(arg0, u8 *, 6);
        M2C_FIELD(arg0, u8 *, 0x17) = (u8) M2C_FIELD(arg0, u8 *, 7);
        M2C_FIELD(arg0, u8 *, 0x18) = (u8) M2C_FIELD(arg0, u8 *, 8);
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, u8 *, 0x14) = (u8) M2C_FIELD(arg0, u8 *, 4);
        M2C_FIELD(arg0, u8 *, 0x1A) = (u8) M2C_FIELD(arg0, u8 *, 0xA);
        M2C_FIELD(arg0, u8 *, 0x1B) = (u8) M2C_FIELD(arg0, u8 *, 0xB);
        return;
    case 1:
        M2C_FIELD(arg0, s8 *, 0x2C) = 0;
        M2C_FIELD(arg0, u8 *, 0x26) = (u8) M2C_FIELD(arg0, u8 *, 0x16);
        M2C_FIELD(arg0, u8 *, 0x27) = (u8) M2C_FIELD(arg0, u8 *, 0x17);
        M2C_FIELD(arg0, u8 *, 0x28) = (u8) M2C_FIELD(arg0, u8 *, 0x18);
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(arg0, u8 *, 0x24) = (u8) M2C_FIELD(arg0, u8 *, 0x14);
        M2C_FIELD(arg0, u8 *, 0x2A) = (u8) M2C_FIELD(arg0, u8 *, 0x1A);
        M2C_FIELD(arg0, u8 *, 0x2B) = (u8) M2C_FIELD(arg0, u8 *, 0x1B);
        return;
    }
}
