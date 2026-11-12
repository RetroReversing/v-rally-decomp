extern char stream_state[];
void fill_leaderboard_entry(int a, char *b, int c);
/* Fills leaderboard slot 9 of the stream_state board from the given track record. */ void leaderboard_fill_slot9(int record) { fill_leaderboard_entry(record, stream_state + 0x10332, 9); }
