extern u8 stream_state[];
void fill_leaderboard_entry(s32 entry, u8 *buf, s32 kind);

/* Fills leaderboard entry 'entry' from the leaderboard buffer in stream_state (kind 6). */
void leaderboard_fill_entry_from_stream(s32 entry) {
    fill_leaderboard_entry(entry, stream_state + 0x10332, 6);
}
