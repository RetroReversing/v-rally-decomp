extern char stream_state[];
void memset(char *a, int b, int c);

/* Zeroes the 512-byte scratch area at stream_state+0x6E22. */
void stream_clear_scratch(void) {
    memset(stream_state + 0x6E22, 0, 0x200);
}
