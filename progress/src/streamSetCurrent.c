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

s32 func_80005744();
extern char stream_state[];

/* Makes stream arg0 the current stream (stored in stream_state+0x7CD6), then calls func_80005744 with the stream's field at +0x178. Returns the stream. */
void *streamSetCurrent(void *stream) {
    s32 field;
    void *result;

    result = stream;
    field = *(s32 *)((char *)result + 0x178);
    *(void * *)(stream_state + 0x7CD6) = result;
    func_80005744(field);
    return result;
}
