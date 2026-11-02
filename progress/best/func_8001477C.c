extern s32 D_8009B5A8;
extern s32 func_80005C48(s32);
extern void func_80014564(s32, s32, s16, s32);
void func_8001477C(s32 x0, s32 y0, s32 x1, s32 y1, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1)
{
  s32 color;
  s32 eadd2;
  u8 dr;
  s32 step;
  u8 dg;
  u8 db;
  u8 red;
  u8 green;
  u8 blue;
  s32 dx;
  u8 new_var;
  s32 dy;
  s32 err;
  s32 eadd;
  s32 swap;
  color = func_80005C48(D_8009B5A8);
  dx = x1 - x0;
  dy = y1 - y0;
  if (dx < 0)
  {
    dx = -dx;
  }
  if (dy < 0)
  {
    dy = -dy;
  }
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
    eadd2 = 2 * dy;
    err = eadd2 - dx;
    eadd = 2 * (dy - dx);
    func_80014564(x0, y0, ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | ((blue >> 2) & 0x3E)) | 1, color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    for (x0++; x0 <= x1; x0++)
    {
      if (err >= 0)
      {
        err += eadd;
        y0 += step;
      }
      else
      {
        err += eadd2;
      }
      func_80014564(x0, y0, ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | ((blue >> 2) & 0x3E)) | 1, color);
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
    eadd2 = 2 * dx;
    err = eadd2 - dy;
    eadd = 2 * (dx - dy);
    func_80014564(x0, y0, ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | ((blue >> 2) & 0x3E)) | 1, color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    for (y0++; y0 <= y1; y0++)
    {
      if (err >= 0)
      {
        err += eadd;
 do { } while (0);
        x0 += step;
      }
      else
      {
        err += eadd2;
      }
      func_80014564(x0, y0, ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | ((blue >> 2) & 0x3E)) | 1, color);
      red += dr;
      green += dg;
      blue += db;
    }

  }
}
