void league_set_flag14(void *league);
extern void *gSelectState;
extern char stream_state[];

/* Clears the select-state byte at +0x245, flags the current league's entry at +0x14, and returns the
 * value at +0x20 of the league table + 0x15. */
s32 func_80071A0C(void)
{
    *(s8 *)((s8 *)gSelectState + 0x245) = 0;
    league_set_flag14(*(void **)(stream_state + 0x325A));
    return *(u16 *)(*(s8 **)(stream_state + 0x32F2) + 0x20) + 0x15;
}
