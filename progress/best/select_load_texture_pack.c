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

M2C_UNK appendString(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_8007A794();                            /* extern */
s32 getTexturePack(M2C_UNK *, M2C_UNK);             /* extern */
M2C_UNK resolve_path(M2C_UNK *);                    /* extern */
extern void *D_800A1468;
extern M2C_UNK D_800A5F9C;
extern M2C_UNK D_800A5FAC;
extern M2C_UNK stream_state;

void select_load_texture_pack(void) {
    M2C_UNK sp10;
    s32 temp_a0;
    s32 var_a1;
    u32 var_v1;
    u8 *var_v0;

    func_8007A794();
    resolve_path(&D_800A5F9C);
    var_a1 = 0;
    temp_a0 = M2C_FIELD(&stream_state, s32 *, 0x103AA) + (M2C_FIELD(D_800A1468, u8 *, 0x237) * 0x2C4);
    var_v1 = 0 & 0xFF;
    var_v0 = temp_a0 + var_v1;
    __repair_rows: {
        var_a1 += 1;
        *(&sp10 + var_v1) = *var_v0;
        var_v1 = var_a1 & 0xFF;
        var_v0 = temp_a0 + var_v1;
    }
if (var_v1 < 5U) goto __repair_rows;
    *(&sp10 + var_v1) = 0;
    appendString(&sp10, &D_800A5FAC, &sp10);
    M2C_FIELD(D_800A1468, s32 *, 0x1E4) = getTexturePack(&sp10, 0);
}
