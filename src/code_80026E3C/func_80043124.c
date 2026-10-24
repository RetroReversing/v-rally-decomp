#include "common.h"

extern char *D_800C35A0; extern int D_800B6880;
void func_80043124(char *arg0) { *(short *)(D_800C35A0 + 0x36) = 0; { int v = *(int *)(arg0 + 0x14); D_800B6880 = 1; *(int *)(arg0 + 0x14) = v & ~0x200; } }
