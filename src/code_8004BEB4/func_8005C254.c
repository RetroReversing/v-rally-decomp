#include "common.h"

typedef struct {char b[5];} Copy5;
typedef struct {char b[10];} Copy10;
extern void *D_800C3508,*D_800C35A0;
extern s32 D_800C6880,D_800C8118;
extern f32 D_800C35E0;
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
M2C_UNK func_80037DE4(void *, M2C_UNK *);           /* extern */
M2C_UNK func_80086854(void *);                      /* extern */
M2C_UNK func_80086A34(M2C_UNK);                     /* extern */
M2C_UNK func_80086DE8(s32);                         /* extern */
void func_8008A1CC(void *,s32,s32,void (*)(void)); /* extern */
M2C_UNK func_8008A270(void *, M2C_UNK, s32);        /* extern */
void func_8008A290(void *,s32,s32,void (*)(void)); /* extern */
extern s32 D_8009D540;
extern s32 D_8009F640;
extern u8 D_800A13B0;
extern u8 D_800A13B1;
extern u8 D_800A13B2;
extern void *D_800A1468;
extern u8 D_800A14D4;
extern M2C_UNK D_800A5384;
extern M2C_UNK D_800A538C;
extern M2C_UNK D_800A5398;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;
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
void func_8005DFC8(void);
void func_8005E1E4(void);
void func_8005E218(void);
void func_8005E250(void);
void func_8005E2B8(void);
void func_8005E2F0(void);
void func_8005E328(void);
void func_8005E49C(void);
void func_8005E798(void);
void func_8005E7B8(void);
void func_8005E83C(void);
void func_8005E870(void);
void func_8005E8B0(void);
void func_8005E928(void);
void func_8005E9DC(void);
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
void func_8005F310(void);
void func_8005F380(void);
void func_8005F3FC(void);
void func_8005F430(void);
void func_8005F460(void);
void func_8005F53C(void);
void func_8005F57C(void);
void func_8005FA90(void);
void func_8005FDF4(void);
void func_8005FE30(void);
void func_8005FE80(void);
void func_8005FED0(void);
void func_8005FF20(void);
void func_8005FF70(void);
void func_8005FFE0(void);
void func_80060054(void);
void func_800600D0(void);
void func_80060178(void);
void func_800601B4(void);
void func_80060204(void);
void func_80060254(void);
void func_800602A4(void);

