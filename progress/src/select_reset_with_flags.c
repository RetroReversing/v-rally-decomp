/* Resets the select state and the item at slot 2, then clears the flag at gRecords+0x22. */ extern char *gRecords; void selectStateReset(int a); void selectSetItem(int a, int b);
int select_reset_with_flags(void) { selectStateReset(1); selectSetItem(2, 1); *(short *)(gRecords + 0x22) = 0; return 0; }
