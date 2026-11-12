extern void *gSelectState;
s8 select_next_named_slot(s8 slot);

/* Moves the current slot index at gSelectState+0x22A to the next named slot. */
s32 select_advance_named_slot(void) {
    *(s8 *)((s8 *)gSelectState + 0x22A) = select_next_named_slot(*(s8 *)((s8 *)gSelectState + 0x22A));
    return 0;
}
