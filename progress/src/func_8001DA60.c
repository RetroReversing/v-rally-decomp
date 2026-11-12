extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills one leaderboard entry from the record buffer at stream_state + 0x10332, using variant 5. */
void func_8001DA60(int slot) {
    fill_leaderboard_entry(slot, stream_state + 0x10332, 5);
}
