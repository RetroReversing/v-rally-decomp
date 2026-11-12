s32 func_80015B00();
s32 flag_test_bit0();
s32 flag_clear_bit0();
extern s8 D_8009CED4;
extern char gOrderState[];

/* If bit 0 of the flag word at gOrderState+0x7368 is set, runs func_80015B00, clears that
   bit, and sets D_8009CED4 to 0. */
void order_handle_pending_flag(void) {
    void *flags;

    flags = gOrderState + 0x7368;
    if (flag_test_bit0(flags) != 0) {
        func_80015B00();
        flag_clear_bit0(flags);
        D_8009CED4 = 0;
    }
}
