struct N { int p0; struct N *next; int p8; int pc; int p10; int p14; int p18; int p1c; int p20; int key; };
extern char gOrderState[];
struct N *func_80046398(int arg0) { struct N *p = **(struct N ***)(gOrderState + 0x72FC); for (; p; p = p->next) { if (p->key == arg0) return p; } return 0; }
