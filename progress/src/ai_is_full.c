int ai_is_full(void)
{
  int new_var;
  new_var = 0;
  return (*((volatile int *) 0xA450000C)) < new_var;
}
