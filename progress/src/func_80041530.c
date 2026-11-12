extern s32 gSlotTableB[];

/* Returns the address of record index within the block for slot in gSlotTableB; records are 0x2C4 bytes. */
s32 func_80041530(s32 slot, s32 index) {
    s32 base;

    base = gSlotTableB[slot];
    return base + index * 0x2C4;
}
