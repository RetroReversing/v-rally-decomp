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

/* Sets the x and y position fields (+0x0C, +0x10) of the item referenced by the set's pointer at +0x10. */ void rect_set_set_item_pos(void *rect_set, s32 x, s32 y) {
    M2C_FIELD(M2C_FIELD(rect_set, void **, 0x10), s32 *, 0xC) = x;
    M2C_FIELD(M2C_FIELD(rect_set, void **, 0x10), s32 *, 0x10) = y;
}
