s32 select_reset_all(void);
extern s8 gSelectResetFlag;
extern s32 stream_state;

/* Sets the reset flag, stores 7 in the state's pointed-to field at +0x1E, then resets the select state. */
s32 select_arm_reset_state(void) {
    gSelectResetFlag = 1;
    *(s16 *)((char *)*(void **)((char *)&stream_state + 0x32F2) + 0x1E) = 7;
    select_reset_all();
    return 0;
}
