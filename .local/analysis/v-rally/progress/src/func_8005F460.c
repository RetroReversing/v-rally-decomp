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

M2C_UNK func_8001B5AC(s32);                         /* extern */
M2C_UNK func_8001B6DC();                            /* extern */
M2C_UNK func_8002B618(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_8004D31C();                            /* extern */
M2C_UNK func_80054838();                            /* extern */
s32 func_80057810(s32);                             /* extern */
M2C_UNK func_800578E0(s32);                         /* extern */
M2C_UNK func_8005803C(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8005BB5C();                            /* extern */
M2C_UNK func_8005BC60();                            /* extern */
M2C_UNK func_8005EB48();                            /* extern */
M2C_UNK func_8006B8C4();                            /* extern */
M2C_UNK func_8006E33C();                            /* extern */
M2C_UNK func_8006F75C();                            /* extern */
M2C_UNK func_8006F7F8();                            /* extern */
extern void *D_800A1468;
extern s32 D_800A14C0;
extern s8 D_800A16F0;
extern M2C_UNK D_800A54F0;
extern M2C_UNK D_800C02AE;

s32 func_8005F460(void) {
    func_8005803C(0, 0);
    M2C_FIELD(D_800A1468, s8 *, 0x24D) = 0;
    D_800A16F0 = 0;
    func_8001B5AC(M2C_FIELD(&D_800C02AE, s32 *, 0x32F2));
    func_8001B6DC();
    func_8006F7F8();
    D_800A16F0 = 0;
    func_8002B618(&D_800A54F0, 0);
    func_8006B8C4();
    func_8006E33C();
    func_8006F75C();
    func_80054838();
    M2C_FIELD(&D_800C02AE, s32 *, 0x32AA) = 0;
    func_800578E0(M2C_FIELD(&D_800C02AE, s32 *, 0x807A));
    M2C_FIELD(&D_800C02AE, s32 *, 0x807A) = func_80057810(D_800A14C0);
    func_8005BC60();
    func_8005BB5C();
    func_8004D31C();
    func_8005EB48();
    return 0;
}
