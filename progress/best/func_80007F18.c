#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define TXL2WORDS_4b(txls) MAX(1, ((txls) / 16))
#define gDPSetTextureImage(pkt, f, s, w, i) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(0xFD, 24, 8) | _SHIFTL(f, 21, 3) | _SHIFTL(s, 19, 2) | _SHIFTL((w) - 1, 0, 12); _g->w1 = (u32)(i); }
#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt, shiftt, cms, masks, shifts) { Gfx *_g = (Gfx *)(pkt);   _g->w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9);   _g->w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4); }
#define gDPNoParam(pkt, cmd) { Gfx *_g = (Gfx *)(pkt); _g->w0 = _SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPLoadSync(pkt) gDPNoParam(pkt, 0xE6)
#define gDPPipeSync(pkt) gDPNoParam(pkt, 0xE7)
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) { Gfx *_g = (Gfx *)(pkt);   _g->w0 = _SHIFTL(0xF3, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);   _g->w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(MIN(lrs, 0x7FF), 12, 12) | _SHIFTL(dxt, 0, 12); }
#define gDPSetTileSize(pkt, t, uls, ult, lrs, lrt) { Gfx *_g = (Gfx *)(pkt);   _g->w0 = _SHIFTL(0xF2, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);   _g->w1 = _SHIFTL(t, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12); }
typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
Gfx *func_80007F18(Gfx *gfx, s32 timg, s32 fmt, s32 siz, s32 width, s32 a5, s32 a6, s32 row, s32 a8, s32 height, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt)
{
  switch (siz)
  {
    case 1:
      gDPSetTextureImage(gfx++, fmt, 2, 1, timg + (row * width));
      gDPSetTile(gfx++, fmt, 2, 0, 0, 7, 0, cmt, maskt, shiftt, cms, masks, shifts);
      gDPLoadSync(gfx++);
      gDPLoadBlock(gfx++, 7, 0, 0, (((width * height) + 1) >> 1) - 1, CALC_DXT(width, 1));
      gDPPipeSync(gfx++);
      gDPSetTile(gfx++, fmt, 1, ((width * 1) + 7) >> 3, 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts);
      gDPSetTileSize(gfx++, 0, 0, 0, (width - 1) << 2, (height - 1) << 2);
      break;

    case 2:
      gDPSetTextureImage(gfx++, fmt, 2, 1, timg + ((row * width) * 2));
      gDPSetTile(gfx++, fmt, 2, 0, 0, 7, 0, cmt, maskt, shiftt, cms, masks, shifts);
      gDPLoadSync(gfx++);
      gDPLoadBlock(gfx++, 7, 0, 0, (width * height) - 1, CALC_DXT(width, 2));
      gDPPipeSync(gfx++);
      gDPSetTile(gfx++, fmt, 2, ((width * 2) + 7) >> 3, 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts);
      gDPSetTileSize(gfx++, 0, 0, 0, (width - 1) << 2, (height - 1) << 2);
      break;

    case 3:
      gDPSetTextureImage(gfx++, fmt, 3, 1, timg + ((row * width) * 4));
      gDPSetTile(gfx++, fmt, 3, 0, 0, 7, 0, cmt, maskt, shiftt, cms, masks, shifts);
      gDPLoadSync(gfx++);
      gDPLoadBlock(gfx++, 7, 0, 0, (width * height) - 1, CALC_DXT(width, 4));
      gDPPipeSync(gfx++);
      gDPSetTile(gfx++, fmt, 3, ((width * 2) + 7) >> 3, 0, 0, pal, cmt, maskt, shiftt, cms, masks, shifts);
      gDPSetTileSize(gfx++, 0, 0, 0, (width - 1) << 2, (height - 1) << 2);
      break;

  }

  if (siz || shiftt)
  {
    return gfx;
  }
  else
  {
    return gfx;
  }
}

