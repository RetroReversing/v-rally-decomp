s32 func_8002AA18(s8 *a, s8 *b)
{
  unsigned long new_var;
  while ((((*a) == (*b)) && ((*a) != 0)) && ((*((u8 *) b)) != 0))
  {
    a++;
    b++;
  }
  if ((*a) == 0 && (*b) == 0) return 0;
  return 1;
}
