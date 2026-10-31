extern f64 D_800A5890;
extern f64 D_800A5890;
extern f64 D_800A58A0;
extern u8 *D_800C35A0;
extern u8 *D_800D0634[];
extern u16 D_800C5D9C[];
extern u8 D_800C721E[];
extern s32 func_8006B924(void *);
void func_8006D10C(void)
{
  f64 fs0;
  f64 fs1;
  f64 x;
  u8 i = 0;
  s32 j;
  s32 k;
  s32 n;
  s32 t;
  int new_var;
  s32 q;
  s32 r;
  s32 code;
  u8 a;
  u8 b;
  u8 *s6;
  u8 *out;
  u16 *height;
  a = D_800C35A0[31];
  b = D_800C35A0[35];
  s6 = D_800D0634[a];
  switch (a)
  {
    case 0:
      break;

    case 2:
      i = 4;
      break;

    case 3:
      i = 9;
      break;

    case 4:
      i = 15;
      break;

  }

  n = (u8) (b + i);
  i = 0;
  fs0 = D_800A5890;
  fs1 = D_800A5890;
  fs1 = ((f64) n) * fs1;
  height = &D_800C5D9C[n];
  do
  {
    x = fs1 + (((f64) (i & 255)) * D_800A58A0);
    j = (u32) x;
    k = i & 255;
    t = k * 16;
    q = (((k * 3) + (n * 9)) * 4) - ((j & 255) * 8);
    code = func_8006B924((s6 + (((*((u16 *) (D_800C35A0 + 34))) << 6) + 44)) + ((short) t));
    out = D_800C721E;
    if ((code & 255) == 5)
    {
      if (q & 255)
      {
        out[(j & 255) + 1] = 255;
        out[j & 255] |= 240;
      }
      else
      {
        out[j & 255] = 255;
        out[(j & 255) + 1] |= 15;
      }
    }
    else
    {
      r = (*height) - (*((s32 *) ((s6 + (t + ((*((u16 *) (D_800C35A0 + 34))) << 6))) + 44)));
      if (r >= 0)
      {
        if (((*height) - (*((s32 *) ((s6 + (t + ((*((u16 *) (D_800C35A0 + 34))) << 6))) + 44)))) >= 1024)
        {
          r = 1022;
        }
        r = r & (~1);
      }
      else
      {
        r = -r;
        if (r >= 1024)
        {
          r = 1022;
        }
        r = r | 1;
      }
      if (q & 255)
      {
        switch (code & 255)
        {
          case 0:
            out[j & 255] &= 207;
            break;

          case 1:
            out[j & 255] = (out[j & 255] | 16) & 223;
            break;

          case 2:
            out[j & 255] = (out[j & 255] & 239) | 32;
            break;

          case 3:
            out[j & 255] |= 48;
            break;

        }

        if (r & 1)
        {
          out[j & 255] |= 64;
        }
        else
        {
          out[j & 255] &= 191;
        }
        if (r & 2)
        {
          out[j & 255] |= 128;
        }
        else
        {
          out[j & 255] &= 127;
        }
        out[(j & 255) + 1] = r >> 2;
      }
      else
      {
        switch (code & 255)
        {
          case 0:
            out[(j & 255) + 1] &= 243;
            break;

          case 1:
            out[(j & 255) + 1] = (out[(j & 255) + 1] | 4) & 247;
            break;

          case 2:
            out[(j & 255) + 1] = (out[(j & 255) + 1] & 251) | 8;
            break;

          case 3:
            out[(j & 255) + 1] |= 12;
            break;

        }

        if (r & 256)
        {
          out[(j & 255) + 1] |= 1;
        }
        else
        {
          out[(j & 255) + 1] &= 254;
        }
        new_var = j & 255;
        if (r & 512)
        {
          out[new_var + 1] |= 2;
        }
        else
        {
          out[new_var + 1] &= 253;
        }
        out[j & 255] = r;
      }
    }
    i++;
  }
  while ((i & 255) < 3);
}
