s32 func_8002F9C8(s32, u16);
s32 clear_records_s32(s32, u16);

/* Resets the object's two record tables: clears the 16-bit field of each entry in the first table (count at +0x16) and the 32-bit field of each entry in the second (count at +0x14), then zeroes the small fields at +0x18, +0x1A and +6..+9. */
void obj_reset_records(void *obj) {
    s32 records_a;
    s32 records_b;
    u32 i;
    u8 *p;
    u8 *q;

    records_a = *(s32 *)((u8 *)obj + 0x10);
    records_b = *(s32 *)obj;
    i = 0;
    p = obj;
    do {
        *(s16 *)(p + 0x18) = 0;
        i++;
        p += 2;
    } while (i < 2);

    i = 0;
    q = obj;
    do {
        q = (u8 *)obj + i;
        q[6] = 0;
        i++;
    } while (i < 4);

    func_8002F9C8(records_a, ((u16 *)obj)[11]);
    clear_records_s32(records_b, *(u16 *)((u8 *)obj + 0x14));
}
