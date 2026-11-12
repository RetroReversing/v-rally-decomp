extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);

/* Fills leaderboard entry `index` from the record at stream_state+0x10332, using mode 2. */
void func_8001D9F4(int index)
{
    fill_leaderboard_entry(index, stream_state + 0x10332, 2);
}
