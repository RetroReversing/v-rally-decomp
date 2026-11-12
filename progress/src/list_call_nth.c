typedef struct ListNode { u8 pad00[12]; void (*fn)(void *); } ListNode;
typedef struct ListOwner { u8 pad00[8]; s32 index; } ListOwner;

ListNode *list_nth_node(ListOwner *owner, s32 index);

/* Calls the callback of the node that is owner->index steps into the owner's list. */
void list_call_nth(ListOwner *owner) {
    ListNode *node = list_nth_node(owner, owner->index);
    node->fn(node);
}
