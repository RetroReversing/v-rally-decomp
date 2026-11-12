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
extern Game *gRecords;
extern Record *D_800D0658;
typedef struct Cursor { s16 marker; u16 position; } Cursor;
extern Cursor D_800ADFDC;
extern u8 gCurCount;
extern u8 D_800B55E0;
extern u8 D_800B6FF2[];
extern u8 D_800B6FF6;

/* Works out the five display values for the race HUD from the stats block: each
   value is scaled by the difficulty and the bonus percentage, and when the
   finishing cars are all in lap 3 the four top values get the late-race boost. */
void hud_compute_values(Stat *s)
{
  u32 i;
  u8 j;
  u8 cnt; u8 value;
  u8 flag;
  u16 n;
  s32 v;
  u16 t;
  D_800ADFDC.marker = -1;
  if ((*((u16 *) (((u8 *) gRecords) + 0x1E))) != 0)
  {
    gCurCount = s[1].v + 1;
  }
  else
    if ((gCurCount = gRecords->b30) != 0)
  {
    gCurCount = gCurCount + 1;
  }
  if ((gRecords->state == 0) && (gRecords->players == 4))
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
    if (gRecords->diff == 0)
    {
      D_800B6FF2[i] = ((((u8) v) * D_800B55E0) / 50) + v;
    }
    if (gRecords->diff == 1)
    {
      D_800B6FF2[i] = D_800B6FF2[i] + ((D_800B6FF2[i] * D_800B55E0) / 100);
    }
    i++;
  }
  while (i < 5);
  if ((gRecords->state != 0) & (gRecords->state < 5))
  {
    t = D_800D0658[gRecords->slots[gRecords->order[0]].car].count;
    n = gRecords->players;
    flag = (t == 1) || (t == 3);
    if (n == 2)
    {
      t = D_800D0658[gRecords->slots[gRecords->order[1]].car].count;
      flag = (t == 1) || (t == 3);
    }
    if (flag == 1)
    {
      cnt = 0;
      for (j = 0; j < n; j++)
      {
        if (D_800D0658[gRecords->slots[gRecords->order[j]].car].count == 3)
        {
          cnt++;
        }
      }

      if (cnt == gRecords->players)
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
