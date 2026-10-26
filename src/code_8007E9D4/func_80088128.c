#include "common.h"

int func_8008949C(int a);

unsigned char *FrandNote(char *arg0, unsigned char *arg1) {
    int v = func_8008949C(*arg1++);
    arg0[0xB5] = v;
    v += *arg1;
    arg0[0xB5] = v;
    return arg1 + 1;
}
