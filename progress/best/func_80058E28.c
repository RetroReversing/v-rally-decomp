extern volatile long long func_80084BF0(s32);
extern s8 func_80084C0C(s32, s32);
extern s32 D_8009D540;
extern u8 *D_800A1468;
extern s32 D_800A14A8;
extern u8 D_800A14AC[4];
extern u8 D_800AE850[];
s32 func_80058E28(void)
{
  u16 *new_var;
  int new_var5;
  s32 s5 = 0;
  s32 s0;
  s32 s2;
  s32 __repair_s2_1;
  int new_var4;
  volatile unsigned char new_var2;
  s32 s4;
  s32 s6;
  s32 v0;
  u16 *new_var3;
  s32 a0 = 0;
  s32 s3 = 0;
  s32 s1 = 0;
  __repair_s2_1 = *((s8 *) (D_800A1468 + 0x22B));
  s2 = __repair_s2_1;
  v0 = ((s8) s1) >= D_800AE850[0x7D50];
  s6 = s2;
  s4 = ((u32) (~s2)) >> 31;
  for (;;)
  {
    s3 = s2 == ((s8) s1);
    if (v0)
    {
      break;
    }
    if (!(s4 & s3))
    {
      v0 = a0;
      v0 = v0 | s3;
      if (s2 < 0)
      {
        goto call1;
      }
    }
    else
    {
      call1:
      a0 = func_80084C0C(s1 & 255, 0x10000);

      s3 = (s8) a0;
      a0 = func_80084C0C(s1 & 255, 0x20000);
      a0 = (s8) a0;
      v0 = a0 | s3;
    }
    if (!v0)
    {
      s1++;
      continue;
    }
    break;
  }

  __repair_s2_1 = 0;
  if (s3 >= 0x50)
  {
    __repair_s2_1 = 0x800;
  }
  else
    if (s3 < (-0x4F))
  {
    __repair_s2_1 = 0x400;
  }
  if (a0 >= 0x60)
  {
    __repair_s2_1 |= 0x100;
  }
  else
    if (a0 < (-0x5F))
  {
    __repair_s2_1 |= 0x200;
  }
  s0 = 0;
  new_var3 = (u16 *) D_800A14AC;
  s1 = 0;
  s3 = (s8) s6;
  s4 = ((u32) (~s3)) >> 31;
  v0 = ((s8) s1) >= D_800AE850[0x7D50];
  for (;;)
  {
    if (v0)
    {
      break;
    }
    new_var2 = s3 == ((s8) s1);
    if ((s4 & new_var2) || (s3 < 0))
    {
      v0 = func_80084BF0(s1 & 255);
      s0 |= v0;
      if (v0)
      {
        D_800AE850[0x741C] = s1;
      }
    }
    if (s0)
    {
      break;
    }
    s1++;
  }

  new_var5 = 0x10;
  if (!s0)
  {
    s0 = __repair_s2_1;
  }
  s1 = 0;
  ;
  for (;;)
  {
    a0 = s0 & v0;
    if (a0 == 1)
    {
      s0 = a0;
      goto scan_done;
    }
    s1++;
    v0 = 1 << s1;
    if (((s8) s1) >= 0x20)
    {
      break;
    }
  }

  scan_done:
  if (s0)
  {
    if (!D_800A14A8)
    {
      u16 __repair_narrow = 0;
      *((u16 *) D_800A14AC) = __repair_narrow;
      D_800A14A8 = s0;
      v0 = s0 & 0x800;
    }
    else
      if (D_800A14A8 == s0)
    {
      u16 t = (*((u16 *) D_800A14AC)) + 1;
      s6 = 0;
      new_var = (u16 *) D_800A14AC;
      *new_var = t;
      if (!D_800A14AC[2])
      {
        s0 = s6;
        if ((t & 65535) != ((D_8009D540 * 3) >> 2))
        {
          s0 = s6;
          goto done;
        }
        D_800A14AC[2] = 1;
        *new_var3 = s6;
        v0 = s0 & 0x800;
      }
      else
      {
        if ((t & 65535) != (D_8009D540 / 6))
        {
          goto done;
        }
        *((u16 *) D_800A14AC) = s6;
        v0 = s0 & 0x800;
      }
    }
    else
    {
      D_800A14A8 = s0;
      new_var4 = 1;
      *((u16 *) D_800A14AC) = new_var4;
      D_800A14AC[2] = s6;
      v0 = s0 & 0x800;
    }
  }
  else
  {
    D_800A14A8 = s6;
    *((u16 *) D_800A14AC) = s6;
    D_800A14AC[2] = s6;
    v0 = s6;
  }

  done:
  if (s0 & 0x800)
  {
    s5 |= 1;
  }

  if (s0 & 0x400)
  {
    s5 |= 2;
  }
  if (s0 & 0x200)
  {
    s5 |= 4;
  }
  if (s0 & 0x100)
  {
    s5 |= 8;
  }
  if (s0 & 0x4000)
  {
    s5 |= 0x20;
  }
  if (s0 & 0x8000)
  {
    s5 |= new_var5;
  }
  if (s0 & 0x1000)
  {
    s5 |= 0x80;
  }
  return s5;
}
