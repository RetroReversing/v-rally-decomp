typedef struct {char b[5];} Copy5;
typedef struct {char b[10];} Copy10;
extern void *gLeague,*gRecords;
extern s32 D_800C6880,D_800C8118;
extern f32 gSpeedAccum;
extern u8 D_800B3DA8[];
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
void league_set_hook(void *,s32,s32,void (*)(void)); /* extern */
M2C_UNK setRecordSlotValue(void *, M2C_UNK, s32);        /* extern */
void league_set_hook_entry(void *,s32,s32,void (*)(void)); /* extern */
extern s32 gRecordTimeScale;
extern s32 gRaceFlags;
extern u8 gSelectResetPending;
extern u8 gSelectResetFlag;
extern u8 select_reset_requested;
extern void *gSelectState;
extern u8 D_800A14D4;
extern M2C_UNK D_800A5384;
extern M2C_UNK D_800A538C;
extern M2C_UNK D_800A5398;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;
void func_8005D844(void);
void func_8005D84C(void);
void select_league_hud_setup(void);
void results_draw_record_panel_entry(void);
void select_league_reset(void);
void func_8005D8B0(void);
void func_8005D958(void);
void func_8005D96C(void);
void select_reset_text_state(void);
void func_8005DC40(void);
void func_8005DD2C(void);
void enterSelectState(void);
void select_reset_session(void);
void select_arm_reset_state(void);
void select_reset_requests(void);
void selectInitDefault(void);
void func_8005E2F0(void);
void select_reset_with_flags(void);
void func_8005E49C(void);
void select_reset_request_cb(void);
void select_reset_screen(void);
void select_clear_reset_flag(void);
void slot_select_prev(void);
void func_8005E8B0(void);
void func_8005E928(void);
void selectSetCallbacks(void);
void func_8005F050(void);
void func_8005F0A4(void);
void func_8005F0F8(void);
void select_clamp_speed_cb(void);
void stream_ramp_step(void);
void select_clamp_speed_alt_cb(void);
void func_8005F188(void);
void func_8005F1D4(void);
void slot_cycle_selection(void);
void func_8005F258(void);
void func_8005F290(void);
void selectStepBack(void);
void select_toggle_slots(void);
void select_reset_defaults(void);
void func_8005F430(void);
void func_8005F460(void);
void func_8005F53C(void);
void select_label_state_enter(void);
void select_hook_callbacks(void);
void streamToggleSelection(void);
void toggle_sel_flag(void);
void func_8005FE80(void);
void toggleStreamFlag200(void);
void func_8005FF20(void);
void func_8005FF70(void);
void func_8005FFE0(void);
void func_80060054(void);
void stream_update_car_mask(void);
void func_80060178(void);
void func_800601B4(void);
void toggle_slot_sel_bit4(void);
void func_80060254(void);
void func_800602A4(void);

