void memset(int a, int b, int c);
/* Zeroes the 0x118-byte race entry block at entries. */ void race_entries_clear(int entries) { memset(entries, 0, 0x118); }
