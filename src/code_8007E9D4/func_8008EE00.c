#include "common.h"

void func_8008EE00(void **arg0, void *arg1) { void *cur = *arg0; while (cur) { if (cur == arg1) { *arg0 = *(void **)cur; return; } arg0 = cur; cur = *(void **)cur; } }