void func_8005C254(void) {
    s32 var_a2;
    s32 var_a2_2;
    void *temp_a0;
    void *state;
    void *temp_s0;

    *(s32*)0x800B6880 = 5;
    D_800C8118 = (s32) (D_8009D540 * 3);
    func_8008A270(D_800C3508, 0, D_8009D540 * 8);
    func_8008A290(D_800C3508, 0, 0x10, &func_8005D958);
    func_8008A290(D_800C3508, 0, 0x10000, &func_8005D96C);
    func_8008A270(D_800C3508, 3, D_8009D540 * 0x3C);
    func_8008A1CC(D_800C3508, 0, 0x10, &func_8005E49C);
    func_8008A1CC(D_800C3508, 1, 0x10, &func_8005E49C);
    func_8008A1CC(D_800C3508, 2, 0x10, &func_8005E49C);
    func_8008A290(D_800C3508, 3, 0x10000, &func_8005E49C);
    func_8008A270(D_800C3508, 1, D_8009D540 * 0x2D);
    func_8008A290(D_800C3508, 1, 0x10000, &func_8005E798);
    if (!(M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x20)) {
        func_8008A270(D_800C3508,4,D_8009D540*30);
    } else {
        func_8008A270(D_800C3508,4,D_8009D540*2);
    }
    func_8008A290(D_800C3508, 4, 0x10000, &func_8005E7B8);
    func_8008A290(D_800C3508, 4, 0x10, &func_8005E7B8);
    func_8008A270(D_800C3508, 5, 1);
    func_8008A290(D_800C3508, 5, 0x10000, &func_8005E83C);
    func_8008A270(D_800C3508, 6, 3);
    func_8008A290(D_800C3508, 6, 0x10000, &func_8005DFC8);
    func_8008A290(D_800C3508, 6, 0x10, &func_8005DFC8);
    func_8008A270(D_800C3508, 7, 3);
    func_8008A290(D_800C3508, 7, 0x10000, &func_8005E1E4);
    func_8008A270(D_800C3508, 2, D_8009D540 * 0x1E);
    func_8008A290(D_800C3508, 2, 0x10000, &func_8005DC1C);
    func_8008A290(D_800C3508, 2, 0x10, &func_8005DC1C);
    if (!(M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x20)) {
        func_8008A270(D_800C3508,8,D_8009D540*60);
    } else {
        func_8008A270(D_800C3508,8,D_8009D540*2);
    }
    func_8008A290(D_800C3508, 8, 0x10000, &func_8005E218);
    func_8008A1CC(D_800C3508, 4, 0x10, &func_8005E2B8);
    func_8008A1CC(D_800C3508, 6, 0x10, &func_8005E2F0);
    func_8008A1CC(D_800C3508, 5, 0x10, &func_8005E328);
    func_8008A1CC(D_800C3508, 8, 0x10, &func_8005E9DC);
    func_8008A1CC(D_800C3508, 9, 0x10, &func_8005FA90);
    func_8008A1CC(D_800C3508, 7, 4, &func_8005E870);
    func_8008A1CC(D_800C3508, 7, 8, &func_8005E8B0);
    func_8008A1CC(D_800C3508, 0xA, 8, &func_8005F21C);
    func_8008A1CC(D_800C3508, 0xA, 4, &func_8005F258);
    func_8008A1CC(D_800C3508, 0x10, 8, &func_8005F1D4);
    func_8008A1CC(D_800C3508, 0x10, 4, &func_8005F1D4);
    func_8008A1CC(D_800C3508, 0xB, 8, &func_8005F188);
    func_8008A1CC(D_800C3508, 0xB, 4, &func_8005F188);
    func_8008A1CC(D_800C3508, 0xC, 8, &func_8005F050);
    func_8008A1CC(D_800C3508, 0xC, 4, &func_8005F0A4);
    func_8008A1CC(D_800C3508, 0xD, 8, &func_8005F0F8);
    func_8008A1CC(D_800C3508, 0xD, 4, &func_8005F11C);
    func_8008A1CC(D_800C3508, 0xE, 8, &func_8005F140);
    func_8008A1CC(D_800C3508, 0xE, 4, &func_8005F164);
    func_8008A1CC(D_800C3508, 0xF, 4, &func_8005F310);
    func_8008A1CC(D_800C3508, 0xF, 8, &func_8005F290);
    func_8008A1CC(D_800C3508, 0x11, 4, &func_8005F380);
    func_8008A1CC(D_800C3508, 0x11, 8, &func_8005F380);
    func_8008A1CC(D_800C3508, 0x12, 0x10, &func_8005F57C);
    func_8008A1CC(D_800C3508, 0x13, 0x10, &func_8005F3FC);
    func_8008A1CC(D_800C3508, 0x15, 0x10, &func_8005F430);
    func_8008A1CC(D_800C3508, 0x15, 0x20, &func_8005F430);
    func_8008A1CC(D_800C3508, 0x16, 0x10, &func_8005F460);
    func_8008A1CC(D_800C3508, 0x16, 0x20, &func_8005F430);
    func_8008A1CC(D_800C3508, 0x14, 0x10, &func_8005E928);
    func_8008A290(D_800C3508, 9, 0x20, &func_8005E928);
    func_8008A290(D_800C3508, 0xB, 0x20, &func_8005F53C);
    func_8008A1CC(D_800C3508, 0x18, 8, &func_8005FDF4);
    func_8008A1CC(D_800C3508, 0x18, 4, &func_8005FDF4);
    func_8008A1CC(D_800C3508, 0x19, 8, &func_8005FE80);
    func_8008A1CC(D_800C3508, 0x19, 4, &func_8005FE80);
    func_8008A1CC(D_800C3508, 0x17, 8, &func_8005FED0);
    func_8008A1CC(D_800C3508, 0x17, 4, &func_8005FED0);
    func_8008A1CC(D_800C3508, 0x1A, 8, &func_8005FF20);
    func_8008A1CC(D_800C3508, 0x1A, 4, &func_8005FF20);
    func_8008A1CC(D_800C3508, 0x1B, 8, &func_8005FF70);
    func_8008A1CC(D_800C3508, 0x1B, 4, &func_8005FFE0);
    func_8008A1CC(D_800C3508, 0x1C, 8, &func_80060054);
    func_8008A1CC(D_800C3508, 0x1C, 4, &func_800600D0);
    func_8008A1CC(D_800C3508, 0x1D, 8, &func_80060178);
    func_8008A1CC(D_800C3508, 0x1D, 4, &func_80060178);
    func_8008A1CC(D_800C3508, 0x1E, 8, &func_8005FE30);
    func_8008A1CC(D_800C3508, 0x1E, 4, &func_8005FE30);
    func_8008A1CC(D_800C3508, 0x1F, 8, &func_800601B4);
    func_8008A1CC(D_800C3508, 0x1F, 4, &func_800601B4);
    func_8008A1CC(D_800C3508, 0x20, 8, &func_80060204);
    func_8008A1CC(D_800C3508, 0x20, 4, &func_80060204);
    func_8008A1CC(D_800C3508, 0x21, 8, &func_80060254);
    func_8008A1CC(D_800C3508, 0x21, 4, &func_80060254);
    func_8008A1CC(D_800C3508, 0x22, 8, &func_800602A4);
    func_8008A1CC(D_800C3508, 0x22, 4, &func_800602A4);
    func_8008A1CC(D_800C3508, 0x23, 0x10, &func_8005E928);
    func_8008A290(D_800C3508, 0xA, 0x20, &func_8005E928);
    func_8008A270(D_800C3508, 0xC, 3);
    func_8008A290(D_800C3508, 0xC, 0x10000, &func_8005E250);
    if (D_800A13B0 != 0) {
        D_800A13B0 = 0;
        M2C_FIELD(D_800C3508, s16 *, 2) = 5;
        return;
    }
    if (D_800A13B1 != 0) {
void *__branch_temp_a0;
void *__branch_state;

        __branch_state=D_800C3508;
        __branch_temp_a0=D_800A1468;
        M2C_FIELD(__branch_state, s16 *, 2) = 7;
        *(Copy5*)((u8*)__branch_temp_a0+0x2a1)=*(Copy5*)&D_800A5384;
        D_800A13B0 = 0;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8005D844;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8005D84C;
        return;
    }
    if (D_800A13B2 != 0) {
void *__branch_temp_a0_;
void *__branch_state_;

        __branch_state_=D_800C3508;
        __branch_temp_a0_=D_800A1468;
        M2C_FIELD(__branch_state_, s16 *, 2) = 0xC;
        *(Copy10*)((u8*)__branch_temp_a0_+0x2a1)=*(Copy10*)&D_800A538C;
        D_800A13B2 = 0;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8005D854;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8005D870;
        return;
    }
    if (M2C_FIELD(D_800C35A0, u16 *, 0x1E) == 7) {
        if (D_800A14D4 != 0) {
            *(s32*)0x800B6880 = 5;
            M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8005D88C;
            M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8005D8B0;
            return;
        }
        *(s32*)0x800B6880 = 5;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8005D88C;
        M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8005D8B0;
        return;
    }
    if (!(D_8009F640 & 0x40)) {
        D_8009F640 |= 0x40;
        func_80086A34(1);
        func_8000DA84();
        temp_s0 = D_800B3DA8;
        func_80037DE4(temp_s0, &D_800A5398);
        func_80086854(temp_s0);
        func_80086DE8((s32) (D_800C35E0 * 112.0f));
    }
    temp_a0 = M2C_FIELD(D_800C3508, void **, 0x10);
    M2C_FIELD(D_800C3508, s16 *, 2) = 8;
    M2C_FIELD(temp_a0, u8 *, 0xAE) = (u8) M2C_FIELD(temp_a0, u8 *, 0xAD);
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8005DC40;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8005DD2C;
}
