typedef struct OrderListNode {
    s32 unk00;
    struct OrderListNode *next;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 key;
} OrderListNode;
extern char gOrderState[];

/* Walks the order list from its head pointer at gOrderState+0x72FC and returns the first node whose key matches, or NULL. */
OrderListNode *order_find_by_key(int key) {
    OrderListNode *p = **(OrderListNode ***)(gOrderState + 0x72FC);
    for (; p; p = p->next) {
        if (p->key == key) {
            return p;
        }
    }
    return 0;
}
