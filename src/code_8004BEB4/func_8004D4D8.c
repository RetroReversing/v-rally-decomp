#include "common.h"

typedef struct 
{
  s16 x;
  s16 pad;
  s16 y;
} Point6;
typedef struct 
{
  u8 pad0[0x24];
  s32 xoff;
  u8 pad28[4];
  s32 yoff;
  u8 pad30[0x24];
  Point6 *pts;
  u8 pad58[0x30];
  u16 count;
  u16 rows;
} A;
typedef struct 
{
  s32 x;
  u8 pad4[4];
  s32 y;
  s32 dx;
  u8 pad10[4];
  s32 dy;
  u8 pad18[2];
  u16 flags;
} B;
void func_8004D4D8(A *arg0, B *arg1)
{
  s32 p[4];
  s32 d[4];
  s32 e[4];
  s32 spare[8];
  u32 best = 0;
  s32 bc = 0;
  s32 row;
  s32 br = 0;
  s32 col;
  s32 prev;
  u32 dist;
  for (row = 0; row < ((s32) arg0->rows); row++)
  {
    for (col = 0; col < ((s32) arg0->count); col++)
    {
      p[0] = arg0->pts[(col * arg0->rows) + row].x + arg0->xoff;
      p[2] = arg0->pts[(col * arg0->rows) + row].y + arg0->yoff;
      e[0] = p[0] - arg1->x;
      e[2] = p[2] - arg1->y;
      dist = ((e[0] >> 4) * (e[0] >> 4)) + ((e[2] >> 4) * (e[2] >> 4));
      if ((row + col) == 0)
      {
        best = dist;
      }
      if (best >= dist)
      {
        best = dist;
        bc = col;
        br = row;
      }
    }

  }

  ;
  if (bc == 0)
  {
    d[0] = arg0->pts[arg0->rows + br].x - arg0->pts[br].x;
    d[2] = arg0->pts[arg0->rows + br].y - arg0->pts[br].y;
  }
  else
  {
    d[0] = arg0->pts[(bc * arg0->rows) + br].x - arg0->pts[((bc - 1) * arg0->rows) + br].x;
    d[2] = arg0->pts[(bc * arg0->rows) + br].y - arg0->pts[((bc - 1) * arg0->rows) + br].y;
  }
  if (((d[0] * arg1->dx) + (d[2] * arg1->dy)) > 0)
  {
    arg1->dx = -arg1->dx;
    arg1->dy = -arg1->dy;
    arg1->flags |= 1;
  }
  else
  {
    arg1->flags = 0;
  }
}
