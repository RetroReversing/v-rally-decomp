extern char gStreamState[];
s32 slot_set_selected(s32 a, s32 b, void *c);

typedef struct VRStreamSlot { u8 pad00[14]; u16 mode; u8 pad10[8]; u16 pending; u16 selected; } VRStreamSlot;

/* Updates the current stream slot's selection flags, then re-marks the slot list
 * with the selected entry. A slot in mode 2 toggles its pending flag into selected;
 * otherwise the slot is reset to selected. */
s32 slot_update_selection(void)
{
    u32 sel_arg;
    VRStreamSlot *slot;

    slot = *(VRStreamSlot **)(gStreamState + 0x32F2);
    if (slot->mode == 2) {
        if (slot->pending != 0) {
            slot->pending = 0;
            slot->selected = 1;
        } else {
            slot->selected = 0;
        }
        sel_arg = *(u16 *)((char *)*(VRStreamSlot **)(gStreamState + 0x32F2) + 0x1A);
        sel_arg = (sel_arg < 1) * 2;
        slot_set_selected(3, sel_arg, slot);
    } else {
        sel_arg = 0;
        slot->pending = 0;
        slot->selected = 1;
        slot_set_selected(3, sel_arg, slot);
    }
    return 0;
}
