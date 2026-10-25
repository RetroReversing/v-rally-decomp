#include "common.h"

extern unsigned char D_800B0D94;
extern unsigned char D_800B0D95;
extern unsigned char D_800B0D96;
extern unsigned char D_800B0D97;
extern unsigned char D_800B0D98;
s32 func_8006FA8C();
extern char *D_800C35A0;
void func_80054740(void)
{
  s32 i;
  char *base;
  char *entry;

  i = 0;
  do {
    base = D_800C35A0;
    entry = base + (i & 0xFF) * 0x28;
    if (*(u16 *)(entry + 0x52) >= 0x65) {
      *(u8 *)(base + 0x2F) |= 1;
    }
    i++;
  } while ((u8)i < 4);
  if (D_800B0D94 + D_800B0D95 >= 0x64) {
    *(u8 *)(D_800C35A0 + 0x2F) |= 8;
  }
  if (D_800B0D96 + D_800B0D97 >= 0x64) {
    *(u8 *)(D_800C35A0 + 0x2F) |= 4;
  }
  if (D_800B0D98 >= 0x64) {
    *(u8 *)(D_800C35A0 + 0x2F) |= 2;
  }
  func_8006FA8C(base, i);
}
