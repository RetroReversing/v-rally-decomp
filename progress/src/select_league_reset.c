extern s32 gRecordTimeScale;
extern u8 gOrderState[];
extern u8 stream_state[];

/* Clears the order-state flag byte at +0x11F9 and stores three times the record time scale at stream_state+0x7E6A. */
void select_league_reset(void) {
    *(s8 *)(gOrderState + 0x11F9) = 0;
    *(s32 *)(stream_state + 0x7E6A) = (s32) (gRecordTimeScale * 3);
}
