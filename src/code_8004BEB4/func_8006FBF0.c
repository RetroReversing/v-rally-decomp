#include "common.h"

/* identical to func_80005120 (matched), with its names changed by decompdecomp */
struct M { int m[16]; };
void func_8001C2C0(char *a, char *b, char *c);
void func_8006FBF0(char *arg0) {
    if (*(char **)(arg0 + 4) != 0) {
        func_8006FBF0(*(char **)(arg0 + 4));
        func_8001C2C0(*(char **)(arg0 + 4) + 0x48, arg0 + 8, arg0 + 0x48);
    } else if (*(int *)arg0 != 0) {
        *(int *)arg0 = 0;
        *(struct M *)(arg0 + 0x48) = *(struct M *)(arg0 + 8);
    }
}
