typedef s32 M2C_UNK;
M2C_UNK league_set_hook(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK league_set_hook_entry(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern void *gSelectState;
extern s32 gLeague;
extern M2C_UNK func_8005E38C;
extern M2C_UNK select_init_screen;
extern M2C_UNK func_80066EBC;
extern M2C_UNK select_advance_named_slot;
extern M2C_UNK select_refresh_upper_slot;
extern M2C_UNK select_flags_state_enter;
extern M2C_UNK selectScreenReinit;
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
extern M2C_UNK select_init_entry_handlers;
extern M2C_UNK select_reset_group0;
extern M2C_UNK func_800684F4;
extern M2C_UNK select_clear_group0;
extern M2C_UNK select_step_next_named_slot;
extern M2C_UNK select_step_upper_slot;
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
    league_set_hook(gLeague, 0, 0x10, &func_800695D0);
    league_set_hook(gLeague, 1, 0x10, &func_800695D0);
    league_set_hook(gLeague, 2, 0x10, &func_80067474);
    league_set_hook(gLeague, 3, 0x10, &select_init_entry_handlers);
    league_set_hook(gLeague, 4, 0x10, &func_8005E38C);
    league_set_hook_entry(gLeague, 0, 0x20, &func_8005E38C);
    league_set_hook(gLeague, 5, 4, &select_refresh_upper_slot);
    league_set_hook(gLeague, 5, 8, &select_advance_named_slot);
    league_set_hook(gLeague, 6, 0x10, &selectSetHandlers);
    league_set_hook(gLeague, 7, 0x10, &select_flags_state_enter);
    league_set_hook(gLeague, 8, 0x10, &func_80069734);
    league_set_hook_entry(gLeague, 1, 0x20, &func_80069734);
    league_set_hook(gLeague, 0x1C, 4, &func_80067248);
    league_set_hook(gLeague, 0x1C, 8, &func_80067248);
    league_set_hook(gLeague, 0x1D, 4, &toggle_selected_record);
    league_set_hook(gLeague, 0x1D, 8, &toggle_selected_record);
    league_set_hook(gLeague, 0x1E, 4, &toggle_selected_record_2);
    league_set_hook(gLeague, 0x1E, 8, &toggle_selected_record_2);
    league_set_hook(gLeague, 0x1F, 8, &select_toggle_record_flag);
    league_set_hook(gLeague, 0x1F, 4, &select_toggle_record_flag);
    league_set_hook(gLeague, 0x20, 0x10, &func_800671A0);
    league_set_hook_entry(gLeague, 5, 0x20, &func_800671A0);
    league_set_hook(gLeague, 9, 8, &select_anim_step);
    league_set_hook(gLeague, 9, 4, &func_80067644);
    league_set_hook(gLeague, 9, 0x10, &func_800676A0);
    league_set_hook(gLeague, 9, 0x20, &func_800677E8);
    league_set_hook(gLeague, 0xB, 0x10, &func_8006786C);
    league_set_hook(gLeague, 0xA, 0x10, &selectScreenReinit);
    var_s1 = 0;
    do {
        league_set_hook(gLeague, (temp_s0 = (u16)(var_s1 + 0x11)), 4, &func_80068C78);
        var_s1 += 1;
        league_set_hook(gLeague, temp_s0, 8, &func_80068CA4);
        league_set_hook(gLeague, temp_s0, 1, &func_80068CD4);
        league_set_hook(gLeague, temp_s0, 2, &func_80068CD4);
    } while ((u32) (var_s1 & 0xFF) < 8U);
    league_set_hook(gLeague, 0x19, 4, &func_80068D9C);
    league_set_hook(gLeague, 0x19, 8, &select_mark_pending);
    league_set_hook(gLeague, 0x1B, 0x10, &stream_slot_store_packed);
    league_set_hook(gLeague, 0x1A, 0x10, &func_8006951C);
    league_set_hook(gLeague, 0xC, 4, &select_step_upper_slot);
    league_set_hook(gLeague, 0xC, 8, &select_step_next_named_slot);
    league_set_hook(gLeague, 0xC, 0x10, &select_reset_group0);
    league_set_hook(gLeague, 0xD, 0x10, &func_80067474);
    league_set_hook(gLeague, 0xE, 0x10, &selectScreenReinit);
    league_set_hook(gLeague, 0xF, 0x10, &select_clear_group0);
    league_set_hook(gLeague, 0x10, 0x10, &func_800684F4);
    league_set_hook_entry(gLeague, 3, 0x20, &selectScreenReinit);
    *(s8 *)((s8 *)gSelectState + 0x228) = 0;
    *(M2C_UNK **)((s8 *)gSelectState + 0x288) = &select_init_screen;
    *(M2C_UNK **)((s8 *)gSelectState + 0x28C) = &func_80066EBC;
}
