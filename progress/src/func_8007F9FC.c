/* Stream buffer setup step: points the stream state at the buffer table D_800A1994 and copies
 * the word at +0x7032 into +0x7042. Returns 1 (always succeeds). */
extern s32 D_800A1994;
extern s32 stream_state;

s32 func_8007F9FC(void) {
    *(s32 **)((u8 *)&stream_state + 0x591A) = &D_800A1994;
    *(s32 *)((u8 *)&stream_state + 0x7042) = *(s32 *)((u8 *)&stream_state + 0x7032);
    return 1;
}
