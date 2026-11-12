extern s32 osPiIsInitialized;
extern s32 osPiCommandQueue;

/* Returns the PI command queue, or NULL (0) if the PI manager has not been initialised. */ s32 osPiGetCommandQueuePtr(void)
{
  s32 initialized;

  initialized = osPiIsInitialized;
  if (initialized == 0)
  {
    return 0;
  }
  return osPiCommandQueue;
}
