#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 a; u8 b; u8 c; u8 d; u8 e; } Rating;
typedef struct { u8 data[40]; } Unit;
typedef struct { u8 pad[0x44]; Unit units[4]; } Game;
typedef struct { u8 pad[6]; u8 active; u8 rest[57]; } Entry;
extern Rating D_800B0D80[];
extern Game *D_800C35A0;
extern Entry D_800C3756[];
s32 func_80098180(void *, void *);
void func_800545E4(void)
{
  u8 i;
  u8 j;
  for (i = 0; i < 12; i++)
  {
    if (D_800C3756[i].active == 1)
    {
      j = 0;
      while (func_80098180(&D_800C35A0->units[j], &D_800C3756[i]) != 0 && j < 4)
      {
        j++;
      }
      if (i < 8)
      {
        D_800B0D80[j].c += 9;
        D_800B0D80[4].c += 9;
      }
      else
      {
        D_800B0D80[j].d += 7;
        D_800B0D80[4].d += 7;
      }
    }
  }
}

