extern short wave_table[];

/* Returns one entry of the wave table; the position wraps every 1024 entries. */
short wave_table_get(int pos) {
    return wave_table[pos & 0x3FF];
}
