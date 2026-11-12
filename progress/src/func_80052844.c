extern u8 gOrderState[];

/* Zeroes a table of 4 words by 5 rows at gOrderState+0x7EC8, rows 0x10 bytes apart. */
void func_80052844(void)
{
    u8 i;
    u8 j;
#ifdef PORT
    u8 *base;
    u8 *row;
#else
    u32 off;
    u32 row;
    u32 base;
#endif

#ifdef PORT
    base = gOrderState + 0x7DB0;
#else
    base = (u32)(gOrderState + 0x7DB0);
#endif
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
#ifdef PORT
            row = base + (j << 4);
#else
            off = j << 4;
            row = off + base;
#endif
            row = row + 0x118;
            *(s32 *)(row + i * 4) = 0;
        }
    }
}
