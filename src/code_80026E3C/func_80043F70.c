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

extern int D_800C8328;
extern int D_800B6880;
s32 func_800056FC();
void *func_80006008();
s32 func_80006014();
s32 func_800061FC();
s32 func_80006298();
s32 func_800068C0();
s32 func_80006CF8();
s32 func_80007404();
s32 func_8000C22C();
s32 func_8000C244();
s32 func_8000C9B0(void *, void *, s32, f32, s32);
s32 func_8001BD1C();
s32 *func_80057918();
s32 func_80084BF0();
s8 func_80084C0C();
s32 func_80084DD4();
s32 func_80085778();
s32 func_800857A0();
s32 func_80099DF8();
s32 guMtxF2L(s32 *, s32);                   /* extern */
s32 guMtxIdent(void *);                         /* extern */
s32 guOrthoF(s32 *, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern s32 D_8009D538;
extern s32 D_800A0200;
extern char D_800A0208[];
extern s32 D_800A1234;
extern char D_800A4E04[];
extern char D_800A4E18[];
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80043F70(void **arg0) {
    char sp48[32];
    f32 sp68[16];
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a3;
    s32 var_a3_2;
    u16 y;
    s16 temp_s0_3;
    s16 temp_s1;
    s32 temp_s0_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s8 temp_v0_5;
    u16 temp_s2_2;
    u16 temp_v0_6;
    void *temp_s0;
    void *temp_s1_2;
    void *temp_s3;
    void *temp_s6;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_7;
    void *temp_v1;
    void *var_a0;
    void *text;
    void *q1,*q2,*q3;
    s32 resetBase;

    temp_s0 = D_800C02AE + 0x80D2;
    guMtxIdent(temp_s0);
    temp_v0 = func_800056FC(M2C_FIELD(*(void * *)(D_800C02AE + 0x7CD6), void **, 0x178));
    temp_v0_2 = func_80006008(temp_v0);
    M2C_FIELD(temp_v0_2, s32 *, 0) = 0xDA380003;
    M2C_FIELD(temp_v0_2, void **, 4) = temp_s0;
    func_80006014(temp_v0, temp_v0_2 + 8);
    temp_s0_2 = func_8001BD1C();
    temp_v1 = M2C_FIELD(*(void * *)(D_800C02AE + 0x7CD6), void **, 0x178); guOrthoF(&sp68, (f32) M2C_FIELD(temp_v1, s16 *, 8), (f32) M2C_FIELD(temp_v1, s16 *, 0xC), (f32) M2C_FIELD(temp_v1, s16 *, 0xE), (f32) M2C_FIELD(temp_v1, s16 *, 0xA), -1.0f, 10.0f, 1.0f);
    guMtxF2L(&sp68, temp_s0_2);
    func_800061FC(temp_v0, temp_s0_2);
    temp_s3 = *arg0;
    M2C_FIELD(temp_s3, s8 *, 0xF) = 0;
    temp_s0_3 = ((s32) (0x140 - (func_8000C9B0(temp_s3 + 0x10, &D_800A4E04, 1, 1.0f, 0) & 0xFFFF)) / 2) - 0xA;
    temp_v0_3 = func_80006008(temp_v0);
    M2C_FIELD(temp_v0_3, s32 *, 0) = 0xDE000000;
    M2C_FIELD(temp_v0_3, s32 **, 4) = &D_800A0208;
    func_80006014(temp_v0, temp_v0_3 + 8);
    temp_s2 = func_80006CF8(temp_v0, 0) & 0xFFFF;
    temp_s1 = 0x140 - temp_s0_3;
    func_800068C0(temp_v0, temp_s2, temp_s0_3, 0x3C, 0, (s32) temp_s0_3, 0xAF, 0, (s32) temp_s1, 0xAF, 0, (s32) temp_s1, 0x3C, 0);
    func_80007404(temp_v0, temp_s2, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA, 0x1E, 0x32, 0x94, 0xAA);
    func_80006298(temp_v0);
    var_s0=0;
    if (M2C_FIELD(*(void **)(D_800C02AE+0x32F2),u16 *,0xE)!=0) do {
        if (!func_80084DD4(var_s0 & 255)) goto fail;
        var_s0++;
    } while ((u16)var_s0 < M2C_FIELD(*(void **)(D_800C02AE+0x32F2),u16 *,0xE));
block_3:
    temp_s6 = **(void ** *)(D_800AE850 + 0x73F0);
    if ((M2C_FIELD(temp_s6, s32 *, 0x14) & 0x200) && !(D_8009D538 & 1)) {
        temp_s2_2 = M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x36);
        func_8000C22C(M2C_FIELD(temp_s3, s32 *, 0x10), 0xFF, 0xFF, 0xFF, 0xFF);
        temp_s1_2 = temp_s3 + 0x10;
        var_s0 = func_8000C9B0(temp_s1_2, func_80057918(D_800C8328, 0xEE), 1, 1.0f, 0);
        func_8000C22C(M2C_FIELD(temp_s3, s32 *, 0x10), 0xDC, 0xDC, 0x80, 0xFF);
        text=func_80057918(D_800C8328, 0xEE);
        func_8000C244(M2C_FIELD(temp_s3, s32 *, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), 0x46, text, 0);
        func_8000C22C(M2C_FIELD(temp_s3, s32 *, 0x10), 0xFF, 0xFF, 0xFF, 0xFF);
        func_80099DF8(&sp48, &D_800A4E18, func_80057918(D_800C8328, 0xEF), temp_s2_2);
        func_8000C244(M2C_FIELD(temp_s3, s32 *, 0x10), temp_v0, 0xA0 - ((u32) (func_8000C9B0(temp_s1_2, &sp48, 1, 1.0f, 0) & 0xFFFF) >> 1), 0x5A, &sp48, 0);
        y=125;
        if (M2C_FIELD(temp_s3, u16 *, 0xC) == 0) {
            func_8000C22C(M2C_FIELD(temp_s3,s32 *,0x10),254,213,30,255);
        } else {
            func_8000C22C(M2C_FIELD(temp_s3,s32 *,0x10),255,255,255,255);
        }

        var_s0 = func_8000C9B0(temp_s3 + 0x10, func_80057918(D_800C8328, 0xF0), 1, 1.0f, 0);
        text=func_80057918(D_800C8328, 0xF0);
        func_8000C244(M2C_FIELD(temp_s3, s32 *, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), y, text, 0);
        y+=20;
        if (M2C_FIELD(temp_s3, u16 *, 0xC) != 0) {
            func_8000C22C(M2C_FIELD(temp_s3,s32 *,0x10),254,213,30,255);
        } else {
            func_8000C22C(M2C_FIELD(temp_s3,s32 *,0x10),255,255,255,255);
        }

        var_s0 = func_8000C9B0(temp_s3 + 0x10, func_80057918(D_800C8328, 0xF1), 1, 1.0f, 0);
        text=func_80057918(D_800C8328, 0xF1);
        func_8000C244(M2C_FIELD(temp_s3, s32 *, 0x10), temp_v0, 0xA0 - ((u32) (var_s0 & 0xFFFF) >> 1), y, text, 0);
        temp_v0_4 = func_80084BF0(0);
        func_80085778(0, temp_v0_4);
        temp_v0_5 = func_80084C0C(0, 0x10000);
        if (((temp_v0_5 >= 90 || (temp_v0_4 & 0x800)) && M2C_FIELD(temp_s3,u16 *,0xC)) ||
            ((temp_v0_5 < -89 || (temp_v0_4 & 0x400)) && !M2C_FIELD(temp_s3,u16 *,0xC))) {
            M2C_FIELD(temp_s3,u16 *,0xC)=1-M2C_FIELD(temp_s3,u16 *,0xC);
        }
        if (temp_v0_4 & 0x8000) {
            if (M2C_FIELD(temp_s3, u16 *, 0xC) != 0) {
                goto cancel;
            } else {
                temp_v0_6 = M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x36);
                if (temp_v0_6 != 0) {
                    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x36) = (u16) (temp_v0_6 - 1);
                }
                var_a0 = **(void ** *)(D_800AE850 + 0x73F0);
                D_800A0200 = 1;
                if (var_a0 != NULL) {
                    resetBase=D_800A1234;
                    do {
                        temp_v1_2 = *M2C_FIELD(var_a0, s32 **, 0x48);
                        if (temp_v1_2 < 5) {
                            q1=resetBase + (temp_v1_2 * 0x44);
                            M2C_FIELD(q1,s16 *,0xA)=3;
                            temp_v0_7 = resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(temp_v0_7, u16 *, 8) &= 0xFDFF;
                            q2=resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q2,s16 *,0xC)=0;
                            q3=resetBase + (*M2C_FIELD(var_a0, s32 **, 0x48) * 0x44);
                            M2C_FIELD(q3,s16 *,0xE)=0;
                            M2C_FIELD(M2C_FIELD(var_a0, void **, 0x44), s32 *, 0x28) = -1;
                            M2C_FIELD(M2C_FIELD(var_a0, void **, 0x70), s32 *, 0x28) = -1;
                        }
                        var_a0 = M2C_FIELD(var_a0, void **, 4);
                    } while (var_a0 != NULL);
                }
                func_800857A0(0);
                M2C_FIELD(temp_s3, u8 *, 0xE) = 1U;
                M2C_FIELD(temp_s3, u16 *, 0xC) = 0U;
            }
        }
        goto check;
fail:
        D_8009D538 |= 2;
        return;
cancel:
        M2C_FIELD(temp_s3, u8 *, 0xE) = 0U;
        func_80085778(0,0x8000);
check:
        if (M2C_FIELD(temp_s3, u8 *, 0xE) == 0) {
            D_800B6880 = 1;
            M2C_FIELD(temp_s3, s8 *, 0xF) = 1;
            var_a0=*(void **)(D_800C02AE+0x32F2);
            M2C_FIELD(temp_s6, s32 *, 0x14) &= ~0x200;
            M2C_FIELD(var_a0, u16 *, 0x36) = 0U;
        }
    }
}
