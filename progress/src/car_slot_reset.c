s32 setNodeFlags(void *, s32);
s32 func_80022BE8(void *, s32, s32);
s32 init_car_from_record(void *, void *);

/* Resets entry slot_index of the 0x44-byte entry table and, unless the car has flag 0x80
 * set, initialises the car from that entry and clears the sub-object fields at +0x30 and +0x5C. */
void car_slot_reset(s32 table, void *car, s32 slot_index) {
    s32 index;
    u8 *entry;

    index = slot_index & 0xFF;
    entry = (u8 *)(table + index * 0x44);
    if (!(*(s32 *)((u8 *)car + 0x14) & 0x80)) {
        *(s16 *)(entry + 0xA) = 3;
        *(s16 *)(entry + 0xC) = 0;
        *(u16 *)(entry + 8) = (u16)(*(u16 *)(entry + 8) & 0xFBFF);
        func_80022BE8(car, *(s32 *)entry, index);
        init_car_from_record(car, entry + 0x1C);
        setNodeFlags(car, 0x10);
        *(s32 *)(*(u8 **)((u8 *)car + 0x5C) + 0x6C) = 0;
        *(s32 *)(*(u8 **)((u8 *)car + 0x30) + 0x6C) = 0;
    }
}
