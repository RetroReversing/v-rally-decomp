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
extern s8 gSelectMode;
extern M2C_UNK select_refresh_entry;

/* Copies the current entry label, sets gSelectMode to 1 and installs select_refresh_entry as the select state's refresh callback at +0x288. */ s32 select_install_refresh_callback(void) {
    select_copy_entry_label();
    gSelectMode = 1;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &select_refresh_entry;
    return 0;
}
