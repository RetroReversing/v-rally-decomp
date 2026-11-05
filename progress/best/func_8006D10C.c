extern f64 D_800A58A0;
extern f64 D_800A5898;
extern u8 *D_800C35A0;
extern u8 *D_800D0634[];
extern u16 D_800C5D9C[];
extern u8 D_800C721E[];
extern s32 func_8006B924(void *);
void func_8006D10C(void)
{
  f64 fs1;
  u8 i;
  u8 j;
  s32 k;
  u8 n;
  s32 q;
  s32 r;
  s32 code;
  u8 a;
  u8 b;
  u8 *s6;
  u8 *out;
  a = D_800C35A0[31];
  b = D_800C35A0[35];
  s6 = D_800D0634[a];
  j = 0;
  switch (a)
  {
    case 0:
      break;
    case 2:
      j = 4;
      break;
    case 3:
      j = 9;
      break;
    case 4:
      j = 15;
      break;
  }
  n = b + j;
  i = 0;
  fs1 = ((f64) n) * D_800A5898;
  do
  {
    j = (u32) (fs1 + ((f64) (i & 255)) * D_800A58A0);
    k = i & 255;
    q = ((n * 9) + (k * 3)) * 4 - (j & 255) * 8;
    code = func_8006B924(s6 + (((*(u16 *) (D_800C35A0 + 34)) << 6) + 44) + k * 16);
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
      r = D_800C5D9C[n] - *(s32 *) (s6 + (k * 16 + ((*(u16 *) (D_800C35A0 + 34)) << 6)) + 44);
      if (r >= 0)
      {
        if (r >= 1024) r = 1022;
        r = r & ~1;
      }
      else
      {
        r = -r;
        if (r >= 1024) r = 1022;
        r = r | 1;
      }
      if (q & 255)
      {
        switch (code & 255)
        {
          case 0: out[j & 255] &= 207; break;
          case 1: out[j & 255] = (out[j & 255] | 16) & 223; break;
          case 2: out[j & 255] = (out[j & 255] & 239) | 32; break;
          case 3: out[j & 255] |= 48; break;
        }
        if (r & 1) out[j & 255] |= 64; else out[j & 255] &= 191;
        if (r & 2) out[j & 255] |= 128; else out[j & 255] &= 127;
        out[(j & 255) + 1] = r >> 2;
      }
      else
      {
        switch (code & 255)
        {
          case 0: out[(j & 255) + 1] &= 243; break;
          case 1: out[(j & 255) + 1] = (out[(j & 255) + 1] | 4) & 247; break;
          case 2: out[(j & 255) + 1] = (out[(j & 255) + 1] & 251) | 8; break;
          case 3: out[(j & 255) + 1] |= 12; break;
        }
        if (r & 256) out[(j & 255) + 1] |= 1; else out[(j & 255) + 1] &= 254;
        if (r & 512) out[(j & 255) + 1] |= 2; else out[(j & 255) + 1] &= 253;
        out[j & 255] = r;
      }
    }
    i++;
  }
  while ((i & 255) < 3);
}
