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

M2C_UNK select_copy_entry_label();                            /* extern */
extern void *gSelectState;
extern M2C_UNK InitRaceHud;
extern M2C_UNK select_update_record_bars;

/* Runs select_copy_entry_label, then installs InitRaceHud and select_update_record_bars in the select state's callback slots (+0x288, +0x28C). */ s32 select_install_callbacks(void) {
    select_copy_entry_label();
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &InitRaceHud;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &select_update_record_bars;
    return 0;
}
