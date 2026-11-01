extern u8 *D_800A1B70;
s8 func_80084C0C(s32 arg0, s32 arg1)
{
  s32 pad[2];
  signed char *e;
  signed char a2;
  int a1;
  s32 a0;
  s32 v1;
  u8 *tbl;
  u8 idx;
  if (arg1 != 0x10000)
  {
    if (arg1 != 0x20000)
    {
      return 0;
    }
    idx = arg0;
    a1 = *((signed char *) ((D_800A1B70 + (idx * 6)) + 0x1E));
    e = (signed char *) (D_800A1B70 + (idx * 20));
    a2 = a1;
    v1 = e[0x5F] + e[0x60];
    if (a1 >= v1)
    {
      a1 = e[0x5C];
      a0 = v1;
    }
    else
    {
      v1 = e[0x5F] + e[0x5E];
      if (v1 < a1)
      {
        return 0;
      }
      a1 = e[0x5D];
      a0 = v1;
    }
  }
  else
  {
    tbl = D_800A1B70;
    idx = arg0;
    a1 = (a2 = *((signed char *) ((tbl + (idx * 6)) + 0x1F)));
 do { e = (signed char *) (tbl + (idx * 20)); v1 = e[0x64] + e[0x65]; } while (0);
    if (a1 >= v1)
    {
      a1 = e[0x61];
      a0 = v1;
    }
    else
    {
      v1 = e[0x64] + e[0x63];
      if (v1 < a1)
      {
        return 0;
      }
      a1 = e[0x62];
      a0 = v1;
    }
  }
  if (a0 < a2)
  {
    if (a1 < a2)
    {
      return 0x7F;
    }
    if (a0 != 0)
    {
      a1 -= a0;
      a2 -= a0;
      a0 = 0;
    }
    return (a2 * 0x7F) / (a1 - a0);
  }
  if (a2 < a0)
  {
    if (a2 < a1)
    {
      return -0x80;
    }
    if (a0 != 0)
    {
      a1 -= a0;
      a2 -= a0;
      a0 = 0;
    }
    return (a2 << 7) / (a0 - a1);
  }
  return 0;
}
