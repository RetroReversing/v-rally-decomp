#include "common.h"

extern s32 D_800B6AFC;
extern s32 D_8009CE8C[];
extern s32 D_8009CE90[];
extern s32 D_8009CE94[];
extern s32 D_8009CE80;
extern s32 D_8009CE84;
extern s32 D_8009CE88;
extern u8 *D_800C7F84;
void func_8002D8A0(void *, void *, void *);
void func_8002DA98(void *, void *);
void func_8002DFF4(void *, void *);
typedef struct Loc
{
  s32 sp10[3];
  s32 pad1C;
  s32 sp20[3];
  s32 pad2C;
  f32 sp30[8];
  f32 sp50[4][4];
  f32 sp90[4];
} Loc;
void func_8001B284(u8 *arg0, u8 *arg1, s32 arg2)
{
  Loc loc;
  u32 t0;
  u32 j;
  s32 x;
  f32 *dst;
  f32 *src;
  u8 *a1p;
  u8 *a3p;
  if ((*((u16 *) (D_800C7F84 + 0x20))) & 0x80)
  {
    x = *(s32 *)0x800B6AFC;
    *((s32 *) (arg1 + 0xC0)) = D_8009CE8C[arg2 * 3];
    *((s32 *) (arg1 + 0xC4)) = D_8009CE90[arg2 * 3] + ((x + ((s32) (((u32) x) >> 31))) >> 1);
    *((s32 *) (arg1 + 0xC8)) = D_8009CE94[arg2 * 3];
    if ((*((u16 *) (D_800C7F84 + 0x20))) & 0x40)
    {
      *((s32 *) (arg1 + 0xC4)) -= 0x28;
    }
  }
  else
  {
    *((s32 *) (arg1 + 0xC0)) = D_8009CE80;
    *((s32 *) (arg1 + 0xC4)) = D_8009CE84;
    *((s32 *) (arg1 + 0xC0)) = D_8009CE88;
  }
  func_8002D8A0(arg0, arg1 + 0xC0, loc.sp20);
  func_8002DA98(arg0, loc.sp30);
  loc.sp20[0] += *((s32 *) (arg0 + 0x14));
  loc.sp20[1] += *((s32 *) (arg0 + 0x18));
  loc.sp20[2] += *((s32 *) (arg0 + 0x1C));
  func_8002D8A0(loc.sp30, loc.sp20, loc.sp10);
  func_8002DFF4(loc.sp50, loc.sp30);
  t0 = 0;
  a3p = (u8 *) loc.sp10;
  loc.sp90[0] = (f32) (-loc.sp10[0]);
  loc.sp90[1] = (f32) (-loc.sp10[1]);
  a1p = arg1;
  loc.sp90[2] = (f32) (-loc.sp10[2]);
  loc.sp50[3][0] = (f32) (-loc.sp10[0]);
  loc.sp50[3][1] = (f32) (-loc.sp10[1]);
  loc.sp50[3][2] = (f32) (-loc.sp10[2]);
  do
  {
    j = 0;
    dst = (f32 *) (a1p + 0x40);
    src = (f32 *) (a3p + 0x40);
    do
    {
      *dst++ = *src++;
      j++;
    } while (j < 4);
    a3p += 0x10;
    a1p += 0x10;
    t0++;
  } while (t0 < 4);
}
