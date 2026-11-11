/* identical to func_800856D4 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_8007FC14 in V-RALLY (matched), with its names changed by decompdecomp */

extern volatile int gHeapBusy;
void func_8007FC14(void)
{
  int new_var;
  s32 *new_var2;
  new_var2 = &gHeapBusy;
  if ((*new_var2) == 1)
  {
    ;
    do
    {
    }
    while (gHeapBusy == 1);
  }
}
