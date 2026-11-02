typedef struct {
  u32 w0;
  u32 w1;
} DLGfx;
typedef struct {
  u32 a:1;
  u32 b:4;
  u32 c:1;
  u32 e:2;
  u32 d:2;
  u32 ca:1;
  u32 cb:4;
  u32 cc:1;
  u32 ce:2;
  u32 cd:2;
  u32 pad:12;
} RFlags;
typedef struct {
  u8 pad0[0x14];
  DLGfx *dl;
  u8 pad18[0x7C - 0x18];
  s32 x7C;
  s32 x80;
  RFlags f;
} RState;
#define CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }
s32 func_80009964(RState *arg0, u8 force)
{
  if (force == 1)
  {
    arg0->x7C = 0;
    arg0->x80 = 0;
  }
  if ((arg0->f.ca != arg0->f.a) | (force == 1))
  {
    arg0->f.ca = arg0->f.a;
    if (arg0->f.a)
      CMD(arg0, 0xD7000002, 0x80008000)
    else
      CMD(arg0, 0xD7000000, 0x80008000)
  }
  if ((arg0->f.cb != arg0->f.b) | (force == 1))
  {
    arg0->f.cb = arg0->f.b;
    if (!arg0->f.b)
      CMD(arg0, 0xE3001201, 0)
    else
      CMD(arg0, 0xE3001201, 0x2000)
  }
  if ((arg0->f.cc != arg0->f.c) | (force == 1))
  {
    arg0->f.cc = arg0->f.c;
    if (arg0->f.c)
      CMD(arg0, 0xE3000C00, 0x80000)
    else
      CMD(arg0, 0xE3000C00, 0)
  }
  if ((arg0->f.cd != arg0->f.d) | (force == 1))
  {
    arg0->f.cd = arg0->f.d;
    switch (arg0->f.d)
    {
      case 0:
        CMD(arg0, 0xE3001001, 0)
        break;
      case 1:
        CMD(arg0, 0xE3001001, 0x8000)
        break;
      case 2:
        CMD(arg0, 0xE3001001, 0xC000)
        break;
    }
  }
  if ((arg0->f.ce != arg0->f.e) | (force == 1))
  {
    arg0->f.ce = arg0->f.e;
    if (!arg0->f.e)
      CMD(arg0, 0xD9DFFFFF, 0)
    else
      CMD(arg0, 0xD9FFFFFF, 0x200000)
  }
  return 1;
}
