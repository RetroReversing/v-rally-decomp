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
void *func_800592AC(u32);                           /* extern */
void *func_800592D0(u32);                            /* extern */
void *func_8005A744(u32, void *);                      /* extern */
extern void *D_800A1468;

void func_800580D0(s32 arg0, s8 arg1) {
    s32 var_a0;
    s32 var_a0_2;
    void *temp_v0;
    void *var_a1;
    void *var_a1_2;

    temp_v0 = func_8005A744(arg0 & 0xFF, (void *)(M2C_FIELD(D_800A1468, void **, 0x24)));
    if (M2C_FIELD(temp_v0, s8 *, 9) != 0) {
        var_a1 = func_800592D0((u8)(M2C_FIELD(temp_v0, u8 *, 8)));
        var_a0 = 0;
        if (M2C_FIELD(temp_v0, s8 *, 9) > 0) {
            do {
                M2C_FIELD(var_a1, s8 *, 0x1A) = arg1;
                var_a1 = M2C_FIELD(var_a1, void **, 0);
                var_a0 += 1;
            } while ((var_a0 & 0xFF) < M2C_FIELD(temp_v0, s8 *, 9));
        }
    }
    var_a1_2 = func_800592AC((u16)(M2C_FIELD(temp_v0, u16 *, 4)));
    var_a0_2 = 0;
    if (M2C_FIELD(temp_v0, u16 *, 6) != 0) {
        do {
            M2C_FIELD(var_a1_2, s8 *, 0x41) = arg1;
            var_a1_2 = M2C_FIELD(var_a1_2, void **, 0);
            var_a0_2 += 1;
        } while ((u32) (var_a0_2 & 0xFF) < (u16) M2C_FIELD(temp_v0, u16 *, 6));
    }
    M2C_FIELD(temp_v0, s8 *, 0xA) = arg1;
}
