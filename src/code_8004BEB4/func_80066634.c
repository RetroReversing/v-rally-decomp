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

M2C_UNK func_8008A1CC(s32, s32, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_8008A290(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern void *D_800A1468;
extern s32 D_800C3508;
extern M2C_UNK func_8005E38C;
extern M2C_UNK func_80066E20;
extern M2C_UNK func_80066EBC;
extern M2C_UNK func_80066F8C;
extern M2C_UNK func_80066FC0;
extern M2C_UNK func_80066FF4;
extern M2C_UNK func_80067108;
extern M2C_UNK func_800671A0;
extern M2C_UNK func_80067248;
extern M2C_UNK func_800672D0;
extern M2C_UNK func_8006735C;
extern M2C_UNK func_800673E8;
extern M2C_UNK func_80067474;
extern M2C_UNK func_800675E8;
extern M2C_UNK func_80067644;
extern M2C_UNK func_800676A0;
extern M2C_UNK func_800677E8;
extern M2C_UNK func_8006786C;
extern M2C_UNK func_800680F0;
extern M2C_UNK func_800684C0;
extern M2C_UNK func_800684F4;
extern M2C_UNK func_800685C0;
extern M2C_UNK func_800685F0;
extern M2C_UNK func_80068624;
extern M2C_UNK func_80068C78;
extern M2C_UNK func_80068CA4;
extern M2C_UNK func_80068CD4;
extern M2C_UNK func_80068D9C;
extern M2C_UNK func_80068E5C;
extern M2C_UNK func_80068F00;
extern M2C_UNK func_80068F94;
extern M2C_UNK func_8006951C;
extern M2C_UNK func_800695D0;
extern M2C_UNK func_80069734;

void func_80066634(void) {
    s32 temp_a1;
    s32 temp_s0;
    u8 var_s1;

    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    func_8008A1CC(D_800C3508, 0, 0x10, &func_800695D0);
    func_8008A1CC(D_800C3508, 1, 0x10, &func_800695D0);
    func_8008A1CC(D_800C3508, 2, 0x10, &func_80067474);
    func_8008A1CC(D_800C3508, 3, 0x10, &func_800680F0);
    func_8008A1CC(D_800C3508, 4, 0x10, &func_8005E38C);
    func_8008A290(D_800C3508, 0, 0x20, &func_8005E38C);
    func_8008A1CC(D_800C3508, 5, 4, &func_80066FC0);
    func_8008A1CC(D_800C3508, 5, 8, &func_80066F8C);
    func_8008A1CC(D_800C3508, 6, 0x10, &func_80068F94);
    func_8008A1CC(D_800C3508, 7, 0x10, &func_80066FF4);
    func_8008A1CC(D_800C3508, 8, 0x10, &func_80069734);
    func_8008A290(D_800C3508, 1, 0x20, &func_80069734);
    func_8008A1CC(D_800C3508, 0x1C, 4, &func_80067248);
    func_8008A1CC(D_800C3508, 0x1C, 8, &func_80067248);
    func_8008A1CC(D_800C3508, 0x1D, 4, &func_800672D0);
    func_8008A1CC(D_800C3508, 0x1D, 8, &func_800672D0);
    func_8008A1CC(D_800C3508, 0x1E, 4, &func_8006735C);
    func_8008A1CC(D_800C3508, 0x1E, 8, &func_8006735C);
    func_8008A1CC(D_800C3508, 0x1F, 8, &func_800673E8);
    func_8008A1CC(D_800C3508, 0x1F, 4, &func_800673E8);
    func_8008A1CC(D_800C3508, 0x20, 0x10, &func_800671A0);
    func_8008A290(D_800C3508, 5, 0x20, &func_800671A0);
    func_8008A1CC(D_800C3508, 9, 8, &func_800675E8);
    func_8008A1CC(D_800C3508, 9, 4, &func_80067644);
    func_8008A1CC(D_800C3508, 9, 0x10, &func_800676A0);
    func_8008A1CC(D_800C3508, 9, 0x20, &func_800677E8);
    func_8008A1CC(D_800C3508, 0xB, 0x10, &func_8006786C);
    func_8008A1CC(D_800C3508, 0xA, 0x10, &func_80067108);
    var_s1 = 0;
    do {
        func_8008A1CC(D_800C3508, (temp_s0 = (u16)(var_s1 + 0x11)), 4, &func_80068C78);
        var_s1 += 1;
        func_8008A1CC(D_800C3508, temp_s0, 8, &func_80068CA4);
        func_8008A1CC(D_800C3508, temp_s0, 1, &func_80068CD4);
        func_8008A1CC(D_800C3508, temp_s0, 2, &func_80068CD4);
    } while ((u32) (var_s1 & 0xFF) < 8U);
    func_8008A1CC(D_800C3508, 0x19, 4, &func_80068D9C);
    func_8008A1CC(D_800C3508, 0x19, 8, &func_80068E5C);
    func_8008A1CC(D_800C3508, 0x1B, 0x10, &func_80068F00);
    func_8008A1CC(D_800C3508, 0x1A, 0x10, &func_8006951C);
    func_8008A1CC(D_800C3508, 0xC, 4, &func_80068624);
    func_8008A1CC(D_800C3508, 0xC, 8, &func_800685F0);
    func_8008A1CC(D_800C3508, 0xC, 0x10, &func_800684C0);
    func_8008A1CC(D_800C3508, 0xD, 0x10, &func_80067474);
    func_8008A1CC(D_800C3508, 0xE, 0x10, &func_80067108);
    func_8008A1CC(D_800C3508, 0xF, 0x10, &func_800685C0);
    func_8008A1CC(D_800C3508, 0x10, 0x10, &func_800684F4);
    func_8008A290(D_800C3508, 3, 0x20, &func_80067108);
    M2C_FIELD(D_800A1468, s8 *, 0x228) = 0;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80066E20;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80066EBC;
}
