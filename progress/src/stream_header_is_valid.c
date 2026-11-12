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

extern unsigned char D_800C72CD;
extern unsigned char D_800C72CE;
extern unsigned char D_800C72CF;


extern char stream_state[];

/* Checks the stream header signature bytes D_800C72CD..CF ('D', 'E', then a byte XOR 0x1D == 0); returns the result or NULL on mismatch. */ void *stream_header_is_valid(void) {
    s32 expected;
    void *sigByte;
    void *result;

    sigByte = stream_state + 0x701F;
#ifdef PORT
    sigByte = (void *)(uintptr_t) D_800C72CD;
#else
    sigByte = (void *) D_800C72CD;
#endif
    expected = 0x44;
    result = NULL;
    if (sigByte == (void *)0x44) {
        sigByte = stream_state + 0x7020;
#ifdef PORT
        sigByte = (void *)(uintptr_t) D_800C72CE;
#else
        sigByte = (void *) D_800C72CE;
#endif
        expected = 0x45;
        if (sigByte == (void *)0x45) {
            result = stream_state + 0x7021;
#ifdef PORT
            result = (void *)(uintptr_t) D_800C72CF;
#else
            result = (void *) D_800C72CF;
#endif
#ifdef PORT
            result = (void *) ((uintptr_t) result ^ 0x1D);
#else
            result = (void *) ((s32) result ^ 0x1D);
#endif
#ifdef PORT
            result = (void *)(uintptr_t) (result == NULL);
#else
            result = (void *) (result == NULL);
#endif
        }
    }
    return result;
}
