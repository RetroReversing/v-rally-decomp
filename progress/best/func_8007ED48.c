typedef struct V
{
  char pad[0x10];
  void *(*fn)(s32, s32, s32);
} V;
extern s32 D_800A19B0;
extern s32 D_800B5B40;
extern s32 D_800C80A8;
extern s32 D_800C8090;
extern s32 D_800C808C;
extern V *D_800C5BB0[];
extern s32 D_800C72D8[];
void *func_8007ED48(s32 a, s32 b, ...)
{
  s32 n;
  s32 *pn = &n;
  int new_var;
  s32 x;
  void *p;
  s32 q;
  p = 0;
  new_var = 0;
  if (D_800A19B0 == 1)
  {
    ((void (*)(s32)) D_800C80A8)(D_800B5B40 - 4);
  }
  D_800A19B0 = 1;
  D_800B5B40 = (s32) __builtin_return_address(0);
  q = a;
  x = *((s32 *) ((((u32) __builtin_next_arg(b)) + 3) & (~3)));
  if (!(q & 0xffff0000))
  {
    q = D_800C72D8[a];
    n = a;
  }
  else
  {
    n = 1;
    q = q;
  }
  if (!q)
  {
    ((void (*)(s32)) D_800C8090)(D_800B5B40 - 4);
    q = new_var;
  }
  else
    if (D_800B5B40)
  {
    q -= 8;
  }
  else
  {
    q -= 8;
  }
  if (q)
  {
    p = D_800C5BB0[n]->fn(q + 8, b, x);
    if (p)
    {
      *(((s32 *) p) - 2) = n;
    }
    else
    {
      ((void (*)(s32, s32)) D_800C808C)(a, D_800B5B40 - 4);
    }
  }
  D_800A19B0 = 0;
  return p;
}
