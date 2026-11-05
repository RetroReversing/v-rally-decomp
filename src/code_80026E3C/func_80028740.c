#include "decompdecomp_snapshot_80028740.h"
#line 1 "func.c"
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
void *func_8002E514(void *, void *, void *);
void func_80028394(Grid *);
extern int D_8009E250[3];
extern u16 D_800C792C;

void func_80028740(Grid *start)
{
  Vertex v;
  int world[3];
  Grid *g;
  Grid *p;
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

  g = start;
  g->flip = 1;
  flip = 0;
  do
  {
    w = g->cols - 1;
    h = g->rows - 1;
    n = w * h;
    {
      int s;
      for (s = 0; s < n; s++)
      {
        if (g->cells[s])
          break;
      }
    }
    n = g->cols * g->rows;
    for (i = 0; i < n; i++)
    {
      v = g->vertices[i];
      func_8002E514(g->matrix, &v, &v);
      g->vertices[i].x = v.x;
      g->vertices[i].y = v.y - 15;
      g->vertices[i].z = v.z;
    }
    if (flip)
    {
      u8 f = g->flip;
      g->pending = f;
      if (!f && g->next)
        g->next->flip = 1;
      g->flip = 1;
      for (k = 0, j = n - 1; k < j; k++, j--)
      {
        v = g->vertices[j];
        g->vertices[j] = g->vertices[k];
        g->vertices[k].x = v.x;
        g->vertices[k].y = v.y;
        g->vertices[k].z = v.z;
      }
      n = (g->cols - 1) * (g->rows - 1);
      for (k = 0, j = n - 1; k < j; k++, j--)
      {
        u16 t;
        u8 tag;
        t = g->cells[j];
        g->cells[j] = g->cells[k];
        g->cells[k] = t;
        t = g->tags[j];
        g->tags[j] = g->tags[k];
        g->tags[k] = t;
      }
      flip = 0;
      g->index = g->cols - g->index - 1;
      g->flags |= 0x100;
    }
    if ((D_800C792C & 0x400) && D_8009E250[2])
    {
      int r;
      for (r = 0; r < h; r++)
      {
        for (i = 0; i < w; i++)
        {
          if ((unsigned) (g->index + 1) < (unsigned) i || (unsigned) i < (unsigned) (g->index - 2))
            g->cells[r * w + i] = 0;
          if ((unsigned) (g->index + 1) < (unsigned) i)
          {
            int t = D_8009E250[1] + 2;
            if ((unsigned) i < (unsigned) (g->index + t))
              g->cells[r * w + i] = D_8009E250[2];
          }
          else if ((unsigned) i < (unsigned) (g->index - 2))
          {
            int t = D_8009E250[0] + 3;
            if (g->index - t < i)
              g->cells[r * w + i] = D_8009E250[2];
          }
        }
      }
    }
    if (g->pending)
    {
      g->pending = 0;
      flip = 1;
    }
    g = g->next;
  }
  while ((g != start) & (g != 0));

  func_80028394(start);
  g = start;
  do
  {
    if (g->prev)
    {
      p = g->prev;
      {
        int m = (p->rows - 1) * p->cols;
        base = m + p->index;
      }
      gi = g->index;
      for (r = -5; r < 6; r++)
      {
        if ((unsigned) (g->index + r) < g->cols && (unsigned) (p->index + r) < p->cols)
        {
          int dx = p->x - g->x;
          int dz = p->z - g->z;
          int s = base + r;
          int d = gi + r;
          g->vertices[d].x = p->vertices[s].x + dx;
          g->vertices[d].z = p->vertices[s].z + dz;
          g->vertices[d].y = p->vertices[s].y;
        }
      }
    }
    n = g->cols * g->rows;
    minz = 10000000;
    minx = 10000000;
    maxz = -10000000;
    maxx = -10000000;
    for (i = 0; i < n; i++)
    {
      x = g->x + g->vertices[i].x;
      world[0] = x;
      z = g->z + g->vertices[i].z;
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
    g->minX = minx - 10;
    g->maxX = maxx + 10;
    g->minZ = minz - 10;
    g->maxZ = maxz + 10;
    g = g->next;
  }
  while ((g != start) & (g != 0));
}

