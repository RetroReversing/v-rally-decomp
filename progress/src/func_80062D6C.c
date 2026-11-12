void slotSetSelected();
extern char stream_state[];

/* Reports the current select state to the slot (slot 3). Mode 2 reports one of two
 * halves, the first time it is set; mode 1 reports both halves at once. */
s32 func_80062D6C(void)
{
    u16 *sel;
    s32 slot;
    s32 selected;

    sel = *(u16 **)(stream_state + 0x32F2);
    if (sel[7] == 2)
    {
        if (sel[0xC] != 0)
            return 0;
        slot = 3;
        if (sel[0xD] != 0)
        {
            sel[0xC] = 1;
            selected = 1;
        }
        else
        {
            sel[0xD] = 1;
            selected = 0;
        }
    }
    else if (sel[7] == 1)
    {
        slot = 3;
        selected = 1;
        sel[0xC] = 1;
        sel[0xD] = 1;
    }
    else
        return 0;
    slotSetSelected(slot, selected);
    return 0;
}
