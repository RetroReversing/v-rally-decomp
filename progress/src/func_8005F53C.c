s32 select_reset_text();
extern void *gSelectState;
extern s32 func_8005EB48;
extern s32 func_8005ED88;

/* Resets the select screen text, then stores the two select callbacks in gSelectState. Returns 0. */
s32 func_8005F53C(void) {
    select_reset_text();
    *(s32 **)((s8 *)gSelectState + 0x288) = &func_8005EB48;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &func_8005ED88;
    return 0;
}
