#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s32 D_8009FF30;
extern u8 D_800C7926;
typedef struct 
{
  s8 u;
  s8 v;
} UV;
typedef struct 
{
  u16 idx[4];
  UV uv[4];
  u16 last;
} Rec;
typedef struct 
{
  u8 color[16];
  u16 pos[4];
  UV uv[4];
  u16 last;
} Out;
typedef struct 
{
  Rec *records;
  u16 count;
} Info;
void func_80055EE8(Out **dst, Info *in, s32 off, u8 *tbl)
{
  Rec *p = in->records;
  s32 n = in->count;
  s32 i;
  u8 c;
  u8 col;
  c = 0x8C;
  if (D_800C7926 == 0)
  {
    c = 0x32;
  }
  for (i = 0; i < n; p++, i++)
  {
    (*dst)->pos[0] = ((int) p->idx[0]) + off;
    (*dst)->pos[1] = p->idx[1] + off;
    (*dst)->pos[2] = p->idx[2] + off;
    (*dst)->pos[3] = p->idx[3] + off;
    if (D_8009FF30 != 2)
    {
      col = tbl[p->idx[0]];
    }
    else
    {
      col = c;
    }
    (*dst)->color[0] = col;
    (*dst)->color[1] = col;
    (*dst)->color[2] = col;
    (*dst)->color[3] = 10;
    if (D_8009FF30 != 2)
    {
      col = tbl[p->idx[1]];
    }
    else
    {
      col = c;
    }
    (*dst)->color[4] = col;
    (*dst)->color[5] = col;
    (*dst)->color[6] = col;
    (*dst)->color[7] = 0;
    if (D_8009FF30 != 2)
    {
      col = tbl[p->idx[2]];
    }
    else
    {
      col = c;
    }
    (*dst)->color[8] = col;
    (*dst)->color[9] = col;
    (*dst)->color[10] = col;
    (*dst)->color[11] = 0;
    if (D_8009FF30 != 2)
    {
      col = tbl[p->idx[3]];
    }
    else
    {
      col = c;
    }
    (*dst)->color[12] = col;
    (*dst)->color[13] = col;
    (*dst)->color[14] = col;
    (*dst)->color[15] = 0;
    (*dst)->uv[0] = p->uv[0];
    (*dst)->uv[1] = p->uv[1];
    (*dst)->uv[2] = p->uv[2];
    (*dst)->uv[3] = p->uv[3];
    (*dst)->last = p->last;
    (*dst)++;
  }

}


