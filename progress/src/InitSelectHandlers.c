#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

M2C_UNK select_reset_text();
extern void *gSelectState;
extern s8 gSelectMode;
extern M2C_UNK func_80070630;
extern M2C_UNK func_80070750;

/* Resets the select text, clears gSelectMode, and installs the two handler
 * pointers (func_80070630, func_80070750) in the select state at +0x288/+0x28C. */
s32 InitSelectHandlers(void) {
    select_reset_text();
    gSelectMode = 0;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80070630;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_80070750;
    return 0;
}
