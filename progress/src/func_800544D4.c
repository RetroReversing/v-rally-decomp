extern char *gRecords;
extern u8 gOrderState[]; extern char gStreamState[];
extern s32 strCmp(const u8*,const u8*);

/* For each active stream slot, find the record in gRecords whose name matches the slot's name
 * (records are 40 bytes, name at +0x44), then add 7 to that record's counter in gOrderState
 * and to the shared counter at 0x2545. */
void func_800544D4(void) {
    s32 slotOff, counterOff;
    u32 slot, recIdx, rec, nameOff;

    slot = 0;
    do {
        slotOff = (slot & 255) << 6;
        if (*(u8 *)(gStreamState + 0x33AE + slotOff) == 1) {
            recIdx = 0;
            nameOff = slotOff;
            for (;;) {
                rec = recIdx & 255;
                if (strCmp((u8 *)(((rec * 5) << 3) + 0x44 + gRecords), (u8 *)(nameOff + gStreamState + 0x33A8)) == 0) {
                    break;
                }
                if (rec >= 4U) {
                    break;
                }
                recIdx++;
            }
            counterOff = (recIdx & 255) * 5;
            gOrderState[0x2531 + counterOff] += 7;
            gOrderState[0x2545] += 7;
        }
        slot++;
    } while ((slot & 255) < 4U);
}
