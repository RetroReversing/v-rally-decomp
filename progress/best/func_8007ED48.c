typedef struct V
{
  char pad[0x10];
  void *(*fn)(s32, s32, s32);
} V;
extern s32 D_800A19B0;
extern s32 D_800B5B40;
extern void (*D_800C80A8)(s32);
extern void (*D_800C8090)(s32);
extern void (*D_800C808C)(s32, s32);
extern V *D_800C5BB0[];
extern s32 D_800C72D8[];
void *func_8007ED48(s32 a, s32 b, ...)
{
  volatile s32 n;
  s32 x;
  s32 q;
  void *p = 0;
  if (D_800A19B0 == 1)
    D_800C80A8(D_800B5B40 - 4);
  D_800A19B0 = 1;
  D_800B5B40 = (s32) __builtin_return_address(0);
  x = *(s32 *) (((u32) __builtin_next_arg(b) + 3) & ~3);
  if (!(a & 0xffff0000)) { q = D_800C72D8[a]; n = a; } else { q = a; n = 1; }
  if (q == 0) { q = D_800B5B40 - 4; D_800C8090(q); q = 0; } else q -= 8;
  if (q)
  {
    p = D_800C5BB0[n]->fn(q + 8, b, x);
    if (p)
      ((s32 *) p)[-2] = n;
    else
      D_800C808C(a, D_800B5B40 - 4);
  }
  D_800A19B0 = 0;
  return p;
}
