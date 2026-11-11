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
extern void *mat3_mul_vec3(void *, void *, void *);
extern void *poolAlloc(s32, s32);
extern u8 gOrderState[];

/* Spawns the payload for each pending node (kind 3) of obj. The payload is
 * placed on the grid point nearest to the query position in[], with the
 * column kept away from the grid edges, and offset by obj's origin. sel
 * selects the payload's variant. Returns 1 if a node was spawned. */
s32 func_8004D7D4(ObjD *obj, u16 *in, s32 sel)
{
  u32 bestDist;
  u32 nearestCol;
  u32 row;
  u32 col;
  u32 i;
  s32 spawned;
  s32 dist;
  s32 idx;
  s32 pt[4];
  s32 offset[4];
  s16 pos[4];
  NodeD *node;
  NodeD *list;
  PayD *p;

  bestDist = 0;
  pos[0] = in[0];
  pos[2] = in[2];
  mat3_mul_vec3(obj->mtx, pos, pos);
  nearestCol = 0;
  spawned = 0;
  if (obj->count == 0)
  {
    obj->list = poolAlloc(1, 8);
    obj->list->f6 = 1;
    obj->list->kind = 3;
    obj->count = 1;
  }
  list = obj->list;
  for (i = 0; i < obj->count; i++)
  {
    node = &list[i];
    if (node->kind == 3)
    {
      node->kind = 0;
      p = poolAlloc(1, 0x50);
      node->payload = p;
      for (row = 0; row < obj->rows; row++)
      {
        for (col = 0; col < obj->cols; col++)
        {
          pt[0] = obj->points[(col * obj->rows + row) * 3];
          pt[2] = obj->points[(col * obj->rows + row) * 3 + 2];
          offset[0] = pt[0] - pos[0];
          offset[2] = pt[2] - pos[2];
          dist = (offset[0] >> 4) * (offset[0] >> 4) + (offset[2] >> 4) * (offset[2] >> 4);
          if (row + col == 0)
          {
            bestDist = dist;
          }
          if (bestDist >= dist)
          {
            bestDist = dist;
            nearestCol = col;
          }
        }
      }
      if (nearestCol >= (u32) (obj->cols - 2))
      {
        nearestCol -= 5;
      }
      if (nearestCol < 3)
      {
        nearestCol += 5;
      }
      idx = nearestCol * obj->rows + obj->lane;
      p->x = obj->points[idx * 3] + obj->xo;
      p->y = obj->points[idx * 3 + 1] + obj->yo;
      p->z = obj->points[idx * 3 + 2] + obj->zo;
      p->dx = obj->points[(idx - obj->rows) * 3] - obj->points[idx * 3];
      p->dy = obj->points[(idx - obj->rows) * 3 + 1] - obj->points[idx * 3 + 1];
      p->dz = obj->points[(idx - obj->rows) * 3 + 2] - obj->points[idx * 3 + 2];
      p->a = 1;
      p->b = 0;
      p->c = 0;
      p->d = 1;
      p->e = 1;
      p->sel = sel;
      p->g = gOrderState[0x87A2 + sel];
      spawned = 1;
    }
  }
  return spawned;
}
