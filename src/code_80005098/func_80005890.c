#include "common.h"

typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } Chunk;
extern char D_800A2590[];
extern char D_800AFAE8[];
extern char D_800B42E4[];
extern char D_800C02AE[];
s32 func_8000E20C();
s32 func_8008F140();
s32 func_8008F200();
s32 func_8008F260();
s32 func_8008F2B0();
void func_8008F420(f32);
s32 func_80090E70();

s32 func_80005890(void)
{
  char *base;
  Chunk *src;
  Chunk *dst;

  func_8000E20C(0x2217);
  func_80090E70(0xFE);
  dst = (Chunk *)D_800AFAE8;
  base = D_800A2590;
  src = (Chunk *)(base + 0x730);
  do {
    *dst = *src;
    src++;
    dst++;
  } while (src != (Chunk *)(base + 0x780));
  func_8008F260(D_800AFAE8);
  func_8008F420(1.0f);
  func_8008F140(1);
  D_800C02AE[0x5BA6] = 4;
  func_8008F200(D_800B42E4, 0, 1);
  func_8008F2B0(0x4A);
  return 1;
}
