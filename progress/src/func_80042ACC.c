s32 flag_test_bit0();
s32 flag_clear_bit0();
void heapReleaseBlock();
void list_for_each();
extern char gOrderState[];
void func_80042AB0(void);

/* If the state block at gOrderState+0x73E8 passes flag_test_bit0, registers func_80042AB0 as
 * the callback for the handle at +0x2354, releases that handle, and closes the block again.
 * Returns 1 when that happened, 0 otherwise. */
s32 func_80042ACC(void)
{
    char *block;

    block = gOrderState + 0x73E8;
    if (flag_test_bit0(block) != 0) {
        list_for_each(*(s32 *)(gOrderState + 0x2354), func_80042AB0);
        heapReleaseBlock(*(s32 *)(gOrderState + 0x2354));
        flag_clear_bit0(block);
        return 1;
    }
    return 0;
}
