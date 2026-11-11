extern char *gSelectState;
extern char gStreamState[];
s32 slot_set_selected();

/* Steps the toggle byte (+9) of the current select entry: 0 counts up, anything else counts down,
 * then passes the new value to slot_set_selected. Always returns 1. */
s32 func_8006AFC0(s32 slot)
{
    char *base;
    char *entry;
    u8 index;

    base = *(char **)(gStreamState + 0x32F2);
    index = *(u8 *)(base + *(s8 *)(gSelectState + 0x228) + 0x32);
    entry = base + (index * 40 + 0x44);
    if (*(u8 *)(entry + 9) == 0) {
        *(u8 *)(entry + 9) = *(u8 *)(entry + 9) + 1;
    } else {
        *(u8 *)(entry + 9) = *(u8 *)(entry + 9) - 1;
    }
    slot_set_selected(slot, *(u8 *)(entry + 9));
    return 1;
}
