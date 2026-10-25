#include "common.h"

typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } Chunk;
extern void *D_800A1468;
extern s32 D_800A14D0;
extern char D_800B6778[];
extern char D_800C02AE[];
s32 func_8005A388();
s32 func_8005C198();
s32 func_8007EE9C();
void func_8006603C();
void func_80066384();
void func_80066470();

s32 func_80065E40(s32 arg0, s32 arg1)
{
  char *base;
  Chunk *src;
  Chunk *dst;

  dst = (Chunk *)D_800B6778;
  base = *(char **)(D_800C02AE + 0x32F2);
  src = (Chunk *)(base + 0x44);
  do {
    *dst = *src;
    src++;
    dst++;
  } while (src != (Chunk *)(base + 0xE4));
  *(s8 *)((char *)D_800A1468 + 0x245) = 0;
  *(s16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x20) = 0;
  func_8005C198();
  if (D_800A14D0 != 0) {
    func_8007EE9C(D_800A14D0);
    D_800A14D0 = 0;
  }
  func_8005A388(arg0, arg1);
  *(void **)((char *)D_800A1468 + 0x288) = func_8006603C;
  *(void **)((char *)D_800A1468 + 0x28C) = func_80066384;
  *(void **)((char *)D_800A1468 + 0x290) = func_80066470;
  return 1;
}
