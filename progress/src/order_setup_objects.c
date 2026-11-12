/* Sets up the pooled lists of every object in the order table's list at gOrderState+0x72FC. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

M2C_UNK list_for_each(s32, M2C_UNK *);              /* extern */
extern M2C_UNK gOrderState;
extern M2C_UNK obj_setup_pooled_lists;

void order_setup_objects(void) {
    list_for_each(M2C_FIELD(&gOrderState, s32 *, 0x72FC), &obj_setup_pooled_lists);
}
