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

M2C_UNK select_arm_if_clear();
M2C_UNK select_request_reset(M2C_UNK, M2C_UNK);
M2C_UNK select_reset_all(s32, M2C_UNK);
M2C_UNK heapFreeBlock(s32);
extern s32 gSelectBuffer;
extern s8 gStreamPhase;

/* Stream-side counterpart of select_screen_setup: marks the screen shown, frees the text buffer if one is held, runs select_reset_all with the arguments, sets the stream phase to 1 and resets select_request_reset. */
s32 func_80072018(s32 arg0, M2C_UNK arg1) {
    select_arm_if_clear();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    select_reset_all(arg0, arg1);
    gStreamPhase = 1;
    select_request_reset(0, 0);
    return 0;
}
