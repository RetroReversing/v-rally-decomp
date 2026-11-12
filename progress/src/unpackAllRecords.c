void unpackRecord(u8 idx);
void unpackStatusWord(void);

/* Unpacks the four record slots, then the status word. */
void unpackAllRecords(void)
{
    s32 i;

    i = 0;
    do {
        unpackRecord(i & 0xFF);
        i += 1;
    } while ((u32)(i & 0xFF) < 4U);
    unpackStatusWord();
}
