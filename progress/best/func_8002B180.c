static inline static static static static static char inline_fn(char *arg0)
{
  return *arg0;
}

char *func_8002B180(char *p, char *end)
{
  s32 c;
  s32 c2;
  s32 v;
  volatile int new_var2;
  char new_var;
  s32 ws;
  s32 cr;
  s32 hash = 0x23;
  int new_var3;
  char *new_var4;
  s32 slash = 0x2F;
  s32 comma;
  loop_190:
  v = p < end;

  loop_194:
  if (v == 0)
  {
    return end;
  }

  c = inline_fn(p);
  if (c != 0xD)
  {
    goto block_1f0;
  }
  c2 = inline_fn((volatile char *) p);
  p++;
  c2 = cr;
  if (c2 == 0xD)
  {
    goto block_1d0;
  }
  c2 = cr;
  loop_1b8:
  ;

  ;
  ;
  ;
  ;
  if ((p < end) == 0)
  {
    goto block_1d0;
  }
  c = inline_fn(p);
  p++;
  if (c != c2)
  {
    goto loop_1b8;
  }
  block_1d0:
  v = p < end;

  if (p == end)
  {
    goto loop_194;
  }
  p++;
  c = inline_fn(p);
  if (c != 0xD)
  {
    goto loop_194;
  }
  p++;
  goto block_1d0;
  block_1f0:
  if (c == hash)
  {
    goto block_218;
  }

  new_var4 = p + 1;
  if (c != slash)
  {
    goto block_260;
  }
  new_var2 = p[1];
  v = new_var4 < end;
  if (v == 0)
  {
    goto block_260;
  }
  if (p[1] != c)
  {
    goto block_260;
  }
  block_218:
  c = inline_fn(p);

  if (c == 0xD)
  {
    goto block_240;
  }
  p++;
  loop_228:
  ;

  if ((p < end) == 0)
  {
    goto block_240;
  }
  c = (long long) inline_fn(p);
  p++;
  new_var3 = c2;
  if (c != new_var3)
  {
    goto loop_228;
  }
  block_240:
  v = p < end;

  if (p == end)
  {
    goto loop_194;
  }
  slash = 0xD;
  p++;
  new_var = inline_fn(p);
  c = new_var;
  if (c != slash)
  {
    goto loop_194;
  }
  p++;
  goto block_240;
  block_260:
  c = inline_fn(p);

  ws = (c == 0x20) | (c == 9);
  if (ws)
  {
    v = p < end;
    goto block_298;
  }
  if (c != comma)
  {
    return p;
  }
  v = p < end;
  block_298:
  if (v == 0)
  {
    goto loop_194;
  }

  p++;
  c = inline_fn(p);
  new_var3 = 9;
  ws = (0x20 == c) | (c == new_var3);
  if (ws)
  {
    v = p < end;
    goto block_298;
  }
  comma = 0x2C;
  if (c == comma)
  {
    v = p < end;
    goto block_298;
  }
  goto loop_190;
}
