extern char *gRecords; void slotSetSelected(int a, int b);
/* Steps the selected index of the given slot back by one (if above 0) and marks the new selection in that slot's object. */ int slot_select_prev(int slot) { char *rec = gRecords; unsigned short sel = *(unsigned short *)(rec + 0xE); if (sel >= 2) { sel--; *(unsigned short *)(rec + 0xE) = sel; slotSetSelected(slot, sel - 1); } return 0; }
