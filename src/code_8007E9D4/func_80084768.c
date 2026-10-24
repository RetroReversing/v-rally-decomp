#include "common.h"

void func_80081E8C(char *a, int b); short func_800822D4(char *a); int func_800822E8(char *a); extern short D_800C3378; extern int D_800C337C; extern short D_800C3384; extern int D_800C3388;
int func_80084768(void) { char buf[0x30]; func_80081E8C(buf, 0x2A); D_800C3378 = func_800822D4(buf + 4); D_800C337C = func_800822E8(buf + 0x10); D_800C3384 = func_800822D4(buf + 0x18); D_800C3388 = func_800822E8(buf + 0x26); return 0; }
