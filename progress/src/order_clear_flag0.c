s32 flag_test_bit0();
s32 flag_clear_bit0();
extern char gOrderState[];

/* Clears bit 0 of the order-state flags word at +0x7378 if that bit is set. */ void order_clear_flag0(void) {
    void *flags;

    flags = gOrderState + 0x7378;
    if (flag_test_bit0(flags) != 0) {
        flag_clear_bit0(flags);
    }
}
