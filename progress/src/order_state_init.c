s32 flag_test_bit0();
s32 flag_set_bit0();
s32 poolAllocHeadNode();
s32 memset();
extern char gOrderState[];

/* One-time init of the order state block at gOrderState+0x7390 (bit 0 of its
 * first word is the done flag). If not yet done, clears the 0xE8 bytes before
 * it, allocates the pool entry stored at gOrderState+0x2370, and sets the flag. */
void order_state_init(void)
{
    void *flags;

    flags = gOrderState + 0x7390;
    if (flag_test_bit0(flags) == 0) {
        memset(flags - 0x88, 0, 0xE8);
        *(s32 *)(gOrderState + 0x2370) = poolAllocHeadNode();
        flag_set_bit0(flags);
    }
}
