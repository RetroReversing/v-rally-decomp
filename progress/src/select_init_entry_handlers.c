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
extern M2C_UNK func_80068130;
extern M2C_UNK func_800683CC;

/* Copies the entry label, then stores two select handler callbacks (func_80068130, func_800683CC) in the select state. Returns 0. */ s32 select_init_entry_handlers(void) {
    select_copy_entry_label();
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80068130;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_800683CC;
    return 0;
}
