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

M2C_UNK func_8000DA84();                            /* extern */
M2C_UNK streamOpenPath(void *, M2C_UNK *);           /* extern */
M2C_UNK start_track_voices(void *);                      /* extern */
M2C_UNK voicesSetIdleParams(M2C_UNK);                     /* extern */
M2C_UNK voicesSetIdleValue(s32);                         /* extern */
M2C_UNK func_8008A1CC(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 gRaceFlags;
extern void *gSelectState;
extern M2C_UNK D_800A5670;
extern u8 gOrderState[];
extern u8 gStreamState[];
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
extern M2C_UNK func_80063224;
extern M2C_UNK select_setup_slot;
extern M2C_UNK func_80063C60;
extern M2C_UNK record_cycle_next_option;
extern M2C_UNK func_80063EC8;
extern M2C_UNK select_state_reset;
extern M2C_UNK func_80064278;
extern M2C_UNK func_800642B8;
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
extern M2C_UNK func_8006B534;
extern M2C_UNK func_8006B664;
extern M2C_UNK func_8007A004;
extern M2C_UNK func_8007A01C;
extern M2C_UNK select_state_init_hooks;
extern M2C_UNK func_8007AAFC;
extern M2C_UNK func_8007AC68;
extern M2C_UNK func_8007ACE0;
extern M2C_UNK func_8007AD68;
extern M2C_UNK func_8007B0B8;

extern s32 gLeague;
extern u16 D_800D061E;
void func_80062404(void) {
    u8 scratch[16];
    u32 var_s0;
    u32 var_s0_2;
    void *temp_s0;
    void *state;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        func_8000DA84();
        temp_s0 = gOrderState + 0x5558;
        streamOpenPath(temp_s0, &D_800A5670);
        start_track_voices(temp_s0);
        voicesSetIdleValue((s32) (M2C_FIELD(gStreamState, f32 *, 0x3332) * 112.0f));
    }
    state = gSelectState;
    M2C_FIELD(M2C_FIELD(gStreamState, void **, 0x32F2), s16 *, 0x1E) = 0;
    M2C_FIELD(state, s8 *, 0x245) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x23B) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x23A) = 0;
    M2C_FIELD(gSelectState, s8 *, 0x228) = 0;
    func_8008A1CC(gLeague, 0, 0x10, &select_state_init_hooks);
    func_8008A1CC(gLeague, 4, 0x10, &func_80063224);
    func_8008A1CC(gLeague, 1, 0x10, &func_8005E360);
    func_8008A1CC(gLeague, 2, 8, &func_80062C48);
    func_8008A1CC(gLeague, 2, 4, &stepStreamSlot);
    func_8008A1CC(gLeague, 3, 8, &slot_update_selection);
    func_8008A1CC(gLeague, 3, 4, &func_80062D6C);
    func_8008A1CC(gLeague, 5, 0x10, &select_menu_setup);
    func_8008A290(gLeague, 0, 0x20, &select_menu_setup);
    var_s0 = 0;
    if (D_800D061E != 0) {
        do {
            func_8008A1CC(gLeague, (var_s0 + 6) & 0xFFFF, 0x10, &select_setup_slot);
            var_s0 += 1;
        } while (var_s0 < (u16) D_800D061E);
    }
    func_8008A1CC(gLeague, 0xE, 2, &record_cycle_next_option);
    func_8008A1CC(gLeague, 0xE, 1, &func_80063C60);
    func_8008A1CC(gLeague, 0xE, 0x20, &select_state_reset);
    func_8008A290(gLeague, 1, 0x20, &func_800631A4);
    var_s0_2 = 0;
    if (D_800D061E != 0) {
        do {
            func_8008A1CC(gLeague, (var_s0_2 + 0xF) & 0xFFFF, 0x10, &select_setup_slot);
            var_s0_2 += 1;
        } while (var_s0_2 < (u16) D_800D061E);
    }
    func_8008A1CC(gLeague, 0x17, 2, &record_cycle_next_option);
    func_8008A1CC(gLeague, 0x17, 1, &func_80063C60);
    func_8008A1CC(gLeague, 0x17, 0x10, &func_80063EC8);
    func_8008A1CC(gLeague, 0x17, 0x20, &select_state_reset);
    func_8008A290(gLeague, 2, 0x20, &func_80063104);
    func_8008A1CC(gLeague, 0x18, 0x10, &func_800643F0);
    func_8008A1CC(gLeague, 0x19, 0x10, &func_8006B664);
    func_8008A1CC(gLeague, 0x1A, 0x10, &func_8006B664);
    func_8008A1CC(gLeague, 0x1B, 0x10, &select_exit_to_race);
    func_8008A1CC(gLeague, 0x1B, 0x10, &func_80064278);
    func_8008A1CC(gLeague, 0x1C, 0x10, &func_800642B8);
    func_8008A1CC(gLeague, 0x1D, 0x10, &func_800642F8);
    func_8008A290(gLeague, 3, 0x20, &select_exit_to_race);
    func_8008A1CC(gLeague, 0x1E, 4, &func_8006AFC0);
    func_8008A1CC(gLeague, 0x1E, 8, &func_8006AFC0);
    func_8008A1CC(gLeague, 0x1F, 4, &stream_slot_select_prev);
    func_8008A1CC(gLeague, 0x1F, 8, &func_8006B02C);
    func_8008A1CC(gLeague, 0x20, 4, &func_8006B150);
    func_8008A1CC(gLeague, 0x20, 8, &func_8006B220);
    func_8008A1CC(gLeague, 0x21, 4, &func_8006B380);
    func_8008A1CC(gLeague, 0x21, 8, &stream_slot_advance);
    func_8008A1CC(gLeague, 0x22, 4, &func_8006B4A4);
    func_8008A1CC(gLeague, 0x22, 8, &func_8006B410);
    func_8008A1CC(gLeague, 0x23, 0x10, &func_8006B534);
    func_8008A290(gLeague, 4, 0x20, &func_8006B534);
    func_8008A1CC(gLeague, 0x24, 0x10, &func_8007AAFC);
    func_8008A1CC(gLeague, 0x25, 0x10, &func_8007AAFC);
    func_8008A1CC(gLeague, 0x26, 0x10, &func_8007AAFC);
    func_8008A1CC(gLeague, 0x27, 0x10, &func_8007AAFC);
    func_8008A1CC(gLeague, 0x25, 2, &func_8007A004);
    func_8008A1CC(gLeague, 0x25, 1, &func_8007A004);
    func_8008A1CC(gLeague, 0x24, 2, &func_8007A004);
    func_8008A1CC(gLeague, 0x24, 1, &func_8007A004);
    func_8008A1CC(gLeague, 0x26, 1, &func_8007A004);
    func_8008A1CC(gLeague, 0x26, 2, &func_8007A004);
    func_8008A1CC(gLeague, 0x27, 1, &func_8007A004);
    func_8008A1CC(gLeague, 0x27, 2, &func_8007A004);
    func_8008A1CC(gLeague, 0x28, 1, &func_8007AC68);
    func_8008A1CC(gLeague, 0x28, 2, &func_8007ACE0);
    func_8008A1CC(gLeague, 0x28, 0x10, &func_8007AD68);
    func_8008A1CC(gLeague, 0x28, 0x20, &func_8007B0B8);
    func_8008A290(gLeague, 5, 0x20, &func_8007A01C);
    M2C_FIELD(gSelectState, s8 *, 0x22F) = 0;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_80062B70;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_80062DF4;
}
