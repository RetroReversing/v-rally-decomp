#include "common.h"

void func_8004F4BC(char *arg0) { char *p = *(char **)(arg0 + 0x48); unsigned char t = p[3]; int v; if (t < 5) { v = 3; } else if (t == 7) { *(int *)(p + 0x20) = 8; *(int *)(*(char **)(arg0 + 0x5C) + 0x6C) = 0; *(int *)(*(char **)(arg0 + 0x30) + 0x6C) = 0; return; } else { v = 4; } *(int *)(p + 0x20) = v; }
