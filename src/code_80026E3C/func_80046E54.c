#include "decompdecomp_snapshot_80046e54.h"
#line 1 "func.c"
typedef struct Stat
{
  u8 pad00[0x44];
  s32 v;
  u8 pad48[4];
} Stat;
typedef struct Slot
{
  u8 pad00[7];
  u8 car;
  u8 pad08[0x20];
} Slot;
typedef struct Game
{
  u8 pad00[0xE];
  u16 players;
  u8 pad10[6];
  u16 diff;
  u8 pad18[6];
  u16 state;
  u8 pad20[0x10];
  u8 b30;
  u8 pad31;
  u8 order[0x16];
  Slot slots[8];
} Game;
typedef struct Record
{
  s32 w[5];
  u16 count;
  u8 pad16[0x2C4 - 0x16];
} Record;
extern Game *D_800C35A0;
extern Record *D_800D0658;
typedef struct Cursor { s16 marker; u16 position; } Cursor;
extern Cursor D_800ADFDC;
extern u8 D_800ADFE0;
extern u8 D_800B55E0;
extern u8 D_800B6FF2[];
extern u8 D_800B6FF6;

void func_80046E54(Stat *s)
{
  u32 i;
  u8 j;
  u8 cnt; u8 value;
  u8 flag;
  u16 n;
  s32 v;
  u16 t;
  D_800ADFDC.marker = -1;
  if ((*((u16 *) (((u8 *) D_800C35A0) + 0x1E))) != 0)
  {
    D_800ADFE0 = s[1].v + 1;
  }
  else
    if ((D_800ADFE0 = D_800C35A0->b30) != 0)
  {
    D_800ADFE0 = D_800ADFE0 + 1;
  }
  if ((D_800C35A0->state == 0) && (D_800C35A0->players == 4))
  {
    D_800ADFDC.position = 0x10;
  }
  i = 0;
  D_800ADFDC.position = 0;
  D_800B55E0 = s[2].v;
  do
  {
    v = s[i + 3].v;
    D_800B6FF2[i] = v;
    if (D_800C35A0->diff == 0)
    {
      D_800B6FF2[i] = ((((u8) v) * D_800B55E0) / 50) + v;
    }
    if (D_800C35A0->diff == 1)
    {
      D_800B6FF2[i] = D_800B6FF2[i] + ((D_800B6FF2[i] * D_800B55E0) / 100);
    }
    i++;
  }
  while (i < 5);
  if ((D_800C35A0->state != 0) & (D_800C35A0->state < 5))
  {
    t = D_800D0658[D_800C35A0->slots[D_800C35A0->order[0]].car].count;
    n = D_800C35A0->players;
    flag = (t == 1) || (t == 3);
    if (n == 2)
    {
      t = D_800D0658[D_800C35A0->slots[D_800C35A0->order[1]].car].count;
      flag = (t == 1) || (t == 3);
    }
    if (flag == 1)
    {
      cnt = 0;
      for (j = 0; j < n; j++)
      {
        if (D_800D0658[D_800C35A0->slots[D_800C35A0->order[j]].car].count == 3)
        {
          cnt++;
        }
      }

      if (cnt == D_800C35A0->players)
      {
        for (j = 0; j < 4; j++)
        {
          value=D_800B6FF2[j]; value += value >> 1; D_800B6FF2[j]=value;
        }

      }
      else
      {
        for (j = 0; j < 4; j++)
        {
          value=D_800B6FF2[j]; value += (value * D_800B6FF2[4])/100; D_800B6FF2[j]=value;
        }

      }
    }
  }
}


