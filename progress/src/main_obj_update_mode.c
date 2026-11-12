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

M2C_UNK obj_set_flag_slot(s32, M2C_UNK);                /* extern */
M2C_UNK obj_copy_mode_result(s32, s32);                    /* extern */
extern s32 gMainObj;

/* Adds flag 8 to the main object's flag slots, then copies src's mode into it. */ void main_obj_update_mode(s32 src) {
    obj_set_flag_slot(gMainObj, 8);
    obj_copy_mode_result(src, gMainObj);
}
