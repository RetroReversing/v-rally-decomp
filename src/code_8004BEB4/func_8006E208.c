#include "common.h"

extern u8 D_800C02AE[];

void func_8006E208(void)
{
  u8 *base;
  u8 i;

  base = D_800C02AE + 0x6E76;
  i = 0;
  do {
    *(u8 *)((s32)base + i + 1) = 0xFF;
    i++;
  } while (i < 0xE1);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0xE2) = 0xFFFF;
    i++;
  } while (i < 0xC);
  i = 0;
  do {
    *(u8 *)((s32)base + i + 0xFA) = 0xFF;
    i++;
  } while (i < 0x51);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x14E) = 0xFFFF;
    i++;
  } while (i < 6);
  i = 0;
  do {
    *(u8 *)((s32)base + i + 0x14B) = 0;
    i++;
  } while (i < 3);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x15A) = 0xFFFF;
    i++;
  } while (i < 0x24);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x1A2) = 0xFFFF;
    i++;
  } while (i < 3);
}
