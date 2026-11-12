extern char stream_state[];
extern void *gSelectState;
s32 select_stream_char(u8, u8, u8);
void slotSetSelected(s32, s32);

/* Advances the selected slot's counter (capped at 2) for the stream under the current select state,
 * then tells slotSetSelected about the new count. Always returns 1. */
s32 func_8006B410(s32 arg0)
{
    char *stream;
    char *base;
    char *entry;
    u8 count;
    u8 next;

    stream = *(char **)(stream_state + 0x32F2);
    base = stream + (*(u8 *)((stream + *(s8 *)((char *)gSelectState + 0x228)) + 0x32) * 0x28 + 0x44);
    entry = base + (select_stream_char(*(u8 *)(stream + 0x1F), *(u8 *)(stream + 0x21), *(u8 *)(stream + 0x23)) & 0xFF);
    count = *(u8 *)(entry + 0x14);
    if (count < 2U) {
        next = count + 1;
        *(u8 *)(entry + 0x14) = next;
        slotSetSelected(arg0, next & 0xFF);
    }
    return 1;
}
