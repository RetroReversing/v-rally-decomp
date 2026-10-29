#include "snapshot29_0433f7af8f6d.h"

typedef s32 M2C_UNK;
extern volatile f32 D_8009CEC0[];
#define D_8009CEC0 (*D_8009CEC0)
extern volatile f32 D_8009CEC4;
extern volatile f32 D_8009CEC8;
extern s32 D_8009D4EC;
extern s32 D_800AE850;
void func_800154A8(void *, s32, s32);

void func_8001A19C(void *arg0) {
    s32 a1;
    s32 a2;
    s32 *p24;
    s16 *p18;
    s16 *p1c;
    s16 *p1a;
    s16 *p1e;
    s16 *p20;
    s16 *p22;
    s16 t22;
    f32 scale8;
    f32 val22;
    p24 = (s32 *)((s8 *)arg0 + 0x24);
    *p24 += *(s32 *)((s8 *)&D_800AE850 + 0x6E9C);
    p18 = (s16 *)((s8 *)arg0 + 0x18);
    p1c = (s16 *)((s8 *)arg0 + 0x1C);
    p1a = (s16 *)((s8 *)arg0 + 0x1A);
    p1e = (s16 *)((s8 *)arg0 + 0x1E);
    p20 = (s16 *)((s8 *)arg0 + 0x20);
    p22 = (s16 *)((s8 *)arg0 + 0x22);
    *p18 = (s16)(s32)((f32)*p18 * D_8009CEC0);
    *p1c = (s16)(s32)((f32)*p1c * D_8009CEC0);
    *p1a = (s16)(s32)((f32)*p1a * D_8009CEC4);
    *p1e = (s16)(s32)((f32)*p1e * D_8009CEC4);
    *p20 = (s16)(s32)((f32)*p20 * D_8009CEC8);
    t22 = *p22;
    scale8 = D_8009CEC8;
    val22 = (f32)t22 * scale8;
    a2 = D_8009D4EC;
    a1 = 2;
    *p22 = (s16)(s32)val22;
    func_800154A8((s8 *)arg0 + 0x28, a1, a2);
}
