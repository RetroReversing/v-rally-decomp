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

M2C_UNK func_8006E208();                            /* extern */
M2C_UNK func_8006F3C0();                            /* extern */
M2C_UNK func_8006F424();                            /* extern */
M2C_UNK func_8006F5B0();                            /* extern */
M2C_UNK func_8006F75C();                            /* extern */
extern M2C_UNK D_800C02AE;

void func_8006B8C4(void) {
    M2C_FIELD(&D_800C02AE, s8 *, 0x701F) = 0x44;
    M2C_FIELD(&D_800C02AE, s8 *, 0x7020) = 0x45;
    M2C_FIELD(&D_800C02AE, s8 *, 0x7021) = 0x1D;
    func_8006F5B0();
    func_8006F3C0();
    func_8006F424();
    func_8006E208();
    func_8006F75C();
}
