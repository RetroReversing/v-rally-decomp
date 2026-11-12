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

M2C_UNK add_car_hud_entry();                            /* extern */
extern M2C_UNK stream_state;

/* Adds a car HUD entry while the counter at stream_state+0x32AA is below 2. */ void car_hud_add_if_room(void) {
    if ((u32) M2C_FIELD(&stream_state, u32 *, 0x32AA) < 2U) {
        add_car_hud_entry();
    }
}
