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
extern unsigned char D_800C355B;
extern float D_800C35E0;
extern float D_800C35D8;
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A140();
s32 func_8000D9CC();
s32 func_8000DA84();
s32 func_8000E774();
s32 func_8000F660();
s32 func_80014388();
s32 func_8001BBE4();
s32 func_80037DE4();
s32 func_800388A0();
s32 func_800388CC();
s32 func_80038F64();
s32 func_80040770();
s32 func_800415EC();
s32 func_80054838();
s32 func_800553B0();
s32 func_80057694();
s32 func_8005792C();
s32 func_8005A790();
s32 func_80066B88();
s32 func_8006B7D4();
s32 func_8007EAA0();
s32 func_8007F050();
s32 func_80080080();
s32 func_800811E0();
s32 func_80081514();
s32 func_80084AA0();
s32 func_80084DD4();
s32 func_80086854();
s32 func_80086A34();
s32 func_80086A94();
s32 MusSetMasterVolume(s32, s32);                /* extern */
s32 func_80086DE8();
s32 func_80089980();
s32 memset();
extern char D_15DB10[];
extern s32 *D_8009B770;
extern s32 D_8009B9D8;
extern s32 D_8009F640;
extern char D_800A3F60[];
extern char D_800A3F6C[];
extern char D_800A3F74[];
extern char D_800A3F80[];
extern char D_800A3F90[];
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern char D_BB9470[];
extern s32 func_8000E3E4;
extern s32 func_8000E404;

extern s32 D_800B0BD0;
extern u8 D_800B65A0;
extern s32 D_800B6880;
extern void * D_800C35A0;
extern s32 D_800C7828;
extern s32 D_800C8124;
extern s32 D_800C837C;
extern u8 D_800C6F18[];
extern u8 D_800C7950[];
extern u8 D_800B7080[];
extern u8 D_800D03D0[];
void func_8000E428(void) {
    s32 *temp_v1;
    s32 temp_a0;
    s32 var_s0;
    void *temp_s0;
    s32 mode;

    memset((u8 *)D_800A73E0 + 0x6C0C, 0, 0x460);
    *(s32 * *)(D_800C02AE + 0x7DFE) = &func_8000E3E4;
    var_s0 = 0;
    func_80080080();
    temp_v1 = *(s32 * *)(D_800C02AE + 0x7DDE);
    *(s32 * *)(D_800C02AE + 0x7DDE) = &func_8000E404;
    D_8009B770 = temp_v1;
    func_800388A0();
    func_800811E0();
    func_800388CC();
    func_80081514(&D_15DB10, (u8 *)&D_BB9470 - (u8 *)&D_15DB10, 1);
    func_800553B0();
    func_80040770();
    func_800415EC();
    func_8001BBE4();
    func_8000A140();
    D_8009B9D8 = func_8007EAA0(3, 0x54C70);
    func_8000D9CC();
    func_80084AA0();
    func_8006B7D4();
    func_80038F64(D_800C355B);
    func_80054838();
    func_80014388();
    D_800B0BD0 = 0;
    D_800C837C = 0;
    D_800C7828 = 0;
    D_800C8124 = 0;
    M2C_FIELD(D_800C35A0, u16 *, 0x1E) = 7U;
    M2C_FIELD(D_800C35A0, s16 *, 0x20) = 0;
    M2C_FIELD(D_800C35A0, s16 *, 0x22) = 0;
    func_80057694();
    D_800B6880 = 5;
    func_8005792C();
    func_80066B88();
    D_800B65A0 = 0U;
    do {
        temp_a0 = var_s0 & 0xFF;
        if ((temp_a0 == D_800B65A0) && (func_80084DD4(temp_a0) != 0)) {
            D_800B65A0 = (u8) (D_800B65A0 + 1);
        }
        var_s0 += 1;
    } while ((u32) (var_s0 & 0xFF) < 2U);
    temp_s0 = (u8 *)D_800AE850 + 0x5558;
    func_80037DE4(temp_s0, &D_800A3F60);
    func_80086854(temp_s0);
    func_80086DE8((s32) (D_800C35E0 * 80.0f));
    mode = 7;
loop_6:
    func_80086A94();
    func_80089980();
    MusSetMasterVolume(3, (s32) (32767.0f * D_800C35D8));
    func_8005A790();
    if (M2C_FIELD(D_800C35A0, u16 *, 0x1E) == mode) {
        D_8009F640 &= ~0x80;
    } else {
        func_80086A34(1);
    }
    D_8009F640 &= ~0x40;
    func_8000DA84();
    func_80037DE4(D_800B7080, &D_800A3F6C);
    func_80037DE4(D_800C6F18, &D_800A3F74);
    func_80037DE4(D_800D03D0, &D_800A3F80);
    func_80037DE4(D_800C7950, &D_800A3F90);
    func_8000F660();
    if (D_800C7828 == 0) {
        D_800C7828 = func_8007F050(2);
    }
    if (D_800C8124 == 0) {
        D_800C8124 = func_8007F050(1);
    }
    func_8000E774();
    goto loop_6;
}
