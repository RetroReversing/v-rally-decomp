typedef struct { u32 w0; u32 w1; } DLGfx;
typedef struct {
    u32 texEnable : 1;
    u32 pad0 : 7;
    u32 textureMode : 2;
    u32 texEnableSent : 1;
    u32 pad1 : 7;
    u32 textureModeSent : 2;
    u32 pad2 : 12;
} RenderFlags;
typedef struct { u8 pad[0x14]; DLGfx *dl; u8 pad2[0x64]; s32 a7c; s32 a80; RenderFlags flags; } RenderState;
#define GFX_CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }

/* Appends to the display list only the render-state commands whose setting changed since
 * they were last sent (all of them when force is 1): the texture enable and the texture mode. */
s32 gfx_sync_render_state(RenderState *state, u8 force)
{
  if (force == 1)
  {
    state->a7c = 0;
    state->a80 = 0;
  }
  if ((state->flags.texEnableSent != state->flags.texEnable) | (force == 1))
  {
    state->flags.texEnableSent = state->flags.texEnable;
    if (state->flags.texEnable)
      GFX_CMD(state, 0xD7000002, 0x80008000)
    else
      GFX_CMD(state, 0xD7000000, 0x80008000)
  }
  if ((state->flags.textureModeSent != state->flags.textureMode) | (force == 1))
  {
    state->flags.textureModeSent = state->flags.textureMode;
    switch (state->flags.textureMode)
    {
      case 0:
        GFX_CMD(state, 0xE3001001, 0)
        break;
      case 1:
        GFX_CMD(state, 0xE3001001, 0x8000)
        break;
      case 2:
        GFX_CMD(state, 0xE3001001, 0xC000)
        break;
    }
  }
  return 1;
}
