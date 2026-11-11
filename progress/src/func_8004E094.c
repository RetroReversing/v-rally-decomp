static inline s16 inline_second(f32 arg0)
{
 return (s16)((s32)(-arg0));
}
static inline s16 inline_fn(f32 arg0)
{
  return (s16) ((s32) (-arg0));
}

static inline f32 inline_fn2(u8 *arg0)
{
  return (f32) (*((u16 *) (arg0 + 6)));
}

/* Sets up a scaled object when its state (+0x74) is 4: marks it active, computes
   the scale (1024 / +0x98), and stores its screen position (+0x70, +0x72) from
   the entry's first vertex. */
void func_8004E094(void *arg0)
{
  u8 *obj = (u8 *) arg0;
  u8 *objFlagsPtr;
  f32 scale;
  f32 y;
  f32 rawY;
  u8 *node;
  int flagsOff;
  u8 *entry;
  u8 *vertex;
  f32 half;
  f32 x;
  int dummy;
  f32 rawX;
  if ((*((u16 *) (obj + 0x74))) == 4)
  {
    *((volatile s16 *) (obj + 0x98)) = 0x100;
    scale = 1024.0f;
    scale = scale / ((f32) (*((s16 *) (obj + 0x98))));
    ;
    dummy = 0x80;
    entry = *((u8 **) (obj + 0xA4));
    flagsOff = dummy;
    *((s32 *) (obj + flagsOff)) = (*((s32 *) (obj + 0x80))) | 5;
    *((s16 *) (obj + 0x7A)) = 0;
    *((s16 *) (obj + 0x78)) = 1;
    *((s32 *) (obj + flagsOff)) |= 4;
    *((u16 *) (obj + 0x9A)) = (double) 0x100;
    node = *((u8 **) (entry + 4));
    vertex = *((u8 **) node);
    half = 0.5f; x = (scale * inline_fn2(vertex)) * 0.5f;
    rawX = (f32) (*((u16 *) (vertex + 8)));
    y = (scale * rawX) * half;
    objFlagsPtr = obj;
    *((u16 *) (objFlagsPtr + 0x9A)) = *((u16 *) (objFlagsPtr + 0x98));
    *((s32 *) (objFlagsPtr + 0xA0)) |= 4;
    *((s16 *) (objFlagsPtr + 0x70)) = inline_fn(x);
    *((s16 *) (objFlagsPtr + 0x72)) = inline_second(y);
  }
}
