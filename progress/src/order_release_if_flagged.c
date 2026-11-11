s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 streamReleaseEntry();
extern s32 D_800A1240;
extern char gOrderState[];

/* If the order block's flag bit 0 is set, clear it and release the stream entry. */
void order_release_if_flagged(void) {
    void *order_block;

    order_block = gOrderState + 0x73E0;
    if (flag_test_bit0(order_block) != 0) {
        flag_clear_bit0(order_block);
        streamReleaseEntry(D_800A1240);
    }
}
