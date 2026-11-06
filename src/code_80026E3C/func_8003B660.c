#include "decompdecomp_contract_func_8003b660.h"
#line 1 "func.c"
typedef struct { char pad[0x14]; s32 flags; char pad18[0x54]; char *def; } Node; /* def at 0x6C */
typedef struct { char pad[0x24]; Node *node; } Link;
typedef struct {
    char pad0[0x78];
    u16 idx;      /* 0x78 */
    s16 digit;    /* 0x7A */
    char pad7C[4];
    s32 flags;    /* 0x80 */
    char pad84[0x10];
    u8 blink;     /* 0x94 */
    char pad95;
    s16 last;     /* 0x96 */
    char pad98[0x10];
    Link *link;   /* 0xA8 */
} Obj;

void func_8003A6D4(Obj *, u8 *);
void func_8003AB38(u32, u8 *, s32);
extern s32 D_8009D534;
extern u8 D_8009D544;
extern u8 D_8009FE00[];
extern u32 D_800AFA6C;

void func_8003B660(void *object) {
    Obj * o = object;
    u8 col[4];
    Node *n;
    s32 c;

    n = o->link->node;
    if (n != NULL) {
        c = **(s32 **)(n->def + 0x24);
        o->flags &= ~4;
        if (c == D_8009D534) {
            o->flags |= 4;
        } else {
            if (!(n->flags & 0x10) && o->last != c) {
                o->blink = 100;
            }
            o->last = c;
            if (o->idx == 0) {
                if (D_8009D544 == 0) {
                    func_8003AB38((u32)(c * 2) / 3, D_8009FE00, c);
                } else {
                    func_8003AB38(c, D_8009FE00, c);
                }
            }
            if (o->blink != 0 && !((D_800AFA6C >> 3) & 1)) {
                if (o->flags & 4) {
                    o->flags &= ~4;
                } else {
                    o->flags |= 4;
                }
            }
        }
    }
    col[0] = 200;
    col[1] = 200;
    col[2] = 10;
    col[3] = 255;
    func_8003A6D4(o, col);
    o->digit = D_8009FE00[o->idx] - 48;
}

