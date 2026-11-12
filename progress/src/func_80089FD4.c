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

/* Copies a record from src into dst: index at +2, byte from table entry (0x14-byte stride, table at +0x10) +0xE, and two words at +8/+0xC into +4/+8. */
void func_80089FD4(void *dst, void *src) {
    M2C_FIELD(dst, u16 *, 0) = (u16) M2C_FIELD(src, u16 *, 2);
#ifdef PORT
    M2C_FIELD(dst, u8 *, 2) = (u8) M2C_FIELD(((s8 *) M2C_FIELD(src, void **, 0x10) + ((s16) M2C_FIELD(src, u16 *, 2) * 0x14)), u8 *, 0xE);
#else
    M2C_FIELD(dst, u8 *, 2) = (u8) M2C_FIELD((((s16) M2C_FIELD(src, u16 *, 2) * 0x14) + M2C_FIELD(src, s32 *, 0x10)), u8 *, 0xE);
#endif
    M2C_FIELD(dst, s32 *, 4) = (s32) M2C_FIELD(src, s32 *, 8);
    M2C_FIELD(dst, s32 *, 8) = (s32) M2C_FIELD(src, s32 *, 0xC);
}
