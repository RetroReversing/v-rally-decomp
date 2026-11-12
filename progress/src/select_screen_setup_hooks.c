extern u16 D_800D0628; extern s32 gRaceState;
typedef struct Menu {u16 pad,state; u8 pad4[12]; u8 *entries;} Menu;
typedef struct State {u8 pad[0x228]; u8 a228; u8 pad229[6]; u8 a22f; u8 pad230[0x15]; u8 a245; u8 pad246[0x42]; void *fn288,*fn28c,*fn290;} State;
extern void *gRecords; extern Menu *gLeague;
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
M2C_UNK record_set_byte9(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8008A104(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK league_set_hook(void *, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK league_set_hook_entry(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 gRaceFlags;
extern State *gSelectState;
extern s8 gStreamPhase;
extern M2C_UNK D_800A5CD0;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;
extern M2C_UNK select_menu_setup;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_8006AFC0;
extern M2C_UNK func_8006B02C;
extern M2C_UNK stream_slot_select_prev;
extern M2C_UNK func_8006B150;
extern M2C_UNK func_8006B220;
extern M2C_UNK stream_slot_advance;
extern M2C_UNK func_8006B380;
extern M2C_UNK func_8006B410;
extern M2C_UNK func_8006B4A4;
extern M2C_UNK func_8006B664;
extern M2C_UNK func_80070630;
extern M2C_UNK func_80070750;
extern M2C_UNK func_800707D0;
extern M2C_UNK func_8007081C;
extern M2C_UNK InitSelectHandlers;
extern M2C_UNK select_setup_callbacks;
extern M2C_UNK func_800708F4;
extern M2C_UNK select_refresh_entry;
extern M2C_UNK select_enter_refresh_state;
extern M2C_UNK select_install_refresh_callback;
extern M2C_UNK func_80070BC8;
extern M2C_UNK finish_race_results;
extern M2C_UNK select_init_first_entry;
extern M2C_UNK func_80070FE4;
extern M2C_UNK select_state_reset_b;
extern M2C_UNK race_save_and_reset;
extern M2C_UNK best_times_select_update;
extern M2C_UNK func_800718F4;
extern M2C_UNK func_80071978;
extern M2C_UNK func_80071A0C;
extern M2C_UNK func_80071A48;
extern M2C_UNK func_80071B3C;
extern M2C_UNK func_80071E08;
extern M2C_UNK select_mark_refresh;
extern M2C_UNK func_80071E74;
extern M2C_UNK select_screen_enter;
extern M2C_UNK select_save_and_enter;
extern M2C_UNK select_setup_handlers;
extern M2C_UNK func_80072018;
extern M2C_UNK func_80072090;
extern M2C_UNK select_init_handlers;
extern M2C_UNK func_80072364;
extern M2C_UNK selectEnterPhase3;
extern M2C_UNK func_800724A4;
extern M2C_UNK func_80072984;
extern M2C_UNK select_set_flag_return1;
extern M2C_UNK func_8007A01C;
extern M2C_UNK func_8007AAFC;
extern M2C_UNK func_8007AC68;
extern M2C_UNK func_8007ACE0;
extern M2C_UNK func_8007AD68;
extern M2C_UNK func_8007B0B8;

/* Sets up the select screen: starts the track voices once, registers the league menu hooks, then picks the next select state from the race state. */ void select_screen_setup_hooks(void) {
    s32 pad[2];
    M2C_UNK var_a2;
    M2C_UNK var_a3;
    u32 var_s0;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        temp_s0 = (char *)&gOrderState + 0x5558;
        streamOpenPath(temp_s0, &D_800A5CD0);
        start_track_voices(temp_s0);
        voicesSetIdleValue((s32) (M2C_FIELD(&stream_state, f32 *, 0x3332) * 112.0f));
    }
    { void *settings = gRecords; State *st=gSelectState;
    M2C_FIELD(settings,s16*,0x1e)=5;
    st->a245=0; }
    gSelectState->a228 = 0;
    league_set_hook(gLeague, 0, 0x10, &select_install_refresh_callback);
    league_set_hook(gLeague, 1, 0x10, &select_enter_refresh_state);
    league_set_hook(gLeague, 2, 8, &func_800707D0);
    league_set_hook(gLeague, 2, 4, &func_800707D0);
    league_set_hook(gLeague, 3, 0x10, &select_setup_callbacks);
    league_set_hook(gLeague, 4, 0x10, &select_menu_setup);
    league_set_hook_entry(gLeague, 0, 0x20, &select_menu_setup);
    record_set_byte9(gLeague, 2, 0);
    league_set_hook(gLeague, 5, 0x10, &func_800708F4);
    league_set_hook(gLeague, 7, 8, &func_8007081C);
    league_set_hook(gLeague, 7, 4, &func_8007081C);
    league_set_hook(gLeague, 6, 0x10, &func_8005E360);
    league_set_hook(gLeague, 8, 0x10, &InitSelectHandlers);
    league_set_hook_entry(gLeague, 1, 0x20, &InitSelectHandlers);
    league_set_hook_entry(gLeague, 2, 0x20, &func_80070BC8);
    if (M2C_FIELD(gRecords,u16 *,0x2c)&0x200) func_8008A104(gLeague,0x21,1,1); else func_8008A104(gLeague,0x21,0,0);
    var_s0=0;
    league_set_hook(gLeague, 0x21, 2, &func_80071978);
    league_set_hook(gLeague, 0x21, 1, &func_800718F4);
    league_set_hook(gLeague, 0x21, 0x10, &select_setup_handlers);
    league_set_hook(gLeague, 0x21, 0x20, &func_80071A0C);
    if (D_800D0628 != 0) {
        do {
            league_set_hook(gLeague, (var_s0 + 0x15) & 0xFFFF, 0x10, &func_80071A48);
            var_s0 += 1;
        } while (var_s0 < (u16) D_800D0628);
    }
    league_set_hook(gLeague, 0x22, 0x10, &func_80070FE4);
    league_set_hook(gLeague, 0x23, 0x10, &select_state_reset_b);
    league_set_hook(gLeague, 0x24, 0x10, &race_save_and_reset);
    league_set_hook_entry(gLeague, 3, 0x20, &select_init_first_entry);
    league_set_hook(gLeague, 0x25, 0x10, &func_80072018);
    league_set_hook(gLeague, 0x26, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x27, 0x10, &func_8006B664);
    league_set_hook(gLeague, 0x28, 0x10, &selectEnterPhase3);
    league_set_hook(gLeague, 0x29, 0x10, &select_mark_refresh);
    league_set_hook(gLeague, 0x2A, 0x10, &func_80071E74);
    league_set_hook(gLeague, 0x2B, 0x10, &select_screen_enter);
    league_set_hook(gLeague, 0x2C, 0x10, &select_save_and_enter);
    league_set_hook(gLeague, 0x2D, 4, &func_8006AFC0);
    league_set_hook(gLeague, 0x2D, 8, &func_8006AFC0);
    league_set_hook(gLeague, 0x2E, 4, &stream_slot_select_prev);
    league_set_hook(gLeague, 0x2E, 8, &func_8006B02C);
    league_set_hook(gLeague, 0x2F, 4, &func_8006B150);
    league_set_hook(gLeague, 0x2F, 8, &func_8006B220);
    league_set_hook(gLeague, 0x30, 4, &func_8006B380);
    league_set_hook(gLeague, 0x30, 8, &stream_slot_advance);
    league_set_hook(gLeague, 0x31, 4, &func_8006B4A4);
    league_set_hook(gLeague, 0x31, 8, &func_8006B410);
    league_set_hook(gLeague, 0x32, 0x10, &select_init_handlers);
    league_set_hook_entry(gLeague, 6, 0x20, &select_init_handlers);
    league_set_hook_entry(gLeague, 5, 0x10, &func_80072090);
    league_set_hook(gLeague, 0x33, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x34, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x35, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x36, 0x10, &func_8007AAFC);
    league_set_hook(gLeague, 0x34, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x34, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x33, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x33, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x35, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x35, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x36, 1, &select_set_flag_return1);
    league_set_hook(gLeague, 0x36, 2, &select_set_flag_return1);
    league_set_hook(gLeague, 0x37, 1, &func_8007AC68);
    league_set_hook(gLeague, 0x37, 2, &func_8007ACE0);
    league_set_hook(gLeague, 0x37, 0x10, &func_8007AD68);
    league_set_hook(gLeague, 0x37, 0x20, &func_8007B0B8);
    league_set_hook_entry(gLeague, 7, 0x20, &func_8007A01C);
    gSelectState->a22f = 0;
    if (M2C_FIELD(&stream_state, u8 *, 0x5D56) == 4) {
        temp_a0 = gLeague->entries;
        gLeague->state = 1;
        M2C_FIELD(temp_a0, u8 *, 0x22) = (u8) M2C_FIELD(temp_a0, u8 *, 0x21);
        gSelectState->fn288 = &select_refresh_entry;
        return;
    }
    { s32 state=gRaceState;
    if(state==5) {
        { void *settings=gRecords; State *st=gSelectState;
        M2C_FIELD(settings,s16*,0x20)=0;
        st->fn288 = &func_80070630;
        st->fn28c = &func_80070750; }
        return;
    } else if(state==3) {
        { void *settings=gRecords;
        u8 val=M2C_FIELD(&stream_state,u8*,0x7F50);
        State *st=gSelectState; Menu *menu=gLeague;
        M2C_FIELD(settings,s16*,0x20)=val;
        st->fn288 = &func_800724A4;
        st->fn28c = &func_80072984;
        temp_v1 = menu->entries;
        menu->state = 5;
        M2C_FIELD(temp_v1, u8 *, 0x72) = (u8) M2C_FIELD(temp_v1, u8 *, 0x71);
        } return;
    } else if(state==0) {
        gSelectState->fn288 = &func_80071B3C;
        gSelectState->fn290 = &func_80071E08;
        gSelectState->fn28c = &func_80072364;
        temp_v1_2 = gLeague->entries;
        gLeague->state = 4;
        M2C_FIELD(temp_v1_2, u8 *, 0x5E) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0x5D);
        gStreamPhase = 0;
        return;
    } else if(state==2) {
        gSelectState->fn288 = &finish_race_results;
        gSelectState->fn28c = &best_times_select_update;
        temp_v1_3 = gLeague->entries;
        gLeague->state = 3;
        M2C_FIELD(temp_v1_3, u8 *, 0x4A) = (u8) M2C_FIELD(temp_v1_3, u8 *, 0x49);
        return;
    } }
}
