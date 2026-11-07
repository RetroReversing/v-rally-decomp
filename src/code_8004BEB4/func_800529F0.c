#include "func_800529F0-context.h"
typedef struct ChRec
{
  char pad0[0x14];
  u16 n;
  char pad16[0x2C4 - 0x16];
} ChRec;
typedef struct ChCfg
{
  char pad0[0xE];
  u16 count;
  char pad10[0x1E - 0x10];
  u16 mode;
  u16 idx;
} ChCfg;
typedef struct ChTable
{
  u32 points[4];
  char pad10[0x18];
  u8 rank[12][4];
  u32 sums[12][4];
  s32 laps[5][4];
  u32 total[4];
} ChTable;
extern ChCfg *D_800C35A0;
extern ChRec *D_800D0648;
extern ChTable D_800B6600;
extern u8 D_800C81FC;
void func_800529F0(void)
{
  ChCfg *cfg;
  ChRec *rec;
  ChTable *t;
  u32 sum;
  u32 i;
  u32 j;
  u32 m;
  u32 rank;
  u32 pts;
  u8 *new_var;
  u8 *flag;
  if (D_800C35A0->mode == 5)
  {
    cfg = D_800C35A0;
    rec = &D_800D0648[cfg->idx];
    t = &D_800B6600;
    new_var = &D_800C81FC;
    for (i = 0; i < 4; i++)
    {
      u32 s;
      s = 0;
      for (m = 0; m < rec->n; )
      {
        u32 contribution;
        contribution = t->laps[m][i];
        m++;
        do {
        do {
        do {
        do {
        do {
        do {
          s += contribution;
        } while (0);
        } while (0);
        } while (0);
        } while (0);
        } while (0);
        } while (0);
      }

      t->sums[cfg->idx][i] = s;
      t->total[i] += s;
    }

    for (m = 0; m < 4; m++)
    {
      u32 one, two, three;
      one = 1;
      two = 2;
      three = 3;
      flag = new_var;
      rank = 0;
      for (j = 0; j < 4; j++)
      {
        rank += t->sums[D_800C35A0->idx][j] < t->sums[D_800C35A0->idx][m];
      }

      t->rank[D_800C35A0->idx][m] = rank;
      if (rank == one) goto rank_one;
      if (rank == 0) goto rank_zero;
      if (rank == two) goto rank_two;
      if (rank == three) goto rank_three;
      goto rank_done;
rank_zero:
      if (m < D_800C35A0->count) {
        *flag = 1;
      } else {
        *flag = 0;
      }
      j = 4;
      goto rank_done;
rank_one:
      j = 2;
      goto rank_done;
rank_two:
      j = 1;
      goto rank_done;
rank_three:
      j = 0;
rank_done:

      t->points[m] += j;
    }

  }
}

