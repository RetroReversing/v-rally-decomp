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

M2C_UNK func_8000F400(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8004D31C();                            /* extern */
M2C_UNK func_800588E0(void *);                      /* extern */
M2C_UNK func_800591E4(void *);                      /* extern */
M2C_UNK func_80059540(void *);                      /* extern */
M2C_UNK func_8005A100();                            /* extern */
M2C_UNK func_8005A2D0(M2C_UNK);                     /* extern */
M2C_UNK func_80089B8C(void *);                      /* extern */
M2C_UNK func_80089F80(void *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_80089F94(void *, void *);              /* extern */
M2C_UNK func_80089FD4(void *, void *);              /* extern */
extern u8 D_800A13B4;
extern u8 D_800A13B6;
extern M2C_UNK D_800A13D0;
extern void *D_800A1468;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_80058E28;
extern M2C_UNK func_8005914C;

extern u8 D_800C6004, D_800AFA5C;
extern void *D_800C3508;
void func_8005B6A8(void) {
    M2C_UNK (*temp_v0)();
    u8 temp_v0_2;
    u8 temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;

    if (M2C_FIELD(D_800A1468, u8 *, 0x2BE) != 0) {
        func_8004D31C();
        M2C_FIELD(D_800A1468, u8 *, 0x2BE) = 0U;
    }
    temp_v1 = D_800A1468;
    if (M2C_FIELD(D_800A1468, u8 *, 0x29F) != 0) {
        M2C_FIELD(D_800A1468, u8 *, 0x29F) = 0U;
        func_80089FD4((D_800C6004 * 0x24) + &D_800A13B4, D_800C3508);
        *(&D_800A13B6 + (D_800C6004 * 0x24)) = M2C_FIELD(((M2C_FIELD(D_800C3508, s16 *, 2) * 0x14) + M2C_FIELD(D_800C3508, s32 *, 0x10)), u8 *, 0xD);
    }
    if (M2C_FIELD(D_800A1468, u8 *, 0x29A) != 0) {
        M2C_FIELD(D_800A1468, u8 *, 0x2BA) = (u8) (M2C_FIELD(D_800A1468, u8 *, 0x2BA) - 1);
        if (M2C_FIELD(D_800A1468, u8 *, 0x2BA) == 0) {
            M2C_FIELD(D_800A1468, s8 *, 0x29A) = 0;
            M2C_FIELD(D_800A1468, u8 *, 0x298) = 0U;
            func_8005A100();
        }
    }
    if ((M2C_FIELD(D_800A1468, u8 *, 0x29B) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x298) == 0)) {
        M2C_FIELD(D_800A1468, u8 *, 0x29B) = 0U;
        M2C_FIELD(D_800A1468, u8 *, 0x299) = 0U;
        func_800591E4(D_800C3508);
    }
    temp_v1_2 = D_800A1468;
    if ((M2C_FIELD(D_800A1468, u8 *, 0x29D) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x299) == 0)) {
        M2C_FIELD(D_800A1468, u8 *, 0x29D) = 0U;
        M2C_FIELD(D_800A1468, u8 *, 0x299) = 1U;
        func_800588E0(D_800A1468 + 0x2AD);
        if ((M2C_FIELD(D_800A1468, u8 *, 0x29E) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x299) != 0)) {
            M2C_FIELD(D_800A1468, u8 *, 0x29E) = 0U;
            func_80089F80((D_800AFA5C * 0x24) + &D_800A13B4, &func_80058E28, &func_8005914C);
        }
        func_80089F94((D_800AFA5C * 0x24) + &D_800A13B4, D_800C3508);
        temp_v0 = *(M2C_UNK (**)())((u8*)&D_800A13D0 + (D_800AFA5C * 0x24));
        if (temp_v0 != NULL) {
            temp_v0();
        }
    }
    if ((M2C_FIELD(D_800A1468, u8 *, 0x29C) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x299) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x2BA) == 0)) {
        if (M2C_FIELD(&D_800AE850, s32 *, 0x7410) == 0) {
            func_8000F400(0, 3, 1);
        }
        M2C_FIELD(D_800A1468, s8 *, 0x29C) = 0;
        M2C_FIELD(D_800A1468, u8 *, 0x298) = 1U;
        func_80059540(D_800A1468 + 0x2A1);
        M2C_FIELD(D_800A1468, u8 *, 0x246) = 1U;
        M2C_FIELD(D_800A1468, u8 *, 0x2BC) = 3U;
    }
    temp_v0_2 = M2C_FIELD(D_800A1468, u8 *, 0x2BB);
    if (temp_v0_2 != 0) {
        M2C_FIELD(D_800A1468, u8 *, 0x2BB) = (u8) (temp_v0_2 - 1);
        if (M2C_FIELD(D_800A1468, u8 *, 0x2BB) == 0) {
            M2C_FIELD(D_800A1468, u8 *, 0x2A0) = 1U;
        }
    }
    if ((M2C_FIELD(D_800A1468, u8 *, 0x298) != 0) && (M2C_FIELD(D_800A1468, u8 *, 0x2BA) == 0)) {
        if (M2C_FIELD(D_800A1468, u8 *, 0x246) == 0) {
            func_80089B8C(D_800C3508);
        } else {
            M2C_FIELD(D_800A1468, u8 *, 0x246) = 0U;
        }
    }
    if ((M2C_FIELD(D_800A1468, u16 *, 0x2BA) == 0) && (M2C_FIELD(D_800A1468, u8 *, 0x2A0) == 0) && (M2C_FIELD(D_800A1468, u8 *, 0x298) != 0)) {
        temp_v0_3 = M2C_FIELD(D_800A1468, u8 *, 0x2BC);
        if (temp_v0_3 == 0) {
            func_8005A2D0(1);
            return;
        }
        M2C_FIELD(D_800A1468, u8 *, 0x2BC) = (u8) (temp_v0_3 - 1);
    }
}
