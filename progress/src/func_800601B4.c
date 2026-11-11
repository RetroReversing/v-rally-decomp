extern char *gRecords;
void slot_set_selected(int a, int b);

/* Toggles bit 0x2 in the flags (+0x2C) of gRecords, then reports the new state
 * (1 when the bit was set) to the given slot. */
int func_800601B4(int slot)
{
    char *rec = gRecords;
    unsigned short flags = *(unsigned short *)(rec + 0x2C);
    int selected;

    if (flags & 2) {
        *(unsigned short *)(rec + 0x2C) = flags & 0xFFFD;
        selected = 0;
    } else {
        *(unsigned short *)(rec + 0x2C) = flags | 2;
        selected = 1;
    }
    slot_set_selected(slot, selected);
    return 0;
}
