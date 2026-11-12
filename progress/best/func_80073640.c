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

M2C_UNK font_set_color(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 make_rect_set(s32);                             /* extern */
M2C_UNK rect_set_set_item_pos(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK rect_set_set_scale(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

void func_80073640(void *arg0) {
    s16 var_a0;
    s32 temp_v0;
    u32 var_a1;
    void *var_v1;

    M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(&stream_state, s32 *, 0x103BA);
    temp_v0 = make_rect_set(M2C_FIELD(&stream_state, s32 *, 0x103BA));
    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
    rect_set_set_scale(temp_v0, 0x3F800000, 0x3F800000, 0x3F800000);
    font_set_color(M2C_FIELD(arg0, s32 *, 0x40), 0xFF, 0xFF, 0xFF, 0xFF);
    rect_set_set_item_pos(M2C_FIELD(arg0, s32 *, 0x40), 0x80, 0x30);
    var_a1 = 0;
    var_a0 = 0x20;
    var_v1 = arg0;
    __repair_rows: {
        M2C_FIELD(var_v1, s16 *, 0xC) = var_a0;
        var_a0 += 8;
        M2C_FIELD(var_v1, s16 *, 0x24) = -0x140;
        var_a1 += 1;
        var_v1 += 2;
    }
if (var_a1 < 0xCU) goto __repair_rows;
    if (M2C_FIELD(&gOrderState, s32 *, 0x8030) == 1) {
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(&gOrderState, s32 *, 0x8030);
    } else {
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x48) = 1;
}
