#include "common.h"

char *func_8008A054(int a, int b);

void func_8008A178(int arg0, int arg1, int arg2) {
    int s = arg1 & 0xFFFF;
    char *v = func_8008A054(arg0, s);
    *(int *)(*(int *)(v + 8) + (s - *(unsigned char *)(v + 0xD)) * 0xC) = arg2;
}
