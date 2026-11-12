extern u8 *gRecords;

/* Copies per-object timing from the current record: a derived value into obj+0x7A, and obj+0x0E from the sub-object's table entry (+6 or +0x10 depending on the mode word). */
void func_8003EE84(void *object) {
    u8 *obj = object;
    u8 *state = *(u8 **)(*(u8 **)(obj+0xA8)+0x24);
    u8 *rec;
    s32 value;
    if (state != 0) {
        rec = gRecords;
        rec = rec + (*(u16*)(obj+0x76) + rec)[0x32]*0x28;
        rec = rec + *(u16*)(obj+0x78);
        value = rec[0x44];
        if (value < 0x41) *(s16*)(obj+0x7A) = value-0x16; else *(s16*)(obj+0x7A) = value-0x41;
        if (*(s32*)(*(u8 **)(state+0x6C)+8) == 1) {
            *(s16*)(obj+0xE) = *(u16*)(*(u8 **)(*(u8 **)(obj+0xA8)+0x178)+0xA) + 6;
        } else {
            *(s16*)(obj+0xE) = *(u16*)(*(u8 **)(*(u8 **)(obj+0xA8)+0x178)+0xA) + 0x10;
        }
    }
}
