#include "common.h"

struct N { struct N *next; struct N **prev; };
void func_8008DCAC(struct N *arg0, struct N **arg1) { arg0->next = *arg1; arg0->prev = arg1; if (*arg1) (*arg1)->prev = (struct N **)arg0; *arg1 = arg0; }
