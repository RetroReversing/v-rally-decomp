typedef struct ListNode { struct ListNode *next; struct ListNode *prev; } ListNode;
typedef struct ListHead { ListNode *first; ListNode *last; } ListHead;

/* Unlinks `node` from the doubly linked list `list`: its neighbours are relinked and,
 * if it was the first or last node, the list's head or tail is updated. */
void list_unlink(ListNode *node, ListHead *list) {
    if (node == list->first) {
        list->first = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    if (node == list->last) {
        list->last = node->next;
        return;
    }
    node->prev->next = node->next;
}
