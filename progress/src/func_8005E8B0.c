extern char gOrderState[];
extern char gStreamState[];
extern void *gSelectState;
s32 slot_set_selected(s32 a, s32 b, void *c);
s32 func_80066B88(void);

/* Advances the select step counter while it is below the order's slot count, marking the
 * next slot as selected; once the counter is 2 or more, sets the select timer to 60. */
s32 func_8005E8B0(s32 arg0)
{
    void *table;
    u16 step;
    u16 next;

    table = *(void **)(gStreamState + 0x32F2);
    step = *(u16 *)((char *)table + 0xE);
    if ((u32)step < *(u8 *)(gOrderState + 0x7D50)) {
        next = step + 1;
        *(u16 *)((char *)table + 0xE) = next;
        slot_set_selected(arg0, (next & 0xFFFF) - 1, table);
        func_80066B88();
    } else if ((u32)step < 2) {
        *(s16 *)((char *)gSelectState + 0x220) = 0x3C;
    }
    return 0;
}
