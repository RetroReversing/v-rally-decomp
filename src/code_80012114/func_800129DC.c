#include "snapshot29_0433f7af8f6d.h"

extern signed char D_800C8200;
extern short D_800C8202;
extern int D_800C8204;
extern int D_800C820C;
extern int D_800C8208;
extern int D_800C8210;
extern unsigned char D_800C81FD;
extern int D_800C81F8;
extern unsigned short D_800C8236;
extern char D_800C02AE[];
extern char D_8009BA70[];
extern char D_800A40BC[];
extern char D_800A40C4[];
extern char D_800A40D0[];
extern char D_800A40DC[];

s32 func_8000BF2C();
void func_8000C1EC();
void func_8000C200(s32, f32, f32, f32);
void func_8000C22C();
s32 func_80034FF0();
void func_80081540();
s32 func_80081664();

void func_800129DC(void *arg0)
{
    s32 alpha=255;
    s32 obj;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;

    *(s32 *)((char *)arg0 + 0x8C) = 0;
    *(s16 *)((char *)arg0 + 0x84) = 0;
    D_800C8200 = 0;
    D_800C8202 = 0;
    func_80081540(&D_800A40BC);
    temp_v0 = func_80081664(6, &D_800A40C4);
    D_800C8204 = temp_v0;
    temp_v0_2 = func_8000BF2C(temp_v0);
    D_800C820C = temp_v0_2;
    func_8000C200(temp_v0_2, 1.0f, 1.0f, 1.0f);
    obj = D_800C820C;
    func_8000C22C(obj, alpha, alpha, alpha, alpha);
    func_8000C1EC(D_800C820C, 0x80, 0x30);
    temp_v0_3 = func_80081664(6, &D_800A40D0);
    D_800C8208 = temp_v0_3;
    temp_v0_4 = func_8000BF2C(temp_v0_3);
    D_800C8210 = temp_v0_4;
    func_8000C200(temp_v0_4, 1.0f, 1.0f, 1.0f);
    obj = D_800C8210;
    func_8000C22C(obj, alpha, alpha, alpha, alpha);
    func_8000C1EC(D_800C8210, 0x80, 0x33);
    if (D_800C81FD == 5) {
        func_80081540(&D_800A40DC);
        D_800C81F8 = func_80034FF0(*(s32 *)(D_8009BA70 + (D_800C8236 * 4)), 0);
        return;
    }
    D_800C81F8 = 0;
}
