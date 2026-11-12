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

M2C_UNK func_80084740();                            /* extern */
M2C_UNK order_stream_read_block(u16);               /* extern */
M2C_UNK streamReadBytes(void *, M2C_UNK);           /* extern */
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

void stream_select_entry(s32 arg0) {
    M2C_FIELD(&gOrderState, s32 *, 0x8AE4) = (s32) (M2C_FIELD(&gOrderState, s32 *, 0x8AE0) + (arg0 * 8));
    streamReadBytes((&gOrderState + 0x8AE0) - 8, 4);
    func_80084740();
    order_stream_read_block(M2C_FIELD(&stream_state, u16 *, 0x30D6));
}
