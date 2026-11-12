extern s32 gSceneSlot1;
extern s32 obj_get_owner(s32);
extern void draw_screen_pixel(s32, s32, s16, s32);
#define PACK_RGB5551(r, g, b) (((((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0) | (((b) >> 2) & 0x3E)) | 1)
/* Draws a Gouraud-shaded line from (x0,y0) to (x1,y1) with Bresenham stepping.
 * The colour is interpolated from (r0,g0,b0) to (r1,g1,b1) and packed to RGB5551. */
void func_8001477C(s32 x0, s32 y0, s32 x1, s32 y1, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1)
{
  s32 color;
  s32 dx;
  s32 dy;
  s32 err;
  s32 eadd2;
  s32 eadd;
  s32 step;
  s32 swap;
  u8 red;
  u8 green;
  u8 blue;
  u8 dr;
  u8 dg;
  u8 db;
  color = obj_get_owner(gSceneSlot1);
  dx = x1 - x0;
  dy = y1 - y0;
  dx = __builtin_abs(dx);
  dy = __builtin_abs(dy);
  red = r0;
  green = g0;
  blue = b0;
  if (dx >= dy)
  {
    dr = (r1 - red) / dx;
    dg = (g1 - green) / dx;
    db = (b1 - blue) / dx;
    if (x1 < x0)
    {
      swap = x1;
      x1 = x0;
      x0 = swap;
      swap = y1;
      y1 = y0;
      y0 = swap;
    }
    step = (y0 < y1) ? (1) : (-1);
    err = 2 * dy - dx;
    eadd2 = 2 * dy;
    eadd = 2 * (dy - dx);
    draw_screen_pixel(x0, y0, PACK_RGB5551(red, green, blue), color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    for (x0++; x0 <= x1; x0++)
    {
      if (err < 0)
      {
        err += eadd2;
      }
      else
      {
        err += eadd;
        y0 += step;
      }
      draw_screen_pixel(x0, y0, PACK_RGB5551(red, green, blue), color);
      red += dr;
      green += dg;
      blue += db;
    }

  }
  else
  {
    dr = (r1 - red) / dy;
    dg = (g1 - green) / dy;
    db = (b1 - blue) / dy;
    if (y1 < y0)
    {
      swap = x1;
      x1 = x0;
      x0 = swap;
      swap = y1;
      y1 = y0;
      y0 = swap;
    }
    step = (x0 < x1) ? (1) : (-1);
    err = 2 * dx - dy;
    eadd2 = 2 * dx;
    eadd = 2 * (dx - dy);
    draw_screen_pixel(x0, y0, PACK_RGB5551(red, green, blue), color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    for (y0++; y0 <= y1; y0++)
    {
      if (err < 0)
      {
        err += eadd2;
      }
      else
      {
        err += eadd;
        x0 += step;
      }
      draw_screen_pixel(x0, y0, PACK_RGB5551(red, green, blue), color);
      red += dr;
      green += dg;
      blue += db;
    }

  }
}
