extern char gStreamState[];
extern char *gSelectState;
extern char *gRecords;
void league_set_flag14(void *);

/* Clears the stream's current item timer and the select-state flag, marks the league entry as set, and returns the record's base index: +9 when that entry's type is 2, +4 otherwise. */
s32 func_80065F28(void)
{
    char *item;
    char *sel;

    item = *(char **)(gStreamState + 0x32F2);
    sel = gSelectState;
    *(s16 *)(item + 0x22) = 0;
    *(s8 *)(sel + 0x245) = 0;
    league_set_flag14(*(void **)(gStreamState + 0x325A));
    if (*(s16 *)(*(char **)(gStreamState + 0x325A) + 2) == 2) {
        return *(u16 *)(gRecords + 0x20) + 9;
    }
    return *(u16 *)(gRecords + 0x20) + 4;
}
