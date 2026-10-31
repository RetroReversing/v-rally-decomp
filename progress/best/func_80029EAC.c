#define W(p,o) (*(s32*)((char*)(p)+(o)))
#define H(p,o) (*(s16*)((char*)(p)+(o)))
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
  s16 h[10];
  int pad[3];
} Matrix;
typedef union 
{
  struct 
  {
    u16 x;
    u16 z;
    u32 pad;
  } p;
  int word;
} Pair;
void func_8002D724(int *);
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
  
  struct 
  {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
  } delta;
  int sign;
  int row;
  int col;
  int base;
  int right;
  int down;
  int tmp;
  int slot = 0;
  int height = 0;
  int cell;
  char *g;
  char *indices;
  char *record;
  Vertex *v;
  g = P(P(a, 140), index * 4);
  indices = P(a, 96) + (index * 4);
  row = W(indices, 0);
  col = W(indices, 48);
  base = (U(g, 138) * row) + col;
  right = base + 1;
  down = base + U(g, 138);
  cell = (row * (U(g, 138) - 1)) + col;
  p.p.x = ((Vertex *) P(g, 84))[right].x;
  p.p.z = ((Vertex *) P(g, 84))[right].z;
  q.p.x = ((Vertex *) P(g, 84))[down].x;
  q.p.z = ((Vertex *) P(g, 84))[down].z;
  r.p.x = point->x;
  r.p.z = point->z;
  func_8002D75C(p.word, q.word, r.word, &sign);
  if (sign < 0)
  {
    tmp = right;
    base = down + 1;
    right = down;
    down = tmp;
  }
  v = (Vertex *) P(g, 84);
  c[0] = v[right].x - v[base].x;
  c[1] = ((Vertex *) P(g, 84))[right].y - ((Vertex *) P(g, 84))[base].y;
  c[2] = ((Vertex *) P(g, 84))[right].z - ((Vertex *) P(g, 84))[base].z;
  b[0] = ((Vertex *) P(g, 84))[tmp].x - ((Vertex *) P(g, 84))[base].x;
  b[1] = ((Vertex *) P(g, 84))[tmp].y - ((Vertex *) P(g, 84))[base].y;
  b[2] = ((Vertex *) P(g, 84))[tmp].z - ((Vertex *) P(g, 84))[base].z;
  if (((((unsigned) (index - 4)) < 2) | (index == 10)) || (index == 11))
  {
    int shifts[6];
    func_8002D724(c);
    slot = (index == 4) * 2;
    if (index == 5)
    {
      slot = 3;
    }
    slot &= -(index != 10);
    if (index == 11)
    {
      slot = 1;
    }
    func_8002D7E4(normal[0], shifts);
    func_8002D7E4(normal[1], shifts + 1);
    func_8002D7E4(normal[2], shifts + 2);
    if (((shifts[0] < 16) || (shifts[1] < 16)) || (shifts[2] < 16))
    {
      if (shifts[1] < shifts[0])
      {
        shifts[0] = shifts[1];
      }
      if (shifts[2] < shifts[0])
      {
        shifts[0] = shifts[2];
      }
      shifts[0] = 17 - shifts[0];
      normal[0] >>= shifts[0];
      normal[1] >>= shifts[0];
      normal[2] >>= shifts[0];
    }
    right = -normal[0];
    v = (Vertex *) P(g, 84);
    if (normal[1])
    {
      height = (((((right * ((s16) r.p.x)) - (normal[2] * ((s16) r.p.z))) + (v[base].x * normal[0])) + (v[base].y * normal[1])) + (v[base].z * normal[2])) / normal[1];
    }
    W(P(a, 140), (slot * 20) + 176) = point->x;
    W(P(a, 140), (slot * 20) + 180) = height;
    W(P(a, 140), (slot * 20) + 184) = point->z;
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
    record = (P(a, 140) + (W(P(a, 140), 820) * 48)) + 824;
    W(record, 40) = tmp;
    W(record, 36) = index;
    W(record, 32) = 0;
    *((Matrix *) record) = mat;
    W(record, 44) = U(P(g, 112), cell * 2);
    W(P(a, 140), 820)++;
  }
}
