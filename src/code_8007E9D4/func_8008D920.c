#include "common.h"

extern char D_800C02AE[];
void osSendMesg(char *a, int b, int c);
void func_8008D920(void) { osSendMesg(D_800C02AE + 0x10312, 0, 0); }
