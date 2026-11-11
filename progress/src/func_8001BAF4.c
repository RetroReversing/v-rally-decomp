s32 releaseNodeObjects(s32);
s32 list_unlink_free(s32, s32 *);

/* Frees every node in the list headed by *head, one node at a time, until the head is empty. */
void func_8001BAF4(s32 *head)
{
    s32 node;

    if (*head != 0) {
        do {
            node = *head;
            releaseNodeObjects(node);
            list_unlink_free(node, head);
        } while (*head != 0);
    }
}
