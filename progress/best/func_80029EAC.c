#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct { s16 x; s16 y; s16 z; } Vertex;
typedef struct { s16 h[10]; int pad[3]; } Matrix;
typedef union { struct { s16 x; s16 z; u32 pad; } p; int word; } Pair;
void func_8002D724(int *, int *, int *);
void func_8002D740(int *, int *, int *);
void func_8002D75C(int, int, int, int *);
void func_8002D7E4(int, int *);
void func_8002DA98(void *, void *);
void func_8002E530(void *, void *, void *);
void func_8002E688(int *, int *);
void func_80029EAC(char *a, Vertex *point, int index)
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
  struct { s16 x; s16 y; s16 z; } delta;
  int sign;
  int row;
  int col;
  int base;
  int right;
  int down;
  int tmp;
  register int slot;
  register int height;
  int dot;
  int cell;
  u16 w;
  char *g;
  char *indices;
  char *record;
  Vertex *v;
  g = P(P(a, 140), index * 4);
  row = W(P(a, 96) + index * 4, 0);
  col = W(P(a, 96) + index * 4, 48);
  w = U(g, 138);
  indices = P(g, 112);
  base = w * row + col;
  r.p.x = point->x;
  r.p.z = point->z;
  right = base + 1;
  p.p.x = ((Vertex *) P(g, 84))[right].x;
  p.p.z = ((Vertex *) P(g, 84))[right].z;
  down = base + w;
  q.p.x = ((Vertex *) P(g, 84))[down].x;
  q.p.z = ((Vertex *) P(g, 84))[down].z;
  cell = row * (w - 1) + col;
  func_8002D75C(p.word, q.word, r.word, &sign);
  height = down + 1;
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
  if ((((unsigned) (index - 4) < 2) | (index == 10)) || (index == 11))
  {
    int sx, sy, sz;
    height = 0;
    func_8002D724(c, b, normal);
    slot = (index == 4) * 2;
    if (index == 5)
      slot = 3;
    slot &= -(index != 10);
    if (index == 11)
      slot = 1;
    func_8002D7E4(normal[0], &sx);
    func_8002D7E4(normal[1], &sy);
    func_8002D7E4(normal[2], &sz);
    if (sx < 16 || sy < 16 || sz < 16)
    {
      if (sx > sy)
        sx = sy;
      if (sx > sz)
        sx = sz;
      sx = 17 - sx;
      normal[0] >>= sx;
      normal[1] >>= sx;
      normal[2] >>= sx;
    }
    v = (Vertex *) P(g, 84);
    right = v[base].x * normal[0] + v[base].y * normal[1] + v[base].z * normal[2];
    if (normal[1])
    {
      height = (-normal[0] * r.p.x - normal[2] * r.p.z + right) / normal[1];
    }
    W(P(a, 140), slot * 20 + 176) = point->x;
    W(P(a, 140), slot * 20 + 180) = height;
    W(P(a, 140), slot * 20 + 184) = point->z;
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
  delta.x = point->x - ((Vertex *) P(g, 84))[base].x;
  delta.y = point->y - ((Vertex *) P(g, 84))[base].y;
  delta.z = point->z - ((Vertex *) P(g, 84))[base].z;
  func_8002E530(&mat, &delta, local);
  func_8002DA98(&mat, &inv);
  mat = inv;
  tmp = local[1] * 16;
  if (tmp <= 0)
  {
    record = P(a, 140) + 824;
    record += W(P(a, 140), 820) * 48;
    W(record, 40) = tmp;
    W(record, 36) = index;
    W(record, 32) = 0;
    *((Matrix *) record) = mat;
    W(record, 44) = U(indices, cell * 2);
    W(P(a, 140), 820)++;
  }
}
