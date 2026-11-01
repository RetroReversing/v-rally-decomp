typedef struct
{
  void *payload;
  s16 kind;
  s16 f6;
} NodeD;
typedef struct
{
  s32 x, y, z;
  s32 dx, dy, dz;
  s16 a, b, c, d;
  s32 e;
  s16 sel;
  s16 g;
} PayD;
typedef struct
{
  u8 pad0[0x10];
  u8 mtx[0x14];
  s32 xo;
  s32 yo;
  s32 zo;
  u8 pad30[0x1C];
  s32 lane;
  u32 count;
  s16 *points;
  u8 pad58[0x10];
  NodeD *list;
  u8 pad6c[0x1C];
  u16 cols;
  u16 rows;
} ObjD;
extern void *func_8002E3AC(void *, void *, void *);
extern void *func_8007EAA0(s32, s32);
extern u8 D_800AE850[];
s32 func_8004D7D4(ObjD *o, u16 *in, s32 sel)
{
  u32 best;
  u32 found;
  u32 row;
  u32 col;
  u32 i;
  s32 ret;
  s32 d;
  s32 index;
  s32 vec[4];
  s32 delta[4];
  s16 pos[4];
  NodeD *node;
  NodeD *list;
  PayD *p;

  best = 0;
  pos[0] = in[0];
  pos[2] = in[2];
  func_8002E3AC(o->mtx, pos, pos);
  found = 0;
  ret = 0;
  if (o->count == 0)
  {
    o->list = func_8007EAA0(1, 8);
    o->list->f6 = 1;
    o->list->kind = 3;
    o->count = 1;
  }
  list = o->list;
  for (i = 0; i < o->count; i++)
  {
    node = &list[i];
    if (node->kind == 3)
    {
      node->kind = 0;
      p = func_8007EAA0(1, 0x50);
      node->payload = p;
      for (row = 0; row < o->rows; row++)
      {
        for (col = 0; col < o->cols; col++)
        {
          vec[0] = o->points[(col * o->rows + row) * 3];
          vec[2] = o->points[(col * o->rows + row) * 3 + 2];
          delta[0] = vec[0] - pos[0];
          delta[2] = vec[2] - pos[2];
          d = (delta[0] >> 4) * (delta[0] >> 4) + (delta[2] >> 4) * (delta[2] >> 4);
          if (row + col == 0)
          {
            best = d;
          }
          if (best >= d)
          {
            best = d;
            found = col;
          }
        }
      }
      if (found >= (u32) (o->cols - 2))
      {
        found -= 5;
      }
      if (found < 3)
      {
        found += 5;
      }
      index = found * o->rows + o->lane;
      p->x = o->points[index * 3] + o->xo;
      p->y = o->points[index * 3 + 1] + o->yo;
      p->z = o->points[index * 3 + 2] + o->zo;
      p->dx = o->points[(index - o->rows) * 3] - o->points[index * 3];
      p->dy = o->points[(index - o->rows) * 3 + 1] - o->points[index * 3 + 1];
      p->dz = o->points[(index - o->rows) * 3 + 2] - o->points[index * 3 + 2];
      p->a = 1;
      p->b = 0;
      p->c = 0;
      p->d = 1;
      p->e = 1;
      p->sel = sel;
      p->g = D_800AE850[0x87A2 + sel];
      ret = 1;
    }
  }
  return ret;
}
