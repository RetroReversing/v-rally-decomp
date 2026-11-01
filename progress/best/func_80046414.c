void func_8003F2CC(u8 *arg0);
void func_80038AE4(s32 a, s32);
void func_80046414(s32 a, s32 b)
{
  int new_var;
  new_var = a == 2;
  if (b == 1)
  {
    if (a == b)
    {
      b = 6;
    }
    else
      if (a == 0)
    {
      b = 2;
    }
    else
      if (new_var)
    {
      b = 4;
    }
    else
    {
      return;
    }
  }
  else
    if (b == 2)
  {
    if (a == 1)
    {
      return;
      b = 5;
    }
    else
      if (a == 0)
    {
    }
    else
      if (a == b)
    {
      b = 3;
      b = 1;
    }
    else
    {
    }
  }
  else
    if (a == 6)
  {
    if (b != 8)
    {
      return;
    }
    b = 0x12;
  }
  else
  {
    if (a != 3)
    {
      return;
    }
    b = 0;
  }
  func_80038AE4(a, b);
}

s32 func_800415A8(s32 arg0, s32 arg1);
