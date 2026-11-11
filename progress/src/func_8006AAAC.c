s32 func_80005C48(s32);
extern s32 gSceneSlot0;

/* Copies a rectangle of 16-bit pixels from a 320-pixel-wide source image into the scene's 320-pixel-wide
 * buffer (func_80005C48 of gSceneSlot0), at the same position. rect is {x, y, width, height}. */
void func_8006AAAC(u16 *src, s16 *rect)
{
  s16 buf[8];
  s32 dstRow;
  s32 dstBase;
  s32 col;
  s32 row;
  s32 dstCol;
  u16 val;
  s32 off;
  dstBase = func_80005C48(gSceneSlot0);
  row = 0;
  if (rect[3] > 0)
  {
    dstRow = 0;
    do
    {
      col = 0;
      if (rect[2] > 0)
      {
        dstCol = dstRow;
        do
        {
          off = (((rect[1] + row) * 0x140) + rect[0] + col) * 2;
          val = *(u16 *)(off + (u8 *)src);
          *((u16 *) (dstBase + ((dstCol + col) * 2))) = *(u16 *)(off + (u8 *)src);
          col += 1;
        }
        while (col < rect[2]);
      }
      row += 1;
      dstRow += 0x140;
    }
    while (row < rect[3]);
  }
}
