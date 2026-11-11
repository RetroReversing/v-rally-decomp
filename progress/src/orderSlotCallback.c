s32 flag_test_bit0();
s32 flag_clear_bit0();
extern char gOrderState[];

void orderSlotCallback(void) {
    void *temp_s0;

    temp_s0 = gOrderState + 0x7310;
    if (flag_test_bit0(temp_s0) != 0) {
        flag_clear_bit0(temp_s0);
    }
}
