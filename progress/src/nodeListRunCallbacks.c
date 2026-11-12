/* Walks the node list headed by *list. Each node holds a payload at +0x10, a next link
 * at +4 and a callback at +0x18; the callback is called with the payload. */
void nodeListRunCallbacks(void **list)
{
    void *node;

    if (list != NULL) {
        node = *list;
        if (node != NULL) {
            do {
                ((s32 (*)(s32))*(void **)((s8 *)node + 0x18))(*(s32 *)((s8 *)node + 0x10));
                node = *(void **)((s8 *)node + 4);
            } while (node != NULL);
        }
    }
}
