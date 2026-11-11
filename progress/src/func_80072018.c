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

M2C_UNK func_8005C198();
M2C_UNK func_8005E28C(M2C_UNK, M2C_UNK);
M2C_UNK func_8005E470(s32, M2C_UNK);
M2C_UNK heapFreeBlock(s32);
extern s32 gSelectBuffer;
extern s8 gStreamPhase;

/* Stream-side counterpart of select_screen_setup: marks the screen shown, frees the text buffer if one is held, runs func_8005E470 with the arguments, sets the stream phase to 1 and resets func_8005E28C. */
s32 func_80072018(s32 arg0, M2C_UNK arg1) {
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    func_8005E470(arg0, arg1);
    gStreamPhase = 1;
    func_8005E28C(0, 0);
    return 0;
}
