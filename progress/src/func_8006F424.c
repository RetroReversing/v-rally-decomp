extern char stream_state[];

/* Resets the stream channel block at stream_state+0x6E64: sets bit 8 of its 16-bit status
   word and keeps only bits 8, 10, 11 and 12. Clears the byte at +0x6E6D, copies the byte at
   +0x6E67 into the half-word at +0x6E66, zeroes the four half-words from +0xA, and zeroes the
   six bytes from +3. */
void func_8006F424(void)
{
    u8 i;
    char *chan;

    chan = stream_state + 0x6E64;
    *((u16 *) chan) = (u16) ((*((u16 *) chan) | 0x100) & 0x1D00);
    *((s8 *) (stream_state + 0x6E6D)) = 0;
    *((s16 *) (stream_state + 0x6E66)) = *((u8 *) (stream_state + 0x6E67));
    i = 0;
    do {
        *((s16 *) (chan + 0xA + i * 2)) = 0;
        i++;
    } while (i < 4);
    i = 0;
    do {
        (chan + i)[3] = 0;
        i++;
    } while (i < 6);
}
