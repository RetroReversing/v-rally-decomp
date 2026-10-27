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
M2C_UNK func_8008A1CC(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern s32 D_8009F640;
extern void *D_800A1468;
extern M2C_UNK D_800A5670;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern M2C_UNK func_8005E0D0;
extern M2C_UNK func_8005E360;
extern M2C_UNK func_80062B70;
extern M2C_UNK func_80062C48;
extern M2C_UNK func_80062C9C;
extern M2C_UNK func_80062CF0;
extern M2C_UNK func_80062D6C;
extern M2C_UNK func_80062DF4;
extern M2C_UNK func_80063104;
extern M2C_UNK func_800631A4;
extern M2C_UNK func_80063224;
extern M2C_UNK func_80063BB8;
extern M2C_UNK func_80063C60;
extern M2C_UNK func_80063D9C;
extern M2C_UNK func_80063EC8;
extern M2C_UNK func_80063F6C;
extern M2C_UNK func_80064278;
extern M2C_UNK func_800642B8;
extern M2C_UNK func_800642F8;
extern M2C_UNK func_80064380;
extern M2C_UNK func_800643F0;
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

extern s32 D_800C3508;
extern u16 D_800D061E;
void func_80062404(void) {
    u8 scratch[16];
    u32 var_s0;
    u32 var_s0_2;
    void *temp_s0;
    void *state;

    if (!(D_8009F640 & 0x40)) {
        D_8009F640 |= 0x40;
        func_80086A34(1);
        func_8000DA84();
        temp_s0 = D_800AE850 + 0x5558;
        func_80037DE4(temp_s0, &D_800A5670);
        func_80086854(temp_s0);
        func_80086DE8((s32) (M2C_FIELD(D_800C02AE, f32 *, 0x3332) * 112.0f));
    }
    state = D_800A1468;
    M2C_FIELD(M2C_FIELD(D_800C02AE, void **, 0x32F2), s16 *, 0x1E) = 0;
    M2C_FIELD(state, s8 *, 0x245) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x23B) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x23A) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x228) = 0;
    func_8008A1CC(D_800C3508, 0, 0x10, &func_8007A24C);
    func_8008A1CC(D_800C3508, 4, 0x10, &func_80063224);
    func_8008A1CC(D_800C3508, 1, 0x10, &func_8005E360);
    func_8008A1CC(D_800C3508, 2, 8, &func_80062C48);
    func_8008A1CC(D_800C3508, 2, 4, &func_80062C9C);
    func_8008A1CC(D_800C3508, 3, 8, &func_80062CF0);
    func_8008A1CC(D_800C3508, 3, 4, &func_80062D6C);
    func_8008A1CC(D_800C3508, 5, 0x10, &func_8005E0D0);
    func_8008A290(D_800C3508, 0, 0x20, &func_8005E0D0);
    var_s0 = 0;
    if (D_800D061E != 0) {
        do {
            func_8008A1CC(D_800C3508, (var_s0 + 6) & 0xFFFF, 0x10, &func_80063BB8);
            var_s0 += 1;
        } while (var_s0 < (u16) D_800D061E);
    }
    func_8008A1CC(D_800C3508, 0xE, 2, &func_80063D9C);
    func_8008A1CC(D_800C3508, 0xE, 1, &func_80063C60);
    func_8008A1CC(D_800C3508, 0xE, 0x20, &func_80063F6C);
    func_8008A290(D_800C3508, 1, 0x20, &func_800631A4);
    var_s0_2 = 0;
    if (D_800D061E != 0) {
        do {
            func_8008A1CC(D_800C3508, (var_s0_2 + 0xF) & 0xFFFF, 0x10, &func_80063BB8);
            var_s0_2 += 1;
        } while (var_s0_2 < (u16) D_800D061E);
    }
    func_8008A1CC(D_800C3508, 0x17, 2, &func_80063D9C);
    func_8008A1CC(D_800C3508, 0x17, 1, &func_80063C60);
    func_8008A1CC(D_800C3508, 0x17, 0x10, &func_80063EC8);
    func_8008A1CC(D_800C3508, 0x17, 0x20, &func_80063F6C);
    func_8008A290(D_800C3508, 2, 0x20, &func_80063104);
    func_8008A1CC(D_800C3508, 0x18, 0x10, &func_800643F0);
    func_8008A1CC(D_800C3508, 0x19, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x1A, 0x10, &func_8006B664);
    func_8008A1CC(D_800C3508, 0x1B, 0x10, &func_80064380);
    func_8008A1CC(D_800C3508, 0x1B, 0x10, &func_80064278);
    func_8008A1CC(D_800C3508, 0x1C, 0x10, &func_800642B8);
    func_8008A1CC(D_800C3508, 0x1D, 0x10, &func_800642F8);
    func_8008A290(D_800C3508, 3, 0x20, &func_80064380);
    func_8008A1CC(D_800C3508, 0x1E, 4, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x1E, 8, &func_8006AFC0);
    func_8008A1CC(D_800C3508, 0x1F, 4, &func_8006B0C0);
    func_8008A1CC(D_800C3508, 0x1F, 8, &func_8006B02C);
    func_8008A1CC(D_800C3508, 0x20, 4, &func_8006B150);
    func_8008A1CC(D_800C3508, 0x20, 8, &func_8006B220);
    func_8008A1CC(D_800C3508, 0x21, 4, &func_8006B380);
    func_8008A1CC(D_800C3508, 0x21, 8, &func_8006B2EC);
    func_8008A1CC(D_800C3508, 0x22, 4, &func_8006B4A4);
    func_8008A1CC(D_800C3508, 0x22, 8, &func_8006B410);
    func_8008A1CC(D_800C3508, 0x23, 0x10, &func_8006B534);
    func_8008A290(D_800C3508, 4, 0x20, &func_8006B534);
    func_8008A1CC(D_800C3508, 0x24, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x25, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x26, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x27, 0x10, &func_8007AAFC);
    func_8008A1CC(D_800C3508, 0x25, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x25, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x24, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x24, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x26, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x26, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x27, 1, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x27, 2, &func_8007A004);
    func_8008A1CC(D_800C3508, 0x28, 1, &func_8007AC68);
    func_8008A1CC(D_800C3508, 0x28, 2, &func_8007ACE0);
    func_8008A1CC(D_800C3508, 0x28, 0x10, &func_8007AD68);
    func_8008A1CC(D_800C3508, 0x28, 0x20, &func_8007B0B8);
    func_8008A290(D_800C3508, 5, 0x20, &func_8007A01C);
    M2C_FIELD(D_800A1468, s8 *, 0x22F) = 0;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80062B70;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80062DF4;
}
