/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

/* Stores a 32-bit value into a sequence record in four separate bytes (offsets 0, 1, 4 and 5), not contiguously. */ void seq_record_store_u32(u32 value, u8 *rec) {
    M2C_FIELD(rec, s8 *, 5) = (s8) (value >> 8);
    M2C_FIELD(rec, u8 *, 0) = (u8) value;
    M2C_FIELD(rec, s8 *, 4) = (s8) (value >> 0x10);
    M2C_FIELD(rec, s8 *, 1) = (s8) (value >> 0x18);
}
