extern char *gRecords;

void selectStateReset(s32 keep);
void selectSetItem(char item, int use_fixed_text);

/* Resets the select state to its defaults, selects item 1 with the fixed text, and clears the 16-bit field at gRecords+0x22. */
s32 selectInitDefault(void) {
    selectStateReset(1);
    selectSetItem(1, 1);
    *(short *)(gRecords + 0x22) = 0;
    return 0;
}
