extern char *gRecords; void func_8005A2F4(int a); void func_8005A474(int a, int b);
int func_8005E328(void) { func_8005A2F4(1); func_8005A474(2, 1); *(short *)(gRecords + 0x22) = 0; return 0; }
