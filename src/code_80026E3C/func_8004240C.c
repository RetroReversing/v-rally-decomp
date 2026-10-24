#include "common.h"

struct N { int p0; struct N *next; int p8; int key; };
extern char D_800AE850[];
struct N *func_8004240C(int arg0) { struct N *p = **(struct N ***)(D_800AE850 + 0x72FC); for (; p; p = p->next) { if (p->key == arg0) return p; } return 0; }
