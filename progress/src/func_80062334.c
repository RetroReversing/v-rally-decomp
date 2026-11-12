extern u16 D_800C34FC;
extern u16 D_800C836E;
extern u16 gNumberBuf;
extern void *gSlotState;

/* Copies slot config halfwords (time/position/record values) from globals into the current slot record. */
void func_80062334(void) {
    u16 v1;
    u16 a0;
    u16 a1;
    char *slot;

    slot = (char *)gSlotState;
    v1 = D_800C34FC;
    a0 = D_800C836E;
    a1 = gNumberBuf;
    *(s16 *)(slot + 0x1E) = v1;
    *(s16 *)(slot + 0x20) = a0;
    *(s16 *)(slot + 0x22) = a1;
}