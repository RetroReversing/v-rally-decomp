#include "common.h"

s32 func_8003354C();
s32 func_80033724();
extern s32 D_8009F4F0;
extern s32 D_8009F4F4;
extern s32 D_8009F4F8;
extern s32 D_8009F4FC;
extern s32 D_8009F510;
extern s32 D_8009F514;
extern s32 D_8009F520;
extern s32 D_8009F524;
extern s32 D_8009F528;
extern s32 D_8009F52C;
extern s32 D_8009F540;
extern s32 D_8009F544;
extern s32 D_8009F550;
extern s32 D_8009F554;
extern s32 D_8009F558;
extern s32 D_8009F55C;
extern s32 D_8009F570;
extern s32 D_8009F574;

void func_80033A20(void *arg0)
{
  s32 k;

  D_8009F4F0 = *(s32 *)((u8 *)arg0 + 0x90) * 0x3C;
  D_8009F4F4 = *(s32 *)((u8 *)arg0 + 0xDC) * 0x3C;
  D_8009F4F8 = (*(s32 *)((u8 *)arg0 + 0x128) * 0xFF) / 100;
  D_8009F4FC = (*(s32 *)((u8 *)arg0 + 0x174) * 0xFF) / 100;
  D_8009F510 = *(s32 *)((u8 *)arg0 + 0x1C0);
  D_8009F520 = *(s32 *)((u8 *)arg0 + 0x20C) * 0x3C;
  D_8009F524 = *(s32 *)((u8 *)arg0 + 0x258) * 0x3C;
  D_8009F528 = (*(s32 *)((u8 *)arg0 + 0x2A4) * 0xFF) / 100;
  D_8009F52C = (*(s32 *)((u8 *)arg0 + 0x2F0) * 0xFF) / 100;
  D_8009F540 = *(s32 *)((u8 *)arg0 + 0x33C);
  D_8009F550 = *(s32 *)((u8 *)arg0 + 0x388) * 0x3C;
  D_8009F554 = *(s32 *)((u8 *)arg0 + 0x3D4) * 0x3C;
  D_8009F558 = (*(s32 *)((u8 *)arg0 + 0x420) * 0xFF) / 100;
  D_8009F55C = (*(s32 *)((u8 *)arg0 + 0x46C) * 0xFF) / 100;
  D_8009F570 = *(s32 *)((u8 *)arg0 + 0x4B8);
  k = 0x19; D_8009F514 = *(s32 *)((u8 *)arg0 + 0x504) * k;
  D_8009F544 = *(s32 *)((u8 *)arg0 + 0x504) * k;
  D_8009F574 = *(s32 *)((u8 *)arg0 + 0x504) * k;
  func_80033724();
  func_8003354C();
}
