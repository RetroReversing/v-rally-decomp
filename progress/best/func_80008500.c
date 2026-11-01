typedef struct { u32 w0; u32 w1; } Gfx;
Gfx *func_80008500(Gfx *g, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15)
{
  Gfx *g0 = g++;
  Gfx *g1 = g++;
  Gfx *g2 = g++;
  Gfx *g3 = g++;
  Gfx *g4;
  Gfx *g5;
  Gfx *g6;
  s32 a, b, c;
  g0->w0 = ((arg2 & 7) << 21) | 0xFD100000;
  g0->w1 = arg1 + (arg6 * arg3) / 2;
  g1->w0 = ((arg2 & 7) << 21) | 0xF5100000;
  g1->w1 = 0x07000000 | ((arg11 & 3) << 18) | ((arg13 & 0xF) << 14) | ((arg15 & 0xF) << 10) | ((arg10 & 3) << 8) | ((arg12 & 0xF) << 4) | (arg14 & 0xF);
  g2->w0 = 0xE6000000;
  g2->w1 = 0;
  g3->w0 = 0xF3000000;
  a = arg3 / 16;
  b = a > 0 ? a + 0x7FF : 0x800;
  c = ((arg3 * arg8 + 3) >> 2) - 1;
  if (c >= 0x800) c = 0x7FF;
  g3->w1 = ((c & 0xFFF) << 12) | 0x07000000 | ((a > 0 ? b / a : b) & 0xFFF);
  g4 = g++;
  g5 = g++;
  g6 = g++;
  g4->w0 = 0xE7000000;
  g4->w1 = 0;
  g5->w0 = ((arg2 & 7) << 21) | 0xF5000000 | ((((arg3 >> 1) + 7) >> 3 & 0x1FF) << 9);
  g5->w1 = ((arg9 & 0xF) << 20) | ((arg11 & 3) << 18) | ((arg13 & 0xF) << 14) | ((arg15 & 0xF) << 10) | ((arg10 & 3) << 8) | ((arg12 & 0xF) << 4) | (arg14 & 0xF);
  g6->w0 = 0xF2000000;
  g6->w1 = 0;
  g->w1 = ((((arg3 - 1) * 4) & 0xFFF) << 12) | (((arg8 - 1) * 4) & 0xFFF);
  return g + 1;
}
