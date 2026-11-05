void func_8000B910(void *, s32, s32);
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
void func_8000A5EC(Obj *o, Img *im, s32 mode, s32 flags, u16 a4, u16 a5, u16 idx)
{
  u32 v;
  u8 m;
  Img *img = im;
  o->img = im;
  m = mode;
  if (im->type == 16)
  {
    u32 w = im->w;
    o->f52 = 0;
    o->f54 = 2;
    o->f55 = 0;
    o->f50 = w >> 4;
    if (mode & 1)
    {
      goto fin;
    }
    o->f30 = 0;
    v = im->w >> 4;
  }
  else
    if (im->type == 256)
  {
    u32 w = im->w;
    o->f54 = 2;
    o->f55 = 1;
    o->f52 = 0;
    o->f50 = w >> 3;
    if (mode & 1)
    {
      goto fin;
    }
    o->f30 = 0;
    v = im->w >> 3;
  }
  else
  {
    u32 w = im->w;
    o->f52 = 0;
    o->f54 = 0;
    o->f55 = 3;
    o->f50 = w >> 2;
    if (mode & 1)
    {
      o->f30 = 0;
      o->f32 = ((im->w * im->h) >> 1) - 1;
      o->f34 = (0x7FF / (im->w >> 2)) + 1;
      goto fin;
    }
    o->f30 = 0;
    v = im->w >> 1;
  }
  o->f32 = (v * 4) - 1;
  o->f34 = (im->size * 4) - 1;
  fin:
  {
    u16 t1;
    u16 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u32 t7;
    o->f42 = 0x400;
    t1 = im->w;
    o->f46 = 0;
    o->f4A = 0x400;
    o->f44 = t1 << 5;
    t2 = im->size;
    o->f4E = 0;
    o->f56 = 0;
    o->f57 = 0;
    o->f4C = t2 << 5;
    o->f28 = (m & 1) ? (0x1033) : (0xFC1034);
    t3 = *im->ptr;
    o->f36 = 0;
    o->f2C = t3;
    t4 = *im->ptr;
    o->f3C = -1;
    o->f38 = t4;
    o->f10 = 0x30;
    t5 = im->tab[idx];
    o->f18 = 0x100;
    o->f14 = t5;
    m = (t2 = -1);
    t6 = im->type;
    o->f1C = 0;
    o->f1E = 0;
    o->f1A = t6 - 1;
    t7 = im->tab[idx];
    o->f24 = m;
    o->f20 = t7;
  }

  if (flags & 0x20)
  {
    func_8000B910(o, (s16) a4, (s16) a5);
  }
  osWritebackDCache(o, 0x60);
}

