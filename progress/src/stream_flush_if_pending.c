s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 stream_list_destroy();
extern char gOrderState[];
extern char stream_state[];

/* If the pending flag (bit 0 of the flag word at gOrderState+0x7380) is set,
 * frees the stream list at stream_state+0x7672 and clears the flag. */
void stream_flush_if_pending(void) {
    void *flags;

    flags = gOrderState + 0x7380;
    if (flag_test_bit0(flags) != 0) {
        stream_list_destroy(*(s32 *)(stream_state + 0x7672));
        flag_clear_bit0(flags);
    }
}
