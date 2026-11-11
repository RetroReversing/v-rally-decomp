void free_owner_slots(void *owner);

extern void *gCarEntries;
extern void *gSlotTable;
extern s32 D_800B0C58;
extern void *gRecords;
extern s32 D_800C5BD8;

/* Frees the slot blocks of the current car owners and slot table, unless
 * gRecords has its mode flag set (u16 at +0x1E), then points both tables at
 * their static buffers. */
void reset_owner_slots(void)
{
    free_owner_slots(gCarEntries);
    if (*(u16 *)((char *)gRecords + 0x1E) == 0) {
        free_owner_slots(gSlotTable);
    }
    gCarEntries = &D_800B0C58;
    gSlotTable = &D_800C5BD8;
}
