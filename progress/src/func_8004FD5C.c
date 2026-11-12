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
extern Cfg *gRecords;
extern s32 gRecordTimeScale;
extern char gOrderState[];
s32 flag_test_bit0(void *);
s32 obj_get_word_0x18(Node *);
void func_80022A98(Node *, s32);
s32 poolAlloc(s32, s32);
void memset(s32, s32, s32);

/* Sets up the four track-buffer slots of the manager: sizes each slot from the
 * node list and the limit (capped to the record time scale when the flag is
 * set), allocates the buffers of any slot not yet in use, then copies each
 * slot's block from the node chain. Returns 1, or 0 when the setup check fails. */
s32 func_8004FD5C(Mgr *mgr, s32 limit)
{
    s32 nodeSize;
    u32 slotCount;
    u32 i;
    Node *node;
    Entry *e;

    D_800C836C = 0;
    nodeSize = 0;
    if (gRecords->flags2C & 1) {
        limit = gRecordTimeScale * 0xA0;
    }
    if (flag_test_bit0(gOrderState + 0x7320) == 0) {
        return 0;
    }
    mgr->unk112 = limit;
    for (node = **(Node ***)(gOrderState + 0x73F0); node != NULL; node = node->next) {
        nodeSize = obj_get_word_0x18(node);
    }
    slotCount = gRecords->u1E ? 4 : mgr->count;
    for (i = 0; i < 4; i++) {
        e = &mgr->e[i];
        e->buf0 = 0;
        e->buf1 = 0;
        e->unk18 = 0;
        e->flags &= 0xF9FF;
        if (gRecords->u1E != 0 || (gRecords->u1A == 0 && i <= mgr->count)) {
            e->flags |= 8;
        }
    }
    for (i = 0; i < slotCount; i++) {
        e = &mgr->e[i];
        if (!(e->flags & 1)) {
            e->unkA = 3;
            e->size0 = nodeSize * 4;
            e->size1 = (limit + 1) * 4;
            e->buf0 = poolAlloc(1, (e->size0 + 3) & ~3);
            if (i < gRecords->nAlloc) {
                e->buf1 = poolAlloc(1, (e->size1 + 3) & ~3);
            } else {
                e->buf1 = 0;
            }
            memset(e->buf0, 0, e->size0);
            if (i < gRecords->nAlloc) {
                memset(e->buf1, 0, e->size1);
            }
            e->unkC = 0;
            e->unkE = 0;
        }
        e->flags |= 1;
    }
    node = **(Node ***)(gOrderState + 0x73F0);
    for (i = 0; i < slotCount; i++) {
        e = &mgr->e[i];
        func_80022A98(node, e->buf0);
        e->blk = gRecords->blk[gRecords->idx[i]];
        e->unk18 = *node->p88;
        node = node->next;
    }
    return 1;
}
