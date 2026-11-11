extern u8 gOrderState[];
s32 records_restore_from_order();
s32 select_menu_setup();

/* Entering the select menu: restores the records first if the order flag at +0x7FCA
 * is set, then runs the select menu setup. */
s32 select_menu_enter(s32 mode, s32 param) {
    if (gOrderState[0x7FCA] != 0) {
        records_restore_from_order();
    }
    select_menu_setup(mode, param);
    return 0;
}
