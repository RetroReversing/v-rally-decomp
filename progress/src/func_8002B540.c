char *func_8002B180(char *, char *);
s32 func_8002AA6C(char *, char *);
void func_8002ABC0(s32, char *, char *);

char *func_8002B540(char *p, char *end)
{
  char *q;
  for (;;)
  {
    p = func_8002B180(p, end);
    if (p >= end || *p == '[')
      return p;
    func_8002ABC0(func_8002AA6C(p, end), p, end);
    q = p;
    do
    {
      while (*q++ != '\r')
      {
        if (!(q < end))
          break;
      }
      if (q == end)
        break;
      q++;
    } while (*q == '\r');
    p = q;
  }
}
