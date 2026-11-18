extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);
/* Fills the leaderboard entry for the given slot from the stream state's record table, with no offset. */
/* Fills entry in board slot 0 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry_slot0(int record) { fill_leaderboard_entry(record, stream_state + 0x10332, 0); }
