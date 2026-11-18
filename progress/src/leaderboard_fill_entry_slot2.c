extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills leaderboard entry `index` from the record at stream_state+0x10332, using mode 2. */
/* Fills entry in board slot 2 of the stream-state leaderboard from a track record. */ void leaderboard_fill_entry_slot2(int record)
{
    fill_leaderboard_entry(record, stream_state + 0x10332, 2);
}
