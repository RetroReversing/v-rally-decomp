extern char D_800AE850[];
extern u16 D_8009BBB6;
s32 func_80015460();
static inline char **inline_fn(char *arg0)
{
  return (char **) (arg0 + 0x50);
}

void *func_80016204(char *arg0)
{
  s32 pad[4];
  s32 i;
  s32 off;
  s32 count;
  s32 add;
  s32 val;
  s32 t;
  u16 n;
  f32 *new_var;
  s32 cnt;
  char *base;
  char *p;
  char *s4;
  func_80015460(arg0, 1);
  s4 = arg0;
  base = *((char **) arg0);
  i = 0;
  cnt = *((u16 *) (arg0 + 4));
  if (cnt > 0)
  {
    off = 0;
    do
    {
      do
      {
        p = base - (-off);
        n = *((u16 *) (p + 0x64));
        val = *((s32 *) (D_800AE850 + 0x6E9C));
        t = (*((s32 *) (p + 0x68))) + val;
        *((s32 *) (p + 0x50)) += val;
        *((s32 *) (p + 0x54)) += val;
      }
      while (0);
      *((s32 *) (p + 0x68)) = t;
      func_80015460(t, count = n, val);
      i += 1;
      off += 0x6C;
    }
    while (i < (*((u16 *) (s4 + 4))));
  }
  count = ((u32) ((*((s32 *) (base + 0x54))) - (*((s32 *) (base + 0x50))))) / 6;
  i = 0;
  if (count != 0)
  {
    do
    {
      off = 0;
      add = D_8009BBB6 + (*((s32 *)((char *)D_800AE850 + 0x10000 + 0x6AFC)) / (val = 2));
    }
    while (0);
    do
    {
      *((u16 *) ((char *)(off + (s32)(*inline_fn(base))) + 2)) += add;
      *((s16 *) ((char *)(off + (s32)(*inline_fn(base))) + 4)) = (s16) ((s32) (((f32) (t = (short) (*((s16 *) ((char *)(off + (s32)(*inline_fn(base))) + 4))))) + (*(new_var = &(*((f32 *) (base + 0x48)))))));
      i += 1;
      off += 6;
    }
    while (i < ((s32) count));
  }
  return arg0;
}
