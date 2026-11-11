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

M2C_UNK func_8000DA84();                            /* extern */
M2C_UNK streamOpenPath(void *, M2C_UNK *);           /* extern */
M2C_UNK start_track_voices(void *);                      /* extern */
M2C_UNK voicesSetIdleParams(M2C_UNK);                     /* extern */
M2C_UNK voicesSetIdleValue(s32);                         /* extern */
void func_8008A1CC(void *,s32,s32,void (*)(void)); /* extern */
M2C_UNK func_8008A270(void *, M2C_UNK, s32);        /* extern */
void func_8008A290(void *,s32,s32,void (*)(void)); /* extern */
extern s32 gRecordTimeScale;
extern s32 gRaceFlags;
extern u8 D_800A13B0;
extern u8 D_800A13B1;
extern u8 D_800A13B2;
extern void *gSelectState;
extern u8 D_800A14D4;
extern M2C_UNK D_800A5384;
extern M2C_UNK D_800A538C;
extern M2C_UNK D_800A5398;
extern M2C_UNK gOrderState;
extern M2C_UNK gStreamState;
void func_8005D844(void);
void func_8005D84C(void);
void func_8005D854(void);
void func_8005D870(void);
void func_8005D88C(void);
void func_8005D8B0(void);
void func_8005D958(void);
void func_8005D96C(void);
void func_8005DC1C(void);
void func_8005DC40(void);
void func_8005DD2C(void);
void enterSelectState(void);
void func_8005E1E4(void);
void func_8005E218(void);
void func_8005E250(void);
void func_8005E2B8(void);
void func_8005E2F0(void);
void func_8005E328(void);
void func_8005E49C(void);
void n_alResampleParam(void);
void func_8005E7B8(void);
void func_8005E83C(void);
void func_8005E870(void);
void func_8005E8B0(void);
void func_8005E928(void);
void selectSetCallbacks(void);
void func_8005F050(void);
void func_8005F0A4(void);
void func_8005F0F8(void);
void func_8005F11C(void);
void func_8005F140(void);
void func_8005F164(void);
void func_8005F188(void);
void func_8005F1D4(void);
void func_8005F21C(void);
void func_8005F258(void);
void func_8005F290(void);
void selectStepBack(void);
void select_toggle_slots(void);
void func_8005F3FC(void);
void func_8005F430(void);
void func_8005F460(void);
void func_8005F53C(void);
void func_8005F57C(void);
void func_8005FA90(void);
void func_8005FDF4(void);
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

