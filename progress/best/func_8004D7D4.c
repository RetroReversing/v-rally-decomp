typedef struct 
{
  void *payload;
  s16 kind;
  s16 f6;
} NodeD;
typedef struct 
{
  u8 pad0[0x24];
  s32 xo;
  s32 yo;
  s32 zo;
  u8 pad30[0x1C];
  s32 lane;
  s32 count;
  s16 *points;
  u8 pad58[0x10];
  NodeD *list;
  u8 pad6c[0x1C];
  u16 cols;
  u16 rows;
} ObjD;
extern s32 func_8002E3AC(u8 *, u16 *, u16 *);
extern void *func_8007EAA0(s32, s32);
extern u8 D_800AE850[];
s32 func_8004D7D4(ObjD *o, u16 *in, s32 arg2)
{
  s32 sel;
  u32 best;
  u32 found;
  u32 row;
  void *new_var2;
  u32 col;
  u32 i;
  s32 ret;
  s32 new_var;
  s32 dx;
  s32 dz;
  s32 d;
  s32 x;
  s32 z;
  s32 index;
  s32 vec[3];
  s32 delta[3];
  s16 pos[12];
  NodeD *node;
  NodeD *born;
  void *q;
  sel = arg2;
  best = 0;
  pos[0] = in[0];
  pos[(short) 2] = in[2];
  func_8002E3AC(((u8 *) o) + 0x10, (u16 *) pos, (u16 *) pos);
  found = 0;
  ret = 0;
  if (o->count == 0)
  {
    born = func_8007EAA0(1, 8);
    o->list = born;
    born->f6 = 1;
    o->list->kind = 3;
    o->count = 1;
  }
  node = o->list;
  i = 0;
  if (((u32) ret) < ((u32) o->count))
  {
    new_var = o->count;
    do
    {
      if (node->kind == 3)
      {
        node->kind = 0;
        q = func_8007EAA0(1, 0x50);
        node->payload = q;
        new_var2 = q;
        if (o->rows != 0)
        {
          row = 0;
          do
          {
            if (o->cols != 0)
            {
              col = 0;
              do
              {
                x = o->points[((col * o->rows) + row) * 3];
                vec[0] = x;
                dx = x - pos[0];
                d = (dx >> 4) * (dx >> 4);
                z = o->points[(((col * o->rows) + row) * 3) + 2];
                dz = z - pos[2];
                d += (dz >> 4) * (dz >> 4);
                delta[0] = dx;
                vec[2] = z;
                if ((row + col) == 0)
                {
                  best = d;
                }
                delta[2] = dz;
                if (best >= d)
                {
                  best = d;
                  found = col;
                }
                col += 1;
              }
              while (col < o->cols);
            }
            row += 1;
          }
          while (row < o->rows);
        }
        if (found >= ((u32) (o->cols - 2)))
        {
          found -= 5;
        }
        if (found < 3)
        {
          found += 5;
        }
        index = (found * o->rows) + o->lane;
        ((s32 *) new_var2)[0] = o->points[index * 3] + o->xo;
        ret = (new_var = index * 3);
        ((s32 *) new_var2)[1] = o->points[ret + 1] + o->yo;
        ((s32 *) new_var2)[2] = o->points[(index * 3) + 2] + o->zo;
        ((s32 *) new_var2)[3] = o->points[(index - ((s32) o->rows)) * 3] - o->points[index * 3];
        ((s32 *) new_var2)[4] = o->points[((index - ((s32) o->rows)) * 3) + 1] - o->points[(index * 3) + 1];
        ((s32 *) new_var2)[5] = o->points[((index - ((s32) o->rows)) * 3) + 2] - o->points[(index * 3) + 2];
        ((s16 *) new_var2)[12] = 1;
        ((s16 *) new_var2)[13] = 0;
        ((s16 *) new_var2)[14] = 0;
        ((s16 *) new_var2)[15] = 1;
        ((s32 *) new_var2)[8] = 1;
        ((s16 *) new_var2)[18] = sel;
        ((s16 *) new_var2)[19] = D_800AE850[0x87A2 + sel];
        ret = 1;
      }
      i += 1;
      node = &o->list[i];
    }
    while (i < ((u32) new_var));
  }
  return ret;
}
