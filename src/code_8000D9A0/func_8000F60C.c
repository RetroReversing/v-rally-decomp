#include "common.h"

extern unsigned char D_8009B96C; extern void (*D_8009B968)(void); extern long long D_800C6080; long long osGetTime(void);
void func_8000F60C(void) { if (D_8009B96C == 0) { D_800C6080 = osGetTime(); D_8009B96C = 1; } D_8009B968(); }