void func_8005C254(void) {
    s32 var_a2;
    s32 var_a2_2;
    void *temp_a0;
    void *state;
    void *temp_s0;

    *(s32*)0x800B6880 = 5;
    D_800C8118 = (s32) (gRecordTimeScale * 3);
    func_8008A270(gLeague, 0, gRecordTimeScale * 8);
    func_8008A290(gLeague, 0, 0x10, &func_8005D958);
    func_8008A290(gLeague, 0, 0x10000, &func_8005D96C);
    func_8008A270(gLeague, 3, gRecordTimeScale * 0x3C);
    func_8008A1CC(gLeague, 0, 0x10, &func_8005E49C);
    func_8008A1CC(gLeague, 1, 0x10, &func_8005E49C);
    func_8008A1CC(gLeague, 2, 0x10, &func_8005E49C);
    func_8008A290(gLeague, 3, 0x10000, &func_8005E49C);
    func_8008A270(gLeague, 1, gRecordTimeScale * 0x2D);
    func_8008A290(gLeague, 1, 0x10000, &n_alResampleParam);
    if (!(M2C_FIELD(gRecords, u16 *, 0x2C) & 0x20)) {
        func_8008A270(gLeague,4,gRecordTimeScale*30);
    } else {
        func_8008A270(gLeague,4,gRecordTimeScale*2);
    }
    func_8008A290(gLeague, 4, 0x10000, &func_8005E7B8);
    func_8008A290(gLeague, 4, 0x10, &func_8005E7B8);
    func_8008A270(gLeague, 5, 1);
    func_8008A290(gLeague, 5, 0x10000, &func_8005E83C);
    func_8008A270(gLeague, 6, 3);
    func_8008A290(gLeague, 6, 0x10000, &enterSelectState);
    func_8008A290(gLeague, 6, 0x10, &enterSelectState);
    func_8008A270(gLeague, 7, 3);
    func_8008A290(gLeague, 7, 0x10000, &func_8005E1E4);
    func_8008A270(gLeague, 2, gRecordTimeScale * 0x1E);
    func_8008A290(gLeague, 2, 0x10000, &func_8005DC1C);
    func_8008A290(gLeague, 2, 0x10, &func_8005DC1C);
    if (!(M2C_FIELD(gRecords, u16 *, 0x2C) & 0x20)) {
        func_8008A270(gLeague,8,gRecordTimeScale*60);
    } else {
        func_8008A270(gLeague,8,gRecordTimeScale*2);
    }
    func_8008A290(gLeague, 8, 0x10000, &func_8005E218);
    func_8008A1CC(gLeague, 4, 0x10, &func_8005E2B8);
    func_8008A1CC(gLeague, 6, 0x10, &func_8005E2F0);
    func_8008A1CC(gLeague, 5, 0x10, &func_8005E328);
    func_8008A1CC(gLeague, 8, 0x10, &selectSetCallbacks);
    func_8008A1CC(gLeague, 9, 0x10, &func_8005FA90);
    func_8008A1CC(gLeague, 7, 4, &func_8005E870);
    func_8008A1CC(gLeague, 7, 8, &func_8005E8B0);
    func_8008A1CC(gLeague, 0xA, 8, &func_8005F21C);
    func_8008A1CC(gLeague, 0xA, 4, &func_8005F258);
    func_8008A1CC(gLeague, 0x10, 8, &func_8005F1D4);
    func_8008A1CC(gLeague, 0x10, 4, &func_8005F1D4);
    func_8008A1CC(gLeague, 0xB, 8, &func_8005F188);
    func_8008A1CC(gLeague, 0xB, 4, &func_8005F188);
    func_8008A1CC(gLeague, 0xC, 8, &func_8005F050);
    func_8008A1CC(gLeague, 0xC, 4, &func_8005F0A4);
    func_8008A1CC(gLeague, 0xD, 8, &func_8005F0F8);
    func_8008A1CC(gLeague, 0xD, 4, &func_8005F11C);
    func_8008A1CC(gLeague, 0xE, 8, &func_8005F140);
    func_8008A1CC(gLeague, 0xE, 4, &func_8005F164);
    func_8008A1CC(gLeague, 0xF, 4, &selectStepBack);
    func_8008A1CC(gLeague, 0xF, 8, &func_8005F290);
    func_8008A1CC(gLeague, 0x11, 4, &select_toggle_slots);
    func_8008A1CC(gLeague, 0x11, 8, &select_toggle_slots);
    func_8008A1CC(gLeague, 0x12, 0x10, &func_8005F57C);
    func_8008A1CC(gLeague, 0x13, 0x10, &func_8005F3FC);
    func_8008A1CC(gLeague, 0x15, 0x10, &func_8005F430);
    func_8008A1CC(gLeague, 0x15, 0x20, &func_8005F430);
    func_8008A1CC(gLeague, 0x16, 0x10, &func_8005F460);
    func_8008A1CC(gLeague, 0x16, 0x20, &func_8005F430);
    func_8008A1CC(gLeague, 0x14, 0x10, &func_8005E928);
    func_8008A290(gLeague, 9, 0x20, &func_8005E928);
    func_8008A290(gLeague, 0xB, 0x20, &func_8005F53C);
    func_8008A1CC(gLeague, 0x18, 8, &func_8005FDF4);
    func_8008A1CC(gLeague, 0x18, 4, &func_8005FDF4);
    func_8008A1CC(gLeague, 0x19, 8, &func_8005FE80);
    func_8008A1CC(gLeague, 0x19, 4, &func_8005FE80);
    func_8008A1CC(gLeague, 0x17, 8, &toggleStreamFlag200);
    func_8008A1CC(gLeague, 0x17, 4, &toggleStreamFlag200);
    func_8008A1CC(gLeague, 0x1A, 8, &func_8005FF20);
    func_8008A1CC(gLeague, 0x1A, 4, &func_8005FF20);
    func_8008A1CC(gLeague, 0x1B, 8, &func_8005FF70);
    func_8008A1CC(gLeague, 0x1B, 4, &func_8005FFE0);
    func_8008A1CC(gLeague, 0x1C, 8, &func_80060054);
    func_8008A1CC(gLeague, 0x1C, 4, &stream_update_car_mask);
    func_8008A1CC(gLeague, 0x1D, 8, &func_80060178);
    func_8008A1CC(gLeague, 0x1D, 4, &func_80060178);
    func_8008A1CC(gLeague, 0x1E, 8, &toggle_sel_flag);
    func_8008A1CC(gLeague, 0x1E, 4, &toggle_sel_flag);
    func_8008A1CC(gLeague, 0x1F, 8, &func_800601B4);
    func_8008A1CC(gLeague, 0x1F, 4, &func_800601B4);
    func_8008A1CC(gLeague, 0x20, 8, &toggle_slot_sel_bit4);
    func_8008A1CC(gLeague, 0x20, 4, &toggle_slot_sel_bit4);
    func_8008A1CC(gLeague, 0x21, 8, &func_80060254);
    func_8008A1CC(gLeague, 0x21, 4, &func_80060254);
    func_8008A1CC(gLeague, 0x22, 8, &func_800602A4);
    func_8008A1CC(gLeague, 0x22, 4, &func_800602A4);
    func_8008A1CC(gLeague, 0x23, 0x10, &func_8005E928);
    func_8008A290(gLeague, 0xA, 0x20, &func_8005E928);
    func_8008A270(gLeague, 0xC, 3);
    func_8008A290(gLeague, 0xC, 0x10000, &func_8005E250);
    if (D_800A13B0 != 0) {
        D_800A13B0 = 0;
        M2C_FIELD(gLeague, s16 *, 2) = 5;
        return;
    }
    if (D_800A13B1 != 0) {
void *__branch_temp_a0;
void *__branch_state;

        __branch_state=gLeague;
        __branch_temp_a0=gSelectState;
        M2C_FIELD(__branch_state, s16 *, 2) = 7;
        *(Copy5*)((u8*)__branch_temp_a0+0x2a1)=*(Copy5*)&D_800A5384;
        D_800A13B0 = 0;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005D844;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D84C;
        return;
    }
    if (D_800A13B2 != 0) {
void *__branch_temp_a0_;
void *__branch_state_;

        __branch_state_=gLeague;
        __branch_temp_a0_=gSelectState;
        M2C_FIELD(__branch_state_, s16 *, 2) = 0xC;
        *(Copy10*)((u8*)__branch_temp_a0_+0x2a1)=*(Copy10*)&D_800A538C;
        D_800A13B2 = 0;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005D854;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D870;
        return;
    }
    if (M2C_FIELD(gRecords, u16 *, 0x1E) == 7) {
        if (D_800A14D4 != 0) {
            *(s32*)0x800B6880 = 5;
            M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005D88C;
            M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D8B0;
            return;
        }
        *(s32*)0x800B6880 = 5;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005D88C;
        M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005D8B0;
        return;
    }
    if (!(gRaceFlags & 0x40)) {
        gRaceFlags |= 0x40;
        voicesSetIdleParams(1);
        func_8000DA84();
        temp_s0 = D_800B3DA8;
        streamOpenPath(temp_s0, &D_800A5398);
        start_track_voices(temp_s0);
        voicesSetIdleValue((s32) (gSpeedAccum * 112.0f));
    }
    temp_a0 = M2C_FIELD(gLeague, void **, 0x10);
    M2C_FIELD(gLeague, s16 *, 2) = 8;
    M2C_FIELD(temp_a0, u8 *, 0xAE) = (u8) M2C_FIELD(temp_a0, u8 *, 0xAD);
    M2C_FIELD(gSelectState, M2C_UNK **, 0x288) = &func_8005DC40;
    M2C_FIELD(gSelectState, M2C_UNK **, 0x28C) = &func_8005DD2C;
}
