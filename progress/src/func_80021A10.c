s32 func_80046AB0(void *);

/* Walks a singly linked list of objects (next pointer at +4), handing each one to
 * func_80046AB0 in turn. */
void func_80021A10(void **list_head)
{
    void *node;

    node = *list_head;
    if (node != NULL) {
        do {
            func_80046AB0(node);
            node = *(void **)((s8 *)node + 4);
        } while (node != NULL);
    }
}
