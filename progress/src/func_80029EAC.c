#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} Vertex;
typedef struct 
{
  s16 h[9];
  unsigned int :16;
  unsigned int :32;
  unsigned int :32;
  unsigned int :32;
} Matrix;
typedef char MatrixSizeCheck[sizeof(Matrix)==32?1:-1];
typedef struct { char c; Matrix m; } MatrixAlignmentCheck;
typedef char MatrixAlignCheck[sizeof(MatrixAlignmentCheck)==36?1:-1];
typedef union 
{
  struct 
  {
    s16 x;
    s16 z;
    u32 pad;
  } p;
  int word;
} Pair;
void func_8002D724(int *, int *, int *);
void func_8002D740(int *, int *, int *);
void func_8002D75C(int, int, int, int *);
void func_8002D7E4(int, int *);
void *func_8002DA98(void *, void *);
int *func_8002E530(s16 *, s16 *, int *);
int func_8002E688(int *, int *);

/* Looks up the cell of a track sector's height grid under `point`, builds the
 * local plane from the cell's two triangle edges, and (for special sector
 * indices) snaps the plane's height. Appends a plane record to the sector's
 * list and returns the depth (0 when the record was written). */
int func_80029EAC(void *track, void *point, int index)
{
  Pair pa;
  Pair pb;
  Pair pt;
  int local[4];
  int b[4];
  int d[4];
  int c[4];
  int normal[4];
  Matrix mat;
  Matrix inv;
  s16 delta[3];
  int sign;
  int row;
  int col;
  int corner;
  int idx_right;
  int idx_down;
  int slot;
  int height;
  int dot;
  int cell;
  u16 w;
  char *grid;
  char *cell_ids;
  char *rec;
  Vertex *v;
  grid = P(P(track, 140), index * 4);
  row = W(P(track, 96) + (index * 4), 0);
  col = W(P(track, 96) + (index * 4), 48);
  w = U(grid, 138);
  cell_ids = P(grid, 112);
  corner = (w * row) + col;
  pt.p.x = (*(s16 *)((unsigned char *)point + 0));
  pt.p.z = (*(s16 *)((unsigned char *)point + 4));
  idx_right = corner + 1;
  pa.p.x = ((Vertex *) P(grid, 84))[idx_right].x;
  pa.p.z = ((Vertex *) P(grid, 84))[idx_right].z;
  idx_down = corner + w;
  pb.p.x = ((Vertex *) P(grid, 84))[idx_down].x;
  pb.p.z = ((Vertex *) P(grid, 84))[idx_down].z;
  cell = (row * (w - 1)) + col;
  func_8002D75C(pa.word, pb.word, pt.word, &sign);
  height = idx_down;
  height++;
  slot = idx_right;
  if (sign < 0)
  {
    corner = height;
    idx_right = idx_down;
    idx_down = slot;
  }
  c[0] = ((Vertex *) P(grid, 84))[idx_right].x - ((Vertex *) P(grid, 84))[corner].x;
  c[1] = ((Vertex *) P(grid, 84))[idx_right].y - ((Vertex *) P(grid, 84))[corner].y;
  c[2] = ((Vertex *) P(grid, 84))[idx_right].z - ((Vertex *) P(grid, 84))[corner].z;
  b[0] = ((Vertex *) P(grid, 84))[idx_down].x - ((Vertex *) P(grid, 84))[corner].x;
  b[1] = ((Vertex *) P(grid, 84))[idx_down].y - ((Vertex *) P(grid, 84))[corner].y;
  b[2] = ((Vertex *) P(grid, 84))[idx_down].z - ((Vertex *) P(grid, 84))[corner].z;
  if (((((unsigned) index - 4U) < 2) | (index == 10)) || (index == 11))
  {
    int sx;
    int sy;
    int sz;
    slot = 0;
    func_8002D724(c, b, normal);
    height = (index == 4) * 2;
    if (index == 5)
    {
      height = 3;
    }
    height &= -(index != 10);
    if (index == 11)
    {
      height = 1;
    }
    func_8002D7E4(normal[0], &sx);
    func_8002D7E4(normal[1], &sy);
    func_8002D7E4(normal[2], &sz);
    if (((sx < 16) || (sy < 16)) || (sz < 16))
    {
      if (sx > sy)
      {
        sx = sy;
      }
      if (sx > sz)
      {
        sx = sz;
      }
      sx = 17 - sx;
      normal[0] >>= sx;
      normal[1] >>= sx;
      normal[2] >>= sx;
    }
    v = (Vertex *) P(grid, 84);
    dot = ((unsigned)v[corner].x * normal[0] + (unsigned)v[corner].y * normal[1]) + (unsigned)v[corner].z * normal[2];
    do
    {
      if (normal[1])
      {
        slot = normal[2];
        do {
        slot = (int)(((0U - normal[0]) * pt.p.x - (unsigned)slot * pt.p.z) + (unsigned)dot) / normal[1];
        } while (0);
      }
    }
    while (0);
    W(P(track, 140), (height * 20) + 176) = (*(s16 *)((unsigned char *)point + 0));
    W(P(track, 140), (height * 20) + 180) = slot;
    W(P(track, 140), (height * 20) + 184) = (*(s16 *)((unsigned char *)point + 4));
  }
  func_8002E688(c, c);
  func_8002E688(b, b);
  func_8002D740(c, b, d);
  func_8002D740(b, d, c);
  mat.h[0] = b[0];
  mat.h[1] = b[1];
  mat.h[2] = b[2];
  mat.h[3] = d[0];
  mat.h[4] = d[1];
  mat.h[5] = d[2];
  mat.h[6] = c[0];
  mat.h[7] = c[1];
  mat.h[8] = c[2];
  delta[0] = (*(s16 *)((unsigned char *)point + 0)) - ((Vertex *) P(grid, 84))[corner].x;
  delta[1] = (*(s16 *)((unsigned char *)point + 2)) - ((Vertex *) P(grid, 84))[corner].y;
  delta[2] = (*(s16 *)((unsigned char *)point + 4)) - ((Vertex *) P(grid, 84))[corner].z;
  func_8002E530(mat.h, delta, local);
  func_8002DA98(&mat, &inv);
  mat = inv;
  { int depth;
  depth = (unsigned)local[1] * 16U;
  if (depth > 0) return depth;
  {
    height = depth;
    rec = (char *)(824 + W(P(track, 140), 820) * 48 + (u32)P(track, 140));
    W(rec, 40) = height;
    W(rec, 36) = index;
    W(rec, 32) = 0;
    *((Matrix *) rec) = mat;
    W(rec, 44) = U(cell_ids, cell * 2);
    W(P(track, 140), 820)++;
  }
  }
}
