extern u8 *gRecords;
s32 select_stream_char(u8, u8, u8);
void carSetSoundVolume(u8 *, s32);

/* Copies a car's setup values from its record into the car's sub-objects (the
 * offsets are the car's stored pointers). Does nothing when the car's mode is 5.
 * The record slot is chosen by the lookup of gRecords[0x1F/0x21/0x23]. */
void init_car_from_record(u8 *car, u8 *record) {
    s32 idx;
    u32 i;
    u8 *p;
    u8 *temp;
    s32 pad[8];

    idx = select_stream_char(gRecords[0x1F], gRecords[0x21], gRecords[0x23]);
    if (*(s32 *)(*(u8 **)(car + 0x48)) != 5) {
        for (i = 0; i < 4; i++) {
            *(s32 *)(*(u8 **)(car + 0x80) + i * 4 + 0x2E0) = record[8];
        }
        *(s32 *)(*(u8 **)(car + 0x24) + 4) = record[9] & 1;
        *(s32 *)(*(u8 **)(car + 0x50) + 4) = record[9] & 1;
        *(s32 *)(*(u8 **)(car + 0x30) + 0x60) = *(u16 *)(record + 0xC);
        *(s32 *)(*(u8 **)(car + 0x5C) + 0x60) = *(u16 *)(record + 0xC);
        *(s32 *)(*(u8 **)(car + 0x28) + 0x30) = *(s16 *)(record + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(car + 0x28) + 0x34) = *(s16 *)(record + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(car + 0x28) + 0x38) = -*(s16 *)(record + (idx & 0xFF) * 2 + 0x1C);
        *(s32 *)(*(u8 **)(car + 0x28) + 0x3C) = -*(s16 *)(record + (idx & 0xFF) * 2 + 0x1C);
        for (i = 0xC; i < 0x10; i++) {
            *(s32 *)(*(u8 **)(car + 0x54) + i * 4) = *(s32 *)(*(u8 **)(car + 0x28) + i * 4);
        }
        temp = *(u8 **)(car + 0x80);
        p = record + (idx & 0xFF);
        *(s32 *)(temp + 0x38C) = p[0x14];
        carSetSoundVolume(car, (*(s32 *)(*(u8 **)(car + 0x84) + 0x40) * 0xA) / 22);
        *(s32 *)(*(u8 **)(car + 0x24) + 0xC) = p[0x18];
        *(s32 *)(*(u8 **)(car + 0x50) + 0xC) = p[0x18];
        *(s32 *)(*(u8 **)(car + 0x1C) + 0x30) = p[0x10];
        *(s32 *)(*(u8 **)(car + 0x48) + 0x30) = p[0x10];
    }
}
