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

s32 order_alloc_records(M2C_UNK);                   /* extern */
extern M2C_UNK func_8001BD44;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

void func_8001BDA0(void) {
    M2C_UNK *temp_a1;
    s32 temp_v0;

    M2C_FIELD(&gOrderState, s32 *, 0x87D8) = order_alloc_records(0x12C);
    temp_v0 = order_alloc_records(0x12C);
    temp_a1 = M2C_FIELD(&stream_state, M2C_UNK **, 0x7DA6);
    M2C_FIELD(&gOrderState, s32 *, 0x87DC) = temp_v0;
    M2C_FIELD(&gOrderState, s32 *, 0x87E4) = temp_v0;
    M2C_FIELD(&gOrderState, s32 *, 0x87E8) = 0;
    M2C_FIELD(&gOrderState, s32 *, 0x87EC) = 0x12C;
    M2C_FIELD(&stream_state, M2C_UNK **, 0x7DA6) = &func_8001BD44;
    M2C_FIELD(&gOrderState, s32 *, 0x87E0) = (s32) M2C_FIELD(&gOrderState, s32 *, 0x87D8);
    M2C_FIELD(&gOrderState, M2C_UNK **, 0x6D9C) = temp_a1;
}
