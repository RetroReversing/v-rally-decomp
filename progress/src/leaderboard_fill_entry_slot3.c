extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills one leaderboard entry from the record buffer at stream_state + 0x10332, using variant 3. */
/* Fills entry in board slot 3 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry_slot3(int record) {
    fill_leaderboard_entry(record, stream_state + 0x10332, 3);
}
