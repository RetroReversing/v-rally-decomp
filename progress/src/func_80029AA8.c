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
void vec3_normalize_fixed(s32 *, s32 *);
void func_8002D740(s32 *, s32 *, s32 *);
void mat3_mul_vec3_q12(void *, void *, void *);
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

/* Solves the sample point's position inside grid cell idx (a 2x2 quad of verts).
   Builds the cell's basis from the right and down edges, inverts it, and stores the
   clamped in-cell coordinate in obj->out[idx] and the cell attribute at +0x320.
   The inverse matrix is also written into the grid's block in obj->grids. */
void func_80029AA8(Obj29 *obj, s32 *point, Vertex3 *sample, s32 idx)
{
  PairHalves rightXZ;
  PairHalves downXZ;
  PairHalves sampleXZ;
  int one;
  s32 solved[4];
  s32 delta[4];
  s32 diffDown[4];
  s32 cross[4];
  int dstBase;
  s32 diffRight[4];
  s16 mat[16];
  s32 inv[8];
  volatile long sign;
  s32 cell;
  Grid29 *grid;
  u16 *attr;
  s32 base;
  s32 down;
  union { s32 index; s32 *ptr; } rightIdx;
  Inv4 *matInv;
  s32 diag;
  s32 clamped;
  s32 *slot;
  s32 row;
  s32 col;
  s32 origRight;
  s32 count;
  Inv4 *dst;
  grid = *((Grid29 **) (((s32) obj->grids) + (idx * 4)));
  slot = (s32 *) ((idx * 4) + ((s32) obj->table));
  row = slot[0];
  col = slot[12];
  count = grid->count;
  attr = grid->attr;
  sampleXZ.x = sample->x;
  sampleXZ.z = sample->z;
  base = count * row + col;
  one = 1;
  down = base + count;
  rightIdx.index = base + one;
  cell = (row * (count - one)) + col;
  rightXZ.x = grid->verts[rightIdx.index].x;
  rightXZ.z = grid->verts[rightIdx.index].z;
  downXZ.x = grid->verts[down].x;
  diag = down + one;
  origRight = rightIdx.index;
  downXZ.z = grid->verts[down].z;
  func_8002D75C(*((s32 *) (&rightXZ)), *((s32 *) (&downXZ)), *((s32 *) (&sampleXZ)), &sign);
  if (sign < 0)
  {
    do
    {
      base = diag;
      rightIdx.index = down;
    }
    while (0);
    down = origRight;
  }
  diffRight[0] = grid->verts[rightIdx.index].x - grid->verts[base].x;
  diffRight[one] = grid->verts[rightIdx.index].y - grid->verts[base].y;
  diffRight[2] = grid->verts[rightIdx.index].z - grid->verts[base].z;
  diffDown[0] = grid->verts[down].x - grid->verts[base].x;
  diffDown[one] = grid->verts[down].y - grid->verts[base].y;
  diffDown[2] = grid->verts[down].z - grid->verts[base].z;
  rightIdx.ptr = diffRight;
  vec3_normalize_fixed(rightIdx.ptr, rightIdx.ptr);
  vec3_normalize_fixed(diffDown, diffDown);
  func_8002D740(rightIdx.ptr, diffDown, cross);
  func_8002D740(diffDown, cross, rightIdx.ptr);
  mat[0] = diffDown[0];
  mat[one] = diffDown[one];
  mat[2] = diffDown[2];
  mat[3] = cross[0];
  matInv = (Inv4 *) mat;
  mat[4] = cross[one];
  mat[5] = cross[2];
  mat[6] = diffRight[0];
  mat[7] = diffRight[one];
  mat[8] = diffRight[2];
  delta[0] = point[0] - (grid->verts[base].x * 16);
  delta[one] = point[one] - (grid->verts[base].y * 16);
  delta[2] = point[2] - (grid->verts[base].z * 16);
  mat3_mul_vec3_q12(mat, delta, solved);
  func_8002DA98(mat, inv);
  *((Inv4 *) mat) = *((Inv4 *) inv);
  *(matInv + one) = *(((Inv4 *) inv) + one);
  clamped = (solved[one] < one) ? (solved[one]) : (0);
  *((s32 *) inline_fn(((s32) obj->out) + (idx * 4))) = clamped;
  *((s32 *) ((((s32) obj->out) + (idx * 4)) + 0x320)) = attr[cell];
  dstBase = 0x30;
  dstBase = ((s32) obj->grids) + dstBase;
  dst = (Inv4 *) ((idx * 32) + dstBase);
  dst[0] = *((Inv4 *) mat);
  dst[one] = *(((Inv4 *) mat) + one);
}
