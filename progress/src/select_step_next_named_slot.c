s8 select_next_named_slot(s8);
extern u8 *gSelectState;

/* Advances the current select slot (gSelectState+0x229) forward to the next
 * entry whose name starts with an uppercase letter. */
s32 select_step_next_named_slot(void) {
    *(s8 *)(gSelectState + 0x229) = select_next_named_slot(*(s8 *)(gSelectState + 0x229));
    return 0;
}
