s32 flag_test_bit0();
s32 flag_set_then_call();
extern char gOrderState[];
extern s32 orderSlotCallback;

/* Queues the order slot at gOrderState+0x7310 if it is free: sets its busy flag and
 * registers orderSlotCallback. Returns 1 if queued, 0 if the slot was already busy. */
s32 orderTrySchedule(void)
{
    void *slot;

    slot = gOrderState + 0x7310;
    if (flag_test_bit0(slot) != 0) {
        return 0;
    }
    flag_set_then_call(slot, &orderSlotCallback);
    return 1;
}
