#include "snapshot29_0433f7af8f6d.h"

typedef struct S_func_80088D10_arg0
{
  u8 p0[8];
  s32 unk_08;
  u8 p1[0x30];
  s32 unk_3C;
  u8 p2[0x10];
  s32 unk_50;
  f32 unk_54;
  f32 unk_58;
  f32 unk_5C;
  s32 unk_60;
  u8 p3[0x53];
  u8 unk_B7;
  u8 unk_B8;
  u8 unk_B9;
  u8 unk_BA;
  u8 unk_BB;
  u8 unk_BC;
  u8 unk_BD;
  u8 unk_BE;
  u8 unk_BF;
  u8 unk_C0;
  u8 p4[4];
  u8 unk_C5;
} S_func_80088D10_arg0;
void func_80088D10(S_func_80088D10_arg0 *arg0)
{
  u8 phase;
  int value;
  f32 amount;
  f32 coef;
  f32 fvalue;
  if ((((u32) arg0->unk_08) >= ((u32) arg0->unk_50)) && (arg0->unk_BB < 4U))
  {
    arg0->unk_BB = 4;
    arg0->unk_BD = 1;
    arg0->unk_C5 = arg0->unk_BC;
  }
  arg0->unk_BD--;
  if (arg0->unk_BD)
  {
    return;
  }
  phase = arg0->unk_BB;
  arg0->unk_BD = arg0->unk_B7;
  if (1)
  {
    switch (phase)
    {
      case 1:
        value = (s32) (((((u32) (arg0->unk_08 - arg0->unk_3C)) >> 8) * ((u32) arg0->unk_60)) >> 10);
        if (value < arg0->unk_BE)
      {
        fvalue = (f32) value;
        coef = arg0->unk_54;
        arg0->unk_BC = arg0->unk_B8 + ((s32) (coef * fvalue));
      }
      else
      {
        arg0->unk_BB = phase + 1;
        arg0->unk_BC = arg0->unk_B9;
      }
        break;

      case 2:
        value = (s32) ((((((u32) (arg0->unk_08 - arg0->unk_3C)) >> 8) - arg0->unk_BE) * ((u32) arg0->unk_60)) >> 10);
        if (value < arg0->unk_BF)
      {
        ;
        arg0->unk_BC = arg0->unk_B9 + ((s32) (arg0->unk_58 * ((f32) value)));
      }
      else
      {
        arg0->unk_BB = phase + 1;
        arg0->unk_BC = arg0->unk_BA;
      }
        break;

      case 3:
        break;

      case 4:
        value = (s32) (((((u32) (arg0->unk_08 - arg0->unk_50)) >> 8) * ((u32) arg0->unk_60)) >> 10);
        if (value < arg0->unk_C0)
      {
        ;
        amount = arg0->unk_5C * (f32)value;
        arg0->unk_BC = arg0->unk_C5 - (s32)(amount * (f32)arg0->unk_C5);
      }
      else
      {
        arg0->unk_BB = phase + 1;
        arg0->unk_BC = 0;
      }
        break;

    }

  }
}
