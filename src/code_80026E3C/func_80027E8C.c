#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern u8 D_800C02AE[];
extern s32 D_800C35A0;
s32 func_8001FEE8(void *);
void func_80027CFC(void *);
u8 func_80027D24(u8, s32);
u8 func_80027D7C(u8, s32);
s8 func_80027DB4(s8, s32, u8);
s32 func_80085374(s32);
s8 func_80085714(s32, s32);
void func_80027E8C(void *arg0, s32 arg1, s8 *arg2)
{
  u32 s2;
  s8 axis;
  u8 *p;
  arg2[1] = 0;
  arg2[0] = 0;
  s2 = func_80085374(arg1 & 255);
  arg2[1] = arg2[1] & 0xEF;
  if (s2 & 0x10) {
    arg2[1] = arg2[1] | 0x10;
  }
  if (s2 & 0x80) {
    arg2[1] |= 0x80;
  }
  if (s2 & 1) {
    arg2[4] = func_80027D24(arg2[4], 255); } else {
    arg2[4] = func_80027D24(arg2[4], 0);
  }
  if (s2 & 2) {
    arg2[5] = func_80027D7C(arg2[5], 255); } else {
    arg2[5] = func_80027D7C(arg2[5], 0);
  }
  *(s32 *)(D_800C02AE + 0x8062 + arg1 * 4) = func_8001FEE8(arg0);
  switch (s2 & 0xC) {
  case 4:
    arg2[0] = func_80027DB4(arg2[0], -128, arg1 & 255);
    break;
  case 8:
    arg2[0] = func_80027DB4(arg2[0], 127, arg1 & 255);
    break;
  case 12:
    arg2[0] = func_80027DB4(arg2[0], 0, arg1 & 255);
  default:
    arg2[0] = func_80027DB4(arg2[0], 0, arg1 & 255);
    break;
  }
  axis = func_80085714(arg1 & 255, 0x200);
  if (axis != 0) {
    arg2[0] = axis;
  }
  if (*(s32 *)(*(u8 **)((u8 *)arg0 + 0x24) + 4) != 1) {
    p = (u8 *)D_800C35A0 + *(u8 *)(D_800C35A0 + (*(u8 **)((u8 *)arg0 + 0x48))[3] + 0x32) * 0x28;
    if (p[0x48] & 0x10) {
      if ((s2 & 0x21) == 0x21) {
        arg2[1] = 0x20;
      }
      if ((s2 & 0x21) == 0x20) {
        arg2[1] = 0x40;
      }
    } else {
      if (s2 & 0x20) {
        arg2[1] = 0x20;
      }
      if (s2 & 0x40) {
        arg2[1] = 0x40;
      }
    }
  }
  func_80027CFC(arg2);
}
