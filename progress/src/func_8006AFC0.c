extern char *gSelectState;
extern char stream_state[];
s32 slotSetSelected();

/* Steps the toggle byte (+9) of the current select entry: 0 counts up, anything else counts down,
 * then passes the new value to slotSetSelected. Always returns 1. */
s32 func_8006AFC0(s32 slot)
{
    char *base;
    char *entry;
    u8 index;

    base = *(char **)(stream_state + 0x32F2);
    index = *(u8 *)(base + *(s8 *)(gSelectState + 0x228) + 0x32);
    entry = base + (index * 40 + 0x44);
    if (*(u8 *)(entry + 9) == 0) {
        *(u8 *)(entry + 9) = *(u8 *)(entry + 9) + 1;
    } else {
        *(u8 *)(entry + 9) = *(u8 *)(entry + 9) - 1;
    }
    slotSetSelected(slot, *(u8 *)(entry + 9));
    return 1;
}
