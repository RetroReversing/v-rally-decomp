s32 flag_test_bit0(s32 *flags);
s32 flag_clear_bit0(char *entry);
void heapReleaseBlock(s32 handle);
void list_for_each(s32 handle, void (*cb)(void));
extern char gOrderState[];
void order_release_entry(void);

/* If the order entry at gOrderState+0x73C0 has its flag bit set, hands its
 * handle (+0x87F4) to list_for_each with the release callback, releases it and
 * clears the entry. Returns 1 when released, 0 otherwise. */
s32 order_check_and_release(void)
{
    char *entry;

    entry = gOrderState + 0x73C0;
    if (flag_test_bit0((s32 *)entry) != 0) {
        list_for_each(*(s32 *)(gOrderState + 0x87F4), order_release_entry);
        heapReleaseBlock(*(s32 *)(gOrderState + 0x87F4));
        flag_clear_bit0(entry);
        return 1;
    }
    return 0;
}
