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

extern u8 D_800A03DC;

/* Once the global counter D_800A03DC reaches 2, sets bit 1 of obj->flags unless bits 1-2 are already set; below 2 it just increments the counter. */
void func_8004C0C4(void *obj) {
    s32 flags;

    if ((u8) D_800A03DC >= 2U) {
        flags = M2C_FIELD(obj, s32 *, 0xC);
        if (!(flags & 6)) {
            M2C_FIELD(obj, s32 *, 0xC) = (s32) (flags | 2);
        }
    } else {
        D_800A03DC += 1;
    }
}
