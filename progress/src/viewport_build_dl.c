typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad00[0x10]; s16 zeroA; u16 curA; s16 posX; u16 prevA; s16 zeroB; u16 curB; s16 posY; u16 prevB; } Frame;
typedef struct { s16 x; s16 y; s16 w; s16 h; u8 pad[0x24]; Frame *frame; } Viewport;
s32 view_get_ctx_id();
s32 func_80005C48(s32);
Gfx *gfx_get_dl(s32);
void gfx_set_dl(s32, Gfx *);
u32 osVirtualToPhysical(s32);
extern s16 *gSceneSlot0;
extern s32 gSceneSlot1;
extern s32 D_8009B5D0;
#define GFX_PUT(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
#define GFX_FIELD(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define GFX_SCISSOR(pkt, ulx, uly, lrx, lry) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = GFX_FIELD(0xED, 24, 8) | GFX_FIELD((int)((float)(ulx) * 4.0F), 12, 12) | GFX_FIELD((int)((float)(uly) * 4.0F), 0, 12); \
  _g->w1 = GFX_FIELD(0, 24, 2) | GFX_FIELD((int)((float)(lrx) * 4.0F), 12, 12) | GFX_FIELD((int)((float)(lry) * 4.0F), 0, 12); }

/* Builds the RDP display list for one viewport: sets the framebuffer, the
 * scissor and the tile state, then submits it with gfx_set_dl. When expand
 * is set the scissor is widened by 8 and the frame position is not reset. */
void viewport_build_dl(Viewport *vp, s32 posX, s32 posY, u8 expand)
{
  Frame *q;
  s32 dlIndex;
  s32 fbVirt;
  Gfx *dl;
  q = vp->frame;
  dlIndex = view_get_ctx_id();
  dl = gfx_get_dl(dlIndex);
  fbVirt = func_80005C48(gSceneSlot1);
  GFX_PUT(dl++, 0xDE000000, (u32)&D_8009B5D0);
  GFX_PUT(dl++, 0xFF100000 | ((gSceneSlot0[2] - 1) & 0xFFF), osVirtualToPhysical(fbVirt));
  if (!expand)
  {
    vp->frame->zeroA = 0;
    vp->frame->zeroB = 0;
    vp->frame->posX = posX * 4;
    vp->frame->posY = posY * 4;
    vp->frame->prevA = vp->frame->curA;
    vp->frame->prevB = vp->frame->curB;
    GFX_SCISSOR(dl++, vp->x, vp->y, vp->w, vp->h);
  }
  else
  {
    vp->frame->zeroA = 0;
    vp->frame->zeroB = 0;
    GFX_SCISSOR(dl++, vp->x, vp->y, vp->w + 8, vp->h);
  }
  GFX_PUT(dl++, 0xE200001C, 0);
  GFX_PUT(dl++, 0xE3000A01, 0x200000);
  GFX_PUT(dl++, 0xE3001001, 0x8000);
  GFX_PUT(dl++, 0x05000017, (u32)q + 0x38);
  GFX_PUT(dl++, 0xE7000000, 0);
  GFX_PUT(dl++, 0x0A000000, (u32)q + 0x10);
  GFX_PUT(dl++, 0xE7000000, 0);
  GFX_PUT(dl++, 0xE3000A01, 0);
  gfx_set_dl(dlIndex, dl);
}
