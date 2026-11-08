typedef struct
{
  s16 x;
  s16 y;
  s16 z;
} Vertex;
typedef struct Grid
{
  char p[0xA];
  u16 flags;
  char pC[4];
  s16 matrix[10];
  s32 x;
  s32 y;
  s32 z;
  char p30[4];
  s32 minX;
  char p38[4];
  s32 maxX;
  char p40[4];
  s32 minZ;
  s32 maxZ;
  s32 index;
  char p50[4];
  Vertex *vertices;
  struct Grid *prev;
  struct Grid *next;
  char p60[12];
  u8 *tags;
  u16 *cells;
  char p74[20];
  u16 rows;
  u16 cols;
  char p8C[2];
  u8 flip;
  s8 pending;
} Grid;
void *mtx3_transform_vec3(void *, void *, void *);
void func_80028394(Grid *);
extern int D_8009E250[3];
extern u16 D_800C792C;

/* Walks the ring of track grids starting at `start`. Each grid's vertices are
 * transformed by its matrix (and flipped when the neighbour asked for it), the
 * cell/tag arrays are reversed to match, optional cell fill runs when D_800C792C
 * has bit 0x400 set, and then each grid is stitched to its predecessor and its
 * world-space bounding box is recomputed. */
void func_80028740(Grid *start)
{
  Vertex v;
  int world[3];
  Grid *cur;
  Grid *prev;
  int flip;
  int w;
  int h;
  int n;
  int i;
  int j;
  int k;
  int r;
  int x;
  int z;
  int minx;
  int maxx;
  int minz;
  int maxz;
  int base;
  int gi;

  cur = start;
  cur->flip = 1;
  flip = 0;
  do
  {
    w = cur->cols - 1;
    h = cur->rows - 1;
    n = w * h;
    {
      int s;
      for (s = 0; s < n; s++)
      {
        if (cur->cells[s])
          break;
      }
    }
    n = cur->cols * cur->rows;
    for (i = 0; i < n; i++)
    {
      v = cur->vertices[i];
      mtx3_transform_vec3(cur->matrix, &v, &v);
      cur->vertices[i].x = v.x;
      cur->vertices[i].y = v.y - 15;
      cur->vertices[i].z = v.z;
    }
    if (flip)
    {
      u8 f = cur->flip;
      cur->pending = f;
      if (!f && cur->next)
        cur->next->flip = 1;
      cur->flip = 1;
      for (k = 0, j = n - 1; k < j; k++, j--)
      {
        v = cur->vertices[j];
        cur->vertices[j] = cur->vertices[k];
        cur->vertices[k].x = v.x;
        cur->vertices[k].y = v.y;
        cur->vertices[k].z = v.z;
      }
      n = (cur->cols - 1) * (cur->rows - 1);
      for (k = 0, j = n - 1; k < j; k++, j--)
      {
        u16 t;
        u8 tag;
        t = cur->cells[j];
        cur->cells[j] = cur->cells[k];
        cur->cells[k] = t;
        t = cur->tags[j];
        cur->tags[j] = cur->tags[k];
        cur->tags[k] = t;
      }
      flip = 0;
      cur->index = cur->cols - cur->index - 1;
      cur->flags |= 0x100;
    }
    if ((D_800C792C & 0x400) && D_8009E250[2])
    {
      int r;
      for (r = 0; r < h; r++)
      {
        for (i = 0; i < w; i++)
        {
          if ((unsigned) (cur->index + 1) < (unsigned) i || (unsigned) i < (unsigned) (cur->index - 2))
            cur->cells[r * w + i] = 0;
          if ((unsigned) (cur->index + 1) < (unsigned) i)
          {
            int t = D_8009E250[1] + 2;
            if ((unsigned) i < (unsigned) (cur->index + t))
              cur->cells[r * w + i] = D_8009E250[2];
          }
          else if ((unsigned) i < (unsigned) (cur->index - 2))
          {
            int t = D_8009E250[0] + 3;
            if (cur->index - t < i)
              cur->cells[r * w + i] = D_8009E250[2];
          }
        }
      }
    }
    if (cur->pending)
    {
      cur->pending = 0;
      flip = 1;
    }
    cur = cur->next;
  }
  while ((cur != start) & (cur != 0));

  func_80028394(start);
  cur = start;
  do
  {
    if (cur->prev)
    {
      prev = cur->prev;
      {
        int m = (prev->rows - 1) * prev->cols;
        base = m + prev->index;
      }
      gi = cur->index;
      for (r = -5; r < 6; r++)
      {
        if ((unsigned) (cur->index + r) < cur->cols && (unsigned) (prev->index + r) < prev->cols)
        {
          int dx = prev->x - cur->x;
          int dz = prev->z - cur->z;
          int s = base + r;
          int d = gi + r;
          cur->vertices[d].x = prev->vertices[s].x + dx;
          cur->vertices[d].z = prev->vertices[s].z + dz;
          cur->vertices[d].y = prev->vertices[s].y;
        }
      }
    }
    n = cur->cols * cur->rows;
    minz = 10000000;
    minx = 10000000;
    maxz = -10000000;
    maxx = -10000000;
    for (i = 0; i < n; i++)
    {
      x = cur->x + cur->vertices[i].x;
      world[0] = x;
      z = cur->z + cur->vertices[i].z;
      world[2] = z;
      if (x < minx)
        minx = x;
      if (maxx < x)
        maxx = x;
      if (z < minz)
        minz = z;
      if (maxz < z)
        maxz = z;
    }
    cur->minX = minx - 10;
    cur->maxX = maxx + 10;
    cur->minZ = minz - 10;
    cur->maxZ = maxz + 10;
    cur = cur->next;
  }
  while ((cur != start) & (cur != 0));
}
