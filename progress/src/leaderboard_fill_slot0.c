extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);
/* Fills the leaderboard entry for the given slot from the stream state's record table, with no offset. */
void leaderboard_fill_slot0(int slot) { fill_leaderboard_entry(slot, stream_state + 0x10332, 0); }
