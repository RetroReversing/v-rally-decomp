#include "common.h"

typedef struct { s32 w0; s32 w1; s32 w2; s32 w3; } Chunk;
extern char D_800A2590[];
extern char D_800AFAE8[];
extern char D_800B42E4[];
extern char D_800C02AE[];
s32 func_8000E20C();
s32 osViBlack();
s32 osViSetEvent();
s32 osViSetMode();
s32 osViSetSpecialFeatures();
void osViSetYScale(f32);
s32 osCreateViManager();

s32 func_80005890(void)
{
  char *base;
  Chunk *src;
  Chunk *dst;

  func_8000E20C(0x2217);
  osCreateViManager(0xFE);
  dst = (Chunk *)D_800AFAE8;
  base = D_800A2590;
  src = (Chunk *)(base + 0x730);
  do {
    *dst = *src;
    src++;
    dst++;
  } while (src != (Chunk *)(base + 0x780));
  osViSetMode(D_800AFAE8);
  osViSetYScale(1.0f);
  osViBlack(1);
  D_800C02AE[0x5BA6] = 4;
  osViSetEvent(D_800B42E4, 0, 1);
  osViSetSpecialFeatures(0x4A);
  return 1;
}
