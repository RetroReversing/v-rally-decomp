#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  u8 b[32];
} Tab;
typedef struct 
{
  u8 pad[0x14];
  u16 n;
  u8 pad2[0x2AE];
} Ent;
extern Tab D_800A51F4;
extern u8 D_800A1548[];
extern u8 D_800C832C[];
extern Ent *D_800D0634;
extern Ent *D_800D0648;
void func_80057490(void)
{
  Tab local;
  u32 t0;
  u8 a3;
  u8 o;
  u8 a2;
  local = D_800A51F4;
  t0 = 0;
  for (o = 0; o < 8; o++)
  {
    D_800C832C[o] = 0;
  }

  o = 0;
  a2 = 0;
  do
  {
    for (a2 = 0; a2 < D_800D0648[o].n; a2++)
    {
      if (local.b[(u8) t0])
      {
        if (o < 8)
        {
          D_800C832C[o] |= 1 << a2;
        }
        else
        {
          u8 idx = D_800A1548[o];
          s32 n=D_800D0634[idx].n; s32 shift=a2-2; D_800C832C[idx] |= 1 << (n+shift);
        }
      }
      t0++;
    }

    o++;
  }
  while (o < 12);
}
