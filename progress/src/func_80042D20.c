extern s8 D_800ADFA8;
void *list_find_node(void **, u8 *);
s32 *findEntryById();
extern s32 gPadFlags;
extern char D_800A4DEC[];
extern char gOrderState[];
extern char stream_state[];

/* Marks the stream's current entry as active (bit 0 set, bit 1 cleared), clears the 0x40 flag on every
 * node of the list at gOrderState+0x72FC, clears the 0x02 flag on the matching stream entry, and sets
 * gPadFlags bit 0 while clearing bit 7. */
void func_80042D20(void)
{
    s32 *entry;
    s32 *inner;
    void *found;
    void *node;
    entry = findEntryById(*(void **)(*(char **)(stream_state + 0x326A) + 0x24));
    entry[4] = (entry[4] & ~2) | 1;
    node = **(void ***)(gOrderState + 0x72FC);
    D_800ADFA8 = 0;
    while (node != NULL) {
        *(u16 *)((char *)node + 0x20) &= 0xFFBF;
        found = list_find_node((void **)((char *)node + 0x28), (u8 *)(D_800A4DEC));
        if (found != NULL) {
            found = *(void **)((char *)found + 0x10);
            inner = *(s32 **)found;
            inner = *(s32 **)((char *)inner + 4);
            *(u16 *)((char *)inner + 0x68) &= 0xFFFD;
        }
        node = *(void **)((char *)node + 4);
    }
    gPadFlags = (gPadFlags & ~0x80) | 1;
}
