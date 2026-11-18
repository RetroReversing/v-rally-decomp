extern u8 stream_state[];
void fill_leaderboard_entry(s32 entry, u8 *buf, s32 kind);

/* Fills one leaderboard entry from the leaderboard buffer kept in the stream state. */
void leaderboard_fill_entry_from_stream(s32 entry) {
    fill_leaderboard_entry(entry, stream_state + 0x10332, 6);
}
