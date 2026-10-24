#include "common.h"

struct S { char p0[16]; int a, b, c; char p1[78]; short h; };
extern int D_8009BA30;
void func_80011058(struct S *a, int b, int c);
void func_80012114(struct S *arg0, int arg1) {
    func_80011058(arg0, arg1, 4);
    D_8009BA30 = 1;
    arg0->a = 0x80; arg0->b = 0x14; arg0->c = 5; arg0->h = 0x1000;
}
