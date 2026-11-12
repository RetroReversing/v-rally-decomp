extern char *gRecords;
void slotSetSelected(int slot, int index);

/* If the count at gRecords+0x16 is nonzero, decrements it and selects the new last index for slot. */
int func_8005F258(int slot) {
    char *records = gRecords;
    unsigned short count = *(unsigned short *)(records + 0x16);
    if (count) {
        count--;
        *(unsigned short *)(records + 0x16) = count;
        slotSetSelected(slot, count);
    }
    return 0;
}
