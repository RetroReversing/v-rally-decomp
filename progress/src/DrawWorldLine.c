extern f64 D_800A4150;
extern f64 D_800A4158;
extern u8 *g_camera;
void func_8001BE68(u8 *, f32, f32, f32, f32 *, f32 *, f32 *);
void draw_screen_line(s32, s32, s32, s32, s32);

/* Projects two s16 world points through the camera (view space, depth in sp28/sp34).
 * If both are in front of the camera within the depth range, maps them to the
 * 320x240 screen (centre 160,120) and draws a line between them. */
void DrawWorldLine(s16 *from, s16 *to, s32 colour)
{
  f32 sp20;
  f32 new_var;
  f32 sp24;
  f32 sp28;
  f32 sp2C;
  f32 sp30;
  f32 sp34;
  f32 fs0;
  f32 fs1;
  f32 fs2;
  f32 fa0;
  f32 fa1;
  f32 fa2;
  fa0 = (f32) from[0];
  fa1 = (f32) from[1];
  fa2 = (f32) from[2];
  fs0 = (f32) to[0];
  fs1 = (f32) to[1];
  fs2 = (f32) to[2];
  func_8001BE68(g_camera + 0xB8, fa0, fa1, fa2, &sp20, &sp24, &sp28);
  func_8001BE68(g_camera + 0xB8, fs0, fs1, fs2, &sp2C, &sp30, &sp34);
  if ((((f64) sp28) < D_800A4150) && (D_800A4158 < ((f64) sp28)))
  {
    if ((((f64) sp34) < D_800A4150) && (D_800A4158 < ((f64) sp34)))
    {
      f32 x0, y0, x1, y1;
      x0 = sp20 * 160.0f + 160.0f;
      y0 = -sp24 * 120.0f + 120.0f;
      x1 = sp2C * 160.0f + 160.0f;
      y1 = -sp30 * 120.0f + 120.0f;
      draw_screen_line((s32) x0, (s32) y0, (s32) x1, (s32) y1, colour);
    }
  }
}
