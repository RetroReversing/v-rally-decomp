#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern signed char D_800C836C;
typedef struct { s32 w[10]; } Blk;
typedef struct {
    u8 pad0[0xE]; u16 nAlloc; u8 pad10[0xA]; u16 u1A; u8 pad1C[2]; u16 u1E;
    u8 pad20[0xC]; u16 flags2C; u8 pad2E[4]; u8 idx[0x12]; Blk blk[1];
} Cfg;
typedef struct {
    s32 buf0; s32 buf1; u16 flags; s16 unkA; s16 unkC; s16 unkE;
    s32 size0; s32 size1; s32 unk18; Blk blk;
} Entry;
typedef struct { Entry e[4]; u16 count; s16 unk112; } Mgr;
typedef struct Node { s32 pad0; struct Node *next; u8 pad8[0x80]; s32 *p88; } Node;
extern Cfg *D_800C35A0;
extern s32 D_8009D540;
extern char D_800AE850[];
s32 func_80022184(void *);
s32 func_80022A90(Node *);
void func_80022A98(Node *, s32);
s32 func_8007EAA0(s32, s32);
void memset(s32, s32, s32);

s32 func_8004FD5C(Mgr *arg0, s32 arg1)
{
    s32 n;
    u32 cnt;
    u32 i;
    Node *node;
    Entry *e;

    D_800C836C = 0;
    n = 0;
    if (D_800C35A0->flags2C & 1) {
        arg1 = D_8009D540 * 0xA0;
    }
    if (func_80022184(D_800AE850 + 0x7320) == 0) {
        return 0;
    }
    arg0->unk112 = arg1;
    for (node = **(Node ***)(D_800AE850 + 0x73F0); node != NULL; node = node->next) {
        n = func_80022A90(node);
    }
    cnt = D_800C35A0->u1E ? 4 : arg0->count;
    for (i = 0; i < 4; i++) {
        e = &arg0->e[i];
        e->buf0 = 0;
        e->buf1 = 0;
        e->unk18 = 0;
        e->flags &= 0xF9FF;
        if (D_800C35A0->u1E != 0 || (D_800C35A0->u1A == 0 && i <= arg0->count)) {
            e->flags |= 8;
        }
    }
    for (i = 0; i < cnt; i++) {
        e = &arg0->e[i];
        if (!(e->flags & 1)) {
            e->unkA = 3;
            e->size0 = n * 4;
            e->size1 = (arg1 + 1) * 4;
            e->buf0 = func_8007EAA0(1, (e->size0 + 3) & ~3);
            if (i < D_800C35A0->nAlloc) {
                e->buf1 = func_8007EAA0(1, (e->size1 + 3) & ~3);
            } else {
                e->buf1 = 0;
            }
            memset(e->buf0, 0, e->size0);
            if (i < D_800C35A0->nAlloc) {
                memset(e->buf1, 0, e->size1);
            }
            e->unkC = 0;
            e->unkE = 0;
        }
        e->flags |= 1;
    }
    node = **(Node ***)(D_800AE850 + 0x73F0);
    for (i = 0; i < cnt; i++) {
        e = &arg0->e[i];
        func_80022A98(node, e->buf0);
        e->blk = D_800C35A0->blk[D_800C35A0->idx[i]];
        e->unk18 = *node->p88;
        node = node->next;
    }
    return 1;
}

