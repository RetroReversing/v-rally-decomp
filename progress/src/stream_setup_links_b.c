/* Points stream_state's slot at D_800A195C and copies the word at 0x7032 into 0x703E; always returns 1. */
extern s32 D_800A195C;
extern s32 stream_state;

s32 stream_setup_links_b(void) {
    *(s32 **)((s8 *)&stream_state + 0x5916) = &D_800A195C;
    *(s32 *)((s8 *)&stream_state + 0x703E) = *(s32 *)((s8 *)&stream_state + 0x7032);
    return 1;
}
