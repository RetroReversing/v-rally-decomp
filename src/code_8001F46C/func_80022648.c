#include "common.h"

struct L { struct L *x; struct L *next; };
int func_80022648(struct L **arg0) { struct L *p = *arg0; int n = 0; while (p) { p = p->next; n++; } return n; }
