#include "common.h"

int func_8008949C(int a);

void *func_800880D8(char *arg0, unsigned char *arg1) {
    int v = func_8008949C(*arg1++);
    arg0[0xB4] = v;
    v += *arg1;
    arg0[0xB4] = v;
    return arg1 + 1;
}
