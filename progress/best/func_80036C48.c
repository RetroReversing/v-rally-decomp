typedef struct 
{
  u8 v[6];
} Bytes6;
typedef struct 
{
  u8 v[18];
} Bytes18;
extern Bytes6 D_800A4A98;
extern Bytes6 D_800A4AA0;
extern Bytes18 D_800A4AA8;
extern void *D_800C60D4;
extern void *func_80080440(void);
extern void *func_800801D0(void *, s32);
extern void *func_80034FF0(void *, s32);
extern void *func_8007EAA0(s32, s32);
extern void func_8000A5EC(void *, void *, s32, s32, s32, s32, s32);
static inline static int inline_fn(u8 arg0)
{
  return arg0 * 3;
}

void func_80036C48(u8 *p)
{
  void *new_var;
  Bytes6 a;
  Bytes6 b;
  Bytes18 c;
  u8 *bp;
  u8 *ap;
  void *new_var3;
  u8 *cp;
  void *new_var4;
  u8 *new_var2;
  u8 *n;
  u8 *q;
  u8 *t;
  u8 j;
  a = D_800A4A98;
  b = D_800A4AA0;
  c = D_800A4AA8;
  j = 0;
  cp = c.v;
  ap = a.v;
  bp = b.v;
  D_800C60D4 = func_80080440();
  n = func_800801D0(D_800C60D4, 28);
  t = func_8007EAA0(6, 176);
  *((void **) (n + 0xC)) = t;
  *((void **) (t + 0xA4)) = q;
  func_8000A5EC((*((u8 **) (n + 0xC))) + 16, *(*((void ***) (q + 4))), 1, 0, 0, 0, 0);
  n[0x14] = 100;
  n[0x15] = 0;
  n[0x16] = 255;
  n[0x17] = 255;
  n[0x18] = 255;
  *((s16 *) (n + 0x10)) = 128;
  n = (new_var = func_800801D0(D_800C60D4, 28));
  *((s16 *) (n + 0x12)) = 128;
  q = func_80034FF0(p + 0x390, 0);
  t = func_8007EAA0(6, 176);
  *((void **) (n + 0xC)) = t;
  *((void **) (t + 0xA4)) = q;
  func_8000A5EC((*((u8 **) (n + 0xC))) + 16, *(*((void ***) (q + 4))), 1, 0, 0, 0, 0);
  *((s16 *) (n + 0x10)) = 0;
  *((s16 *) (n + 0x12)) = 0;
  n[0x14] = 100;
  n[0x15] = 0;
  n[0x16] = 255;
  n[0x17] = 255;
  n[0x18] = 255;
  do
  {
    q = func_80034FF0(p + 0x2F8, 0);
    new_var3 = func_8007EAA0(6, 176);
    n = func_800801D0(D_800C60D4, 28);
    t = new_var3;
    *((void **) (n + 0xC)) = t;
    *((void **) (t + 0xA4)) = q;
    func_8000A5EC((*((u8 **) (n + 0xC))) + 16, *(*((void ***) (q + 4))), 1, 0, 0, 0, 0);
    *((s16 *) (n + 0x10)) = 0;
    *((s16 *) (n + 0x12)) = 0;
    n[0x14] = bp[j];
    n[0x15] = ap[j];
    n[0x16] = cp[inline_fn(j)];
    n[0x17] = cp[inline_fn(j) + 1];
    n[0x18] = cp[(j * 3) + 2];
    j++;
  }
  while (j < 5);
  new_var2 = c.v;
  n = func_800801D0(D_800C60D4, 28);
  q = func_80034FF0(p + 0x2AC, 0);
  new_var4 = func_8007EAA0(6, 176);
  q = func_80034FF0(p + 0x344, 0);
  t = new_var4;
  *((void **) (n + 0xC)) = t;
  *((void **) (t + 0xA4)) = q;
  func_8000A5EC((*((u8 **) (n + 0xC))) + 16, *(*((void ***) (q + 4))), 1, 0, 0, 0, 0);
  *((s16 *) (n + 0x10)) = 0;
  *((s16 *) (n + 0x12)) = 0;
  n[0x14] = b.v[j];
  n[0x15] = D_800A4A98.v[j];
  n[0x16] = new_var2[inline_fn(j)];
  n[0x17] = new_var2[(j * 3) + 1];
  n[0x18] = new_var2[inline_fn(j) + 2];
}
