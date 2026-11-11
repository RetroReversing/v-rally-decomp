s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 heapReleaseBlock();
extern char gOrderState[];

/* If the flag at gOrderState+0x7390 has bit 0 set, releases the heap block stored at
 * gOrderState+0x2370 and calls flag_clear_bit0 on the flag. */
void order_release_flagged_block(void) {
    void *flag_ptr;

    flag_ptr = gOrderState + 0x7390;
    if (flag_test_bit0(flag_ptr) != 0) {
        heapReleaseBlock(*(s32 *) (gOrderState + 0x2370));
        flag_clear_bit0(flag_ptr);
    }
}
