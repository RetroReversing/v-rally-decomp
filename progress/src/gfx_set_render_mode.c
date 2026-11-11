typedef struct { u32 w0; u32 w1; } DLGfx;
typedef struct { u8 pad[0x14]; DLGfx *dl; u8 pad18[0x78 - 0x18]; u16 flags; } GfxState;

#define GFX_CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }

/* Appends the RDP/RSP state-setup commands for the current render mode to the
 * display list. flags bit 0 selects the alternate (second) mode. */
void gfx_set_render_mode(GfxState *state)
{
  GfxState *s = state;
  if (!(s->flags & 1))
  {
    GFX_CMD(s, 0xD9C0F9FA, 0)
    GFX_CMD(s, 0xD9FFFFFF, 5)
    GFX_CMD(s, 0xD7000000, 0)
    GFX_CMD(s, 0xFCFFFFFF, 0xFFFE793C)
  }
  else
  {
    GFX_CMD(s, 0xE7000000, 0)
    GFX_CMD(s, 0xE3000A01, 0)
    GFX_CMD(s, 0xD7000000, 0)
    GFX_CMD(s, 0xFCFFFFFF, 0xFFFE793C)
    GFX_CMD(s, 0xD9E0F9FA, 0)
    GFX_CMD(s, 0xD9FFFFFF, 0x200005)
  }
}
