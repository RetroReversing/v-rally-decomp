#include "common.h"

void func_80005E3C(s32);
void func_8007EE9C(s32);
extern char D_800AE850[];

void func_80016870(char *arg0)
{
  char pad[8];
  char *s2;
  s32 n;
  s32 i;
  char *s0;

  s2 = arg0;
  n = *(u16 *)(*(char **)(s2 + 8) + 0x30);
  *(s32 *)(D_800AE850 + 0x82AC) = 0;
  i = 0;
  if (n != 0) {
    do {
      s0 = (char *)(i * 4);
      func_80005E3C(*(s32 *)(*(s32 *)((s32)s0 + *(s32 *)(s2 + 0x10)) + 0x90));
      i++;
      s0 = s0 + *(s32 *)(s2 + 0x10);
      func_8007EE9C(*(s32 *)s0);
    } while (i < n);
  }
  func_8007EE9C(*(s32 *)(s2 + 0x10));
  func_8007EE9C(*(s32 *)(*(char **)(s2 + 8) + 0x24));
}
