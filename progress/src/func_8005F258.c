extern char *gRecords; void slot_set_selected(int a, int b);
int func_8005F258(int arg0) { char *p = gRecords; unsigned short n = *(unsigned short *)(p + 0x16); if (n) { n--; *(unsigned short *)(p + 0x16) = n; slot_set_selected(arg0, n); } return 0; }
