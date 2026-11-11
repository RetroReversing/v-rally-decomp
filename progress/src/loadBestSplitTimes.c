extern signed char D_800C3AC4;
extern signed char D_800C3AC5;
extern signed char D_800C3ACA;
extern signed char D_800C3ACB;
extern signed char D_800C3ACC;
extern s32 D_800C3AC0;
extern void *gRecords;
s32 sort_split_times();
s32 copyStringAligned();
extern char gOrderState[];

/* Fills the split-time table at D_800C3AC0 from the records in gRecords: for each
   record, copies its split time and name, then sorts the four entries. */
void loadBestSplitTimes(void)
{
    s32 *slot;
    s32 i;
    s32 idx;
    char *records;
    char *splitTimes;
    char *entry;

    records = gRecords;
    splitTimes = gOrderState + 0x7DB0;
    if (*((u16 *) (records + 0xE)) != 0)
    {
        slot = &D_800C3AC0;
        i = 0;
        do
        {
            idx = i & 0xFF;
            *slot = *((s32 *) (splitTimes + (idx * 4) + 0x168));
            entry = records + ((*((u8 *) (records + idx + 0x32))) * 0x28);
            D_800C3AC4 = *((u16 *) (entry + 0x4E));
            D_800C3AC5 = *((u16 *) (records + 0x16));
            copyStringAligned((char *) slot + 6, records + ((*((u8 *) (records + idx + 0x32))) * 0x28 + 0x44), records);
            D_800C3ACA = 0;
            D_800C3ACB = 0;
            D_800C3ACC = 1;
            sort_split_times((char *) slot - 0x30);
            i++;
            records = gRecords;
        }
        while ((u32)(i & 0xFF) < *((u16 *) (records + 0xE)));
    }
}
