typedef s32 M2C_UNK;
M2C_UNK func_8008A1CC(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern void *gSelectState;
extern s32 gLeague;
extern M2C_UNK func_8005E38C;
extern M2C_UNK select_init_screen;
extern M2C_UNK func_80066EBC;
extern M2C_UNK func_80066F8C;
extern M2C_UNK func_80066FC0;
extern M2C_UNK func_80066FF4;
extern M2C_UNK SelectStateReset;
extern M2C_UNK func_800671A0;
extern M2C_UNK func_80067248;
extern M2C_UNK toggle_selected_record;
extern M2C_UNK toggle_selected_record_2;
extern M2C_UNK select_toggle_record_flag;
extern M2C_UNK func_80067474;
extern M2C_UNK select_anim_step;
extern M2C_UNK func_80067644;
extern M2C_UNK func_800676A0;
extern M2C_UNK func_800677E8;
extern M2C_UNK func_8006786C;
extern M2C_UNK func_800680F0;
extern M2C_UNK func_800684C0;
extern M2C_UNK func_800684F4;
extern M2C_UNK func_800685C0;
extern M2C_UNK func_800685F0;
extern M2C_UNK func_80068624;
extern M2C_UNK func_80068C78;
extern M2C_UNK func_80068CA4;
extern M2C_UNK func_80068CD4;
extern M2C_UNK func_80068D9C;
extern M2C_UNK select_mark_pending;
extern M2C_UNK stream_slot_store_packed;
extern M2C_UNK selectSetHandlers;
extern M2C_UNK func_8006951C;
extern M2C_UNK func_800695D0;
extern M2C_UNK func_80069734;

/* Registers the handlers for the script/event table at gLeague: each call
 * binds one handler to a (group, slot) pair; the loop registers the eight
 * per-group handlers for groups 0x12..0x19. Also clears the state flags at
 * gSelectState and stores the two dispatch callbacks at +0x288 and +0x28C. */
void func_80066634(void) {
    s32 temp_a1;
    s32 temp_s0;
    u8 var_s1;

    *(s8 *)((s8 *)gSelectState + 0x245) = 0;
    func_8008A1CC(gLeague, 0, 0x10, &func_800695D0);
    func_8008A1CC(gLeague, 1, 0x10, &func_800695D0);
    func_8008A1CC(gLeague, 2, 0x10, &func_80067474);
    func_8008A1CC(gLeague, 3, 0x10, &func_800680F0);
    func_8008A1CC(gLeague, 4, 0x10, &func_8005E38C);
    func_8008A290(gLeague, 0, 0x20, &func_8005E38C);
    func_8008A1CC(gLeague, 5, 4, &func_80066FC0);
    func_8008A1CC(gLeague, 5, 8, &func_80066F8C);
    func_8008A1CC(gLeague, 6, 0x10, &selectSetHandlers);
    func_8008A1CC(gLeague, 7, 0x10, &func_80066FF4);
    func_8008A1CC(gLeague, 8, 0x10, &func_80069734);
    func_8008A290(gLeague, 1, 0x20, &func_80069734);
    func_8008A1CC(gLeague, 0x1C, 4, &func_80067248);
    func_8008A1CC(gLeague, 0x1C, 8, &func_80067248);
    func_8008A1CC(gLeague, 0x1D, 4, &toggle_selected_record);
    func_8008A1CC(gLeague, 0x1D, 8, &toggle_selected_record);
    func_8008A1CC(gLeague, 0x1E, 4, &toggle_selected_record_2);
    func_8008A1CC(gLeague, 0x1E, 8, &toggle_selected_record_2);
    func_8008A1CC(gLeague, 0x1F, 8, &select_toggle_record_flag);
    func_8008A1CC(gLeague, 0x1F, 4, &select_toggle_record_flag);
    func_8008A1CC(gLeague, 0x20, 0x10, &func_800671A0);
    func_8008A290(gLeague, 5, 0x20, &func_800671A0);
    func_8008A1CC(gLeague, 9, 8, &select_anim_step);
    func_8008A1CC(gLeague, 9, 4, &func_80067644);
    func_8008A1CC(gLeague, 9, 0x10, &func_800676A0);
    func_8008A1CC(gLeague, 9, 0x20, &func_800677E8);
    func_8008A1CC(gLeague, 0xB, 0x10, &func_8006786C);
    func_8008A1CC(gLeague, 0xA, 0x10, &SelectStateReset);
    var_s1 = 0;
    do {
        func_8008A1CC(gLeague, (temp_s0 = (u16)(var_s1 + 0x11)), 4, &func_80068C78);
        var_s1 += 1;
        func_8008A1CC(gLeague, temp_s0, 8, &func_80068CA4);
        func_8008A1CC(gLeague, temp_s0, 1, &func_80068CD4);
        func_8008A1CC(gLeague, temp_s0, 2, &func_80068CD4);
    } while ((u32) (var_s1 & 0xFF) < 8U);
    func_8008A1CC(gLeague, 0x19, 4, &func_80068D9C);
    func_8008A1CC(gLeague, 0x19, 8, &select_mark_pending);
    func_8008A1CC(gLeague, 0x1B, 0x10, &stream_slot_store_packed);
    func_8008A1CC(gLeague, 0x1A, 0x10, &func_8006951C);
    func_8008A1CC(gLeague, 0xC, 4, &func_80068624);
    func_8008A1CC(gLeague, 0xC, 8, &func_800685F0);
    func_8008A1CC(gLeague, 0xC, 0x10, &func_800684C0);
    func_8008A1CC(gLeague, 0xD, 0x10, &func_80067474);
    func_8008A1CC(gLeague, 0xE, 0x10, &SelectStateReset);
    func_8008A1CC(gLeague, 0xF, 0x10, &func_800685C0);
    func_8008A1CC(gLeague, 0x10, 0x10, &func_800684F4);
    func_8008A290(gLeague, 3, 0x20, &SelectStateReset);
    *(s8 *)((s8 *)gSelectState + 0x228) = 0;
    *(M2C_UNK **)((s8 *)gSelectState + 0x288) = &select_init_screen;
    *(M2C_UNK **)((s8 *)gSelectState + 0x28C) = &func_80066EBC;
}
