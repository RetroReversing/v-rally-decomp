#include "common.h"

extern int *D_800C6F0C;
extern int D_800C35A0;
void func_800803C0(int a, int *b);

void func_8001B654(void) {
    func_800803C0(D_800C6F0C[1], D_800C6F0C);
    D_800C35A0 = D_800C6F0C[1];
}
