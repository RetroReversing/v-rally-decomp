extern char gOrderState[];
extern s32 func_80042ACC;
s32 flag_test_bit0(void *);
s32 flag_set_then_call(void *, s32 *);
s32 poolAllocHeadNode(void);

/* Returns 0 if the flag at gOrderState+0x73E8 is already set. Otherwise it stores poolAllocHeadNode()'s result at +0x2354, registers func_80042ACC on that flag, and returns 1. */
s32 func_80042B2C(void)
{
    void *flag;
    s32 ret;

    flag = gOrderState + 0x73E8;
    if (flag_test_bit0(flag)) {
        ret = 0;
    } else {
        *((s32 *) (gOrderState + 0x2354)) = poolAllocHeadNode();
        flag_set_then_call(flag, &func_80042ACC);
        ret = 1;
    }
    return ret;
}
