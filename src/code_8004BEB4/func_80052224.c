#include "common.h"

extern char *D_800B0BCC; extern char D_800A500C[]; int func_80098400(char *a, char *b, int c); void func_800520D4(int a, int b);
void func_80052224(int arg0) { char pad[8]; int k = 0; int i = 0; int off; if (arg0 > 0) { off = 0; do { if (func_80098400(D_800B0BCC + off, D_800A500C, 3) == 0) { int t = k & 0xFFFF; k++; func_800520D4(i & 0xFFFF, t); } i++; off += 0x14; } while (i < arg0); } }
