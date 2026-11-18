extern u16 D_800C34FC;
extern u16 D_800C836E;
extern u16 gNumberBuf;
extern void *gSlotState;

/* Copies slot config halfwords (time/position/record values) from globals into the current slot record. */
/* Writes the three 16-bit globals D_800C34FC, D_800C836E and gNumberBuf into the current slot record at +0x1E, +0x20 and +0x22 (the inverse of func_80062304). */ void func_80062334(void) {
    u16 value_a;
    u16 value_b;
    u16 value_c;
    char *slot_rec;

    slot_rec = (char *)gSlotState;
    value_a = D_800C34FC;
    value_b = D_800C836E;
    value_c = gNumberBuf;
    *(s16 *)(slot_rec + 0x1E) = value_a;
    *(s16 *)(slot_rec + 0x20) = value_b;
    *(s16 *)(slot_rec + 0x22) = value_c;
}
