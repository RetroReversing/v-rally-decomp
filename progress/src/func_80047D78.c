s32 streamReleaseEntry(s32);
s32 list_unlink_free(void *, void **);

/* Releases each node in the list headed by *head: the stream at +0xC is released, then the node is unlinked and freed. The next pointer is at +4. */
void func_80047D78(void **head)
{
    void *node;
    void *cur;

    if (head != NULL) {
        cur = *head;
        if (cur != NULL) {
            do {
                streamReleaseEntry(((s32 *) cur)[3]);
                node = cur;
                cur = ((void **) cur)[1];
                list_unlink_free(node, head);
            } while (cur != NULL);
        }
    }
}
