extern s8 gSelectResetFlag;
extern u8 stream_state;
s32 select_reset_all(void);

/* Resets select state: clears the active flag, sets the status word at
 * stream_state+0x32F2 -> +0x1E to 7, then resets the select lists. */
s32 select_reset_session(void) {
    gSelectResetFlag = 0;
    *(s16 *)(*(void **)((u8 *)&stream_state + 0x32F2) + 0x1E) = 7;
    select_reset_all();
    return 0;
}
