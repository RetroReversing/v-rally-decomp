#include "common.h"

extern char D_8009BEE8[];

void func_80015B2C(void *arg0)
{
  char pad[8];
  u32 i;
  void *s2;
  u8 *s0;

  s2 = *(void **)((u8 *)arg0 + 0x44);
  i = 0;
  s0 = (u8 *)s2 + 0x24;
  if (*(u32 *)((u8 *)s2 + 0x20) != 0) {
    do {
      u32 off = *(u16 *)(s0 + 6) * 4;
      ((void (*)(void *))(*(void **)(D_8009BEE8 + off)))(s0);
      i++;
      s0 += 8;
    } while (i < *(u32 *)((u8 *)s2 + 0x20));
  }
}
