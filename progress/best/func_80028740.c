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
  volatile u16 *cells;
  char p74[20];
  u16 rows;
  u16 cols;
  char p8C[2];
  u8 flip;
  u8 pending;
} Grid;
void func_8002E514(void *, void *, void *);
long func_80028394(Grid *);
void func_80028740(Grid *);
extern int D_8009E250;
extern int D_8009E254;
extern int D_8009E258;
extern u16 D_800C792C;
void func_80028740(Grid *start)
{
  volatile unsigned long new_var4;
  Grid *new_var3;
  Vertex v;
  int world[5];
  Grid *p;
  Grid *g;
  int flip = 0;
  int cols;
  Grid *new_var7;
  int new_var5;
  int rows;
  int n;
  int i;
  int x;
  int j;
  int r;
  unsigned c;
  int minx;
  s32 new_var6;
  int minz;
  int maxx;
  int maxz;
  Vertex *new_var;
  int new_var2;
  int z;
  start->flip = 1;
  g = start;
  new_var4 = (g != start) & (g != 0);
  do
  {
    rows = g->rows;
    rows = rows - 1;
    cols = g->cols;
    cols = cols - 1;
    i = rows;
    n = cols * i;
    {
      int scan;
      for (scan = 0; scan < n; scan++)
      {
        if (g->cells[scan])
        {
          break;
        }
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
      g->pending = g->flip;
      if ((!g->flip) && g->next)
      {
        g->next->flip = 1;
      }
      g->flip = 1;
      for (i = 0, j = n - 1; i < j; i++, j--)
      {
        v = g->vertices[j];
        g->vertices[j] = g->vertices[i];
        g->vertices[i].x = v.x;
        g->vertices[(long) i].y = v.y;
        g->vertices[i].z = v.z;
      }

      new_var2 = (g->cols - 1) * (g->rows - 1);
      for (i = 0, j = new_var2 - 1; i < j; i++, j--)
      {
        u16 t;
        u8 tag;
        t = g->cells[j];
        g->cells[j] = g->cells[i];
        g->cells[i] = t;
        tag = g->tags[j];
        g->tags[j] = g->tags[i];
        g->tags[i] = tag;
      }

      flip = 0;
      g->index = (g->cols - g->index) - 1;
      g->flags = g->flags | 256;
    }
    if ((D_800C792C & 1024) && D_8009E258)
    {
      for (r = 0; r < rows; r++)
      {
        for (c = 0; c < ((unsigned) cols); c++)
        {
          ;
          new_var3 = g;
          if ((((unsigned) (new_var3->index + 1)) < c) || (c < ((unsigned) (g->index - 2))))
          {
            g->cells[(r * cols) + c] = 0;
          }
          if (((unsigned) (g->index + 1)) < c)
          {
            if (c < ((unsigned) ((new_var3->index + D_8009E254) + 2)))
            {
              new_var3->cells[(r * cols) + c] = D_8009E258;
            }
          }
          else
            if ((c < ((unsigned) (g->index - 2))) && (((new_var3->index - (*((&D_8009E254) - 1))) - 3) < ((int) c)))
          {
            g->cells[(r * cols) + c] = D_8009E258;
          }
        }

      }

    }
    if ((s8) new_var3->pending)
    {
      g->pending = 0;
      flip = 1;
    }
    g = g->next;
  }
  while (new_var4);
  func_80028394(start);
  g = start;
  do
  {
    p = g->prev;
    if (p)
    {
      for (i = -5; i < 6; i++)
      {
        if ((((unsigned) (g->index + i)) < (*g).cols) && (((unsigned) (p->index + i)) < p->cols))
        {
          new_var6 = p->index;
          i = ((((new_var7 = p)->rows - 1) * new_var7->cols) + new_var6) + i;
          j = i;
          cols = new_var7->z;
          cols = j;
          n = g->index + i;
          new_var5 = cols - g->z;
          new_var = new_var7->vertices;
          g->vertices[n].x = (new_var7->x - g->x) + ((u16) new_var7->vertices[cols].x);
          g->vertices[n].z = ((u16) new_var7->vertices[cols].z) + new_var5;
          g->vertices[n].y = (u16) new_var[cols].y;
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
      {
        minx = x;
      }
      if (maxx < x)
      {
        maxx = x;
      }
      if (z < minz)
      {
        minz = z;
      }
      if (maxz < z)
      {
        maxz = z;
      }
    }

    g->minX = minx - 10;
    g->maxX = maxx + 10;
    g->minZ = minz - 10;
    g->maxZ = maxz + 10;
    g = g->next;
  }
  while ((g != start) & (g != 0));
}

