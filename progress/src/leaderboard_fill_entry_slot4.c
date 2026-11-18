extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills one leaderboard entry from the record buffer at stream_state + 0x10332, using variant 4. */
/* Fills entry in board slot 4 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry_slot4(int record) {
    fill_leaderboard_entry(record, stream_state + 0x10332, 4);
}
