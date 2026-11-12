typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u32 dirty : 1; u32 pad : 5; u32 tt : 2; u32 rest : 24; } RSFlags;
typedef struct
{
  char pad[0x14];
  Gfx *dl;
  char pad18[0x64];
  void *image;
  void *palette;
  RSFlags flags;
  u16 height;
  u16 width;
} RenderState;
typedef struct
{
  u32 unused;
  u16 format;
  u16 width;
  u16 height;
  char pad[6];
  void **palettes;
  void **images;
} Texture;
u32 osVirtualToPhysical(void *);
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define gDPSetTextureImage(pkt, f, s, w, i) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = _SHIFTL(0xFD, 24, 8) | _SHIFTL(f, 21, 3) | _SHIFTL(s, 19, 2) | _SHIFTL((w) - 1, 0, 12); \
  _g->w1 = (u32)(i); }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9); \
  _g->w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4); }
#define gDPNoParam(pkt, cmd) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPLoadSync(pkt) gDPNoParam(pkt, 0xE6)
#define gDPPipeSync(pkt) gDPNoParam(pkt, 0xE7)
#define gDPTileSync(pkt) gDPNoParam(pkt, 0xE8)
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = (_SHIFTL(0xF3, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); \
  _g->w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs, 2047)), 12, 12) | _SHIFTL(dxt, 0, 12)); }
#define gDPSetTileSize(pkt, t, uls, ult, lrs, lrt) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = _SHIFTL(0xF2, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
  _g->w1 = _SHIFTL(t, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12); }
#define gDPLoadTLUTCmd(pkt, tile, count) { Gfx *_g = (Gfx *)(pkt); \
  _g->w0 = _SHIFTL(0xF0, 24, 8); _g->w1 = _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10); }
#define TXL2WORDS(txls, b) MAX(1, ((txls) * (b) / 8))
#define CALC_DXT(width, b) (((1 << 11) + TXL2WORDS(width, b) - 1) / TXL2WORDS(width, b))
#define TXL2WORDS_4b(txls) MAX(1, ((txls) / 16))
#define CALC_DXT_4b(width) (((1 << 11) + TXL2WORDS_4b(width) - 1) / TXL2WORDS_4b(width))
#define gDPLoadTextureBlock_4b(pkt, timg, fmt, width, height) { \
  gDPSetTextureImage(pkt, fmt, 2, 1, timg); \
  gDPSetTile(pkt, fmt, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0); \
  gDPLoadSync(pkt); \
  gDPLoadBlock(pkt, 7, 0, 0, (((width) * (height) + 3) >> 2) - 1, CALC_DXT_4b(width)); \
  gDPPipeSync(pkt); \
  gDPSetTile(pkt, fmt, 0, ((((width) >> 1) + 7) >> 3), 0, 0, 0, 0, 0, 0, 0, 0, 0); \
  gDPSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); }
#define gDPLoadTextureBlock(pkt, timg, fmt, siz, lsiz, incr, shift, bytes, lbytes, width, height) { \
  gDPSetTextureImage(pkt, fmt, lsiz, 1, timg); \
  gDPSetTile(pkt, fmt, lsiz, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0); \
  gDPLoadSync(pkt); \
  gDPLoadBlock(pkt, 7, 0, 0, (((width) * (height) + incr) >> shift) - 1, CALC_DXT(width, bytes)); \
  gDPPipeSync(pkt); \
  gDPSetTile(pkt, fmt, siz, ((((width) * lbytes) + 7) >> 3), 0, 0, 0, 0, 0, 0, 0, 0, 0); \
  gDPSetTileSize(pkt, 0, 0, 0, ((width) - 1) << 2, ((height) - 1) << 2); }
#define gDPLoadTLUT(pkt, dram, tmem, count) { \
  gDPSetTextureImage(pkt, 0, 2, 1, dram); \
  gDPTileSync(pkt); \
  gDPSetTile(pkt, 0, 0, 0, tmem, 7, 0, 0, 0, 0, 0, 0, 0); \
  gDPLoadSync(pkt); \
  gDPLoadTLUTCmd(pkt, 7, count); \
  gDPPipeSync(pkt); }
/* Points the render state's display list at the texture's image and palette, emitting texture-load commands only when they changed since the last call. */ s32 gfx_set_texture(RenderState *state, Texture *tex, u8 pal_index)
{
  RenderState *arg0 = state;
  u32 f;
  f = *(u32 *)&arg0->flags;
  f &= 0x7FFFFFFF;
  f |= 0x80000000;
  *(u32 *)&arg0->flags = f;
  switch (tex->format)
  {
    case 0x10:
      arg0->flags.tt = 1;
      if (arg0->image != tex->images[0])
      {
        arg0->image = tex->images[0];
        arg0->height = tex->height;
        arg0->width = tex->width;
        gDPLoadTextureBlock_4b(arg0->dl++, osVirtualToPhysical(tex->images[0]), 2, tex->width, tex->height);
      }
      if (arg0->palette != tex->palettes[pal_index])
      {
        arg0->palette = tex->palettes[pal_index];
        gDPLoadTLUT(arg0->dl++, osVirtualToPhysical(tex->palettes[pal_index]), 256, 15);
      }
      break;
    case 0x100:
      arg0->flags.tt = 1;
      if (arg0->image != tex->images[0])
      {
        arg0->image = tex->images[0];
        arg0->height = tex->height;
        arg0->width = tex->width;
        gDPLoadTextureBlock(arg0->dl++, osVirtualToPhysical(tex->images[0]), 2, 1, 2, 1, 1, 1, 1, tex->width, tex->height);
      }
      if (arg0->palette != tex->palettes[pal_index])
      {
        arg0->palette = tex->palettes[pal_index];
        gDPLoadTLUT(arg0->dl++, osVirtualToPhysical(tex->palettes[pal_index]), 256, 255);
      }
      break;
    case 0xA0:
      if (arg0->image != tex->images[0])
      {
        arg0->flags.tt = 0;
        arg0->height = tex->height;
        arg0->width = tex->width;
        gDPLoadTextureBlock(arg0->dl++, osVirtualToPhysical(tex->images[0]), 0, 3, 3, 0, 0, 4, 2, tex->width, tex->height);
        arg0->palette = 0;
      }
      break;
  }
  return 0;
}
