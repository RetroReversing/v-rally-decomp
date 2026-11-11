extern char *gCarEntries;
extern char *gSlotTable;
extern char gStreamState[];

/* Resets the two per-slot tables (0x44-byte entries) at index 0x114; then resets slot
   `index` in the car table, and in the slot table too when the stream state is 1
   (also clearing the 0x0400 flag there and setting its state to 4). */
void func_80050AB8(s32 index)
{
    u8 car_index;
    u8 slot_index;
    char *entry;
    char *car_table;

    entry = gSlotTable;
    car_table = gCarEntries;
    entry[0x114] = 0;
    car_table[0x114] = 0;
    car_index = index;
    if (*((u16 *) (*((char **) (gStreamState + 0x32F2)) + 0x1A)) == 1) {
        slot_index = index;
        entry = entry + (slot_index * 0x44);
        *((u16 *) (entry + 0xA)) = 4;
        *((u16 *) (entry + 0xC)) = 0;
        *((u16 *) (entry + 0x8)) &= 0xFBFF;
        car_index = index;
    }
    entry = car_table + (car_index * 0x44);
    *((u16 *) (entry + 0xC)) = 0;
    *((u16 *) (entry + 0xA)) = 1;
}
