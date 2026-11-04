typedef struct Vertex3
{
  s16 x;
  s16 y;
  s16 z;
} Vertex3;
typedef struct PairHalves
{
  u16 x;
  u16 z;
} PairHalves;
typedef struct Inv4
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
} Inv4;
void func_8002D75C(s32, s32, s32, s32 *);
void func_8002E688(s32 *, s32 *);
void func_8002D740(s32 *, s32 *, s32 *);
void func_8002D8A0(void *, void *, void *);
void func_8002DA98(void *, void *);
typedef struct Grid29
{
  u8 pad0[0x54];
  Vertex3 *verts;
  u8 pad58[0x18];
  u16 *attr;
  u8 pad74[0x16];
  u16 count;
} Grid29;
typedef struct Obj29
{
  u8 pad0[0x60];
  s32 *table;
  u8 pad64[0x1C];
  s32 *out;
  u8 pad84[8];
  s32 *grids;
} Obj29;
static inline int inline_fn(int arg0)
{
  return arg0 + 0x310;
}

void func_80029AA8(Obj29 *obj, s32 *point, Vertex3 *sample, s32 index)
{
  PairHalves rightXZ;
  PairHalves downXZ;
  PairHalves sampleXZ;
  int new_var2;
  s32 local[4];
  s32 delta[4];
  s32 diffD[4];
  s32 cross[4];
  int new_var3;
  s32 diffR[4];
  s16 mat[16];
  s32 inv[8];
  volatile long sign;
  s32 cell;
  Grid29 *grid;
  u16 *attr;
  s32 base;
  s32 down;
  s32 right;
  Inv4 *new_var;
  s32 diag;
  s32 clamped;
  s32 *slot;
  s32 row;
  s32 col;
  s32 count;
  Inv4 *dst;
  grid = *((Grid29 **) (((s32) obj->grids) + (index * 4)));
  slot = (s32 *) ((index * 4) + ((s32) obj->table));
  row = slot[0];
  col = slot[12];
  count = grid->count;
  attr = grid->attr;
  sampleXZ.x = sample->x;
  sampleXZ.z = sample->z;
  base = count * row + col;
  new_var2 = 1;
  down = base + count;
  right = base + new_var2;
  cell = (row * (count - new_var2)) + col;
  rightXZ.x = grid->verts[right].x;
  rightXZ.z = grid->verts[right].z;
  downXZ.x = grid->verts[down].x;
  diag = down + new_var2;
  downXZ.z = grid->verts[down].z;
  func_8002D75C(*((s32 *) (&rightXZ)), *((s32 *) (&downXZ)), *((s32 *) (&sampleXZ)), &sign);
  if (sign < 0)
  {
    do
    {
      base = diag;
      diag = down;
      down = right;
      right = count;
    }
    while (0);
    right = diag;
  }
  diffR[0] = grid->verts[right].x - grid->verts[base].x;
  diffR[new_var2] = grid->verts[right].y - grid->verts[base].y;
  diffR[2] = grid->verts[right].z - grid->verts[base].z;
  diffD[0] = grid->verts[down].x - grid->verts[base].x;
  diffD[new_var2] = grid->verts[down].y - grid->verts[base].y;
  diffD[2] = grid->verts[down].z - grid->verts[base].z;
  func_8002E688(diffR, diffR);
  func_8002E688(diffD, diffD);
  func_8002D740(diffR, diffD, cross);
  func_8002D740(diffD, cross, diffR);
  mat[0] = diffD[0];
  mat[new_var2] = diffD[new_var2];
  mat[2] = diffD[2];
  mat[3] = cross[0];
  new_var = (Inv4 *) mat;
  mat[4] = cross[new_var2];
  mat[5] = cross[2];
  mat[6] = diffR[0];
  mat[7] = diffR[new_var2];
  mat[8] = diffR[2];
  delta[0] = point[0] - (grid->verts[base].x * 16);
  delta[new_var2] = point[new_var2] - (grid->verts[base].y * 16);
  delta[2] = point[2] - (grid->verts[base].z * 16);
  func_8002D8A0(mat, delta, local);
  func_8002DA98(mat, inv);
  *((Inv4 *) mat) = *((Inv4 *) inv);
  *(new_var + new_var2) = *(((Inv4 *) inv) + new_var2);
  clamped = (local[new_var2] < new_var2) ? (local[new_var2]) : (0);
  *((s32 *) inline_fn(((s32) obj->out) + (index * 4))) = clamped;
  *((s32 *) ((((s32) obj->out) + (index * 4)) + 0x320)) = attr[cell];
  new_var3 = 0x30;
  new_var3 = ((s32) obj->grids) + new_var3;
  dst = (Inv4 *) ((index * 32) + new_var3);
  dst[0] = *((Inv4 *) mat);
  dst[new_var2] = *(((Inv4 *) mat) + new_var2);
}

