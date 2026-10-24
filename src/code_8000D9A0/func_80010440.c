#include "common.h"

struct O { char pad[12]; void (*fn)(void *); };
struct A { char pad[8]; int x; };
struct O *func_80022668(struct A *a, int b);
void func_80010440(struct A *arg0) { struct O *o = func_80022668(arg0, arg0->x); o->fn(o); }
