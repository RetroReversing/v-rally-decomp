extern char *gRecords;
void selectStateReset(int a);
void selectSetItem(int a, int b);

/* Resets the select state, runs selectSetItem(3, 1), and clears the 16-bit value at gRecords+0x22. */
int func_8005E2F0(void) {
    selectStateReset(1);
    selectSetItem(3, 1);
    *(short *)(gRecords + 0x22) = 0;
    return 0;
}
