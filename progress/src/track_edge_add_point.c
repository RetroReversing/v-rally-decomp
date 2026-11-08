/* Field accessors: W = s32 at byte offset, P = pointer at offset, H = u16 at offset. */
#define W(p,o) (*(s32*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
extern void func_8002E688(s32 *, s32 *);
extern void func_8002E530(void *, void *, void *);
extern void func_8002DA98(void *, void *);
typedef struct 
{
  s32 w[8];
} Mat;

/* Adds a point to a track edge: picks the two segment vertices for this edge
 * (edge is -8..-1), builds a rotation matrix from the segment direction, and
 * for the ring edges (idx 4, 5, 10, 11) stores the point in the car's slots.
 * When the point is below the track (d[1] <= 0) a 48-byte record is appended
 * to the car's edge list at obj+0x8c. */
void track_edge_add_point(u8 *obj, s16 *point, s32 idx, s32 edge)
{
  s32 first = 0;
  s32 second = 0;
  s32 x;
  s32 z;
  s32 off;
  s32 n;
  u8 *seg;
  u8 *idx_tab;
  u8 *rec_list;
  u8 *rec;
  s32 delta[4];
  s16 rel[4];
  union 
  {
    s16 h[16];
    Mat m;
  } mat;
  Mat inv;
  s16 unused[4];
  seg = P(P(obj, 0x8c), idx * 4);
  idx_tab = P(obj, 0x60);
  x = W(idx_tab, idx * 4);
  z = W(idx_tab, (idx * 4) + 0x30);
  switch (edge)
  {
    case -8:
      first = (H(seg, 0x8a) * x) + z;
      second = first + 1;
      break;
    case -7:
      second = ((H(seg, 0x8a) * x) + z) + H(seg, 0x8a);
      first = second + 1;
      break;
    case -6:
      second = (H(seg, 0x8a) * x) + z;
      first = second + H(seg, 0x8a);
      break;
    case -5:
      first = ((H(seg, 0x8a) * x) + z) + 1;
      second = first + H(seg, 0x8a);
      break;
    case -4:
      { s32 base = H(seg, 0x8a) * x + z;
      first = base + 1;
      second = base + H(seg, 0x8a); }
      break;
    case -3:
      second = (H(seg, 0x8a) * x) + z;
      first = (second + H(seg, 0x8a)) + 1;
      break;
    case -2:
      first = (H(seg, 0x8a) * (x + 1)) + z;
      second = (first - H(seg, 0x8a)) + 1;
      break;
    case -1:
      first = (H(seg, 0x8a) * x) + z;
      second = (first + H(seg, 0x8a)) + 1;
      break;
  }
  delta[0] = ((s16 *) P(seg, 0x54))[second * 3] - ((s16 *) P(seg, 0x54))[first * 3];
  delta[1] = ((s16 *) P(seg, 0x54))[(second * 3) + 1] - ((s16 *) P(seg, 0x54))[(first * 3) + 1];
  delta[2] = ((s16 *) P(seg, 0x54))[(second * 3) + 2] - ((s16 *) P(seg, 0x54))[(first * 3) + 2];
  switch (edge)
  {
    case -5:
      first = ((H(seg, 0x8a) * (x + 1)) + z) + 1;
      break;
    case -6:
      first = (H(seg, 0x8a) * (x + 1)) + z;
      break;
    case -7:
      first = (H(seg, 0x8a) * x) + z;
      break;
    case -8:
      first = ((H(seg, 0x8a) * x) + z) + 1;
      break;
  }
  func_8002E688(delta, delta);
  mat.h[0] = -delta[0];
  mat.h[1] = 0;
  mat.h[2] = -delta[2];
  mat.h[3] = -delta[2];
  mat.h[4] = 0;
  mat.h[5] = delta[0];
  mat.h[6] = 0;
  mat.h[7] = 4096;
  mat.h[8] = 0;
  rel[0] = point[0] - ((u16 *) P(seg, 0x54))[first * 3];
  rel[1] = point[1] - ((u16 *) P(seg, 0x54))[(first * 3) + 1];
  rel[2] = point[2] - ((u16 *) P(seg, 0x54))[(first * 3) + 2];
  func_8002E530(&mat, rel, delta);
  func_8002DA98(&mat, &inv);
  mat.m = inv;
  if ((off = delta[1] << 4) > 0)
    goto L8C0;
  rec_list = P(obj, 0x8c);
  n = W(rec_list, 0x334);
  rec_list += 0x338;
  off = n * 48;
  rec = (u8 *)(off + (u32)rec_list);
  W(rec, 0x28) = delta[1] << 4;
  W(rec, 0x24) = idx;
  W(rec, 0x20) = 0;
  *((Mat *) rec) = mat.m;
  W(rec, 0x2c) = 0;
  rec_list = P(obj, 0x8c);
  W(rec_list, 0x334)++;
L8C0:
  if (((((u32) (idx - 4)) < 2) || (idx == 10)) || (idx == 11))
  {
    n = (idx == 4) * 2;
    if (idx == 5) { n = 3; }
    if (idx == 10) { n = 0; }
    if (idx == 11) { n = 1; }
    W(P(obj, 0x8c), (n * 20) + 0xb0) = point[0];
    W(P(obj, 0x8c), (n * 20) + 0xb8) = point[2];
  }
}
