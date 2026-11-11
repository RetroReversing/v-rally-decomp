s32 flag_test_bit0(s32 *flags);
s32 flag_clear_bit0(char *entry);
void heapReleaseBlock(s32 handle);
void func_800804C4(s32 handle, void (*cb)(void));
extern char gOrderState[];
void func_80042750(void);

/* If the order entry at gOrderState+0x73C0 has its flag bit set, hands its
 * handle (+0x87F4) to func_800804C4 with the release callback, releases it and
 * clears the entry. Returns 1 when released, 0 otherwise. */
s32 order_check_and_release(void)
{
    char *entry;

    entry = gOrderState + 0x73C0;
    if (flag_test_bit0((s32 *)entry) != 0) {
        func_800804C4(*(s32 *)(gOrderState + 0x87F4), func_80042750);
        heapReleaseBlock(*(s32 *)(gOrderState + 0x87F4));
        flag_clear_bit0(entry);
        return 1;
    }
    return 0;
}
