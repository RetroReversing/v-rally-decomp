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

void *_filterBuffer(s32, s16, s32, void *);         /* extern */
void *_loadBuffer(void *, u32, s16, s32, void *);   /* extern */
void *_loadOutputBuffer(void *, void *, s16, s32, void *); /* extern */
void *_saveBuffer(void *, u32, s16, s32, void *);   /* extern */
M2C_UNK func_800914E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_800A71C0;
extern M2C_UNK D_800A71C4;

void *alFxPull(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    u16 sp1E;                                       /* compiler-managed */
    u32 sp24;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v1;
    s16 var_s6;
    s16 var_s7;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a2;
    s32 temp_s0_2;
    s32 var_fp;
    u32 temp_a0;
    u32 temp_s4;
    u32 temp_v0_8;
    void *temp_s0;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_7;
    void *var_s1;

    temp_s0 = M2C_FIELD(arg0, void **, 0);
    var_fp = 0;
    if (temp_s0 == NULL) {
        func_800914E0(&D_800A71C0, &D_800A71C4, 0x4B);
    }
    var_s7 = 0;
    sp1E = 0;
    temp_v0 = M2C_FIELD(temp_s0, void *(**)(void *, M2C_UNK, s32, M2C_UNK, s32), 4)(temp_s0, arg1, arg2, arg3, arg4);
    temp_s1 = temp_v0 + 8;
    temp_s1_2 = temp_s1 + 8;
    temp_s0_2 = arg2 * 2;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x08000000;
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) (temp_s0_2 & 0xFFFF);
    M2C_FIELD(temp_v0, s32 *, 8) = 0x0C00DA83;
    M2C_FIELD(temp_s1, s32 *, 4) = 0x06C006C0;
    M2C_FIELD(temp_s1, s32 *, 8) = 0x0C005A82;
    M2C_FIELD(temp_s1_2, s32 *, 4) = 0x080006C0;
    temp_v0_2 = _saveBuffer(arg0, M2C_FIELD(arg0, u32 *, 0x18), 0x6C0, arg2, temp_s1_2 + 8);
    M2C_FIELD(temp_v0_2, s32 *, 0) = 0x02000800;
    M2C_FIELD(temp_v0_2, s32 *, 4) = temp_s0_2;
    var_s6 = 0x140;
    var_s1 = temp_v0_2 + 8;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x24) > 0) {
        do {
            temp_s2 = M2C_FIELD(arg0, s32 *, 0x20) + ((s16) sp1E * 0x28);
            temp_a0 = M2C_FIELD(arg0, u32 *, 0x18);
            temp_s4 = temp_a0 - (M2C_FIELD(temp_s2, s32 *, 0) * 2);
            sp24 = temp_a0 - (M2C_FIELD(temp_s2, s32 *, 4) * 2);
            if (temp_s4 == var_fp) {
                temp_v0_4 = var_s6;
                var_s6 = var_s7;
                var_s7 = temp_v0_4;
            } else {
                var_s1 = _loadBuffer(arg0, temp_s4, var_s7, arg2, var_s1);
            }
            temp_v1 = M2C_FIELD(temp_s2, s16 *, 8);
            var_s1 = _loadOutputBuffer(arg0, temp_s2, var_s6, arg2, var_s1);
            if (temp_v1 != 0) {
                M2C_FIELD(var_s1, s32 *, 0) = (s32) ((temp_v1 & 0xFFFF) | 0x0C000000);
                M2C_FIELD(var_s1, s32 *, 4) = (s32) ((var_s7 << 0x10) | (var_s6 & 0xFFFF));
                var_s1 += 8;
                if ((M2C_FIELD(temp_s2, s32 *, 0x24) == 0) && (M2C_FIELD(temp_s2, s32 *, 0x20) == 0)) {
                    var_s1 = _saveBuffer(arg0, sp24, var_s6, arg2, var_s1);
                }
            }
            temp_v0_5 = M2C_FIELD(temp_s2, s16 *, 0xA);
            if (temp_v0_5 != 0) {
                M2C_FIELD(var_s1, s32 *, 0) = (s32) ((temp_v0_5 & 0xFFFF) | 0x0C000000);
                M2C_FIELD(var_s1, s32 *, 4) = (s32) ((var_s6 << 0x10) | (var_s7 & 0xFFFF));
                var_s1 = _saveBuffer(arg0, temp_s4, var_s7, arg2, var_s1 + 8);
            }
            temp_a0_2 = M2C_FIELD(temp_s2, s32 *, 0x20);
            if (temp_a0_2 != 0) {
                var_s1 = _filterBuffer(temp_a0_2, var_s6, arg2, var_s1);
            }
            if (M2C_FIELD(temp_s2, s32 *, 0x24) == 0) {
                var_s1 = _saveBuffer(arg0, sp24, var_s6, arg2, var_s1);
            }
            temp_v0_6 = M2C_FIELD(temp_s2, s16 *, 0xC);
            if (temp_v0_6 != 0) {
                temp_v0_7 = var_s1;
                var_s1 += 8;
                M2C_FIELD(temp_v0_7, s32 *, 0) = (s32) ((temp_v0_6 & 0xFFFF) | 0x0C000000);
                M2C_FIELD(temp_v0_7, s32 *, 4) = (s32) ((var_s6 << 0x10) | 0x800);
            }
            temp_v0_3 = sp1E + 1;
            var_fp = M2C_FIELD(arg0, u32 *, 0x18) + (M2C_FIELD(temp_s2, s32 *, 4) * 2);
            sp1E = temp_v0_3;
        } while (temp_v0_3 < (s32) M2C_FIELD(arg0, u8 *, 0x24));
    }
    temp_a2 = arg2 * 2;
    temp_v0_8 = M2C_FIELD(arg0, u32 *, 0x18) + temp_a2;
    temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x1C) * 2;
    M2C_FIELD(arg0, u32 *, 0x18) = temp_v0_8;
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x14) + temp_a0_3) < temp_v0_8) {
        M2C_FIELD(arg0, u32 *, 0x18) = (u32) (temp_v0_8 - temp_a0_3);
    }
    M2C_FIELD(var_s1, s32 *, 0) = (s32) (((u32) (0x800 << 0x10) >> 0x10) | 0x0A000000);
    M2C_FIELD(var_s1, s32 *, 4) = (s32) ((temp_a2 & 0xFFFF) | 0x06C00000);
    return var_s1 + 8;
}
