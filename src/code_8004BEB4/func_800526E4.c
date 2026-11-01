#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 pad0[0x10]; u16 flags; u8 pad12[0x2C4 - 0x12]; } RCar;
typedef struct { s32 w[0x28]; } Cfg;
typedef struct { u8 pad0[0x44]; Cfg cfg; } Game;
typedef struct {
  s32 a[4];
  s16 b[12];
  u8 c[12][4];
  s32 e[17][4];
  s32 d[4];
  Cfg cfg;
  u8 pad218[2];
  u8 x21A;
} Race;
typedef struct { u16 count; u8 pad2[0x1E]; u8 *cars; } RaceInfo;
extern RaceInfo D_800D0628;
extern Game *D_800C35A0;

void func_800526E4(Race *r)
{
  u32 i;
  u32 j;
  u8 *car;

  for (i = 0; i < 4; i++) r->a[i] = 0;
  car = D_800D0628.cars;
  for (i = 0; i < D_800D0628.count; i++) {
    *(u16 *)(car + 0x10) &= ~2;
    car += 0x2C4;
  }
  for (i = 0; i < D_800D0628.count; i++) r->b[i] = 0;
  for (j = 0; j < 4; j++) {
    for (i = 0; i < D_800D0628.count; i++) {
      r->e[i][j] = 0;
      r->c[i][j] = 3;
    }
    r->d[j] = 0;
  }
  r->cfg = D_800C35A0->cfg;
  r->x21A = 1;
}
