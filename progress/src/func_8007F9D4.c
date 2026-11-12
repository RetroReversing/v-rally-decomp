/* Points stream_state's slot at D_800A1978 and copies the word at 0x7032 into 0x703A; always returns 1. */
extern s32 D_800A1978;
extern s32 stream_state;

s32 func_8007F9D4(void) {
    *(s32 **)((s8 *)&stream_state + 0x5912) = &D_800A1978;
    *(s32 *)((s8 *)&stream_state + 0x703A) = *(s32 *)((s8 *)&stream_state + 0x7032);
    return 1;
}
