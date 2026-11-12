#ifdef PORT
extern char *gControllerInputContext;

/* Handles command 2 for controller channel `channel`: if its state at +4 is 1, it sets the
 * +8 flag, sets the +0xC divisor to 0xFF / divisor (0xFF when divisor is 0), sets the
 * +0x10 flag and returns 1. Returns 0 for other commands or when the state is not 1. */
s32 func_800857EC(s32 channel, s32 cmd, s32 divisor)
{
  s32 temp_v1;
  s32 result;
  char *temp_a1;
  char *temp_a3;
  result = 0;
  if ((cmd & 0xFF) == 2)
  {
    temp_a1 = gControllerInputContext + ((channel & 0xFF) * 4);
    temp_a3 = *((char **) (temp_a1 + 0x38C));
    temp_v1 = *((s32 *) (temp_a3 + 4));
    if (temp_v1 != 1)
    {
      return 0;
    }
    *((vs32 *) (temp_a3 + 8)) = temp_v1;
    divisor = divisor & 0xFF;
    if (divisor != 0)
    {
      *((s32 *) (*((char **) (temp_a1 + 0x38C)) + 0xC)) = (s32) (0xFF / divisor);
    }
    else
    {
      *((s32 *) (*((char **) (temp_a1 + 0x38C)) + 0xC)) = 0xFF;
    }
    result = 1;
    *((s32 *) (*((char **) (gControllerInputContext + ((channel & 0xFF) * 4) + 0x38C)) + 0x10)) = 1;
    return result;
  }
  return result;
}
#else
extern s32 gControllerInputContext;

/* Handles command 2 for controller channel `channel`: if its state at +4 is 1, it sets the
 * +8 flag, sets the +0xC divisor to 0xFF / divisor (0xFF when divisor is 0), sets the
 * +0x10 flag and returns 1. Returns 0 for other commands or when the state is not 1. */
s32 func_800857EC(s32 channel, s32 cmd, s32 divisor)
{
  s32 temp_v1;
  s32 result;
  void *temp_a1;
  void *temp_a3;
  result = 0;
  if ((cmd & 0xFF) == 2)
  {
    temp_a1 = ((channel & 0xFF) * 4) + gControllerInputContext;
    temp_a3 = *((void **) (((char *) temp_a1) + 0x38C));
    temp_v1 = *((s32 *) (((char *) temp_a3) + 4));
    if (temp_v1 != 1)
    {
      return 0;
    }
    *((vs32 *) (((char *) temp_a3) + 8)) = temp_v1;
    divisor = divisor & 0xFF;
    if (divisor != 0)
    {
      *((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x38C)))) + 0xC)) = (s32) (0xFF / divisor);
    }
    else
    {
      *((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x38C)))) + 0xC)) = 0xFF;
    }
    result = 1;
    *((s32 *) (((char *) (*((void **) (((char *) (((channel & 0xFF) * 4) + gControllerInputContext)) + 0x38C)))) + 0x10)) = 1;
    return result;
  }
  return result;
}
#endif
