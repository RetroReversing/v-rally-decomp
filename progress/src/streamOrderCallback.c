s32 flag_test_bit0(void *);
s32 flag_clear_bit0(void *);
s32 nodeListRunCallbacks(void *);
s32 list_unlink_free(s32, void *);
s32 heapReleaseBlock(void *);
s32 func_800804C4(void *, void *);
extern void *D_800B5B4C;
extern char D_800B5B88[];
extern s32 func_8004247C;

/* Tears down the active list at D_800B5B4C if D_800B5B88 is ready: drains the pending
 * count at +0x28 of every node (following the +4 next link), releases the list, clears
 * D_800B5B4C and closes D_800B5B88. Returns 1 when it ran, 0 otherwise. */
s32 streamOrderCallback(void)
{
    char *node;

    if (flag_test_bit0(D_800B5B88) != 0) {
        node = *(char **)D_800B5B4C;
        if (node != NULL) {
            do {
                nodeListRunCallbacks(node + 0x28);
                if (*(s32 *)(node + 0x28) != 0) {
                    do {
                        list_unlink_free(*(s32 *)(node + 0x28), node + 0x28);
                    } while (*(s32 *)(node + 0x28) != 0);
                }
                node = *(char **)(node + 4);
            } while (node != NULL);
        }
        func_800804C4(D_800B5B4C, &func_8004247C);
        heapReleaseBlock(D_800B5B4C);
        D_800B5B4C = NULL;
        flag_clear_bit0(D_800B5B88);
        return 1;
    }
    return 0;
}
