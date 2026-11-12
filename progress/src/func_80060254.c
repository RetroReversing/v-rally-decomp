s32 slotSetSelected();
extern char stream_state[];

/* Toggles bit 0x800 in the flags (+0x2C) of the object at stream_state+0x32F2, then
 * reports the new state (1 when the bit was set) to the given slot. */
s32 func_80060254(s32 slot) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2C);
    if (flags & 0x800) {
        goto clear;
    }
    goto set;
clear:
    *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2C) = (u16)(flags & 0xF7FF);
    selected = 0;
    goto report;
set:
    *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2C) = (u16)(flags | 0x800);
    selected = 1;
report:
    slotSetSelected(slot, selected);
    return 0;
}
