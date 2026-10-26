#include "common.h"

extern char D_800AE850[];
void osSendMesg(char *a, int b, int c);
void func_80094720(void) { osSendMesg(D_800AE850 + 0x87A8, 0, 0); }
