typedef struct
{
  s16 x;
  s16 pad;
  s16 y;
} GridPoint;

typedef struct
{
  u8 pad0[0x24];
  s32 xoff;
  u8 pad28[4];
  s32 yoff;
  u8 pad30[0x24];
  GridPoint *pts;
  u8 pad58[0x30];
  u16 count;
  u16 rows;
} PathGrid;

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
} PathState;

/* Finds the grid cell nearest the state's position (distance in 1/16 units),
 * takes the grid direction at that cell, and reverses the state's direction
 * (flag bit 0) when it points against the grid direction. */
void updatePathDirection(PathGrid *grid, PathState *state)
{
  s32 pos[4];
  s32 dir[4];
  s32 diff[4];
  s32 spare[8];
  u32 best = 0;
  s32 bestCol = 0;
  s32 row;
  s32 bestRow = 0;
  s32 col;
  s32 prev;
  u32 dist;
  for (row = 0; row < ((s32) grid->rows); row++)
  {
    for (col = 0; col < ((s32) grid->count); col++)
    {
      pos[0] = grid->pts[(col * grid->rows) + row].x + grid->xoff;
      pos[2] = grid->pts[(col * grid->rows) + row].y + grid->yoff;
      diff[0] = pos[0] - state->x;
      diff[2] = pos[2] - state->y;
      dist = ((diff[0] >> 4) * (diff[0] >> 4)) + ((diff[2] >> 4) * (diff[2] >> 4));
      if ((row + col) == 0)
      {
        best = dist;
      }
      if (best >= dist)
      {
        best = dist;
        bestCol = col;
        bestRow = row;
      }
    }
  }
  if (bestCol == 0)
  {
    dir[0] = grid->pts[grid->rows + bestRow].x - grid->pts[bestRow].x;
    dir[2] = grid->pts[grid->rows + bestRow].y - grid->pts[bestRow].y;
  }
  else
  {
    dir[0] = grid->pts[(bestCol * grid->rows) + bestRow].x - grid->pts[((bestCol - 1) * grid->rows) + bestRow].x;
    dir[2] = grid->pts[(bestCol * grid->rows) + bestRow].y - grid->pts[((bestCol - 1) * grid->rows) + bestRow].y;
  }
  if (((dir[0] * state->dx) + (dir[2] * state->dy)) > 0)
  {
    state->dx = -state->dx;
    state->dy = -state->dy;
    state->flags |= 1;
  }
  else
  {
    state->flags = 0;
  }
}
