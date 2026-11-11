static inline char *rowAt(char *p)
{
  return p;
}

/* Builds a 4x4 float transform from a pose record. The 3x3 s16 rotation (1/4096 fixed point) is
 * transposed into the matrix's upper-left block, the s32 position at pose+0x14 goes into row 3
 * as floats, and the rest is set to the identity's zero and one entries. */
void buildPoseMatrix(void *mtx, void *pose)
{
  f32 scaled;
  s32 rowOff;
  s32 colOff;
  s32 dstCol;
  s32 rowPtr;
  s32 col;
  s32 row;
  row = 0;
  do
  {
    col = 0;
    rowOff = row & 0xFF;
    rowPtr = rowAt(((char *) mtx) + (rowOff * 0x10));
    colOff = rowOff * 2;
    do
    {
      dstCol = col & 0xFF;
      scaled = ((f32) (*((s16 *) (colOff + (u32)(((char *) pose) + (dstCol * 6)))))) * 0.000244140625f;
      ++col;
      *((f32 *) (rowPtr + (dstCol * 4))) = scaled;
    }
    while (((u32) (col & 0xFF)) < 3U);
    row += 1;
  }
  while (((u32) (row & 0xFF)) < 3U);
  *((f32 *) (((char *) mtx) + 0x30)) = (f32) (*((s32 *) (((char *) pose) + 0x14)));
  *((f32 *) (((char *) mtx) + 0x34)) = (f32) (*((s32 *) (((char *) pose) + 0x18)));
  *((f32 *) (((char *) mtx) + 0x38)) = (f32) (*((s32 *) (((char *) pose) + 0x1C)));
  *((s32 *) (((char *) mtx) + 0xC)) = 0;
  *((s32 *) (((char *) mtx) + 0x1C)) = 0;
  *((s32 *) (((char *) mtx) + 0x2C)) = 0;
  *((f32 *) (((char *) mtx) + 0x3C)) = 1.0f;
}
