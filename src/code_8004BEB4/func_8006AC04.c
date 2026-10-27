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

void *func_800051B4(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80005500(void *, s32);                 /* extern */
M2C_UNK func_800056FC(void *);                      /* extern */
M2C_UNK func_80005718(s32, void *);                 /* extern */
M2C_UNK func_80005838(void *);                      /* extern */
M2C_UNK func_80005A54(s32, s32);                    /* extern */
M2C_UNK func_8000E8B8(void *);                      /* extern */
M2C_UNK func_8000E8FC(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_8005A790(void);                     /* extern */
s32 func_8007F4E4(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_8007F634(s32);                         /* extern */
M2C_UNK func_8007F6E0(s32);                         /* extern */
extern s32 D_8009B5A4;
extern s32 D_8009B5A8;
extern u8 D_800A13B0;
extern u8 D_800A13B1;
extern u8 D_800A13B2;
extern M2C_UNK D_800C02AE;

void func_8006AC04(void) {
    s32 temp_s1;
    s32 temp_s2;
    void *temp_v0;

    if (((D_800A13B1 != 0) || (D_800A13B0 != 0) || (D_800A13B2 != 0)) && (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x1E) != 8)) {
        func_8005A790();
        return;
    }
    temp_s1 = func_8007F4E4(6, 2, 1);
    temp_s2 = func_8007F4E4(9, 2, 0x10);
    temp_v0 = func_800051B4(D_8009B5A4, 0, 0xBB8, 0xBB8, 0);
    M2C_FIELD(temp_v0, s8 *, 0x10) = 0;
    M2C_FIELD(temp_v0, s8 *, 0x11) = 0;
    M2C_FIELD(temp_v0, s8 *, 0x12) = 0;
    func_8000E8B8(temp_v0);
    func_80005500(temp_v0, D_8009B5A4);
    func_800056FC(temp_v0);
    func_8000E8FC(temp_v0, D_8009B5A4, 0);
    M2C_FIELD(&D_800C02AE, s8 *, 0x5BA6) = 1;
    func_80005718(D_8009B5A4, temp_v0);
    func_8007F6E0(temp_s2);
    func_80005A54(D_8009B5A4, D_8009B5A8);
    func_8007F6E0(temp_s1);
    func_80005A54(D_8009B5A4, D_8009B5A8);
    func_8007F6E0(temp_s1);
    func_80005A54(D_8009B5A4, D_8009B5A8);
    func_8007F6E0(temp_s1);
    func_80005838(temp_v0);
    func_8007F634(temp_s2);
    func_8007F634(temp_s1);
}
