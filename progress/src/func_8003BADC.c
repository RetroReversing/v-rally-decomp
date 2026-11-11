extern char *gRecords;

/* Per-slot status update. Bit 4 of the status word at +0x80 is cleared when the play mode (gRecords+0xE)
 * allows the slot to run (mode 1, or mode 2+ with the record's flags 0x880000 set); otherwise bit 4 is set.
 * On the first allowed pass the slot adds its linked slot's time offset to +0x7A and sets its started flag at +0x78. */
void func_8003BADC(char *slot) {
    u16 mode;
    char *linked;

    mode = *(u16 *)(gRecords + 0xE);
    if ((mode >= 2 && (*(s32 *)(*(char **)(slot + 0xA8) + 0x20) & 0x880000)) || mode == 1) {
        if (*(u16 *)(slot + 0x78) == 0) {
            linked = *(char **)(*(char **)(slot + 0xA8) + 0x24);
            if (linked != NULL) {
                *(u16 *)(slot + 0x7A) += *(s32 *)(*(char **)(linked + 0x78) + 0x60);
            }
            *(u16 *)(slot + 0x78) = 1;
        }
        *(s32 *)(slot + 0x80) &= ~4;
    } else {
        *(s32 *)(slot + 0x80) |= 4;
    }
}
