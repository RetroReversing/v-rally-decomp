extern char gOrderState[];
extern u16 D_8009BBB6;
s32 add_pos_bias_words();
static inline char **inline_fn(char *arg0)
{
  return (char **) (arg0 + 0x50);
}

/* Adds a per-frame offset to the entries of each sub-object (0x6C bytes each) and to the
   six-byte records of the list at obj->base, scaling by the float at +0x48. Returns obj. */
void *func_80016204(char *obj)
{
  s32 pad[4];
  s32 i;
  s32 off;
  s32 off1;
  s32 count;
  s32 add;
  s32 t;
  s32 h;
  s32 b;
  s32 e;
  f32 *new_var;
  s32 cnt;
  char *base;
  char *p;
  char *s4;
  add_pos_bias_words(obj, 1);
  s4 = obj;
  base = *((char **) obj);
  i = 0;
  cnt = *((u16 *) (obj + 4));
  if (cnt > 0)
  {
    off1 = 0;
    do
    {
      do
      {
        p = base - (-off1);
        off = *((u16 *) (p + 0x64));
        count = *((s32 *) (gOrderState + 0x6E9C));
        t = (*((s32 *) (p + 0x68)));
        t += count;
        b = (*((s32 *) (p + 0x50))) + count;
        *((s32 *) (p + 0x50)) = b;
        e = (*((s32 *) (p + 0x54))) + count;
        *((s32 *) (p + 0x54)) = e;
      }
      while (0);
      *((s32 *) (p + 0x68)) = t;
      add_pos_bias_words(t, off, count);
      i += 1;
      off1 += 0x6C;
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
      b = *((s32 *)0x800B6AFC);
      e = (u32) b >> 31;
      t = D_8009BBB6;
      add = t + ((b + e) >> 1);
    }
    while (0);
    do
    {
      *((u16 *) ((char *)(off + (s32)(*inline_fn(base))) + 2)) += add;
      *((s16 *) ((char *)(off + (s32)(*inline_fn(base))) + 4)) = (s16) ((s32) (((f32) (h = (short) (*((s16 *) ((char *)(off + (s32)(*inline_fn(base))) + 4))))) + (*(new_var = &(*((f32 *) (base + 0x48)))))));
      i += 1;
      off += 6;
    }
    while (i < ((s32) count));
  }
  return obj;
}
