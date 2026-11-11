s32 func_80084BF0(s32);
extern s32 gContCtx;
/* Reads the pressed-button mask for a player and ORs together the 32-bit field that
 * each pressed button maps to in that player's 56-byte state record. */
s32 getPressedButtonValue(s32 player)
{
  s32 index, pressed, value;
  value = 0;
  index = player & 255;
  pressed = func_80084BF0(index);
  if (pressed & 1)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value = *(s32 *)(rec + 172);
  }
  if (pressed & 2)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 176);
  }
  if (pressed & 4)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 180);
  }
  if (pressed & 8)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 184);
  }
  if (pressed & 16)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 188);
  }
  if (pressed & 32)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 192);
  }
  if (pressed & 256)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 196);
  }
  if (pressed & 512)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 200);
  }
  if (pressed & 1024)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 204);
  }
  if (pressed & 2048)
  {
    s32 rec = gContCtx;
    rec += index * 56;
    value |= *(s32 *)(rec + 208);
  }
  if (pressed & 4096)
  {
    s32 rec = gContCtx;
    rec += (player & 255) * 56;
    value |= *(s32 *)(rec + 212);
  }
  if (pressed & 8192)
  {
    s32 rec = gContCtx;
    rec += (player & 255) * 56;
    value |= *(s32 *)(rec + 216);
  }
  if (pressed & 16384)
  {
    s32 rec = gContCtx;
    rec += (player & 255) * 56;
    value |= *(s32 *)(rec + 220);
  }
  if (pressed & 32768)
  {
    s32 rec = gContCtx;
    rec += (player & 255) * 56;
    value |= *(s32 *)(rec + 224);
  }
  return value;
}
