extern char stream_state[];
s32 select_draw_results_table();

/* Looks up the current select entry (from stream_state+0x325A, indexed by its
 * word at +2, 20-byte entries in the table at +0x10) and passes the value at
 * entry+0xE through the state's lookup table at stream_state+0x32F2 (+0x32).
 * Values of 2 or more pass -1. */
void func_80066EBC(void) {
    char *base;
    u8 v;
    s8 arg;

    base = *(char **)(stream_state + 0x325A);
    v = *(u8 *)(*(char **)(base + 0x10) + *(s16 *)(base + 2) * 20 + 0xE);
    if (v < 2) {
        arg = *(u8 *)(*(char **)(stream_state + 0x32F2) + v + 0x32);
    } else {
        arg = -1;
    }
    select_draw_results_table(arg);
}