/* Sets up the league select screen: configures the timers and button hooks on gLeague, then either handles a pending reset or starts the select state machine. */ void select_league_setup(void) {
    s32 var_a2;
    s32 var_a2_2;
    void *league_sub;
    void *unused_state;
    void *stream_buf;

    *(s32*)0x800B6880 = 5;
    D_800C8118 = (s32) (gRecordTimeScale * 3);
    setRecordSlotValue(gLeague, 0, gRecordTimeScale * 8);
    league_set_hook_entry(gLeague, 0, 0x10, &func_8005D958);
    league_set_hook_entry(gLeague, 0, 0x10000, &func_8005D96C);
    setRecordSlotValue(gLeague, 3, gRecordTimeScale * 0x3C);
    league_set_hook(gLeague, 0, 0x10, &func_8005E49C);
    league_set_hook(gLeague, 1, 0x10, &func_8005E49C);
    league_set_hook(gLeague, 2, 0x10, &func_8005E49C);
    league_set_hook_entry(gLeague, 3, 0x10000, &func_8005E49C);
    setRecordSlotValue(gLeague, 1, gRecordTimeScale * 0x2D);
    league_set_hook_entry(gLeague, 1, 0x10000, &select_reset_request_cb);
    if (!(M2C_FIELD(gRecords, u16 *, 0x2C) & 0x20)) {
        setRecordSlotValue(gLeague,4,gRecordTimeScale*30);
    } else {
        setRecordSlotValue(gLeague,4,gRecordTimeScale*2);
    }
    league_set_hook_entry(gLeague, 4, 0x10000, &select_reset_screen);
    league_set_hook_entry(gLeague, 4, 0x10, &select_reset_screen);
    setRecordSlotValue(gLeague, 5, 1);
    league_set_hook_entry(gLeague, 5, 0x10000, &select_clear_reset_flag);
    setRecordSlotValue(gLeague, 6, 3);
    league_set_hook_entry(gLeague, 6, 0x10000, &enterSelectState);
    league_set_hook_entry(gLeague, 6, 0x10, &enterSelectState);
    setRecordSlotValue(gLeague, 7, 3);
    league_set_hook_entry(gLeague, 7, 0x10000, &select_reset_session);
    setRecordSlotValue(gLeague, 2, gRecordTimeScale * 0x1E);
    league_set_hook_entry(gLeague, 2, 0x10000, &select_reset_text_state);
    league_set_hook_entry(gLeague, 2, 0x10, &select_reset_text_state);
    if (!(M2C_FIELD(gRecords, u16 *, 0x2C) & 0x20)) {
        setRecordSlotValue(gLeague,8,gRecordTimeScale*60);
    } else {
        setRecordSlotValue(gLeague,8,gRecordTimeScale*2);
    }
    league_set_hook_entry(gLeague, 8, 0x10000, &select_arm_reset_state);
    league_set_hook(gLeague, 4, 0x10, &selectInitDefault);
    league_set_hook(gLeague, 6, 0x10, &func_8005E2F0);
    league_set_hook(gLeague, 5, 0x10, &select_reset_with_flags);
    league_set_hook(gLeague, 8, 0x10, &selectSetCallbacks);
    league_set_hook(gLeague, 9, 0x10, &select_hook_callbacks);
    league_set_hook(gLeague, 7, 4, &slot_select_prev);
    league_set_hook(gLeague, 7, 8, &func_8005E8B0);
    league_set_hook(gLeague, 0xA, 8, &slot_cycle_selection);
    league_set_hook(gLeague, 0xA, 4, &func_8005F258);
    league_set_hook(gLeague, 0x10, 8, &func_8005F1D4);
    league_set_hook(gLeague, 0x10, 4, &func_8005F1D4);
    league_set_hook(gLeague, 0xB, 8, &func_8005F188);
    league_set_hook(gLeague, 0xB, 4, &func_8005F188);
    league_set_hook(gLeague, 0xC, 8, &func_8005F050);
    league_set_hook(gLeague, 0xC, 4, &func_8005F0A4);
    league_set_hook(gLeague, 0xD, 8, &func_8005F0F8);
    league_set_hook(gLeague, 0xD, 4, &select_clamp_speed_cb);
    league_set_hook(gLeague, 0xE, 8, &stream_ramp_step);
    league_set_hook(gLeague, 0xE, 4, &select_clamp_speed_alt_cb);
    league_set_hook(gLeague, 0xF, 4, &selectStepBack);
    league_set_hook(gLeague, 0xF, 8, &func_8005F290);
    league_set_hook(gLeague, 0x11, 4, &select_toggle_slots);
    league_set_hook(gLeague, 0x11, 8, &select_toggle_slots);
    league_set_hook(gLeague, 0x12, 0x10, &select_label_state_enter);
    league_set_hook(gLeague, 0x13, 0x10, &select_reset_defaults);
    league_set_hook(gLeague, 0x15, 0x10, &func_8005F430);
    league_set_hook(gLeague, 0x15, 0x20, &func_8005F430);
    league_set_hook(gLeague, 0x16, 0x10, &func_8005F460);
    league_set_hook(gLeague, 0x16, 0x20, &func_8005F430);
    league_set_hook(gLeague, 0x14, 0x10, &func_8005E928);
    league_set_hook_entry(gLeague, 9, 0x20, &func_8005E928);
    league_set_hook_entry(gLeague, 0xB, 0x20, &func_8005F53C);
    league_set_hook(gLeague, 0x18, 8, &streamToggleSelection);
    league_set_hook(gLeague, 0x18, 4, &streamToggleSelection);
    league_set_hook(gLeague, 0x19, 8, &func_8005FE80);
    league_set_hook(gLeague, 0x19, 4, &func_8005FE80);
    league_set_hook(gLeague, 0x17, 8, &toggleStreamFlag200);
    league_set_hook(gLeague, 0x17, 4, &toggleStreamFlag200);
    league_set_hook(gLeague, 0x1A, 8, &func_8005FF20);
    league_set_hook(gLeague, 0x1A, 4, &func_8005FF20);
    league_set_hook(gLeague, 0x1B, 8, &func_8005FF70);
    league_set_hook(gLeague, 0x1B, 4, &func_8005FFE0);
    league_set_hook(gLeague, 0x1C, 8, &func_80060054);
    league_set_hook(gLeague, 0x1C, 4, &stream_update_car_mask);
    league_set_hook(gLeague, 0x1D, 8, &func_80060178);
    league_set_hook(gLeague, 0x1D, 4, &func_80060178);
    league_set_hook(gLeague, 0x1E, 8, &toggle_sel_flag);
    league_set_hook(gLeague, 0x1E, 4, &toggle_sel_flag);
    league_set_hook(gLeague, 0x1F, 8, &func_800601B4);
    league_set_hook(gLeague, 0x1F, 4, &func_800601B4);
    league_set_hook(gLeague, 0x20, 8, &toggle_slot_sel_bit4);
    league_set_hook(gLeague, 0x20, 4, &toggle_slot_sel_bit4);
    league_set_hook(gLeague, 0x21, 8, &func_80060254);
    league_set_hook(gLeague, 0x21, 4, &func_80060254);
    league_set_hook(gLeague, 0x22, 8, &func_800602A4);
    league_set_hook(gLeague, 0x22, 4, &func_800602A4);
    league_set_hook(gLeague, 0x23, 0x10, &func_8005E928);
    league_set_hook_entry(gLeague, 0xA, 0x20, &func_8005E928);
    setRecordSlotValue(gLeague, 0xC, 3);
    league_set_hook_entry(gLeague, 0xC, 0x10000, &select_reset_requests);
    if (gSelectResetPending != 0) {
        gSelectResetPending = 0;
        M2C_FIELD(gLeague, s16 *, 2) = 5;
        return;
    }
    if (gSelectResetFlag != 0) {
void *__branch_temp_a0;
void *__branch_state;

        __branch_state=gLeague;
        __branch_temp_a0=gSelectState;
        M2C_FIELD(__branch_state, s16 *, 2) = 7;
        *(Copy5*)((u8*)__branch_temp_a0+0x2a1)=*(Copy5*)&D_800A5384;
        gSelectResetPending = 0;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005D844;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D84C;
        return;
    }
    if (select_reset_requested != 0) {
void *__branch_temp_a0_;
void *__branch_state_;

        __branch_state_=gLeague;
        __branch_temp_a0_=gSelectState;
        M2C_FIELD(__branch_state_, s16 *, 2) = 0xC;
        *(Copy10*)((u8*)__branch_temp_a0_+0x2a1)=*(Copy10*)&D_800A538C;
        select_reset_requested = 0;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &select_league_hud_setup;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &results_draw_record_panel_entry;
        return;
    }
    if (M2C_FIELD(gRecords, u16 *, 0x1E) == 7) {
        if (D_800A14D4 != 0) {
            *(s32*)0x800B6880 = 5;
            M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &select_league_reset;
            M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D8B0;
            return;
        }
        *(s32*)0x800B6880 = 5;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &select_league_reset;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D8B0;
        return;
    }
    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        order_recv_msg();
        stream_buf = D_800B3DA8;
        streamOpenPath(stream_buf, &D_800A5398);
        start_track_voices(stream_buf);
        voicesSetIdleValue((s32) (gSpeedAccum * 112.0f));
    }
    league_sub = M2C_FIELD(gLeague, void **, 0x10);
    M2C_FIELD(gLeague, s16 *, 2) = 8;
    M2C_FIELD(league_sub, u8 *, 0xAE) = (u8) M2C_FIELD(league_sub, u8 *, 0xAD);
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005DC40;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005DD2C;
}
