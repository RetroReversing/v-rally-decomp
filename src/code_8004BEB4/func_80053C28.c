#include "snapshot31_verified.h"

extern s32 D_800A5060;
extern s32 D_800A5064;
extern s32 D_800A5068;
extern s32 D_800A506C;
extern s32 D_800A5070;
extern s32 D_800A5074;
extern s32 D_800A5078;
extern s32 D_800A507C;
extern s32 D_800A5080;
extern s32 D_800A5084;
extern s32 D_800A5088;
extern s32 D_800A508C;
extern s32 D_800A5090;
extern s32 D_800A5094;
extern s32 D_800A5098;
extern s32 D_800A50A0;
extern s32 D_800A50A4;
extern s32 D_800A50A8;
extern s32 D_800A50AC;
extern s32 D_800A50B0;
extern u8 *D_800C35A0;
extern s32 func_80098180(u8 *, u8 *);
void func_80053C28(s32 arg0, s32 arg1)
{
  s32 off = (arg0 &= 0xff) * 0x28;
  int new_var;
  s32 off44 = off + 0x44;
  s32 ok;
  s32 x;
  s32 limit;
  u8 i;
  u8 *base;
  u8 *p;
  u8 v;
  limit = 0x16;
  for (;;)
  {
    switch (arg1 & 0xff)
    {
      case 0:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5060;
        break;

      case 1:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5064;
        break;

      case 2:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5068;
        break;

      case 3:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A506C;
        break;

      case 4:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5070;
        break;

      case 5:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5078;
        break;

      case 6:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A507C;
        break;

      case 7:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5080;
        break;

      case 8:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5084;
        break;

      case 9:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5088;
        break;

      case 10:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A508C;
        break;

      case 11:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5090;
        break;

      case 12:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5094;
        break;

      case 13:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5098;
        break;

      case 14:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A50A0;
        break;

      case 15:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A50A4;
        break;

      case 16:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A50A8;
        break;

      case 17:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A50AC;
        break;

      case 18:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A50B0;
        break;

      case 19:

      case 20:

      case 21:

      case 22:

      default:
        *((s32 *) (((u8 *)(off + (s32)D_800C35A0)) + 0x44)) = D_800A5074;
        break;

    }

    ok = 1;
    i = 0;
    do
    {
      base = D_800C35A0;
      v = *(i + base + 0x32);
      if (arg0 != v)
      {
        p = base + ((v * 0x28) + 0x44);
        new_var = func_80098180(base + off44, p);
        x = new_var;
        ok &= -(x != 0);
      }
      if (!(ok & 0xff))
      {
        x = arg1 + 1;
        new_var = -(((x & 0xff) ^ limit) != 0);
        arg1 = x & new_var;
      }
      i++;
    }
    while (i < 4);
    if (ok & 0xff)
    {
      break;
    }
  }

}
