typedef struct { u8 a; u8 b; u8 c; u8 d; u8 e; } Rating;
typedef struct { u8 data[40]; } Unit;
typedef struct { u8 pad[0x44]; Unit units[4]; } Game;
typedef struct { u8 pad[6]; u8 active; u8 rest[57]; } Entry;
extern Rating D_800B0D80[];
extern Game *gRecords;
extern Entry D_800C3756[];
s32 strCmp(void *, void *);

/* For each active entry (the first 12), finds the matching unit slot in the current
   game and adds points to that slot's rating and to the total in slot 4. Entries 0-7
   score in field c, the rest in field d. */
void func_800545E4(void)
{
  u8 i;
  u8 j;
  for (i = 0; i < 12; i++)
  {
    if (D_800C3756[i].active == 1)
    {
      j = 0;
      while (strCmp(&gRecords->units[j], &D_800C3756[i]) != 0 && j < 4)
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
