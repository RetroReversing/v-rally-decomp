typedef struct 
{
  u8 pad[0x14];
  s32 *p;
} GfxState;
typedef struct 
{
  u8 pad0[6];
  u16 w;
  u16 h;
  u8 padA[10];
  s32 *tbl;
} Tex;
s32 osVirtualToPhysical(s32);
s32 func_80007CA0(GfxState *g, Tex *t, s32 idx)
{
  GfxState *new_var;
  GfxState *s1;
  s32 *q;
  s32 x;
  s32 y;
  s32 z;
  u16 w;
  u16 h;
  new_var = g;
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xD7000002;
    p[1] = 0x80008000;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xE3001201;
    p[1] = 0x2000;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xE3000C00;
    p[1] = 0x80000;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xFC119623;
    p[1] = 0xFF2FFFFF;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xFD700000;
    q = p;
    q[1] = osVirtualToPhysical(*((s32 *) (((u32) ((255 & idx) * 4)) + ((u32) t->tbl))));
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xF5700000;
    p[1] = 0x7000000;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xE6000000;
    p[1] = 0;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xF3000000;
    w = t->w;
    y = w >> 4;
    x = 0x800;
    if (y)
    {
      x = y + 0x7ff;
    }
    h = t->h;
    z = (((w * h) + 3) >> 2) - 1;
    if (z >= 0x800)
    {
      z = 0x7ff;
    }
    p[1] = (((z & 0xfff) << 12) | 0x7000000) | (((y) ? (x / y) : (x)) & 0xfff);
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xE7000000;
    p[1] = 0;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    w = t->w;
    p[0] = 0xF5600000 | (((((w >> 1) + 7) >> 3) & 0x1ff) << 9);
    p[1] = 0;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xF2000000;
    w = t->w;
    h = t->h;
    p[1] = ((((w - 1) * 4) & 0xfff) << 12) | (((h - 1) * 4) & 0xfff);
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xE3001001;
    p[1] = 0xc000;
    return 0;
  }
}
