/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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
M2C_UNK league_set_hook(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK league_set_hook_entry(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 gRaceFlags;
extern void *gSelectState;
extern M2C_UNK D_800A5670;
extern u8 gOrderState[];
extern u8 stream_state[];
extern M2C_UNK select_menu_setup;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_80062B70;
extern M2C_UNK func_80062C48;
extern M2C_UNK stepStreamSlot;
extern M2C_UNK slot_update_selection;
extern M2C_UNK func_80062D6C;
extern M2C_UNK func_80062DF4;
extern M2C_UNK func_80063104;
extern M2C_UNK func_800631A4;
extern M2C_UNK select_install_callbacks;
extern M2C_UNK select_setup_slot;
extern M2C_UNK func_80063C60;
extern M2C_UNK record_cycle_next_option;
extern M2C_UNK func_80063EC8;
extern M2C_UNK select_state_reset;
extern M2C_UNK select_init_flags;
extern M2C_UNK select_reset_entries;
extern M2C_UNK func_800642F8;
extern M2C_UNK select_exit_to_race;
extern M2C_UNK func_800643F0;
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

extern s32 gLeague;
extern u16 D_800D061E;
/* Sets up the track-select screen: starts the order stream once, clears select-state flags and registers the league hook table that routes each menu event to its handler. */ void select_screen_init(void) {
    u8 unused_buf[16];
    u32 i;
    u32 j;
    void *stream_buf;
    void *sel_state;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        stream_buf = gOrderState + 0x5558;
        streamOpenPath(stream_buf, &D_800A5670);
        start_track_voices(stream_buf);
        voicesSetIdleValue((s32) (M2C_FIELD(stream_state, f32 *, 0x3332) * 112.0f));
    }
    sel_state = gSelectState;
    M2C_FIELD(M2C_FIELD(stream_state, void **, 0x32F2), s16 *, 0x1E) = 0;
    M2C_FIELD(sel_state, s8 *, 0x245) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x23B) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x23A) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x228) = 0;
    league_set_hook(gLeague, 0, 0x10, &select_state_init_hooks);
    league_set_hook(gLeague, 4, 0x10, &select_install_callbacks);
    league_set_hook(gLeague, 1, 0x10, &func_8005E360);
    league_set_hook(gLeague, 2, 8, &func_80062C48);
    league_set_hook(gLeague, 2, 4, &stepStreamSlot);
    league_set_hook(gLeague, 3, 8, &slot_update_selection);
    league_set_hook(gLeague, 3, 4, &func_80062D6C);
    league_set_hook(gLeague, 5, 0x10, &select_menu_setup);
    league_set_hook_entry(gLeague, 0, 0x20, &select_menu_setup);
    i = 0;
    if (D_800D061E != 0) {
        do {
            league_set_hook(gLeague, (i + 6) & 0xFFFF, 0x10, &select_setup_slot);
            i += 1;
        } while (i < (u16) D_800D061E);
    }
    league_set_hook(gLeague, 0xE, 2, &record_cycle_next_option);
    league_set_hook(gLeague, 0xE, 1, &func_80063C60);
    league_set_hook(gLeague, 0xE, 0x20, &select_state_reset);
    league_set_hook_entry(gLeague, 1, 0x20, &func_800631A4);
    j = 0;
    if (D_800D061E != 0) {
        do {
            league_set_hook(gLeague, (j + 0xF) & 0xFFFF, 0x10, &select_setup_slot);
            j += 1;
        } while (j < (u16) D_800D061E);
    }
    league_set_hook(gLeague, 0x17, 2, &record_cycle_next_option);
    league_set_hook(gLeague, 0x17, 1, &func_80063C60);
    league_set_hook(gLeague, 0x17, 0x10, &func_80063EC8);
    league_set_hook(gLeague, 0x17, 0x20, &select_state_reset);
    league_set_hook_entry(gLeague, 2, 0x20, &func_80063104);
    league_set_hook(gLeague, 0x18, 0x10, &func_800643F0);
    league_set_hook(gLeague, 0x19, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x1A, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x1B, 0x10, &select_exit_to_race);
    league_set_hook(gLeague, 0x1B, 0x10, &select_init_flags);
    league_set_hook(gLeague, 0x1C, 0x10, &select_reset_entries);
    league_set_hook(gLeague, 0x1D, 0x10, &func_800642F8);
    league_set_hook_entry(gLeague, 3, 0x20, &select_exit_to_race);
    league_set_hook(gLeague, 0x1E, 4, &func_8006AFC0);
    league_set_hook(gLeague, 0x1E, 8, &func_8006AFC0);
    league_set_hook(gLeague, 0x1F, 4, &stream_slot_select_prev);
    league_set_hook(gLeague, 0x1F, 8, &func_8006B02C);
    league_set_hook(gLeague, 0x20, 4, &func_8006B150);
    league_set_hook(gLeague, 0x20, 8, &func_8006B220);
    league_set_hook(gLeague, 0x21, 4, &func_8006B380);
    league_set_hook(gLeague, 0x21, 8, &stream_slot_advance);
    league_set_hook(gLeague, 0x22, 4, &func_8006B4A4);
    league_set_hook(gLeague, 0x22, 8, &func_8006B410);
    league_set_hook(gLeague, 0x23, 0x10, &select_pick_next_state);
    league_set_hook_entry(gLeague, 4, 0x20, &select_pick_next_state);
    league_set_hook(gLeague, 0x24, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x25, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x26, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x27, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x25, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x25, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x24, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x24, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x26, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x26, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x27, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x27, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x28, 1, &func_8007AC68);
    league_set_hook(gLeague, 0x28, 2, &func_8007ACE0);
    league_set_hook(gLeague, 0x28, 0x10, &func_8007AD68);
    league_set_hook(gLeague, 0x28, 0x20, &func_8007B0B8);
    league_set_hook_entry(gLeague, 5, 0x20, &func_8007A01C);
    M2C_FIELD(gSelectState, s8 *, 0x22F) = 0;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80062B70;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_80062DF4;
}
