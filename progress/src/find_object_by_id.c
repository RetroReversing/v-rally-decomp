struct N { int p0; struct N *next; int p8; int key; };
extern char gOrderState[];
struct N *find_object_by_id(int arg0) { struct N *p = **(struct N ***)(gOrderState + 0x72FC); for (; p; p = p->next) { if (p->key == arg0) return p; } return 0; }
