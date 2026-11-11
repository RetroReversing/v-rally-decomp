typedef struct Node { char pad0[4]; struct Node *child; char pad8[0x28]; struct Node *at30; char pad34[0x14]; s32 *at48; char pad4c[0x10]; struct Node *at5c; char pad60[0xc]; s32 value; } Node;
typedef struct Entry { char pad[8]; u16 flags,state,other; char rest[54]; } Entry;
extern Entry *gSlotTable;
extern char *gRecords;
void setNodeFlags(Node *, int);

/* Marks the slot of the node's current record: when the record mode is 0 and
 * the flag is 1, and the slot entry has flag 0x200 set, the child node gets
 * flag 16 and its two sub-nodes get the value 1, and the slot is cleared
 * and set to state 4. */
void func_800515D0(Node *node) {
    Node *orig;
    s32 flag;
    u32 idx;
    if (*(u16 *)(gRecords + 0x1e) == 0) {
        flag = *(u16 *)(gRecords + 0x1a);
        if (flag == 1) {
            idx = *((u8 *)node->at48 + 3);
            if (idx < 5) {
                char *base;
                Entry *entry;
                base = (char *)gSlotTable;
                base += idx * 68;
                entry = (Entry *)base;
                if (entry->flags & 0x200) {
                    Entry *slot;
                    orig = node;
                    node = node->child;
                    setNodeFlags(node, 16);
                    node->at5c->value = flag;
                    node->at30->value = flag;
                    slot = gSlotTable;
                    entry = slot + *orig->at48;
                    entry->other = 0;
                    slot += *orig->at48;
                    slot->state = 4;
                }
            }
        }
    }
}
