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
void func_80029EAC(void *a, void *point, int index)
{
  Pair p;
  Pair q;
  Pair r;
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
  int base;
  int right;
  int down;
  int slot;
  int height;
  int dot;
  int cell;
  u16 w;
  char *g;
  char *indices;
  char *record;
  Vertex *v;
  g = P(P(a, 140), index * 4);
  row = W(P(a, 96) + (index * 4), 0);
  col = W(P(a, 96) + (index * 4), 48);
  w = U(g, 138);
  indices = P(g, 112);
  base = (w * row) + col;
  r.p.x = (*(s16 *)((unsigned char *)point + 0));
  r.p.z = (*(s16 *)((unsigned char *)point + 4));
  right = base + 1;
  p.p.x = ((Vertex *) P(g, 84))[right].x;
  p.p.z = ((Vertex *) P(g, 84))[right].z;
  down = base + w;
  q.p.x = ((Vertex *) P(g, 84))[down].x;
  q.p.z = ((Vertex *) P(g, 84))[down].z;
  cell = (row * (w - 1)) + col;
  func_8002D75C(p.word, q.word, r.word, &sign);
  height = down;
  height++;
  slot = right;
  if (sign < 0)
  {
    base = height;
    right = down;
    down = slot;
  }
  c[0] = ((Vertex *) P(g, 84))[right].x - ((Vertex *) P(g, 84))[base].x;
  c[1] = ((Vertex *) P(g, 84))[right].y - ((Vertex *) P(g, 84))[base].y;
  c[2] = ((Vertex *) P(g, 84))[right].z - ((Vertex *) P(g, 84))[base].z;
  b[0] = ((Vertex *) P(g, 84))[down].x - ((Vertex *) P(g, 84))[base].x;
  b[1] = ((Vertex *) P(g, 84))[down].y - ((Vertex *) P(g, 84))[base].y;
  b[2] = ((Vertex *) P(g, 84))[down].z - ((Vertex *) P(g, 84))[base].z;
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
    v = (Vertex *) P(g, 84);
    dot = ((unsigned)v[base].x * normal[0] + (unsigned)v[base].y * normal[1]) + (unsigned)v[base].z * normal[2];
    do
    {
      if (normal[1])
      {
        slot = normal[2];
        slot = (int)(((0U - normal[0]) * r.p.x - (unsigned)slot * r.p.z) + (unsigned)dot) / normal[1];
      }
    }
    while (0);
    W(P(a, 140), (height * 20) + 176) = (*(s16 *)((unsigned char *)point + 0));
    W(P(a, 140), (height * 20) + 180) = slot;
    W(P(a, 140), (height * 20) + 184) = (*(s16 *)((unsigned char *)point + 4));
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
  delta[0] = (*(s16 *)((unsigned char *)point + 0)) - ((Vertex *) P(g, 84))[base].x;
  delta[1] = (*(s16 *)((unsigned char *)point + 2)) - ((Vertex *) P(g, 84))[base].y;
  delta[2] = (*(s16 *)((unsigned char *)point + 4)) - ((Vertex *) P(g, 84))[base].z;
  func_8002E530(mat.h, delta, local);
  func_8002DA98(&mat, &inv);
  mat = inv;
  slot = (unsigned)local[1] * 16U;
  if (slot <= 0)
  {
    height = slot;
    record = (char *)(824 + W(P(a, 140), 820) * 48 + (u32)P(a, 140));
    W(record, 40) = height;
    W(record, 36) = index;
    W(record, 32) = 0;
    *((Matrix *) record) = mat;
    W(record, 44) = U(indices, cell * 2);
    W(P(a, 140), 820)++;
  }
}
