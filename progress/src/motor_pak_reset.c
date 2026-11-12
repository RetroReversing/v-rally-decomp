s32 __osMotorAccess();
s32 osMotorInit();
extern s32 gControllerInputContext;
extern char gOrderState[];
static inline int contPfsOffset(s32 channel)
{
  return (channel * 0x68) + 0x18C;
}

/* Resets the motor pak on one controller channel: when doInitFirst is set it inits
 * the pak once up front, then inits it and switches the motor off three times. */
void motor_pak_reset(s32 channel, s32 doInitFirst)
{
  s32 pfsOffset;
  void *msgQueue;
  if (doInitFirst & 0xFF)
  {
    osMotorInit(gOrderState + 0x5A38, gControllerInputContext + contPfsOffset(channel), channel);
  }
  msgQueue = gOrderState + 0x5A38;
  pfsOffset = contPfsOffset(channel);
  osMotorInit(msgQueue, gControllerInputContext + pfsOffset, channel);
  __osMotorAccess(gControllerInputContext + pfsOffset, 0);
  osMotorInit(msgQueue, gControllerInputContext + pfsOffset, channel);
  __osMotorAccess(gControllerInputContext + pfsOffset, 0);
  osMotorInit(msgQueue, gControllerInputContext + pfsOffset, channel);
  __osMotorAccess(gControllerInputContext + pfsOffset, 0);
}
