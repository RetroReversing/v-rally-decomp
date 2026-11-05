typedef struct Node {
    void *next;
    u16 a;
    u16 b;
    u8 n;
    s8 k;
    u8 flag;
} Node;
typedef struct { char pad[0xD]; u8 base; char pad2[6]; } Ent;
typedef struct { s16 pad0; s16 idx; char pad4[0xC]; Ent *tab; } Ctx;
typedef struct { char pad[4]; u16 id; s16 pad6; s16 w; s8 sel; char padB[5]; s32 v; } Item;
typedef struct { char pad[8]; u16 id; s16 padA; s16 w; s8 sel; char padF[5]; s32 v; } Seg;
typedef struct { char pad[0x18]; void *head; void *tail; s32 count; char pad24[0xAC]; u8 pair[0x14][2]; } Mgr;

void *func_8007EAA0(s32, s32);void *func_800592D0(u32);void *func_800592AC(u32);
s32 func_80057918(s32, u16);
s32 func_8000C9B0(void *, s32, u8, s32, s32);
extern Mgr *D_800A1468;
extern u8 D_800C02AE[];
extern s32 D_800C8328;
#define CTX (*(Ctx **)(D_800C02AE + 0x325A))
#define TABP(m, s) ((u8 *)(m) + ((m)->pair[s][0] * 4 + 0xE4))

void func_80057D5C(s32 arg0, s32 arg1, u8 arg2, s8 arg3)
{
    Node *node;
    Item *item;
    Seg *seg;
    Mgr *m;
    s16 hi, lo, v;
    s8 i;
    s32 id;

    node = func_8007EAA0(1, 12);
    lo = 240;
    node->a = arg0 - CTX->tab[CTX->idx].base;
    hi = 0;
    node->b = arg1 - CTX->tab[CTX->idx].base;
    node->n = arg2;
    node->k = arg3;
    item = func_800592D0((s8)(arg3));
    for (i = 0; i < node->n; i++) {
        id = func_80057918(D_800C8328, item->id);
        m = D_800A1468;
        v = func_8000C9B0(TABP(m, item->sel), id, m->pair[item->sel][1], item->v, 0);
        if (v > hi) hi = v;
        if (item->w < lo) lo = item->w;
    }
    seg = func_800592AC((u16)(node->a));
    id = func_80057918(D_800C8328, seg->id);
    m = D_800A1468;
    v = func_8000C9B0(TABP(m, seg->sel), id, m->pair[seg->sel][1], seg->v, 0);
    if (v > hi) hi = v;
    if (seg->w < lo) lo = item->w;
    seg = func_800592AC((u16)(node->b));
    id = func_80057918(D_800C8328, seg->id);
    m = D_800A1468;
    v = func_8000C9B0(TABP(m, seg->sel), id, m->pair[seg->sel][1], seg->v, 0);
    if (v > hi) hi = v;
    if (seg->w < lo) lo = item->w;
    if (hi > lo) {
        node->flag = 0;
    } else {
        node->flag = 0;
    }
    if (D_800A1468->tail != NULL) {
        ((Node *)D_800A1468->tail)->next = node;
    } else {
        D_800A1468->head = node;
    }
    D_800A1468->tail = node;
    D_800A1468->count++;
}
