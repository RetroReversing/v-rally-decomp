extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills one leaderboard entry from the record buffer at stream_state + 0x10332, using variant 5. */
/* Fills entry in board slot 5 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry_slot5(int record) {
    fill_leaderboard_entry(record, stream_state + 0x10332, 5);
}
