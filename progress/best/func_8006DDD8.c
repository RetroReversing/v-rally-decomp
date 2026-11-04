extern u8 D_800C02AE[];
extern u8 *D_800C35A0;
extern u8 *D_800D0634;
extern u16 D_800C5D38[];
extern u8 D_800C7125[];
extern f64 D_800A58A8;
extern f64 D_800A58B0;
extern f64 D_800A58B8;
s32 func_8006B9E0(u8, u8);
s32 func_8006B924(void *, int);
long func_8006DDD8(void)
{
  char *__repair_addr;
  f64 bound = D_800A58A8;
  u8 *p = D_800C35A0;
  u8 *tab = D_800C7125;
  s32 i = 0;
  u8 *base = D_800D0634 + (p[0x21] * 0x2c4);
  u32 idx;
  u32 x;
  s32 raw;
  u32 twice;
  s16 off;
  s32 delta;
  s32 code;
  s32 stride;
  f64 b;
  int new_var;
  idx = (u8) func_8006B9E0(p[0x21], p[0x23]);
  twice = idx * 2;
  b = ((f64) ((s32) idx)) * D_800A58B0;
  stride = (*((u8 **) (D_800C02AE + 0x32f2)))[0x23] * 64;
  new_var = 0x40;
  loop:
  {
    {
      f64 value = b + (((f64) (i & 255)) * D_800A58B8);
      if (!(bound <= value))
      {
        raw = (s32) value;
      }
      else
      {
        raw = ((s32) (value - bound)) | 0x80000000;
      }
      x = raw;
    }
    off = (((idx * 9) + ((i & 255) * 3)) * 4) - (((u8) x) * 8);
    code = func_8006B924((base + (stride + 0x2c)) + ((i & 255) * 16), i & 255);
    if (((u8) code) == 5)
    {
      if ((u8) off)
      {
 do { tab[((u8) x) + 1] = 255; tab[(u8) x] |= 0xf0; } while (0);
      }
      else
      {
        tab[(u8) x] = 255;
        tab[((u8) x) + 1] |= 15;
      }
    }
    else
    {
      if (code)
      {
        delta = (*((u16 *) (((u8 *) D_800C5D38) + twice))) - (*((s32 *) ((char *) ((base + (((i & 255) * 16) + stride)) + 0x2c))));
      }
      else
      {
        delta = (*((u16 *) (((u8 *) D_800C5D38) + twice))) - (*((s32 *) ((char *) ((base + (((i & 255) * 16) + stride)) + 0x2c))));
      }
      if (delta >= 0)
      {
        if (delta >= 1024)
        {
          delta = 1022;
        }
        delta &= ~1;
      }
      else
      {
        delta = -delta;
        if (delta >= 1024)
        {
          delta = 1022;
        }
        delta |= 1;
      }
      if ((u8) off)
      {
        switch ((u8) code)
        {
          case 0:
            tab[(u8) x] &= 0xcf;
            break;

          case 1:
            off = (tab[(u8) x] = (tab[(u8) x] | 0x10) & 0xdf);
            break;

          case 2:
            tab[(u8) x] = (tab[(u8) x] & 0xef) | 0x20;
            break;

          case 3:
            tab[(u8) x] |= 0x30;
            break;

        }

        if (delta & 1)
        {
          tab[(u8) x] |= new_var;
        }
        else
        {
          tab[(u8) x] &= 0xbf;
        }
        if (delta & 2)
        {
          tab[(u8) x] |= 0x80;
        }
        else
        {
          tab[(u8) x] &= 0x7f;
        }
        tab[((u8) x) + 1] = delta >> 2;
      }
      else
      {
        switch ((u8) code)
        {
          case 0:
            tab[((u8) x) + 1] &= 0xf3;
            break;

          case 1:
            tab[((u8) x) + 1] = (tab[((u8) x) + 1] | 4) & 0xf7;
            break;

          case 2:
            tab[((u8) x) + 1] = (tab[((u8) x) + 1] & 0xfb) | 8;
            break;

          case 3:
            tab[((u8) x) + 1] |= 12;
            break;

        }

        if (delta & 0x100)
        {
          tab[((u8) x) + 1] |= 1;
        }
        else
        {
          tab[((u8) x) + 1] &= 0xfe;
        }
        if (delta & 0x200)
        {
          tab[((u8) x) + 1] |= 2;
        }
        else
        {
          tab[((u8) x) + 1] &= 0xfd;
        }
        tab[(u8) x] = delta;
      }
    }
    i++;
  }

  if (((u32) (i & 255)) < 3)
  {
    goto loop;
  }
}
