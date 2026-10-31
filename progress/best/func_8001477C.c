extern s32 D_8009B5A8;
extern s32 func_80005C48();
extern void func_80014564(s32, s32, s16, s32);
void func_8001477C(s32 x0, s32 y0, s32 x1, s32 y1, u8 r0, u8 g0, u8 b0, s32 unused0, s32 unused1, s32 unused2, s32 unused3, u8 r1, u8 g1, u8 b1)
{
  u8 red;
  u8 green;
  u8 blue;
  s32 color;
  s32 dx;
  s32 dy;
  s32 dr;
  s32 dg;
  s32 db;
  s32 sr;
  s32 sg;
  s32 sb;
  s32 t;
  s32 ystep;
  s32 err;
  s32 eadd;
  s32 swap;
  color = func_80005C48(D_8009B5A8);
  dx = x1;
  dx = dx - x0;
  dy = y1 - y0;
  if (dx < 0)
  {
    dx = -dx;
  }
  if (dy < 0)
  {
    dy = -dy;
  }
  red = r0;
  green = g0;
  blue = b0;
  if (dx >= dy)
  {
    dr = (r1 - (red & 255)) / dx;
    dg = green;
    dg = (g1 - (dg & 255)) / dx;
    db = (b1 - (blue & 255)) / dx;
    sr = (r1 - (red & 255)) % dx;
    sg = (g1 - (green & 255)) % dx;
    sb = (b1 - (blue & 255)) % dx;
    if (x1 < x0)
    {
      swap = x0;
      x0 = x1;
      x1 = swap;
      swap = y0;
      y0 = y1;
      y1 = swap;
    }
    ystep = (y0 < y1) ? (1) : (-1);
    err = (2 * dy) - dx;
    eadd = 2 * (dy - dx);
    func_80014564(x0, y0, (s16) ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | (((blue >> 2) & 0x3E) | 1)), color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    x0++;
    while (x0 <= x1)
    {
      if (err >= 0)
      {
        err += eadd;
        y0 += ystep;
      }
      else
      {
        err += 2 * dy;
      }
      func_80014564(x0, y0, (s16) (((((red & 255) << 8) & 0xF800) | ((green << 3) & 0x7C0)) | (((blue >> 2) & 0x3E) | 1)), color);
      x0++;
      red += dr;
      green += dg;
      blue += db;
    }

  }
  else
  {
    dr = (r1 - (red & 255)) / dy;
    dg = (g1 - (green & 255)) / dy;
    db = (b1 - (blue & 255)) / dy;
    sr = (r1 - (red & 255)) % dy;
    sg = (g1 - (green & 255)) % dy;
    sb = (b1 - (blue & 255)) % dy;
    if (y1 < y0)
    {
      swap = x1;
      x1 = x0;
      x0 = swap;
      swap = y1;
      y1 = y0;
      y0 = swap;
    }
    ystep = (x0 < x1) ? (1) : (-1);
    err = (2 * dx) - dy;
    eadd = 2 * (dx - dy);
    func_80014564(x0, y0, (s16) ((((red << 8) & 0xF800) | ((green << 3) & 0x7C0)) | (((blue >> 2) & 0x3E) | 1)), color);
    red = r0 + dr;
    green = g0 + dg;
    blue = b0 + db;
    y0++;
    while (y0 <= y1)
    {
      if (err >= 0)
      {
        err += eadd;
        x0 += ystep;
      }
      else
      {
        err += 2 * dx;
      }
      func_80014564(x0, y0, (s16) (((((red & 255) << 8) & 0xF800) | ((green << 3) & 0x7C0)) | (((blue >> 2) & 0x3E) | 1)), color);
      y0++;
      red += dr;
      green += dg;
      blue += db;
    }

  }
}
