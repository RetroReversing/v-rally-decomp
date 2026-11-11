void updateRotatedTransform(void *, s32, s32);
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
} Img;
typedef struct 
{
  u8 pad0[0xC];
  Img *img;
  u32 f10;
  u32 f14;
  u16 f18;
  s16 f1A;
  u16 f1C;
  u16 f1E;
  u32 f20;
  s32 f24;
  u32 f28;
  u32 f2C;
  u16 f30;
  s16 f32;
  s16 f34;
  u16 f36;
  u32 f38;
  s32 f3C;
  u16 pad40;
  s16 f42;
  s16 f44;
  s16 f46;
  u16 pad48;
  s16 f4A;
  s16 f4C;
  s16 f4E;
  u16 f50;
  u16 f52;
  u8 f54;
  u8 f55;
  u8 f56;
  u8 f57;
} Obj;

/* Fills an Obj's draw state from a texture descriptor. The tile layout depends on img->type:
 * 16 and 256 are the two palette-indexed formats, anything else is treated as 16bpp.
 * Mode bit 0 skips the per-tile setup. Flags bit 0x20 applies a transform at (x, y). */
void func_8000A5EC(Obj *obj, Img *img, u8 mode, s32 flags, u16 x, u16 y, u16 idx)
{
  u32 v;
  s32 m;
  obj->img = img;
  m = mode;
  if (img->type == 16)
  {
    u32 w = img->w;
    obj->f52 = 0;
    obj->f54 = 2;
    obj->f55 = 0;
    obj->f50 = w >> 4;
    if (mode & 1)
    {
      goto fin;
    }
    obj->f30 = 0;
    v = img->w >> 4;
  }
  else
    if (img->type == 256)
  {
    u32 w = img->w;
    obj->f54 = 2;
    obj->f55 = 1;
    obj->f52 = 0;
    obj->f50 = w >> 3;
    if (mode & 1)
    {
      goto fin;
    }
    obj->f30 = 0;
    v = img->w >> 3;
  }
  else
  {
    u32 w = img->w;
    obj->f52 = 0;
    obj->f54 = 0;
    obj->f55 = 3;
    obj->f50 = w >> 2;
    if (mode & 1)
    {
      obj->f30 = 0;
      obj->f32 = ((img->w * img->h) >> 1) - 1;
      obj->f34 = (0x7FF / (img->w >> 2)) + 1;
      goto fin;
    }
    obj->f30 = 0;
    v = img->w >> 1;
  }
  obj->f32 = (v * 4) - 1;
  obj->f34 = (img->size * 4) - 1;
  fin:
  {
    u16 t1;
    u16 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u32 t7;
    obj->f42 = 0x400;
    t1 = img->w;
    obj->f46 = 0;
    obj->f4A = 0x400;
    obj->f44 = t1 << 5;
    t2 = img->size;
    obj->f4E = 0;
    obj->f56 = 0;
    obj->f57 = 0;
    obj->f4C = t2 << 5;
    obj->f28 = (mode & 1) ? (0x1033) : (0xFC1034);
    t3 = *img->ptr;
    obj->f36 = 0;
    obj->f2C = t3;
    t4 = *img->ptr;
    obj->f3C = -1;
    obj->f38=t4;
    do {t3=0x30;obj->f10=t3;}while(0);
    t5 = img->tab[idx];
    obj->f18 = 0x100;
    obj->f14 = t5;
    m = -1;
    t6 = img->type;
    obj->f1C = 0;
    obj->f1E = 0;
    obj->f1A = t6 - 1;
    t7 = img->tab[idx];
    obj->f24 = m;
    obj->f20 = t7;
  }

  if (flags & 0x20)
  {
    updateRotatedTransform(obj, (s16) x, (s16) y);
  }
  osWritebackDCache(obj, 0x60);
}
