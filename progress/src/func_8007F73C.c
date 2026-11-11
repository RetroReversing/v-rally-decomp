s32 osRecvMesg();
extern char gOrderState[];

/* Blocks until a message arrives on the 0x5C-byte queue record at (arg0 + arg1) in gOrderState, then returns its value (0 if none). */
s32 func_8007F73C(s32 arg0, s32 arg1)
{
  int new_var;
  s32 *msg;
  int new_var2;
  new_var2 = 0;
  osRecvMesg(((arg0 + arg1) * 0x5C) + (gOrderState + 0x5924), &msg, 1);
  if (msg == NULL)
  {
    if (arg0)
    {
      return new_var2;
    }
    else
    {
      return new_var2;
    }
  }
  new_var = *msg;
  return new_var;
}
