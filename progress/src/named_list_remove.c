typedef struct NamedNode { struct NamedNode *prev; struct NamedNode *next; u8 pad08[4]; char *name; void *data; u8 pad14[4]; void (*destroy)(void *); } NamedNode;

/* Head and tail of a doubly linked list of NamedNode. */
typedef struct NodeList { NamedNode *head; NamedNode *tail; } NodeList;

s32 strCmp(void *a, void *b);
void list_unlink_free(NamedNode *node, NodeList *list);

/* Finds the first node whose name matches, calls its destroy hook on its data, then unlinks and frees the list head. Stops after one match. */
void named_list_remove(NodeList *list, char *name) {
    s32 searching;
    NamedNode *node;

    searching = 1;
    if (list != NULL) {
        node = list->head;
        if (node != NULL) {
            do {
                if (strCmp(node->name, name) == 0) {
                    node->destroy(node->data);
                    searching = 0;
                    list_unlink_free(list->head, list);
                }
                node = node->next;
            } while (searching && node != NULL);
        }
    }
}
