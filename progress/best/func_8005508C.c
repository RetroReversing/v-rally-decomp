extern u8 *D_800C35A0;
extern u8 D_800C3A90[];
extern u8 D_800C3A96[];
extern u8 D_800C3A9A[];
extern u8 D_800C3A9C[];
extern u8 D_800C3AD0[];
extern u8 D_800C3AD6[];
extern u8 D_800C3ADA[];
extern u8 D_800C3ADC[];
extern u8 D_800C3B10[];
extern u8 D_800C3B16[];
extern u8 D_800C3B40[];
extern u8 D_800C3B44;
extern u8 D_800C3B45;
extern u8 D_800C3B4A;
extern u8 D_800C3B4B;
extern u8 D_800C3B4C;
extern void func_80098290(void *, void *);
extern s32 func_80098180();
extern void func_800535F4(void *);
static inline static static int inline_fn(s32 arg0, int arg1)
{
  return ((u32) (arg0 & 255)) < arg1;
}

static inline static int inline_fn2(s32 arg0, int arg1)
{
  return arg0 & arg1;
}

void func_8005508C(void)
{
  char *__repair_addr;
  s32 values[8];
  u8 pos[6];
  s32 i = 0;
  s32 j;
  s32 active;
  s32 found;
  s32 first;
  s32 ok;
  s32 *p;
  s32 offset;
  do
  {
    first = 0;
    found = 0;
    active = 1;
    j = 0;
    func_80098290(pos, D_800C35A0 + ((inline_fn2(i, 255) * 40) + 0x44));
    p = &values[inline_fn2(i, 255)];
    p[0] = 0;
    p[4] = 0;
    do
    {
      j = inline_fn2(j, 255) * 16;
      offset = j;
      if ((D_800C3A9C[offset] == 1) && (func_80098180(pos, D_800C3A96 + offset) == 0))
      {
        p[0] += *((s32 *) (D_800C3A90 + offset));
        p[4] += D_800C3A9A[offset];
        found = 1;
        goto first_done;
      }
      else
      {
        j++;
      }
    }
    while (inline_fn2(active, inline_fn(j, 3)));
    first_done:
    if (inline_fn2(found, 255))
    {
      first = 1;
    }

    found = 0;
    active = 1;
    j = 0;
    p = &values[inline_fn2(i, 255)];
    do
    {
      offset = inline_fn2(j, 255) * 16;
      if ((D_800C3ADC[offset] == 1) && (func_80098180(pos, D_800C3AD6 + offset) == 0))
      {
        p[0] += *((s32 *) (D_800C3AD0 + offset));
        found = 1;
        p[4] += D_800C3ADA[offset];
        break;
      }
      else
      {
        j++;
      }
    }
    while (inline_fn2(active, ((u32) inline_fn2(j, 255)) < 3));
    ok = 1;
    if (inline_fn2(first, found))
    {
      j = 0;
      do
      {
        offset = inline_fn2(j, 255) * 16;
        j++;
        if (func_80098180(pos, D_800C3B16 + offset) == 0)
        {
          ok &= -((*((s32 *) (D_800C3B10 + offset))) != values[inline_fn2(i, 255)]);
        }
      }
      while (((u32) inline_fn2(j, 255)) < 3);
      if (inline_fn2(ok, 255))
      {
        p = &values[inline_fn2(i, 255)];
        *((s32 *) D_800C3B40) = p[0];
        __repair_addr = (char *) ((D_800C35A0 + (inline_fn2(i, 255) * 40)) + 0x4e);
        D_800C3B44 = *((u16 *) __repair_addr);
        D_800C3B45 = *((u16 *) (D_800C35A0 + 0x16));
        func_80098290(D_800C3B40 + 6, D_800C35A0 + ((inline_fn2(i, 255) * 40) + 0x44));
        D_800C3B4B = 0;
        D_800C3B4C = 1;
        D_800C3B4A = (((u32) p[4]) >> 3) + 4;
        func_800535F4(D_800C3B40 - 0x30);
      }
    }
    i++;
  }
  while (((u32) inline_fn2(i, 255)) < 4);
}
