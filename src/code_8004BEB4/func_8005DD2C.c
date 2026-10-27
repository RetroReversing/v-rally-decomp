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

void *func_800592D0(M2C_UNK);                       /* extern */
M2C_UNK func_80059618(void *, u8, u8, u8, s32);     /* extern */
M2C_UNK func_800596F4(void *, s16, s16, char *); /* extern */
void *func_8005A744(M2C_UNK, s32);                  /* extern */
s32 func_80084BF0(M2C_UNK);                         /* extern */
M2C_UNK func_8008A0D8(void *, M2C_UNK, u8);         /* extern */
M2C_UNK func_80099DF8(char *, M2C_UNK *, ...); /* extern */
extern void *D_800A1468;
extern f32 D_800A14CC;
extern s8 D_800A14D4;
extern M2C_UNK D_800A5488;
extern M2C_UNK D_800A5490;
extern M2C_UNK D_800C02AE;

extern void *D_800C3508;
extern void *D_800C35A0;
void func_8005DD2C(void) {
    char sp18[5];
    f32 temp_fv1;
    s32 temp_a3;
    u32 var_a0;
    s32 var_a2;
    s32 var_v1;
    s32 var_v1_2;
    void *temp_v0;
    void *temp_v1;

    temp_v1 = M2C_FIELD(D_800C3508, void **, 0x10) + (M2C_FIELD(D_800C3508, s16 *, 2) * 0x14);
    if (M2C_FIELD(temp_v1, u8 *, 0xE) != M2C_FIELD(temp_v1, u8 *, 0xD)) {
        D_800A14D4 = 1;
    }
    if ((M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x2000) && (func_80084BF0(0) == 0x2020)) {
        M2C_FIELD(D_800A1468, u8 *, 0x248) = (u8) ~M2C_FIELD(D_800A1468, u8 *, 0x248);
        func_8008A0D8(D_800C3508, 9, M2C_FIELD(D_800A1468, u8 *, 0x248));
        M2C_FIELD(func_8005A744(5, M2C_FIELD(D_800A1468, s32 *, 0xC)), u8 *, 0x41) = (u8) M2C_FIELD(D_800A1468, u8 *, 0x248);
    }
    if (M2C_FIELD(D_800A1468, u16 *, 0x220) != 0) {
        temp_v0 = func_800592D0(0);
        var_v1 = 0;
        do {
            M2C_FIELD(temp_v0, s8 *, 0x1A) = 1;
            temp_v0 = M2C_FIELD(temp_v0, void **, 0);
            var_v1 += 1;
        } while ((u32) (var_v1 & 0xFF) < 3U);
        M2C_FIELD(D_800A1468, u16 *, 0x220) = (u16) (M2C_FIELD(D_800A1468, u16 *, 0x220) - 1);
    } else {
        temp_v0 = func_800592D0(0);
        var_v1_2 = 0;
        do {
            M2C_FIELD(temp_v0, s8 *, 0x1A) = 0;
            temp_v0 = M2C_FIELD(temp_v0, void **, 0);
            var_v1_2 += 1;
        } while ((u32) (var_v1_2 & 0xFF) < 3U);
    }
    temp_v0 = func_800592D0(4);
    func_80059618(temp_v0, M2C_FIELD(temp_v0, u8 *, 0xB), M2C_FIELD(temp_v0, u8 *, 0xC), M2C_FIELD(temp_v0, u8 *, 0xD), (s32) M2C_FIELD(temp_v0, u8 *, 0xE));
    sp18[4] = 0;
    var_a2 = (u32)D_800A14CC;
    var_a0 = (u16)(u32)(D_800A14CC * 10.0f);
    temp_a3 = (var_a0 % 10) & 0xFFFF;
    if (temp_a3 != 0) {
        func_80099DF8(sp18, &D_800A5488, var_a2 & 0xFF, temp_a3);
    } else {
        func_80099DF8(sp18, &D_800A5490, var_a2 & 0xFF);
    }
    func_800596F4(temp_v0, M2C_FIELD(temp_v0, s16 *, 6), M2C_FIELD(temp_v0, s16 *, 8), sp18);
}
