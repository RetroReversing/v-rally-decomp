#define I(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern s32 gOrderState[];
extern s32 gStreamState[];
extern u8 *gMirrorListHead;
extern s32 D_8009F500[];
extern s32 D_8009F504[];
extern s32 D_8009F508[];
extern s32 D_8009F50C[];
extern s32 D_8009F518[];
extern s32 D_8009F51C[];
extern void mat3_mul_vec3_q12(s32, void *, void *);
static inline void add3(s32 *d, s32 *a, s32 *b)
{
  d[0] = a[0] + b[0];
  d[1] = a[1] + b[1];
  d[2] = a[2] + b[2];
}

/* Fills the two per-object matrix/record blocks of dst from the source object's rows:
   the header fields and the 4 row-pairs (negated x, then y, z), then the 12 per-vertex
   entries (transformed positions and per-entry counters), and finally adds the
   per-table deltas for the current frame and clears the block's state fields. */
void func_8002B970(u8 *src, u8 *dst)
{
  struct
  {
    s32 x;
    s32 y;
    s32 z;
  } vtx;
  s32 ax0;
  s32 frame;
  s32 base_y;
  s32 idx4;
  s32 ax1;
  s32 ax2;
  s32 tbl_off;
  s32 tbl_off2;
  u8 *anim_c;
  s32 row;
  s32 rowByte;
  s32 off1;
  u8 *ptr_b;
  s32 i;
  s32 near;
  s32 far;
  u8 *anim_a;
  void *pa;
  void *pc;
  void *pd;
  void *vp;
  u8 *anim;
  struct Row { u8 pad[0x44]; s32 v; s32 w; };
  frame = I(gOrderState, 0x82AC);
  base_y = I(src, 0x90);
  frame -= 0x1E;
  base_y += frame;
  I(P(dst, 0x80), 0x4) = base_y;
  i = 4;
  I(P(dst, 0x80), 0x8) = (s32) (I(src, 0xDC) + I(gStreamState, 0x3246));
  rowByte = 0x50;
  row = 4;
  I(P(dst, 0x80), 0xC) = (s32) I(src, 0x128);
  do
  {
    ax0 = ((struct Row *) src)[row].v;
    ax1 = ((struct Row *) src)[row + 1].v;
    ax2 = ((struct Row *) src)[row + 2].v;
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x10) = (s32) (-ax0);
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x14) = ax1;
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x18) = ax2;
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x24) = ax0;
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x28) = ax1;
    row += 3;
    i += 2;
    I((u8 *) (rowByte + ((s32) P(dst, 0x80))), 0x2C) = ax2;
    rowByte += 0x28;
  }
  while (i <= (0xC - 1));
  i = 0;
  far = 0x100;
  near = 0x10;
  off1 = 0;
  do
  {
    pc = P(dst, 0x80);
    mat3_mul_vec3_q12(I(dst, 0x5C) + 0x40, pc + near, pc + far);
    pa = P(dst, 0x80);
    pd = P(dst, 0x58);
    add3((s32 *) ((u8 *) (off1 + (s32) pa) + 0x1F0), (s32 *) ((u8 *) (off1 + (s32) pa) + 0x100), (s32 *) ((u8 *) pd + 0xC));
    vp = (u8 *) (off1 + (s32) P(dst, 0x80));
    vtx = *((typeof(vtx) *) (vp + 0x1F0));
    { s32 tx; I(off1 + (s32) P(dst, 0x60), 0x60) = (tx = vtx.x, anim = gMirrorListHead, tx); }
    I(off1 + (s32) P(dst, 0x60), 0x64) = vtx.y;
    far += 0x14;
    I(off1 + (s32) P(dst, 0x60), 0x68) = vtx.z;
    idx4 = i * 4;
    I((i * 4) + (s32) P(dst, 0x60), 0x30) = (s32) (I(anim, 0x4C) - 1);
    near += 0x14;
    anim_a = anim;
    I(idx4 + (s32) P(dst, 0x34), 0x30) = (s32) (I(anim_a, 0x4C) - 1);
    i += 1;
    ptr_b = anim_a;
    I(idx4 + (s32) P(dst, 0x60), 0) = ((u16) H(anim_a, 0x88)) >> 1;
    I(idx4 + (s32) P(dst, 0x34), 0) = ((u16) H(ptr_b, 0x88)) >> 1;
    off1 += 0x14;
  }
  while (i < 0xC);
  I(P(dst, 0x8C), 0x578) = (s32) I(D_8009F500, H(P(gStreamState, 0x32F2), 0x16) * 0x30);
  I(P(dst, 0x8C), 0x57C) = (s32) I(D_8009F504, H(P(gStreamState, 0x32F2), 0x16) * 0x30);
  tbl_off = H(P(gStreamState, 0x32F2), 0x16) * 0x30;
  I(D_8009F500, tbl_off) = I(D_8009F500, tbl_off) + I(D_8009F508, tbl_off);
  tbl_off2 = H(P(gStreamState, 0x32F2), 0x16) * 0x30;
  anim_c = anim_a;
  I(D_8009F504, tbl_off2) = I(D_8009F504, tbl_off2) + I(D_8009F50C, tbl_off2);
  I(P(dst, 0x34), 0x170) = (s32) I(D_8009F518, H(P(gStreamState, 0x32F2), 0x16) * 0x30);
  row = H(P(gStreamState, 0x32F2), 0x16) * 0x30;
  I(D_8009F518, row) = I(D_8009F518, row) + I(D_8009F51C, row);
  I(P(dst, 0x34), 0x160) = 1;
  I(P(dst, 0x34), 0x158) = 0;
  I(P(dst, 0x34), 0x164) = 0;
  I(P(dst, 0x34), 0x168) = 0;
  I(P(dst, 0x34), 0x16C) = 0x1F4;
  I(P(dst, 0x34), 0x154) = 0;
  P(P(dst, 0x34), 0x150) = anim_a;
  I(P(dst, 0x60), 0x160) = 0;
  I(P(dst, 0x60), 0x158) = 0;
  I(P(dst, 0x60), 0x164) = 0;
  I(P(dst, 0x60), 0x168) = 0;
  I(P(dst, 0x60), 0x16C) = 0x1F4;
  I(P(dst, 0x60), 0x154) = 0;
  P(P(dst, 0x60), 0x150) = anim_c;
  I(P(dst, 0x60), 0x178) = 0;
  I(P(dst, 0x60), 0x174) = 0;
}
