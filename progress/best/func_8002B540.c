char *func_8002B180(char *, char *);
s32 func_8002AA6C(char *, char *);
void func_8002ABC0(s32, char *, char *);
static inline static static static int inline_fn(char *arg0, char *arg1)
{
  return arg0 == arg1;
}

char *func_8002B540(char *arg0, char *arg1)
{
  char *new_var2;
  char *s0;
  char *a0;
  char *new_var;
  s0 = arg0;
  for (;;)
  {
    new_var2 = arg1;
    s0 = func_8002B180(s0, new_var2);
    if ((s0 >= arg1) || ((*s0) == 91))
    {
      return s0;
    }
    new_var = s0;
    func_8002ABC0(func_8002AA6C(new_var, new_var2), s0, new_var2);
    a0 = s0;
    s0 = &(*(a0++));
    if ((*s0) != 13)
    {
      unsigned int cr = 13;
      scan:
      if (a0 >= new_var2)
      {
        goto tail;
      }

      ;
      if ((*(a0++)) != cr)
      {
        goto scan;
      }
    }
    tail:
    for (;;)
    {
      s0 = a0;
      if (inline_fn(a0, new_var2))
      {
        break;
      }
      a0++;
      do
      {
        if ((*a0) != 13)
        {
          break;
        }
        s0 = a0;
        a0++;
      }
      while (0);
    }


  }

}
