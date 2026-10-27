#include "common.h"

extern u16 D_800D0628; extern s32 D_800B6880;
typedef struct Menu {u16 pad,state; u8 pad4[12]; u8 *entries;} Menu;
typedef struct State {u8 pad[0x228]; u8 a228; u8 pad229[6]; u8 a22f; u8 pad230[0x15]; u8 a245; u8 pad246[0x42]; void *fn288,*fn28c,*fn290;} State;
extern void *D_800C35A0; extern Menu *D_800C3508;
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
M2C_UNK func_80037DE4(void *, M2C_UNK *);           /* extern */
M2C_UNK func_80086854(void *);                      /* extern */
M2C_UNK func_80086A34(M2C_UNK);                     /* extern */
M2C_UNK func_80086DE8(s32);                         /* extern */
M2C_UNK func_8008A0D8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8008A104(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8008A1CC(void *, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 D_8009F640;
extern State *D_800A1468;
extern s8 D_800A16D4;
extern M2C_UNK D_800A5CD0;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_8005E0D0;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_8006AFC0;
extern M2C_UNK func_8006B02C;
extern M2C_UNK func_8006B0C0;
extern M2C_UNK func_8006B150;
extern M2C_UNK func_8006B220;
extern M2C_UNK func_8006B2EC;
extern M2C_UNK func_8006B380;
extern M2C_UNK func_8006B410;
extern M2C_UNK func_8006B4A4;
extern M2C_UNK func_8006B664;
extern M2C_UNK func_80070630;
extern M2C_UNK func_80070750;
extern M2C_UNK func_800707D0;
extern M2C_UNK func_8007081C;
extern M2C_UNK func_8007086C;
extern M2C_UNK func_800708B4;
extern M2C_UNK func_800708F4;
extern M2C_UNK func_80070A34;
extern M2C_UNK func_80070AF0;
extern M2C_UNK func_80070B30;
extern M2C_UNK func_80070BC8;
extern M2C_UNK func_80070C34;
extern M2C_UNK func_80070FB0;
extern M2C_UNK func_80070FE4;
extern M2C_UNK func_8007102C;
extern M2C_UNK func_800710BC;
extern M2C_UNK func_8007159C;
extern M2C_UNK func_800718F4;
extern M2C_UNK func_80071978;
extern M2C_UNK func_80071A0C;
extern M2C_UNK func_80071A48;
extern M2C_UNK func_80071B3C;
extern M2C_UNK func_80071E08;
extern M2C_UNK func_80071E34;
extern M2C_UNK func_80071E74;
extern M2C_UNK func_80071EB4;
extern M2C_UNK func_80071F40;
extern M2C_UNK func_80071F80;
extern M2C_UNK func_80072018;
extern M2C_UNK func_80072090;
extern M2C_UNK func_8007227C;
extern M2C_UNK func_80072364;
extern M2C_UNK func_80072458;
extern M2C_UNK func_800724A4;
extern M2C_UNK func_80072984;
extern M2C_UNK func_8007A004;
extern M2C_UNK func_8007A01C;
extern M2C_UNK func_8007AAFC;
extern M2C_UNK func_8007AC68;
extern M2C_UNK func_8007ACE0;
extern M2C_UNK func_8007AD68;
extern M2C_UNK func_8007B0B8;

void func_8006FC84(void) {
    s32 pad[2];
    M2C_UNK var_a2;
    M2C_UNK var_a3;
    u32 var_s0;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (!(D_8009F640 & 0x40)) {
        D_8009F640 |= 0x40;
        func_80086A34(1);
        func_8000DA84();
        temp_s0 = (char *)&D_800AE850 + 0x5558;
        func_80037DE4(temp_s0, &D_800A5CD0);
        func_80086854(temp_s0);
        func_80086DE8((s32) (M2C_FIELD(&D_800C02AE, f32 *, 0x3332) * 112.0f));
    }
    { void *settings = D_800C35A0; State *st=D_800A1468;
    M2C_FIELD(settings,s16*,0x1e)=5;
    st->a245=0; }
    D_800A1468->a228 = 0;
    func_8008A1CC(D_800C3508, 0, 0x10, &func_80070B30);
    func_8008A1CC(D_800C3508, 1, 0x10, &func_80070AF0);
    func_8008A1CC(D_800C3508, 2, 8, &func_800707D0);
    func_8008A1CC(D_800C3508, 2, 4, &func_800707D0);
    func_8008A1CC(D_800C3508, 3, 0x10, &func_800708B4);
    func_8008A1CC(D_800C3508, 4, 0x10, &func_8005E0D0);
    func_8008A290(D_800C3508, 0, 0x20, &func_8005E0D0);
    func_8008A0D8(D_800C3508, 2, 0);
    func_8008A1CC(D_800C3508, 5, 0x10, &func_800708F4);
    func_8008A1CC(D_800C3508, 7, 8, &func_8007081C);
    func_8008A1CC(D_800C3508, 7, 4, &func_8007081C);
    func_8008A1CC(D_800C3508, 6, 0x10, &func_8005E360);
    func_8008A1CC(D_800C3508, 8, 0x10, &func_8007086C);
    func_8008A290(D_800C3508, 1, 0x20, &func_8007086C);
    func_8008A290(D_800C3508, 2, 0x20, &func_80070BC8);
    if (M2C_FIELD(D_800C35A0,u16 *,0x2c)&0x200) func_8008A104(D_800C3508,0x21,1,1); else func_8008A104(D_800C3508,0x21,0,0);
    var_s0=0;
    func_8008A1CC(D_800C3508, 0x21, 2, &func_80071978);
    func_8008A1CC(D_800C3508, 0x21, 1, &func_800718F4);
    func_8008A1CC(D_800C3508, 0x21, 0x10, &func_80071F80);
    func_8008A1CC(D_800C3508, 0x21, 0x20, &func_80071A0C);
    if (D_800D0628 != 0) {
        do {
            func_8008A1CC(D_800C3508, (var_s0 + 0x15) & 0xFFFF, 0x10, &func_80071A48);
            var_s0 += 1;
        } while (var_s0 < (u16) D_800D0628);
    }
    func_8008A1CC(D_800C3508, 0x22, 0x10, &func_80070FE4);
    func_8008A1CC(D_800C3508, 0x23, 0x10, &func_8007102C);
    func_8008A1CC(D_800C3508, 0x24, 0x10, &func_800710BC);
    func_8008A290(D_800C3508, 3, 0x20, &func_80070FB0);
    func_8008A1CC(D_800C3508, 0x25, 0x10, &func_80072018);
    func_8008A1CC(D_800C3508, 0x26, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x27, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x28, 0x10, &func_80072458);
    func_8008A1CC(D_800C3508, 0x29, 0x10, &func_80071E34);
    func_8008A1CC(D_800C3508, 0x2A, 0x10, &func_80071E74);
    func_8008A1CC(D_800C3508, 0x2B, 0x10, &func_80071EB4);
    func_8008A1CC(D_800C3508, 0x2C, 0x10, &func_80071F40);
    func_8008A1CC(D_800C3508, 0x2D, 4, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x2D, 8, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x2E, 4, &func_8006B0C0);
    func_8008A1CC(D_800C3508, 0x2E, 8, &func_8006B02C);
    func_8008A1CC(D_800C3508, 0x2F, 4, &func_8006B150);
    func_8008A1CC(D_800C3508, 0x2F, 8, &func_8006B220);
    func_8008A1CC(D_800C3508, 0x30, 4, &func_8006B380);
    func_8008A1CC(D_800C3508, 0x30, 8, &func_8006B2EC);
    func_8008A1CC(D_800C3508, 0x31, 4, &func_8006B4A4);
    func_8008A1CC(D_800C3508, 0x31, 8, &func_8006B410);
    func_8008A1CC(D_800C3508, 0x32, 0x10, &func_8007227C);
    func_8008A290(D_800C3508, 6, 0x20, &func_8007227C);
    func_8008A290(D_800C3508, 5, 0x10, &func_80072090);
    func_8008A1CC(D_800C3508, 0x33, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x34, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x35, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x36, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x34, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x34, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x33, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x33, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x35, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x35, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x36, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x36, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x37, 1, &func_8007AC68);
    func_8008A1CC(D_800C3508, 0x37, 2, &func_8007ACE0);
    func_8008A1CC(D_800C3508, 0x37, 0x10, &func_8007AD68);
    func_8008A1CC(D_800C3508, 0x37, 0x20, &func_8007B0B8);
    func_8008A290(D_800C3508, 7, 0x20, &func_8007A01C);
    D_800A1468->a22f = 0;
    if (M2C_FIELD(&D_800C02AE, u8 *, 0x5D56) == 4) {
        temp_a0 = D_800C3508->entries;
        D_800C3508->state = 1;
        M2C_FIELD(temp_a0, u8 *, 0x22) = (u8) M2C_FIELD(temp_a0, u8 *, 0x21);
        D_800A1468->fn288 = &func_80070A34;
        return;
    }
    { s32 state=D_800B6880;
    if(state==5) {
        { void *settings=D_800C35A0; State *st=D_800A1468;
        M2C_FIELD(settings,s16*,0x20)=0;
        st->fn288 = &func_80070630;
        st->fn28c = &func_80070750; }
        return;
    } else if(state==3) {
        { void *settings=D_800C35A0;
        u8 val=M2C_FIELD(&D_800C02AE,u8*,0x7F50);
        State *st=D_800A1468; Menu *menu=D_800C3508;
        M2C_FIELD(settings,s16*,0x20)=val;
        st->fn288 = &func_800724A4;
        st->fn28c = &func_80072984;
        temp_v1 = menu->entries;
        menu->state = 5;
        M2C_FIELD(temp_v1, u8 *, 0x72) = (u8) M2C_FIELD(temp_v1, u8 *, 0x71);
        } return;
    } else if(state==0) {
        D_800A1468->fn288 = &func_80071B3C;
        D_800A1468->fn290 = &func_80071E08;
        D_800A1468->fn28c = &func_80072364;
        temp_v1_2 = D_800C3508->entries;
        D_800C3508->state = 4;
        M2C_FIELD(temp_v1_2, u8 *, 0x5E) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0x5D);
        D_800A16D4 = 0;
        return;
    } else if(state==2) {
        D_800A1468->fn288 = &func_80070C34;
        D_800A1468->fn28c = &func_8007159C;
        temp_v1_3 = D_800C3508->entries;
        D_800C3508->state = 3;
        M2C_FIELD(temp_v1_3, u8 *, 0x4A) = (u8) M2C_FIELD(temp_v1_3, u8 *, 0x49);
        return;
    } }
}
