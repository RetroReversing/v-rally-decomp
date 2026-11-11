extern char *gRecords; void slot_set_selected(int a, int b);
int func_8005E870(int arg0) { char *p = gRecords; unsigned short n = *(unsigned short *)(p + 0xE); if (n >= 2) { n--; *(unsigned short *)(p + 0xE) = n; slot_set_selected(arg0, n - 1); } return 0; }
