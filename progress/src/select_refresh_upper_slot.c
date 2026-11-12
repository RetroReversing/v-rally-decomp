extern void *gSelectState;
s8 slot_find_upper_before(s8 start);

/* Re-runs slot_find_upper_before on the slot index stored at gSelectState+0x22A and writes the result back. */
s32 select_refresh_upper_slot(void) {
    *(s8 *)((s8 *)gSelectState + 0x22A) = slot_find_upper_before(*(s8 *)((s8 *)gSelectState + 0x22A));
    return 0;
}
