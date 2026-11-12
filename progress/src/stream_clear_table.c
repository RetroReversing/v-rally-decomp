extern char stream_state[];

/* Zeroes the 0x800-entry int table at stream_state+0x3902. */
void stream_clear_table(void)
{
    int idx = 0;

    do {
        ((int *)(stream_state + 0x3902))[idx & 0xFFFF] = 0;
        idx++;
    } while ((unsigned)(idx & 0xFFFF) < 0x800);
}
