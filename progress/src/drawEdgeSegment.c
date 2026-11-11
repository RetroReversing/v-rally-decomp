typedef struct 
{
  s32 pad10[4];
  s32 vx0;
  s32 vx1;
  s32 vx2;
  s32 vx3;
  s32 vy0;
  s32 vy1;
  s32 vy2;
  s32 vy3;
  s32 col0;
  s32 col1;
  s32 col2;
  s32 col3;
  u8 rgb[12];
  u8 alpha[4];
  s32 pad60[2];
} EdgeQuad;
void func_8004C370(s32, EdgeQuad *, s32, s32);

/* Builds a 4-vertex quad that covers the edge from (x0, y0) to (x1, y1),
 * with each far corner one pixel larger, all vertices white with the given
 * alpha, and sends it to the display list through func_8004C370. */
void drawEdgeSegment(s32 unused, s32 x0, s32 y0, s32 x1, u16 y1, u8 alpha)
{
  EdgeQuad quad;
  u16 sx0 = x0;
  u16 sy0 = y0;
  u16 sx1 = x1;
  u16 sy1 = y1;
  quad.vx0 = sx0;
  quad.col0 = 0;
  quad.vy0 = sy0;
  quad.vx1 = sx1;
  quad.col1 = 0;
  quad.vx2 = sx1 + 1;
  quad.vx3 = sx0 + 1;
  quad.col2 = 0;
  quad.vy3 = sy0 + 1;
  quad.col3 = 0;
  quad.rgb[0] = 0xFF;
  quad.rgb[4] = 0xFF;
  quad.rgb[8] = 0xFF;
  quad.rgb[1] = 0xFF;
  quad.rgb[5] = 0xFF;
  quad.rgb[9] = 0xFF;
  quad.rgb[2] = 0xFF;
  quad.rgb[6] = 0xFF;
  quad.rgb[10] = 0xFF;
  quad.rgb[3] = 0xFF;
  quad.rgb[7] = 0xFF;
  quad.rgb[11] = 0xFF;
  quad.vy1 = sy1;
  quad.vy2 = sy1 + 1;
  quad.alpha[0] = alpha;
  quad.alpha[1] = alpha;
  quad.alpha[2] = alpha;
  quad.alpha[3] = alpha;
  func_8004C370(unused, &quad, sy0 + 1, sx1 + 1);
}
