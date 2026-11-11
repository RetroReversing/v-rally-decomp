void *guMtxCatF(f32 *, f32 *, f32 *);
void guRotateF(f32 *, s32, f32, f32, f32);

/* Builds a rotation from three Euler angles in `angles` (applied about X, Y, then Z) by
 * multiplying the three rotation matrices, and copies the result's translation row
 * (elements 12..14, one per row of `out`) into `out`. */
void func_8001C1A8(s32 *angles, f32 *out)
{
  f32 rotX[16];
  f32 rotY[16];
  f32 rotZ[16];
  f32 combined[16];
  f32 *src;
  f32 *srcPtr;
  f32 *dst;
  f32 *dstRow;
  s32 i;
  s32 j;
  guRotateF(rotX, angles[0], 1.0f, 0.0f, 0.0f);
  guRotateF(rotY, angles[1], 0.0f, 1.0f, 0.0f);
  guRotateF(rotZ, angles[2], 0.0f, 0.0f, 1.0f);
  guMtxCatF(rotZ, rotX, combined);
  guMtxCatF(combined, rotY, combined);
  dstRow = out;
  i = 0;
  src = rotX;
  do
  {
    j = 0;
 do { } while (0);
    dst = dstRow;
    srcPtr = src + 48;
    do
    {
      *dst = *srcPtr;
      srcPtr++;
      j++;
      dst++;
    }
    while (j < 3);
    src += 4;
    i++;
    dstRow += 4;
  }
  while (i < 3);
}
