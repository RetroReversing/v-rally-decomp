s32 flag_test_bit0();
s32 flag_clear_bit0();
extern char gOrderState[];

/* Runs when the order slot at gOrderState+0x7310 is scheduled: if its busy flag is set, clear it. */
void orderSlotCallback(void) {
    void *slot;

    slot = gOrderState + 0x7310;
    if (flag_test_bit0(slot) != 0) {
        flag_clear_bit0(slot);
    }
}
