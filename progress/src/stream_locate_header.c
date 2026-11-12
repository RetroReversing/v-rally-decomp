/* Starts a stream read: scans for the record marker from the saved position, then seeks to the saved header offset. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

M2C_UNK stream_scan_marker(s32);                         /* extern */
M2C_UNK stream_seek_block(s32);                         /* extern */
extern M2C_UNK stream_state;

void stream_locate_header(void) {
    stream_scan_marker(M2C_FIELD(&stream_state, s32 *, 0x30A2));
    stream_seek_block(M2C_FIELD(&stream_state, s32 *, 0x30E6));
}
