#include "checkpoint_common.h"

extern unsigned char D_800B0004, D_800B0005, D_800B0006; extern char D_800AE850[];
void func_8001F488(char *arg0) { *(unsigned char *)(D_800AE850 + 0x18B4) = *(int *)(arg0 + 0x90); { int v = *(int *)(arg0 + 0xDC); *(unsigned char *)(D_800AE850 + 0x18B6) = 0xFF; *(unsigned char *)(D_800AE850 + 0x18B5) = v; } }
