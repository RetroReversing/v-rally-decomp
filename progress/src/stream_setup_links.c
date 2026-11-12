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

extern M2C_UNK D_800A1940;
extern M2C_UNK stream_state;

/* Points the stream state's link at D_800A1940 and copies the word at +0x7032 to +0x7036. */
s32 stream_setup_links(void) {
    M2C_FIELD(&stream_state, M2C_UNK **, 0x590E) = &D_800A1940;
    M2C_FIELD(&stream_state, s32 *, 0x7036) = (s32) M2C_FIELD(&stream_state, s32 *, 0x7032);
    return 1;
}
