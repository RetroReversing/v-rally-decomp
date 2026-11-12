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

/* Appends one 64-bit display-list command (two words) to the state. */
#define GFX_EMIT(g, w0v, w1v) { s32 *p = (g)->p; (g)->p = p + 2; p[0] = (w0v); p[1] = (w1v); }

/* Emits the RDP commands that load texture idx of tex (from its address table)
 * into TMEM and set its tile size, mask and clamp state. Returns 0. */
s32 gfxLoadTexture(GfxState *g, Tex *t, s32 idx)
{
  GfxState *new_var;
  GfxState *s1;
  s32 *q;
  s32 num;
  s32 den;
  s32 lines;
  u16 width;
  u16 height;
  new_var = g;
  GFX_EMIT(new_var, 0xD7000002, 0x80008000);
  GFX_EMIT(new_var, 0xE3001201, 0x2000);
  GFX_EMIT(new_var, 0xE3000C00, 0x80000);
  GFX_EMIT(new_var, 0xFC119623, 0xFF2FFFFF);
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xFD700000;
    q = p;
#ifdef PORT
    q[1] = osVirtualToPhysical(*((s32 *) ((u8 *) t->tbl + (255 & idx) * 4)));
#else
    q[1] = osVirtualToPhysical(*((s32 *) (((u32) ((255 & idx) * 4)) + ((u32) t->tbl))));
#endif
  }
  GFX_EMIT(new_var, 0xF5700000, 0x7000000);
  GFX_EMIT(new_var, 0xE6000000, 0);
  {
    s32 *v = *(s32 *volatile *)&new_var->p;
    s32 *p;
    new_var->p = v + 2;
    p = v;
    v = 0;
    p[0] = 0xF3000000;
    width = t->w;
    den = width >> 4;
    num = 0x800;
    if (den)
    {
      num = den + 0x7ff;
    }
    height = t->h;
    lines = (((width * height) + 3) >> 2) - 1;
    if (lines >= 0x800)
    {
      lines = 0x7ff;
    }
    p[1] = (((lines & 0xfff) << 12) | 0x7000000) | (((den) ? (num / den) : (num)) & 0xfff);
  }
  GFX_EMIT(new_var, 0xE7000000, 0);
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    width = t->w;
    p[0] = 0xF5600000 | (((((width >> 1) + 7) >> 3) & 0x1ff) << 9);
    p[1] = 0;
  }
  {
    s32 *p = new_var->p;
    new_var->p = p + 2;
    p[0] = 0xF2000000;
    width = t->w;
    height = t->h;
    p[1] = ((((width - 1) * 4) & 0xfff) << 12) | (((height - 1) * 4) & 0xfff);
  }
  GFX_EMIT(new_var, 0xE3001001, 0xc000);
  return 0;
}
