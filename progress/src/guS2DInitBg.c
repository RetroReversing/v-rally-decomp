typedef struct uObjBgAttr {
    s16 imageX;
    u16 imageW;
    s16 frameX;
    u16 frameW;
    u8 pad08[12];
    u16 imageLoad;
    u8 imageFmt;
    u8 imageSiz;
    u8 pad18[4];
    u16 tmemW;
    u16 tmemH;
    u16 tmemLoadSH;
    u16 tmemLoadTH;
    u16 tmemSizeW;
    u16 tmemSize;
} uObjBgAttr;

typedef struct uObjBg {
    uObjBgAttr b;
} uObjBg;

/* Fills in the TMEM tiling fields of a background object from its image and frame sizes.
 * Block-loaded images (imageLoad 0x33) take the texel-per-row count from imageW; other
 * images are tiled from frameW with three extra texels. */
void guS2DInitBg(uObjBg *bg)
{
  u16 tmem_bytes;
  u16 shift;
  u32 tmem_size;

  tmem_bytes = (bg->b.imageFmt == 2) ? 256 : 512;
  shift = 6 - bg->b.imageSiz;

  if (bg->b.imageLoad == 0x0033) {
    bg->b.tmemW = bg->b.imageW >> shift;
    bg->b.tmemH = (tmem_bytes / bg->b.tmemW) << 2;
    bg->b.tmemSizeW = bg->b.tmemW << 1;
    bg->b.tmemSize = bg->b.tmemH * bg->b.tmemSizeW;
    bg->b.tmemLoadSH = (bg->b.tmemSize >> 1) - 1;
    bg->b.tmemLoadTH = (((1 << 11) - 1) / (bg->b.tmemW) + 1);
  } else {
    bg->b.tmemW = (bg->b.frameW >> shift) + 3;
    bg->b.tmemH = (tmem_bytes / bg->b.tmemW) << 2;
    bg->b.tmemSizeW = (bg->b.imageW >> shift) * 2;
    tmem_size = bg->b.tmemH * bg->b.tmemSizeW;
    bg->b.tmemSize = tmem_size >> 16;
    bg->b.tmemLoadSH = tmem_size & 0xffff;
    bg->b.tmemLoadTH = bg->b.tmemH - 1;
  }
}
