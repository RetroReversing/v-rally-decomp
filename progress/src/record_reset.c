/* Resets a record to its initial state: the flags and counters at +0xC..+0x38 get their
   start values, and the four slot indices at +0x32 are set to 0..3. */
void record_reset(u8 *rec)
{
    u8 i = 0;
    s16 one = 1;
    u8 three = 3;

    *(s16 *) (rec + 0xE) = one;
    *(rec + 0x30) = three;
    *(s16 *) (rec + 0x12) = one;
    *(s16 *) (rec + 0x14) = one;
    *(s16 *) (rec + 0x16) = 0;
    *(s16 *) (rec + 0x1C) = 0;
    *(s16 *) (rec + 0x2A) = 0;
    *(s16 *) (rec + 0x2C) = 0x10;
    *(rec + 0x2F) = 0;
    *(s16 *) (rec + 0x38) = 0;
    *(s16 *) (rec + 0x1A) = one;
    do {
        *(rec + i + 0x32) = i;
        i++;
    } while (i < 4);
    *(s16 *) (rec + 0xC) = 0x1C;
}
