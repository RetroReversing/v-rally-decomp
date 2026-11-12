s8 slot_find_upper_before(s8);
extern void *gSelectState;

/* Replaces the select state's byte at +0x228 with the slot index found before it. */
s32 updateSelectStateUpperSlot(void) {
    *(s8 *)((char *)gSelectState + 0x228) = slot_find_upper_before(*(s8 *)((char *)gSelectState + 0x228));
    return 0;
}
