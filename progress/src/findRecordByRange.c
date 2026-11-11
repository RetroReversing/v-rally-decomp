/* Scans the record table (count at +0, records of 20 bytes at +16) for the first
 * record whose range end (bytes +12 + +13) is above key. Returns it, or NULL. */
s32 findRecordByRange(void *table, s32 key) {
    u16 count;
    u8 *rec;
    u32 i;
    u32 t0;
    s32 pad[1];
    count = *(u16 *)table;
    rec = *(u8 **)((u8 *)table + 16);
    i = 0;
    if (count == 0) {
        return 0;
    } else {
        u8 *p;
        key &= 65535;
        t0 = count;
        table = (void *)((u8 *)rec + 13);
        do {
            p = (u8 *)table;
            if (key < p[-1] + p[0]) {
                return (s32)rec;
            }
            table = (void *)(p + 20);
            i++;
            rec += 20;
        } while (i < t0);
    }
    (void)&pad;
    return 0;
}
