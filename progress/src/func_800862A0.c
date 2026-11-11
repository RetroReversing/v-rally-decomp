extern s8 *gContCtx;

/* Resets the stick calibration of controller slot `slot` in gContCtx (entries are 0x14 bytes
 * apart, calibration at +0x5C..+0x65): the X and Y ranges are +/-0x3D and +/-0x3F, and the
 * dead zone is +/-7 around 0. */
void func_800862A0(s32 slot)
{
  s32 off;
  s8 *base;

  base = gContCtx;
  off = slot * 0x14;
  *(base + off + 0x5C) = 0x3D;
  *(gContCtx + off + 0x5E) = -7;
  *(gContCtx + off + 0x5F) = 0;
  *(gContCtx + off + 0x60) = 7;
  *(gContCtx + off + 0x5D) = -0x3D;
  *(gContCtx + off + 0x61) = 0x3F;
  *(gContCtx + off + 0x63) = -7;
  *(gContCtx + off + 0x64) = 0;
  *(gContCtx + off + 0x65) = 7;
  *(gContCtx + off + 0x62) = -0x3F;
}
