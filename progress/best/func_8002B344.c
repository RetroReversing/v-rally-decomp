u32 func_8002B180();
void *func_8002B344(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3)
{
  volatile unsigned int new_var3;
  s8 *a0;
  s8 *a1;
  s8 *a2;
  s8 new_var2;
  s32 c1;
  s32 v0;
  s32 v1;
  s32 lbrack;
  s32 cr;
  s8 *new_var;
  s32 pad[2];
  lbrack = 0x5B;
  cr = 0xD;
  a0 = arg0;
  L374:
  a0 = (s8 *) func_8002B180((u32) a0, (u32) arg1);

  if (!(a0 < arg1))
  {
    goto fail;
  }
  new_var3 = *a0;
  if ((*a0) == lbrack)
  {
    goto L3E4;
  }
  if (new_var3 == cr)
  {
    a0++;
    goto L3C0;
  }
  a0++;
  L3A8:
  if (!((new_var = a0) < arg1))
  {
    goto L3C0;
  }

  if ((*new_var) == cr)
  {
    a0++;
    do
    {
      goto L3C0;
    }
    while (0);
  }
  a0++;
  goto L3A8;
  L3C0:
  if (a0 == arg1)
  {
    goto L3DC;
  }

  a0++;
  if ((*a0) == cr)
  {
    a0++;
    goto L3C0;
  }
  L3DC:
  if (a0 < arg1)
  {
    goto L374;
  }

  L3E4:
  if (!(a0 < arg1))
  {
    goto fail;
  }

  a0++;
  a1 = a0;
  while (((*a1) != 0x5D) && (a1 < arg1))
  {
    a1++;
  }

  if (!(a0 < arg1))
  {
    goto fail;
  }
  *a1 = 0;
  arg0 = arg2;
  c1 = *a0;
  a2 = a0;
  v0 = *arg0;
  goto L454;
  L43C:
  if (v1 == 0)
  {
    goto L464;
  }

  a2++;
  arg0++;
  c1 = *a2;
  v0 = *arg0;
  L454:
  if (c1 != v0)
  {
    goto L464;
  }

  v1 = *((u8 *) arg0);
  if (c1 != 0)
  {
    goto L43C;
  }
  L464:
  v1 = 1;

  new_var2 = *a2;
  if (new_var2 == 0)
  {
    v0 = *arg0;
    v1 = v0 != 0;
  }
  if (v1 != 0)
  {
    goto L4CC;
  }
  *arg3 = 1;
  if ((*a0) == cr)
  {
    a0++;
    goto L4AC;
  }
  a0++;
  L494:
  if (!(a0 < arg1))
  {
    goto L4AC;
  }

  if ((*a0) == cr)
  {
    a0++;
    goto L4AC;
  }
  a0++;
  goto L494;
  L4AC:
  if (a0 == arg1)
  {
    return a0;
  }

  if ((*a0) == cr)
  {
    a0++;
    goto L4AC;
  }
  return a0;
  L4CC:
  if ((*a0) == (c1 = cr))
  {
    a0++;
    goto L4F4;
  }

  a0++;
  L4DC:
  if (!(a0 < arg1))
  {
    goto L4F4;
  }

  if ((*a0) == cr)
  {
    a0++;
    goto L4F4;
  }
  goto L4DC;
  L4F4:
  if (a0 == arg1)
  {
    goto L510;
  }

  a0++;
  a0++;
  if ((*a0) == cr)
  {
    a0++;
    goto L4F4;
  }
  v1 = a0 < arg1;
  L510:
  if (v1)
  {
    goto L374;
    a0++;
  }

  fail:
  *arg3 = 0;

  return NULL;
}
