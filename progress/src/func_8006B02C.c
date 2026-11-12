extern void *gSelectState;
extern char stream_state[];
s32 slotSetSelected(s32, s32);
s32 select_stream_char(u8, u8, u8);

/* Steps the option count of the stream slot picked by select_stream_char (up to 2) and
 * then selects that option on the slot's entry list. Always returns 1. */
s32 func_8006B02C(s32 arg0) {
    u8 count;
    u8 count_next;
    void *slot;
    void *option;

    slot = *(void **) (stream_state + 0x32F2) + ((*(u8 *) ((*(void **) (stream_state + 0x32F2) + *(s8 *) (((char *) gSelectState) + 0x228)) + 0x32) * 0x28) + 0x44);
    option = slot + (select_stream_char(*(u8 *) (*(void **) (stream_state + 0x32F2) + 0x1F), *(u8 *) (*(void **) (stream_state + 0x32F2) + 0x21), *(u8 *) (*(void **) (stream_state + 0x32F2) + 0x23)) & 0xFF);
    count = *(u8 *) (option + 0x10);
    if (count < 2U) {
        count_next = count + 1;
        *(u8 *) (option + 0x10) = count_next;
        slotSetSelected(arg0, count_next & 0xFF);
    }
    return 1;
}
