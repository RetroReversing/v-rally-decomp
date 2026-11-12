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

M2C_UNK select_flush_pending();                            /* extern */
extern void *gSelectState;

/* Copies the s32 at src+0x90 into the select state's flag byte at +0x233; if that flag is negative, flushes the pending select entries. */ void func_800585DC(void *src) {
    M2C_FIELD(gSelectState, s8 *, 0x233) = (s8) M2C_FIELD(src, s32 *, 0x90);
    if (M2C_FIELD(gSelectState, s8 *, 0x233) < 0) {
        select_flush_pending();
    }
}
