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

extern M2C_UNK stream_state;

/* Sets the stream state to 3 unless the sub-object at +0x32F2 reports state 1. */
void stream_check_sub_state(void) {
    if (M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u16 *, 0xE) != 1) {
        M2C_FIELD(&stream_state, s8 *, 0x7681) = 3;
    }
}
