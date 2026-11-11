/* Steps a stream record's entry list: the top entry's counter at +0x124 counts down (0xFF means
 * it never expires), and when it reaches zero the entry is dropped. If an entry is left, its
 * parameters are copied into the record. Returns the entry's word at +0xD4, or ret if none is left. */
s32 func_80087E9C(u8 *rec, s32 ret) {
    s32 entry;
    u8 *counters;
    u8 counter;
    u8 next;
    s32 *words;
    u16 *halves;
    u16 w;
    entry = rec[0xD3] - 1;
    counters = rec + entry;
    counter = counters[0x124];
    if (counter != 0xFF) {
        next = counter - 1;
        counters[0x124] = next;
        if (next == 0) {
            rec[0xD3] = entry;
            entry = -1;
        }
    }
    if (entry >= 0) {
        words = (s32 *)(entry * 4 + (s32)rec);
        ret = words[0xD4 / 4];
        *(s32 *)(rec + 0x34) = words[0xE8 / 4];
        *(s32 *)(rec + 0x30) = words[0xFC / 4];
        rec[0xB4] = *(rec + entry + 0x129);
        *(f32 *)(rec + 0x6C) = (f32)*(rec + entry + 0x12E);
        halves = (u16 *)(entry * 2 + (s32)rec);
        w = halves[0x110 / 2];
        *(u16 *)(rec + 0x9A) = w;
        *(u16 *)(rec + 0x9C) = halves[0x11A / 2];
        *(f32 *)(rec + 0x20) = *(volatile f32 *)(rec + 0x6C) * *(f32 *)(rec + 0x68);
    }
    return ret;
}
