s32 view_get_ctx_id();
void *gfx_get_dl();
s32 gfx_set_dl();

/* Clears a rect of the z-buffer: points the colour image at zbuf, fills rect with 0xFFFCFFFC
 * (maximum depth) using a fill rectangle, then restores the pipeline state. Appends the
 * display-list words to the current view's list and stores the new list end. */
void gfx_clear_zbuffer_rect(s32 unused, s32 zbuf, void *rect)
{
  s32 physAddr;
  s32 ctx;
  s32 zImgHi;
  s32 fillRectHi;
  u8 *dl;
  s32 *pipeSyncA;
  s32 *zImg;
  s32 *fillRect;
  int width;
  s32 *cimg;
  s32 *fillColor;
  s32 *pipeSyncB;
  s32 *setOtherMode;
  s32 *pipeSyncC;
  s32 *cimgPtr;
  s32 *fillRectPtr;
  s32 fillRectLo;

  ctx = view_get_ctx_id();
  dl = gfx_get_dl(ctx);
  pipeSyncA = (s32 *) dl;
  dl += 8;
  pipeSyncA[0] = 0xE7000000;
  pipeSyncA[1] = 0;
  setOtherMode = (s32 *) dl;
  dl += 8;
  setOtherMode[1] = 0x300000;
  setOtherMode[0] = 0xE3000A01;
  zImg = (s32 *) dl;
  dl += 8;
  zImg[0] = 0xFE000000;
  physAddr = zbuf - 0x80000000;
  zImg[1] = physAddr;
  cimg = (s32 *) dl;
  width = *((s16 *) (((u8 *) rect) + 4));
  dl += 8;
  fillColor = (s32 *) dl;
  dl += 8;
  fillRect = (s32 *) dl;
  dl += 8;
  cimg[1] = physAddr;
  cimg[0] = ((width - 1) & 0xFFF) | 0xFF100000;
  fillColor[0] = 0xF7000000;
  fillColor[1] = 0xFFFCFFFC;
  zImgHi = (((*((s16 *) (((u8 *) rect) + 4))) - 1) & 0x3FF) << 14;
  fillRectHi = ((((*((s16 *) (((u8 *) rect) + 6))) - 1) & 0x3FF) << 2) | 0xF6000000;
  fillRect[0] = zImgHi | fillRectHi;
  fillRect[1] = (((*((u16 *) (((u8 *) rect) + 0))) & 0x3FF) << 14) | (((*((u16 *) (((u8 *) rect) + 2))) & 0x3FF) << 2);
  pipeSyncC = (s32 *) dl;
  dl += 8;
  pipeSyncC[0] = 0xE7000000;
  pipeSyncC[1] = 0;
  gfx_set_dl(ctx, dl, fillRect, cimg);
}
