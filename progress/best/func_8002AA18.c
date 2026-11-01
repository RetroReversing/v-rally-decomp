s32 func_8002AA18(s8 *a, s8 *b)
{
  unsigned long new_var;
  while ((((*a) == (*b)) && ((*a) != 0)) && ((*((u8 *) b)) != 0))
  {
    a++;
    b++;
  }
  new_var = (*a) == 0;
  if (new_var) {
    return (*b) != 0;
  }
  return 1;
}
