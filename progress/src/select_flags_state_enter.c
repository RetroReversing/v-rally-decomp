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
extern M2C_UNK select_push_record_flags;
extern M2C_UNK select_redraw_results;

/* Copies the entry label, then installs select_push_record_flags and a second callback as this state's handlers. */ s32 select_flags_state_enter(void) {
    select_copy_entry_label();
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &select_push_record_flags;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &select_redraw_results;
    return 0;
}
