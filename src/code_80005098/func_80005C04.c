#include "common.h"

extern int D_8009B5A4;
extern int D_8009B5A8;
extern void (*D_800C8054)(void);
void func_80005C04(void)
{
    int a = D_8009B5A4;
    int b = D_8009B5A8;
    D_8009B5A8 = a;
    D_8009B5A4 = b;
    (*D_800C8054)();
}
