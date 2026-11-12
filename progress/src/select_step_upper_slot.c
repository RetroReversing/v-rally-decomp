s8 slot_find_upper_before(s8);
extern u8 *gSelectState;

/* Moves the current select slot (gSelectState+0x229) back to the nearest
 * entry before it whose name starts with an uppercase letter. */
s32 select_step_upper_slot(void) {
    *(s8 *)(gSelectState + 0x229) = slot_find_upper_before(*(s8 *)(gSelectState + 0x229));
    return 0;
}
