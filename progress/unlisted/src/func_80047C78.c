s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 stream_list_destroy();
extern char gOrderState[];
extern char gStreamState[];

/* If the pending flag (bit 0 of the flag word at gOrderState+0x7380) is set,
 * frees the stream list at gStreamState+0x7672 and clears the flag. */
void func_80047C78(void) {
    void *flags;

    flags = gOrderState + 0x7380;
    if (flag_test_bit0(flags) != 0) {
        stream_list_destroy(*(s32 *)(gStreamState + 0x7672));
        flag_clear_bit0(flags);
    }
}
