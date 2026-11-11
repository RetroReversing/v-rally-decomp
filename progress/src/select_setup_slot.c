s32 select_copy_entry_state(s32, s32);
s32 select_set_active_sub(s32, s32);
s32 select_clear_entry_flag2(s32);
void text_obj_set_enabled(u32);
extern void *gSelectState;
extern char gStreamState[];

/* Prepares a select slot: clears its highlight, copies entry state into the destination
   entry (0x17 or 0xE) and makes the slot's current sub-entry active. */
s32 select_setup_slot(s32 slot) {
    s32 dst;
    s32 src;

    src = slot;
    ((s8 *) gSelectState)[0x245] = 1;
    ((u16 *) *(void **) (gStreamState + 0x32F2))[0x22 / 2] = 0;
    if (((s16 *) *(void **) (gStreamState + 0x325A))[1] == 2) {
        dst = 0x17;
    } else {
        select_clear_entry_flag2(0);
        text_obj_set_enabled(0x13);
        text_obj_set_enabled(0x14);
        text_obj_set_enabled(0x15);
        text_obj_set_enabled(0x16);
        src = slot;
        dst = 0xE;
    }
    select_copy_entry_state(src, dst);
    select_set_active_sub(slot, ((u16 *) *(void **) (gStreamState + 0x32F2))[0x22 / 2]);
    return 0;
}
