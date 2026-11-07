typedef struct { u32 w0; u32 w1; } DLGfx;
typedef struct { u8 pad[0x14]; DLGfx *dl; u8 pad18[0x78 - 0x18]; u16 flags; } RS60C0;
#define CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }

void func_800060C0(RS60C0 *s)
{
  RS60C0 *arg0 = s;
  if (!(arg0->flags & 1))
  {
    CMD(arg0, 0xD9C0F9FA, 0)
    CMD(arg0, 0xD9FFFFFF, 5)
    CMD(arg0, 0xD7000000, 0)
    CMD(arg0, 0xFCFFFFFF, 0xFFFE793C)
  }
  else
  {
    CMD(arg0, 0xE7000000, 0)
    CMD(arg0, 0xE3000A01, 0)
    CMD(arg0, 0xD7000000, 0)
    CMD(arg0, 0xFCFFFFFF, 0xFFFE793C)
    CMD(arg0, 0xD9E0F9FA, 0)
    CMD(arg0, 0xD9FFFFFF, 0x200005)
  }
}
