#include "common.h"

extern char D_800C02AE[];
void func_800553B0(void) { int i = 0; do { ((int *)(D_800C02AE + 0x3902))[i & 0xFFFF] = 0; i++; } while ((unsigned)(i & 0xFFFF) < 0x800); }
