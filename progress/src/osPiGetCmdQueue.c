extern s32 __osPiInitialized;
extern s32 __osPiCmdQueue;

s32 osPiGetCmdQueue(void)
{
  s32 temp_v1;

  temp_v1 = __osPiInitialized;
  if (temp_v1 == 0)
  {
    return 0;
  }
  return __osPiCmdQueue;
}
