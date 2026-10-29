#include "snapshot29_0433f7af8f6d.h"

typedef struct Node { char pad0[4]; struct Node *child; char pad8[0x28]; struct Node *at30; char pad34[0x14]; s32 *at48; char pad4c[0x10]; struct Node *at5c; char pad60[0xc]; s32 value; } Node;
typedef struct Entry { char pad[8]; u16 flags,state,other; char rest[54]; } Entry;
extern Entry *D_800A1238; extern char *D_800C35A0;
void func_8002291C(Node*,int);
void func_800515D0(Node *self) {
    Node *orig;
    s32 flag;
    u32 idx;
    if (*(u16 *)(D_800C35A0 + 0x1e) == 0) {
        flag = *(u16 *)(D_800C35A0 + 0x1a);
        if (flag == 1) {
            idx = *((u8 *)self->at48 + 3);
            if (idx < 5) {
                char *c;
                Entry *e;
                c = (char *)D_800A1238;
                c += idx * 68;
                e = (Entry *)c;
                if (e->flags & 0x200) {
                    Entry *b;
                    orig = self;
                    self = self->child;
                    func_8002291C(self, 16);
                    self->at5c->value = flag;
                    self->at30->value = flag;
                    b = D_800A1238;
                    e = b + *orig->at48;
                    e->other = 0;
                    b += *orig->at48;
                    b->state = 4;
                }
            }
        }
    }
}
