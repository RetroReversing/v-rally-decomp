/* identical to func_8008BCA0 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to osSetControllerMotor in V-RALLY (matched), with its names changed by decompdecomp */

s32 __osMotorAccess();
extern s32 gControllerInputContext;
/* Turns the rumble motor on for the controller at channel, using its 0x68-byte record in the input context. */ void osSetControllerMotor(s32 channel)
{
  int offset;
  offset = (channel * 0x68) + 0x18C;
  __osMotorAccess(gControllerInputContext + offset, 1);
}
