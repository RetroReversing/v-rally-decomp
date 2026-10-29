#include "snapshot29_0433f7af8f6d.h"

extern char D_800C02AE[];
extern f32 D_800C35D8;
extern void *D_800C81D4;
extern s32 D_800B0BC4;
extern char D_800AE850[];
extern s32 D_8009FBCC;
extern s32 D_8009FCE4;
extern char D_A7FE0[];
extern char D_ABE70[];
extern s32 func_80038F64(u8);
extern void *func_8007EAA0(s32, s32, s32, s32);
extern s32 func_8007ED48(s32, s32, s32);
typedef struct 
{
  s32 w[5];
} Args5;
extern s32 func_80081040(s32 *, s32, s32, s32, Args5);
extern s32 func_800864F8(s32 *);
extern s32 MusSetMasterVolume(s32, s32);
extern s32 func_80089980(void);
s32 func_80037AA4(s32 arg0, s32 arg1)
{
  s32 i;
  s32 *p;
  s32 sp[16];
  f32 volume = 0.625f;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331A)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331C)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331D)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331E)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331F)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x3320)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x3321)) = 255;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x331B)) = 0;
  *((u8 *) (((s8 *) (&D_800C02AE)) + 0x333E)) = 1;
  *((f32 *) (((s8 *) (&D_800C02AE)) + 0x332A)) = volume;
  *((f32 *) (((s8 *) (&D_800C02AE)) + 0x332E)) = volume;
  *((f32 *) (((s8 *) (&D_800C02AE)) + 0x3332)) = volume;
  *((f32 *) (((s8 *) (&D_800C02AE)) + 0x3336)) = 70.0f;
  *((f32 *) (((s8 *) (&D_800C02AE)) + 0x333A)) = volume;
  {
    s32 allocation = func_8007ED48(1, 0x4650, 8);
    func_80081040((s32 *) (&D_A7FE0), D_800B0BC4 = allocation, ((s32) (&D_ABE70)) - ((s32) (&D_A7FE0)), *((s32 *) (((s8 *) (&D_800AE850)) + 0x2358)), *((Args5 *) (D_800AE850 + 0x235C)));
  }
  sp[0] = 0;
  sp[1] = arg0 & 255;
  sp[2] = 6;
  sp[3] = *((s32 *) (D_800C02AE + 0x325E));
  sp[4] = 0x48440;
  sp[5] = D_800B0BC4;
  {
    extern char D_000ABE70[];
    sp[6] = (s32) D_000ABE70;
  }
  sp[7] = (s32) (&D_8009FBCC);
  sp[8] = (s32) (&D_8009FCE4);
  sp[10] = 0x5622;
  sp[9] = 0x100;
  sp[11] = 0x1000;
  sp[12] = 1;
  sp[13] = arg1 & 255;
  sp[14] = 0x1000;
  ((u8 *) sp)[60] = 28;
  ((u8 *) sp)[61] = 50;
  *((void **) (D_800C02AE + 0x7F26)) = func_8007EAA0(1, 0x1D4, sp[3], sp[5]);
  i = 0;
  func_80038F64(*((u8 *) (((s8 *) (&D_800C02AE)) + 0x32AD)));
  p = (s32) (*((void **) (((s8 *) (&D_800C02AE)) + 0x7F26)));
  p[0x6C / 4] = 0x10;
  p[0x60 / 4] = 0x11;
  p[0x54 / 4] = 0x12;
  p[0x84 / 4] = 0x16;
  p[0x90 / 4] = 0x14;
  p[0x9C / 4] = 0x17;
  p[0xA8 / 4] = 0x18;
  p[0xB4 / 4] = 0x15;
  p[0xC0 / 4] = 0x19;
  p[0x78 / 4] = 0x1A;
  p[0xF0 / 4] = 0x22;
  p[0xFC / 4] = 0x13;
  p[0x108 / 4] = 0x23;
  p[0x114 / 4] = 0x24;
  p[0x120 / 4] = 0x1B;
  p[0x12C / 4] = 0x1E;
  p[0x138 / 4] = 0x26;
  p[0x144 / 4] = 0x27;
  p[0x150 / 4] = 0x28;
  p[0x15C / 4] = 0x29;
  p[0x168 / 4] = 0x2A;
  p[0x174 / 4] = 0x2B;
  p[0x180 / 4] = 0x2C;
  p[0x18C / 4] = 0x2D;
  p[0x198 / 4] = 0x2E;
  p[0x1A4 / 4] = 0x2F;
  p[0x1B0 / 4] = 0x30;
  p[0x1BC / 4] = 5;
  p[0x1C8 / 4] = 0x45;
  for (; i < 0x27; i++)
  {
    *((((u8 *) D_800C81D4) + (i * 12)) + 8) = 0;
  }

  i = func_800864F8(sp);
  MusSetMasterVolume(3, (s32) (D_800C35D8 * 32767.0f));
  func_80089980();
  return i;
}
