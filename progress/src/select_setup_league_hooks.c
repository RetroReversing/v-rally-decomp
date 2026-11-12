/* Wires up the track-select screen: one-time voice and order init, the league menu hook table, and the per-race-state screen callbacks. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK order_recv_msg();                            /* extern */
M2C_UNK streamOpenPath(void *, M2C_UNK *);           /* extern */
M2C_UNK start_track_voices(void *);                      /* extern */
M2C_UNK voicesSetIdleParams(M2C_UNK);                     /* extern */
M2C_UNK voicesSetIdleValue(s32);                         /* extern */
M2C_UNK func_8008A104(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK league_set_hook(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK league_set_hook_entry(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 gRaceFlags;
extern void *gSelectState;
extern M2C_UNK D_800A56B0;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;
extern M2C_UNK select_menu_setup;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_80064E48;
extern M2C_UNK hud_draw_counter_text;
extern M2C_UNK select_install_league_callback;
extern M2C_UNK func_80064F04;
extern M2C_UNK league_season_setup;
extern M2C_UNK func_80065860;
extern M2C_UNK streamStepCountdown;
extern M2C_UNK select_step_next;
extern M2C_UNK func_80065E40;
extern M2C_UNK func_80065F28;
extern M2C_UNK func_80065F9C;
extern M2C_UNK init_stage_screen;
extern M2C_UNK func_8006632C;
extern M2C_UNK func_80066384;
extern M2C_UNK select_shutdown_pending_stub;
extern M2C_UNK select_arm_first_entry;
extern M2C_UNK select_reset_flags;
extern M2C_UNK select_start_race;
extern M2C_UNK func_8006AFC0;
extern M2C_UNK func_8006B02C;
extern M2C_UNK stream_slot_select_prev;
extern M2C_UNK func_8006B150;
extern M2C_UNK func_8006B220;
extern M2C_UNK stream_slot_advance;
extern M2C_UNK func_8006B380;
extern M2C_UNK func_8006B410;
extern M2C_UNK func_8006B4A4;
extern M2C_UNK select_pick_next_state;
extern M2C_UNK func_8006B664;
extern M2C_UNK select_set_flag_return1;
extern M2C_UNK func_8007A01C;
extern M2C_UNK select_state_init_hooks;
extern M2C_UNK func_8007AAFC;
extern M2C_UNK func_8007AC68;
extern M2C_UNK func_8007ACE0;
extern M2C_UNK func_8007AD68;
extern M2C_UNK func_8007B0B8;

extern void *gLeague;
extern void *gRecords;
extern s32 gRaceState;
void select_setup_league_hooks(void) {
    M2C_UNK var_a2;
    M2C_UNK var_a3;
    u16 temp_v1;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1_2;
    void *temp_v1_3;
    void *manager;
    void *manager0;
    void *state;
    void *config;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        temp_s0 = (u8 *)&gOrderState + 0x5558;
        streamOpenPath(temp_s0, &D_800A56B0);
        start_track_voices(temp_s0);
        voicesSetIdleValue((s32) (M2C_FIELD(&stream_state, f32 *, 0x3332) * 112.0f));
    }
    temp_v1 = M2C_FIELD(gRecords, u16 *, 0x1E);
    if (((temp_v1 >= 5U) | (temp_v1 == 0)) != 0) {
        M2C_FIELD(gRecords, u16 *, 0x1E) = 1U;
    }
    M2C_FIELD(gSelectState, s8 *, 0x245) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x228) = 0;
    league_set_hook(gLeague, 0, 0x10, &select_state_init_hooks);
    league_set_hook(gLeague, 1, 0x10, &func_8005E360);
    league_set_hook(gLeague, 2, 0x10, &select_install_league_callback);
    league_set_hook(gLeague, 3, 0x10, &select_menu_setup);
    league_set_hook_entry(gLeague, 0, 0x20, &select_menu_setup);
    func_8008A104(gLeague, 8, 1, 1);
    league_set_hook(gLeague, 8, 2, &select_step_next);
    league_set_hook(gLeague, 8, 1, &streamStepCountdown);
    league_set_hook(gLeague, 8, 0x20, &func_80065F28);
    league_set_hook_entry(gLeague, 1, 0x20, &func_80064F04);
    if (M2C_FIELD(gRecords, u16 *, 0x2C) & 0x100) {
        func_8008A104(gLeague, 0xD, 1, 1);
    } else {
        func_8008A104(gLeague, 0xD, 0, 0);
    }
    league_set_hook(gLeague, 0xD, 2, &select_step_next);
    league_set_hook(gLeague, 0xD, 1, &streamStepCountdown);
    league_set_hook(gLeague, 0xD, 0x10, &func_80065E40);
    league_set_hook(gLeague, 0xD, 0x20, &func_80065F28);
    league_set_hook_entry(gLeague, 2, 0x20, &func_80065F9C);
    league_set_hook(gLeague, 0xE, 0x10, &func_8006632C);
    league_set_hook(gLeague, 0xF, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x10, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x11, 0x10, &select_arm_first_entry);
    league_set_hook(gLeague, 0x12, 0x10, &select_reset_flags);
    league_set_hook(gLeague, 0x13, 0x10, &select_start_race);
    league_set_hook(gLeague, 0x14, 4, &func_8006AFC0);
    league_set_hook(gLeague, 0x14, 8, &func_8006AFC0);
    league_set_hook(gLeague, 0x15, 4, &stream_slot_select_prev);
    league_set_hook(gLeague, 0x15, 8, &func_8006B02C);
    league_set_hook(gLeague, 0x16, 4, &func_8006B150);
    league_set_hook(gLeague, 0x16, 8, &func_8006B220);
    league_set_hook(gLeague, 0x17, 4, &func_8006B380);
    league_set_hook(gLeague, 0x17, 8, &stream_slot_advance);
    league_set_hook(gLeague, 0x18, 4, &func_8006B4A4);
    league_set_hook(gLeague, 0x18, 8, &func_8006B410);
    league_set_hook(gLeague, 0x19, 0x10, &select_pick_next_state);
    league_set_hook_entry(gLeague, 4, 0x20, &select_pick_next_state);
    league_set_hook(gLeague, 0x1A, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x1B, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x1C, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x1D, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x1B, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1B, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1A, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1A, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1C, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1C, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1D, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1D, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x1E, 1, &func_8007AC68);
    league_set_hook(gLeague, 0x1E, 2, &func_8007ACE0);
    league_set_hook(gLeague, 0x1E, 0x10, &func_8007AD68);
    league_set_hook(gLeague, 0x1E, 0x20, &func_8007B0B8);
    league_set_hook_entry(gLeague, 5, 0x20, &func_8007A01C);
    M2C_FIELD(gSelectState, s8 *, 0x22F) = 0;
    if (M2C_FIELD(&stream_state, u8 *, 0x5D56) == 4) {
        temp_v1_2 = M2C_FIELD(gLeague, void **, 0x10);
        M2C_FIELD(gLeague, s16 *, 2) = 0;
        M2C_FIELD(temp_v1_2, u8 *, 0xE) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0xD);
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80064E48;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &hud_draw_counter_text;
        return;
    }
    if (((gRaceState == 5) | (gRaceState == 2)) != 0) {
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80064E48;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &hud_draw_counter_text;
        return;
    }
    if (gRaceState == 0) {
        state = gSelectState;
        manager0 = gLeague;
        M2C_FIELD(state, M2C_UNK **, 0x288) = &init_stage_screen;
        M2C_FIELD(state, M2C_UNK **, 0x28C) = &func_80066384;
        M2C_FIELD(state, M2C_UNK **, 0x290) = &select_shutdown_pending_stub;
        temp_v1_3 = M2C_FIELD(manager0, void **, 0x10);
        M2C_FIELD(manager0, s16 *, 2) = 3;
        M2C_FIELD(temp_v1_3, u8 *, 0x4A) = (u8) M2C_FIELD(temp_v1_3, u8 *, 0x49);
        return;
    } else if (gRaceState == 3) {
        state = gSelectState;
        manager = gLeague;
        M2C_FIELD(state, M2C_UNK **, 0x288) = &league_season_setup;
        M2C_FIELD(state, M2C_UNK **, 0x28C) = &func_80065860;
        temp_a0 = M2C_FIELD(manager, void **, 0x10);
        config = gRecords;
        M2C_FIELD(manager, s16 *, 2) = 2;
        M2C_FIELD(temp_a0, s8 *, 0x36) = (s8) (M2C_FIELD(temp_a0, u8 *, 0x35) + M2C_FIELD(config, u8 *, 0x21));
        return;
    }
}
