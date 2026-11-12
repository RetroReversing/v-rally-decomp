/* identical to func_8008BCA0 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80086370 in V-RALLY (matched), with its names changed by decompdecomp */

s32 __osMotorAccess();
extern s32 gContCtx;
void func_80086370(s32 arg0)
{
  int new_var;
  new_var = (arg0 * 0x68) + 0x18C;
  __osMotorAccess(gContCtx + new_var, 1);
}
