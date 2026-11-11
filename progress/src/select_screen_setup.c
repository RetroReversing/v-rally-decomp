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

extern void *gSelectState;
extern s32 gSelectBuffer;
extern M2C_UNK func_80064E48;
extern M2C_UNK func_80064E50;
M2C_UNK func_8005C198(void);
M2C_UNK select_reset_text(s32, M2C_UNK);
M2C_UNK heapFreeBlock(s32);

/* Sets up the select screen: marks it shown, frees its text buffer if one is held, resets the text, and installs the two state callbacks. */
s32 select_screen_setup(s32 arg0, M2C_UNK arg1) {
    func_8005C198();
    if (gSelectBuffer != 0) {
        heapFreeBlock(gSelectBuffer);
        gSelectBuffer = 0;
    }
    select_reset_text(arg0, arg1);
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80064E48;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_80064E50;
    return 1;
}
