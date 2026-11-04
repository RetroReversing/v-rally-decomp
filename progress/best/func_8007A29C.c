#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define P(p,o) (*(void **)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define SH(p,o) (*(s16 *)((u8 *)(p)+(o)))
void func_8004C7F0(void *);
void func_8004D31C();
u8 *func_800592AC(s8);
u8 *func_800592D0(s32);
void func_8005937C(s32, u8);
void func_8005BB5C();
void func_8005BC60();
void func_80069974(u8, void *);
void func_8007EE9C(void *);
void func_80081540(void *);
void func_8008A0D8(void *, s32, s32);
extern u8 *D_800A1468;
extern u8 D_800A5F7C[];
extern u8 D_800A5F8C[];
extern u8 *D_800C3508;
typedef struct 
{
  u8 pad0[0x32];
  u8 idx[0x16];
  struct 
  {
    u8 pad[6];
    u8 b6;
    u8 b7;
    u8 pad2[0x20];
  } e[4];
} RS;
extern u8 *D_800C35A0;
extern u8 *D_800D0658;
void func_8007A29C(void)
{
  u8 *ent;
  u8 *tbl;
  u8 *q;
  u8 *ctx;
  u8 *base;
  u8 *node;
  u8 *prev;
  u8 *p;
  u8 *cnt;
  u8 *arr;
  u8 m;
  u8 *r;
  u16 off;
  s8 i;
  s8 j;
  s32 n;
  s32 pad[2];
  u8 t;
  func_8004D31C();
  func_8005BC60();
  func_8005BB5C();
  i = 0;
  B(D_800A1468, 0x22B) = B(D_800A1468, 0x228);
  t = ((RS *) D_800C35A0)->e[((RS *) D_800C35A0)->idx[(s8) B(D_800A1468, 0x228)]].b7;
  B(D_800A1468, 0x237) = t;
  ctx = D_800C3508;
  ent = P(ctx, 0x10) + (SH(ctx, 2) * 0x14);
  B(D_800A1468, 0x238) = H(D_800D0658 + (t * 0x2C4), 0x14);
  base = D_800A1468;
  cnt = base + 0x23D;
  tbl = D_800D0658;
  q = base + 0x241;
  B(base, 0x23D) = 4;
  B(base, 0x23E) = 8;
  B(base, 0x23F) = 4;
  B(base, 0x240) = 4;
  B(base, 0x241) = 0;
  B(base, 0x242) = 4;
  B(base, 0x243) = 0xC;
  B(base, 0x244) = 0x10;
  do
  {
    p = func_800592AC(i);
    node = P(p, 0x28);
    j = 0;
    n = cnt[i];
    off = H(node, 8);
    prev = 0;
    if (n > 0)
    {
      arr = q + i;
      r = cnt + i;
      do
      {
        B(node, 0x22) = (*arr) + j;
        if (H(tbl + ((((s8) (*arr)) + j) * 0x2C4), 0x10) & 8)
        {
          if (prev == 0)
          {
            prev = node;
            node = P(node, 0);
            P(p, 0x28) = node;
            func_8007EE9C(prev);
            prev = 0;
          }
          else
          {
            P(prev, 0) = P(node, 0);
            func_8007EE9C(node);
            node = P(prev, 0);
          }
          do
          {
            *r -= 1;
            B(p, 0x4C) -= 1;
          }
          while (0);
        }
        else
        {
          H(node, 8) = off;
          off += 0x14;
          prev = node;
          node = P(node, 0);
        }
        j++;
      }
      while (j < n);
    }
    if (cnt[i] == 0)
    {
      B(func_800592AC(i), 0x41) = 0;
      func_8008A0D8(D_800C3508, (B(P(D_800C3508, 0x10) + (SH(D_800C3508, 2) * 0x14), 0xD) + i) & 0xFFFF, 0);
      if (B(D_800A1468, 0x238) == i)
      {
        {
          u8 *rs = D_800C35A0;
          rs += (rs + ((s8) B(D_800A1468, 0x228)))[0x32] * 40;
          H(rs, 0x4E) = 4;
        }
        B(D_800A1468, 0x238) = H(D_800D0658, 0xB24);
      }
    }
    func_8005937C(B(ent, 0xD) + i, cnt[i]);
    i++;
  }
  while (i < 4);
  {
    u8 *a2 = P(D_800C3508, 0x10);
    s32 m2 = B(D_800A1468, 0x238);
    B(a2 + (SH(D_800C3508, 2) * 0x14), 0xE) = B(a2 + (SH(D_800C3508, 2) * 0x14), 0xD) + m2;
    func_80069974(m2, a2);
  }
  B(D_800A1468, 0x2BD) = 1;
  func_80081540(D_800A5F7C);
  func_8004C7F0(D_800A5F8C);
  node = func_800592D0(0x38);
  H(node, 4) = ((*((s8 *) (D_800A1468 + 0x228))) == 0) ? (3) : (0x98);
}

