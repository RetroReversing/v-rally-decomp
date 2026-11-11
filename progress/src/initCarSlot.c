s32 func_80022BE8(void *, s32);
void init_car_from_record(u8 *car, u8 *record);

/* Initialises one 0x44-byte slot of the table for this car, unless the car's
 * flag 0x80 is set: clears the slot's counter, loads its data block into the
 * car with func_80022BE8 and runs init_car_from_record on the record at +0x1C. */
void initCarSlot(u8 *table, u8 *car, s32 slot) {
    u8 *entry;

    if (!(*(s32 *)(car + 0x14) & 0x80)) {
        entry = table + ((slot & 0xFF) * 0x44);
        *(s16 *)(entry + 0xC) = 0;
        func_80022BE8(car, *(s32 *)entry);
        init_car_from_record(car, entry + 0x1C);
    }
}
