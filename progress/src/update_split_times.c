extern signed char D_800C3B04;
extern signed char D_800C3B05;
extern signed char sSplitFlagA;
extern signed char sSplitFlagB;
extern signed char D_800C3B0C;
extern s32 D_800C3B00;
extern void *gRecords;
s32 sort_split_times();
s32 strCpy();
extern char gOrderState[];

/* For each record, copy its split time and name into the shared split slot,
 * then sort the four split slots by time. */
void update_split_times(void)
{
    s32 *slot;
    s32 i;
    s32 idx;
    char *records;
    char *times;
    char *entry;

    records = gRecords;
    times = gOrderState + 0x7DB0;
    if (*((u16 *) (records + 0xE)) != 0)
    {
        slot = &D_800C3B00;
        i = 0;
        do
        {
            idx = i & 0xFF;
            *slot = *((s32 *) (times + (idx * 4) + 0x168));
            entry = records + ((*((u8 *) (records + idx + 0x32))) * 0x28);
            D_800C3B04 = *((u16 *) (entry + 0x4E));
            D_800C3B05 = *((u16 *) (records + 0x16));
            /* the third argument is unused by strCpy, but the call passes it */
            strCpy((char *) slot + 6, records + ((*((u8 *) (records + idx + 0x32))) * 0x28 + 0x44), records);
            sSplitFlagA = 0;
            sSplitFlagB = 0;
            D_800C3B0C = 1;
            sort_split_times((char *) slot - 0x30);
            i++;
            records = gRecords;
        }
        while ((u32) (i & 0xFF) < *((u16 *) (records + 0xE)));
    }
}
