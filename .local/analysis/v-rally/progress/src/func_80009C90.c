typedef struct { u32 w0; u32 w1; } DLGfx;
typedef struct {
    u32 b31 : 1;
    u32 pad0 : 7;
    u32 b22 : 2;
    u32 b21 : 1;
    u32 pad1 : 7;
    u32 b12 : 2;
    u32 pad2 : 12;
} S9C90Flags;
typedef struct { u8 pad[0x14]; DLGfx *dl; u8 pad2[0x64]; s32 a7c; s32 a80; S9C90Flags flags; } S9C90;
#define CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }

s32 func_80009C90(S9C90 *o, u8 force)
{
  if (force == 1)
  {
    o->a7c = 0;
    o->a80 = 0;
  }
  if ((o->flags.b21 != o->flags.b31) | (force == 1))
  {
    o->flags.b21 = o->flags.b31;
    if (o->flags.b31)
      CMD(o, 0xD7000002, 0x80008000)
    else
      CMD(o, 0xD7000000, 0x80008000)
  }
  if ((o->flags.b12 != o->flags.b22) | (force == 1))
  {
    o->flags.b12 = o->flags.b22;
    switch (o->flags.b22)
    {
      case 0:
        CMD(o, 0xE3001001, 0)
        break;
      case 1:
        CMD(o, 0xE3001001, 0x8000)
        break;
      case 2:
        CMD(o, 0xE3001001, 0xC000)
        break;
    }
  }
  return 1;
}
