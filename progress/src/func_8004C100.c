void drawEdgeSegment(s32, s32, s32, s32, s32, s32);

/* Draws three edge segments of a box at layer `layer`: x is the left edge of the first
 * segment, `left` and `right` are the box sides, `bottom` is the lowest edge, and `mid`
 * is bottom - 16. Every segment uses colour 0xCC. */
void func_8004C100(s32 layer, s32 x, s32 left, s32 bottom, u16 right)
{
  s32 var_s5 = layer;
  s32 var_s4 = bottom;
  u16 mid = var_s4 - 0x10;
  s32 var_s0 = left & 0xFFFF;
  u16 var_s2 = right;
  u16 new_var;
  s32 var_s3 = 0xCC;
  mid &= 0xFFFF;
  drawEdgeSegment(var_s5, x & 0xFFFF, var_s0, mid, var_s0, var_s3);
  var_s2 &= 0xFFFF;
  drawEdgeSegment(var_s5, mid, var_s0, mid, var_s2, var_s3);
  new_var = var_s2;
  var_s2 = var_s4;
  drawEdgeSegment(var_s5, mid, new_var, var_s2 & 0xFFFF, new_var, var_s3);
}
