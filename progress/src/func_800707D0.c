extern char *gRecords;
void slotSetSelected(int a, int b);

/* Toggles the mode word at gRecords+0x20 between 0 and 8, then reports the new state (1 when on)
   to slot. Returns 0. */
int func_800707D0(int slot)
{
    char *records;
    int selected;

    records = gRecords;
    if (*(unsigned short *)(records + 0x20) >= 8) {
        *(unsigned short *)(records + 0x20) = 0;
        selected = 0;
    } else {
        *(unsigned short *)(records + 0x20) = 8;
        selected = 1;
    }
    slotSetSelected(slot, selected);
    return 0;
}
