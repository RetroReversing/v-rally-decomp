#include "common.h"

extern char D_800AFA5C; extern char *D_800A1468; extern char D_800A13C0[]; extern char D_800A5268[]; void func_80098290(char *a, char *b); void func_800594F4(char *a);
void func_8005A474(char arg0, int arg1) { char *p; D_800AFA5C = arg0; func_80098290(D_800A1468 + 0x2AD, D_800A13C0 + (arg0 & 0xFF) * 0x24); if (arg1 & 0xFF) { p = D_800A5268; D_800A1468[0x29E] = 1; } else { p = *(char **)(D_800A1468 + 0x1F4); } D_800A1468[0x29D] = 1; func_800594F4(p); }
