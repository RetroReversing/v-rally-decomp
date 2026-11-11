/* Rounds the decimal digit string buf to len digits. The digit at buf[len] decides it: below
   '5' the string is cut there and value is returned. Otherwise the last kept digit is
   incremented, carrying leftwards through any '9's. If every digit carries, the string
   becomes "10" and value + 1 is returned. */
s32 func_80098998(s8 *buf, s32 value, s32 len)
{
  s8 *p;
  s8 *q;
  s32 n;
  s8 c;
  p = buf + len;
  if ((*p) < 0x35)
  {
    *p = 0;
    return value;
  }
  if (c)
  {
    q = p;
    n = len - 1;
    *q = 0;
  }
  else
  {
    q = p;
    n = len - 1;
    *q = 0;
  }
  if (n < 0)
  {
    goto end;
  }
  do
  {
    p--;
    c = *p;
    if (c != 0x39)
    {
      *p = c + 1;
      return value;
    }
    *p = 0x30;
    n--;
  } while (n >= 0);
end:
  *p = 0x31;
  q[0] = 0x30;
  q[1] = 0;
  return value + 1;
}
