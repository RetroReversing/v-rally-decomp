#include "common.h"

unsigned char *func_80087FCC(char *arg0, unsigned char *arg1) { char *b = *(char **)(arg0 + 0x70); *(int *)(arg0 + 0x7C) = (int)b + (*(int **)(b + 0x14))[*arg1]; return arg1 + 1; }
