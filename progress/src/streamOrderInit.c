extern char gOrderState[];
extern char stream_state[];

s32 flag_test_bit0();
s32 flag_set_then_call();
s32 poolAllocHeadNode();
extern s32 streamOrderCallback;

/* Starts the order list if flag_test_bit0 reports the order slot is free: stores the new
 * list head at gOrderState+0x72FC, registers streamOrderCallback on the slot and clears
 * the stream's +0x3312 field. Returns 1 when started, 0 otherwise. */
s32 streamOrderInit(void) {
    void *slot;

    slot = gOrderState + 0x7338;
    if (flag_test_bit0(slot) == 0) {
        *((s32 *)(gOrderState + 0x72FC)) = poolAllocHeadNode();
        flag_set_then_call(slot, &streamOrderCallback);
        *((s32 *)(stream_state + 0x3312)) = 0;
        return 1;
    }
    return 0;
}
