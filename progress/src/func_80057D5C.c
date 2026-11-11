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
typedef struct { char pad[4]; u16 id; s16 pad6; s16 w; s8 sel; char padB[5]; f32 v; } Item;
typedef struct { char pad[8]; u16 id; s16 padA; s16 w; s8 sel; char padF[5]; f32 v; } Seg;
typedef struct { char pad[0x18]; void *head; void *tail; s32 count; char pad24[0xAC]; u8 pair[0x14][2]; } Mgr;

void *poolAlloc(s32, s32);void *textObjGet(u32);void *select_get_entry(u32);
s32 pool_get_item(s32, u16);
s32 func_8000C9B0(void *, void *, u8, f32, u8);
extern Mgr *gSelectState;
extern u8 gStreamState[];
extern s32 gSelectStepHandle;
#define CTX (*(Ctx **)(gStreamState + 0x325A))
#define TABP(m, s) ((u8 *)(m) + ((m)->pair[s][0] * 4 + 0xE4))

/* Appends a line entry to the list at gSelectState. The entry covers the
 * x-range arg0..arg1 (converted to the table's base) and holds the text id
 * arg3 with arg2 glyph slots. Its flag is set from the widest and narrowest
 * of the glyph and segment values. */
void func_80057D5C(s32 arg0, s32 arg1, u8 arg2, s8 arg3)
{
    Node *node;
    Item *item;
    Seg *seg;
    Mgr *m;
    s16 hi, lo, v;
    s8 i;
    s32 id;

    node = poolAlloc(1, 12);
    lo = 240;
    node->a = arg0 - CTX->tab[CTX->idx].base;
    hi = 0;
    node->b = arg1 - CTX->tab[CTX->idx].base;
    node->n = arg2;
    node->k = arg3;
    item = textObjGet((s8)(arg3));
    for (i = 0; i < node->n; i++) {
        id = pool_get_item(gSelectStepHandle, item->id);
        m = gSelectState;
        v = func_8000C9B0((void *)(TABP(m, item->sel)), (void *)(id), (u8)(m->pair[item->sel][1]), (f32)(item->v), (u8)(0));
        if (v > hi) hi = v;
        if (item->w < lo) lo = item->w;
    }
    seg = select_get_entry((u16)(node->a));
    id = pool_get_item(gSelectStepHandle, seg->id);
    m = gSelectState;
    v = func_8000C9B0((void *)(TABP(m, seg->sel)), (void *)(id), (u8)(m->pair[seg->sel][1]), (f32)(seg->v), (u8)(0));
    if (v > hi) hi = v;
    if (seg->w < lo) lo = item->w;
    seg = select_get_entry((u16)(node->b));
    id = pool_get_item(gSelectStepHandle, seg->id);
    m = gSelectState;
    v = func_8000C9B0((void *)(TABP(m, seg->sel)), (void *)(id), (u8)(m->pair[seg->sel][1]), (f32)(seg->v), (u8)(0));
    if (v > hi) hi = v;
    if (seg->w < lo) lo = item->w;
    if (hi > lo) {
        node->flag = 0;
    } else {
        node->flag = 0;
    }
    if (gSelectState->tail != NULL) {
        ((Node *)gSelectState->tail)->next = node;
    } else {
        gSelectState->head = node;
    }
    gSelectState->tail = node;
    gSelectState->count++;
}
