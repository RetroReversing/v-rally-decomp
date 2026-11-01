void func_8000B910(void *, s16, s16);
void osWritebackDCache(void *, s32);
typedef struct 
{
  u8 pad[4];
  u16 type;
  u16 w;
  u16 h;
  u16 padA;
  u16 size;
  u8 padE[2];
  u32 *tab;
  u32 *ptr;
  u32 x;
  u32 *items;
} Img;
static inline static u16 *inline_fn(void *arg0)
{
  return (u16 *) (((u8 *) arg0) + 0x52);
}

static inline static static static static u16 inline_fn2(Img *arg0, int arg1)
{
  return arg0->w >> arg1;
}

static inline static static static static u8 *inline_fn23(void *arg0)
{
  return (u8 *) arg0;
}

void func_8000A5EC(void *o, Img *im, s32 mode, s32 flags, s32 arg4, s32 arg5, s32 arg6)
{
  u16 a4;
  u8 *new_var3;
  u16 a5;
  u16 idx;
  u16 new_var2;
  s32 type;
  unsigned int v;
  void *new_var;
  s32 __repair_v_1;
  s32 x;
  *((void **) (inline_fn23(o) + 12)) = im;
  a4 = arg4;
  new_var = o;
  a5 = arg5;
  idx = arg6;
  type = im->type;
  if (type == 16)
  {
    new_var2 = inline_fn2(im, 4);
    *((u16 *) (inline_fn23(o) + 0x52)) = 0;
    *inline_fn23(inline_fn23(o) + 0x54) = 2;
    *inline_fn23(inline_fn23(o) + 0x55) = 0;
    *((u16 *) (inline_fn23(o) + 0x50)) = new_var2;
    if (mode & 1)
    {
      goto finish;
    }
    *((u16 *) (inline_fn23(o) + 0x30)) = 0;
    v = inline_fn2(im, 4);
    goto basic;
  }
  else
    if (type == 256)
  {
    v = im->w;
    *((u8 *) (((u8 *) o) + 0x54)) = 2;
    *((u8 *) (((u8 *) o) + 0x55)) = 1;
    *((u16 *) (((u8 *) o) + 0x52)) = 0;
    *((u16 *) (((u8 *) o) + 0x50)) = v >> 3;
    if (mode & 1)
    {
      if (1)
      {
        goto direct;
      }
    }
    *((u16 *) (((u8 *) o) + 0x30)) = 0;
    v = inline_fn2(im, 3);
    goto basic;
  }
  else
  {
    v = im->w;
    *inline_fn(o) = 0;
    *((u8 *) (inline_fn23(o) + 0x54)) = 0;
    *inline_fn23(inline_fn23(o) + 0x55) = 3;
    *((u16 *) (inline_fn23(o) + 0x50)) = inline_fn2(im, 2);
    if (mode & 1)
    {
      *((u16 *) (inline_fn23(o) + 0x30)) = 0;
      ;
      ;
      *((s16 *) (((u8 *) o) + 0x32)) = (((s32) (im->w * im->h)) >> 1) - 1;
      ;
      *((s16 *) (((u8 *) o) + 0x34)) = (0x7ff / inline_fn2(im, 2)) + 1;
      goto finish;
    }
    *((u16 *) (((u8 *) o) + 0x30)) = 0;
    v = inline_fn2(im, 1);
    goto basic;
  }
  direct:
  *((u16 *) (((u8 *) o) + 0x30)) = 0;

  goto finish;
  basic:
  *((s16 *) (inline_fn23(o) + 0x32)) = (v << 2) - 1;

  v = im->size;
  ;
  *((s16 *) (inline_fn23(o) + 0x34)) = (v << 2) - 1;
  finish:
  *((s16 *) (((u8 *) o) + 0x42)) = 0x400;

  *((s16 *) (inline_fn23(o) + 0x46)) = 0;
  *((s16 *) (((u8 *) o) + 0x4a)) = 0x400;
  __repair_v_1 = im->w;
  *((s16 *) (inline_fn23(o) + 0x44)) = __repair_v_1 << 5;
  v = im->size;
  *((s16 *) (inline_fn23(o) + 0x4e)) = 0;
  *inline_fn23(inline_fn23(o) + 0x56) = 0;
  *inline_fn23(((u8 *) o) + 0x57) = 0;
  *((s16 *) (inline_fn23(o) + 0x4c)) = v << 5;
  v = 0x1033;
  if (!(mode & 1))
  {
    v = 0xfc1034;
  }
  *((u32 *) (inline_fn23(o) + 0x28)) = v;
  v = *((u32 *) im->ptr);
  *((u16 *) (((u8 *) o) + 0x36)) = 0;
  *((u32 *) (((u8 *) o) + 0x2c)) = v;
  v = *((u32 *) im->ptr);
  *((u32 *) (((u8 *) o) + 0x3c)) = -1;
  new_var3 = ((u8 *) o) + 0x10;
  *((u32 *) (((u8 *) o) + 0x38)) = v;
  *((u32 *) new_var3) = 0x30;
  x = idx;
  x = x << 2;
  v = *((u32 *) (x + ((int) im->tab)));
  *((u16 *) (((u8 *) o) + 0x18)) = 0x100;
  *((u32 *) (((u8 *) o) + 0x14)) = v;
  *((u16 *) (inline_fn23(new_var) + 0x1c)) = 0;
  *((u16 *) (inline_fn23(o) + 0x1e)) = 0;
  ;
  *((s16 *) (((u8 *) o) + 0x1a)) = im->type - 1;
  v = *((u32 *) (x + ((int) im->tab)));
  *((u32 *) (((u8 *) o) + 0x24)) = -1;
  *((u32 *) (((u8 *) o) + 0x20)) = v;
  if (flags & 32)
  {
    do
    {
      func_8000B910(o, (s16) a4, (s16) a5);
    }
    while (0);
  }
  osWritebackDCache(o, 96);
}

