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

void func_8003AE84(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x24);
    if (temp_v1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x80) |= 4;
        if (M2C_FIELD(M2C_FIELD(temp_v1, void **, 0x6C), s32 *, 0xC) != 0) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 0xB;
            if (M2C_FIELD(M2C_FIELD(temp_v1, void **, 0x6C), s32 *, 0x20) == 0) {
                M2C_FIELD(arg0, u8 *, 0x90) = 0xFE;
                M2C_FIELD(arg0, u8 *, 0x91) = 0xD5;
                M2C_FIELD(arg0, s8 *, 0x92) = 0x1E;
                M2C_FIELD(arg0, u8 *, 0x93) = 0xFF;
            }
            M2C_FIELD(arg0, s32 *, 0x80) &= ~4;
        }
    }
}
