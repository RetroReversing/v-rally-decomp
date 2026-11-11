extern char gOrderState[];
extern s32 order_check_and_release;
s32 flag_test_bit0(void *);
s32 flag_set_then_call(void *, s32 *);
s32 poolAllocHeadNode(void);

/* Returns 0 if the flag at gOrderState+0x73C0 is already set. Otherwise it stores poolAllocHeadNode()'s result at +0x87F4, registers order_check_and_release on that flag, and returns 1. */
s32 func_800427CC(void)
{
    void *flag;
    s32 ret;

    flag = gOrderState + 0x73C0;
    if (flag_test_bit0(flag)) {
        ret = 0;
    } else {
        *((s32 *) (gOrderState + 0x87F4)) = poolAllocHeadNode();
        flag_set_then_call(flag, &order_check_and_release);
        ret = 1;
    }
    return ret;
}
