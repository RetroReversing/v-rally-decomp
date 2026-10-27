#include "common.h"

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
M2C_UNK func_8008A104(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8008A1CC(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 D_8009F640;
extern void *D_800A1468;
extern M2C_UNK D_800A56B0;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_8005E0D0;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_80064E48;
extern M2C_UNK func_80064E50;
extern M2C_UNK func_80064ED0;
extern M2C_UNK func_80064F04;
extern M2C_UNK func_8006556C;
extern M2C_UNK func_80065860;
extern M2C_UNK func_80065D6C;
extern M2C_UNK func_80065DD0;
extern M2C_UNK func_80065E40;
extern M2C_UNK func_80065F28;
extern M2C_UNK func_80065F9C;
extern M2C_UNK func_8006603C;
extern M2C_UNK func_8006632C;
extern M2C_UNK func_80066384;
extern M2C_UNK func_80066470;
extern M2C_UNK func_8006648C;
extern M2C_UNK func_800664CC;
extern M2C_UNK func_8006650C;
extern M2C_UNK func_8006AFC0;
extern M2C_UNK func_8006B02C;
extern M2C_UNK func_8006B0C0;
extern M2C_UNK func_8006B150;
extern M2C_UNK func_8006B220;
extern M2C_UNK func_8006B2EC;
extern M2C_UNK func_8006B380;
extern M2C_UNK func_8006B410;
extern M2C_UNK func_8006B4A4;
extern M2C_UNK func_8006B534;
extern M2C_UNK func_8006B664;
extern M2C_UNK func_8007A004;
extern M2C_UNK func_8007A01C;
extern M2C_UNK func_8007A24C;
extern M2C_UNK func_8007AAFC;
extern M2C_UNK func_8007AC68;
extern M2C_UNK func_8007ACE0;
extern M2C_UNK func_8007AD68;
extern M2C_UNK func_8007B0B8;

extern void *D_800C3508;
extern void *D_800C35A0;
extern s32 D_800B6880;
void func_80064694(void) {
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

    if (!(D_8009F640 & 0x40)) {
        D_8009F640 |= 0x40;
        func_80086A34(1);
        func_8000DA84();
        temp_s0 = (u8 *)&D_800AE850 + 0x5558;
        func_80037DE4(temp_s0, &D_800A56B0);
        func_80086854(temp_s0);
        func_80086DE8((s32) (M2C_FIELD(&D_800C02AE, f32 *, 0x3332) * 112.0f));
    }
    temp_v1 = M2C_FIELD(D_800C35A0, u16 *, 0x1E);
    if (((temp_v1 >= 5U) | (temp_v1 == 0)) != 0) {
        M2C_FIELD(D_800C35A0, u16 *, 0x1E) = 1U;
    }
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x228) = 0;
    func_8008A1CC(D_800C3508, 0, 0x10, &func_8007A24C);
    func_8008A1CC(D_800C3508, 1, 0x10, &func_8005E360);
    func_8008A1CC(D_800C3508, 2, 0x10, &func_80064ED0);
    func_8008A1CC(D_800C3508, 3, 0x10, &func_8005E0D0);
    func_8008A290(D_800C3508, 0, 0x20, &func_8005E0D0);
    func_8008A104(D_800C3508, 8, 1, 1);
    func_8008A1CC(D_800C3508, 8, 2, &func_80065DD0);
    func_8008A1CC(D_800C3508, 8, 1, &func_80065D6C);
    func_8008A1CC(D_800C3508, 8, 0x20, &func_80065F28);
    func_8008A290(D_800C3508, 1, 0x20, &func_80064F04);
    if (M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x100) {
        func_8008A104(D_800C3508, 0xD, 1, 1);
    } else {
        func_8008A104(D_800C3508, 0xD, 0, 0);
    }
    func_8008A1CC(D_800C3508, 0xD, 2, &func_80065DD0);
    func_8008A1CC(D_800C3508, 0xD, 1, &func_80065D6C);
    func_8008A1CC(D_800C3508, 0xD, 0x10, &func_80065E40);
    func_8008A1CC(D_800C3508, 0xD, 0x20, &func_80065F28);
    func_8008A290(D_800C3508, 2, 0x20, &func_80065F9C);
    func_8008A1CC(D_800C3508, 0xE, 0x10, &func_8006632C);
    func_8008A1CC(D_800C3508, 0xF, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x10, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x11, 0x10, &func_8006648C);
    func_8008A1CC(D_800C3508, 0x12, 0x10, &func_800664CC);
    func_8008A1CC(D_800C3508, 0x13, 0x10, &func_8006650C);
    func_8008A1CC(D_800C3508, 0x14, 4, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x14, 8, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x15, 4, &func_8006B0C0);
    func_8008A1CC(D_800C3508, 0x15, 8, &func_8006B02C);
    func_8008A1CC(D_800C3508, 0x16, 4, &func_8006B150);
    func_8008A1CC(D_800C3508, 0x16, 8, &func_8006B220);
    func_8008A1CC(D_800C3508, 0x17, 4, &func_8006B380);
    func_8008A1CC(D_800C3508, 0x17, 8, &func_8006B2EC);
    func_8008A1CC(D_800C3508, 0x18, 4, &func_8006B4A4);
    func_8008A1CC(D_800C3508, 0x18, 8, &func_8006B410);
    func_8008A1CC(D_800C3508, 0x19, 0x10, &func_8006B534);
    func_8008A290(D_800C3508, 4, 0x20, &func_8006B534);
    func_8008A1CC(D_800C3508, 0x1A, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x1B, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x1C, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x1D, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x1B, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1B, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1A, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1A, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1C, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1C, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1D, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1D, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x1E, 1, &func_8007AC68);
    func_8008A1CC(D_800C3508, 0x1E, 2, &func_8007ACE0);
    func_8008A1CC(D_800C3508, 0x1E, 0x10, &func_8007AD68);
    func_8008A1CC(D_800C3508, 0x1E, 0x20, &func_8007B0B8);
    func_8008A290(D_800C3508, 5, 0x20, &func_8007A01C);
    M2C_FIELD(D_800A1468, s8 *, 0x22F) = 0;
    if (M2C_FIELD(&D_800C02AE, u8 *, 0x5D56) == 4) {
        temp_v1_2 = M2C_FIELD(D_800C3508, void **, 0x10);
        M2C_FIELD(D_800C3508, s16 *, 2) = 0;
        M2C_FIELD(temp_v1_2, u8 *, 0xE) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0xD);
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80064E48;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80064E50;
        return;
    }
    if (((D_800B6880 == 5) | (D_800B6880 == 2)) != 0) {
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80064E48;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80064E50;
        return;
    }
    if (D_800B6880 == 0) {
        state = D_800A1468;
        manager0 = D_800C3508;
        M2C_FIELD(state, M2C_UNK **, 0x288) = &func_8006603C;
        M2C_FIELD(state, M2C_UNK **, 0x28C) = &func_80066384;
        M2C_FIELD(state, M2C_UNK **, 0x290) = &func_80066470;
        temp_v1_3 = M2C_FIELD(manager0, void **, 0x10);
        M2C_FIELD(manager0, s16 *, 2) = 3;
        M2C_FIELD(temp_v1_3, u8 *, 0x4A) = (u8) M2C_FIELD(temp_v1_3, u8 *, 0x49);
        return;
    } else if (D_800B6880 == 3) {
        state = D_800A1468;
        manager = D_800C3508;
        M2C_FIELD(state, M2C_UNK **, 0x288) = &func_8006556C;
        M2C_FIELD(state, M2C_UNK **, 0x28C) = &func_80065860;
        temp_a0 = M2C_FIELD(manager, void **, 0x10);
        config = D_800C35A0;
        M2C_FIELD(manager, s16 *, 2) = 2;
        M2C_FIELD(temp_a0, s8 *, 0x36) = (s8) (M2C_FIELD(temp_a0, u8 *, 0x35) + M2C_FIELD(config, u8 *, 0x21));
        return;
    }
}
