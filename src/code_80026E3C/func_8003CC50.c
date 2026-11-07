#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern unsigned char D_800ADFE0;
void func_8003CC50(void *object) {
    char * arg0 = object; unsigned int t = **(unsigned int **)(*(char **)(*(char **)(arg0 + 0xA8) + 0x24) + 0x70) + 1; if (t != D_800ADFE0 && D_800ADFE0 >= t) { *(int *)(arg0 + 0x80) &= ~4; } else { *(int *)(arg0 + 0x80) |= 4; } }

