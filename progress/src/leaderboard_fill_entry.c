extern char stream_state[];
void fill_leaderboard_entry(s32 record, char *board, s32 slot);

/* Fills leaderboard slot 8 of the stream-state board from the given track record. */
/* Fills entry in board slot 8 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry(s32 record) {
    fill_leaderboard_entry(record, stream_state + 0x10332, 8);
}
