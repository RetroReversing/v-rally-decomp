extern char gOrderState[];
void osSendMesg(char *a, int b, int c);
void func_80094720(void) { osSendMesg(gOrderState + 0x87A8, 0, 0); }
