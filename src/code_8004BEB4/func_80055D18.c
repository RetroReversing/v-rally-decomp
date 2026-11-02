#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s32 D_8009FF30;
extern u8 D_800C7926;
typedef struct { s8 a, b; } Pair;
typedef struct
{
  u16 x;
  u16 y;
  u16 z;
  Pair n[3];
  u16 flag;
} Rec;
typedef struct
{
  Rec *recs;
  u16 count;
} RecList;
typedef struct
{
  u8 col[16];
  u16 v[4];
  Pair n[3];
  u8 pad[2];
  u16 flag;
} Out;
void func_80055D18(Out **dst, RecList *info, s32 add, u8 *tbl)
{
  Rec *p;
  s32 n;
  s32 i;
  u8 fb;
  u8 c;
  p = info->recs;
  n = info->count;
  fb = 0x8C;
  if (D_800C7926 == 0)
  {
    fb = 0x32;
  }
  for (i = 0; i < n; i++)
  {
    (*dst)->v[0] = p->x + add;
    (*dst)->v[1] = p->y + add;
    (*dst)->v[2] = p->z + add;
    (*dst)->v[3] = 0;
    if (D_8009FF30 != 2)
    {
      c = tbl[p->x];
    }
    else
    {
      c = fb;
    }
    (*dst)->col[0] = c;
    (*dst)->col[1] = c;
    (*dst)->col[2] = c;
    (*dst)->col[3] = 6;
    c = fb;
    if (D_8009FF30 != 2)
    {
      c = tbl[p->y];
    }
    (*dst)->col[4] = c;
    (*dst)->col[5] = c;
    (*dst)->col[6] = c;
    (*dst)->col[7] = 0;
    c = fb;
    if (D_8009FF30 != 2)
    {
      c = tbl[p->z];
    }
    (*dst)->col[8] = c;
    (*dst)->col[9] = c;
    (*dst)->col[10] = c;
    (*dst)->col[11] = 0;
    (*dst)->col[12] = 0;
    (*dst)->col[13] = 0;
    (*dst)->col[14] = 0;
    (*dst)->col[15] = 0;
    (*dst)->n[0] = p->n[0];
    (*dst)->n[1] = p->n[1];
    (*dst)->n[2] = p->n[2];
    (*dst)->pad[0] = 0;
    (*dst)->pad[1] = 0;
    (*dst)->flag = p->flag;
    p++;
    (*dst)++;
  }
}

