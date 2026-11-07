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

M2C_UNK func_800699E4();                            /* extern */
M2C_UNK func_8006F75C();                            /* extern */
M2C_UNK func_8007A794();                            /* extern */
extern void *D_8009B5A4;
extern s16 D_800A0370;
extern s16 D_800A0372;
extern u16 D_800A0374;
extern u16 D_800A0376;
extern void *D_800A1468;

void func_8007AA94(void) {
    D_800A0370 = 0;
    D_800A0372 = 0;
    D_800A0374 = M2C_FIELD(D_8009B5A4, u16 *, 4);
    D_800A0376 = M2C_FIELD(D_8009B5A4, u16 *, 6);
    func_800699E4();
    M2C_FIELD(D_800A1468, s8 *, 0x2BD) = -1;
    func_8006F75C();
    func_8007A794();
}
