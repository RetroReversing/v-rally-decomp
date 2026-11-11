void *poolAllocListNode(s32, s32);
s32 poolAllocHeadNode();

/* Creates the list head on first use, then appends a new 0x50-byte node to the list. */
void listAppendDefaultNode(s32 *head)
{
    if (*head == 0) {
        *head = poolAllocHeadNode();
    }
    poolAllocListNode(*head, 0x50);
}
