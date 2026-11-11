s32 clearRaceData();
extern char gOrderState[];
extern char *gRecords;

/* Copies the four 0x28-byte entries of saved slot data (at gOrderState+0x7F28)
 * into the matching entries of gRecords, then clears the race data. */
void records_restore_from_order(void) {
    u8 i;
    s32 off;
    char *p;

    i = 0;
    do {
        p = gRecords;
        off = i * 0x28;
        *(u8 *)(p + off + 0x44) = *(u8 *)(gOrderState + 0x7F28 + off);
        *(u8 *)(gRecords + off + 0x45) = *(u8 *)(gOrderState + 0x7F29 + off);
        *(u8 *)(gRecords + off + 0x46) = *(u8 *)(gOrderState + 0x7F2A + off);
        *(u16 *)(gRecords + off + 0x4E) = *(u16 *)(gOrderState + 0x7F32 + off);
        i++;
    } while (i < 4);
    clearRaceData();
}
