/* A cartridge device on one of the two PI domains. The timing fields are the
   values for the PI BSD_DOM registers: latency, release duration, pulse width and
   page size. */
typedef struct 
{
  u8 pad00[5];
  u8 latency;
  u8 rel_duration;
  u8 pulse;
  u8 page_size;
  u8 domain;
  u8 pad0a[2];
  s32 addr;
} PiDevice;
extern PiDevice *gPiCurrentDev[4];
extern u8 D_800A7170;
extern u8 D_800A7174;
void func_800914E0(void *, void *, s32);

/* Reads one word from cartridge address dev->addr + offset into *dst. First waits
   for PI to go idle, then, if this device isn't the one currently programmed for
   its domain, rewrites that domain's timing registers. An unset dst is an error. */
s32 pi_read_word(PiDevice *dev, s32 offset, s32 *dst)
{
  PiDevice *old;
  s32 a;
  if (dst == NULL)
  {
    func_800914E0(&D_800A7170, &D_800A7174, 0x2B);
  }
  if ((*((volatile u32 *) 0xA4600010)) & 3)
  {
    do
    {
    }
    while ((*((volatile u32 *) 0xA4600010)) & 3);
  }
  a = dev->domain;
  old = gPiCurrentDev[a];
  if (old != dev)
  {
    if (a == 0)
    {
      if (old->latency != dev->latency)
      {
        *((volatile u32 *) 0xA4600014) = dev->latency;
      }
      if (old->rel_duration != dev->rel_duration)
      {
        *((volatile u32 *) 0xA460001C) = dev->rel_duration;
      }
      if (old->pulse != dev->pulse)
      {
        *((volatile u32 *) 0xA4600020) = dev->pulse;
      }
      if (old->page_size != dev->page_size)
      {
        *((volatile u32 *) 0xA4600018) = dev->page_size;
      }
    }
    else
    {
      if (old->latency != dev->latency)
      {
        *((volatile u32 *) 0xA4600024) = dev->latency;
      }
      if (old->rel_duration != dev->rel_duration)
      {
        *((volatile u32 *) 0xA460002C) = dev->rel_duration;
      }
      if (old->pulse != dev->pulse)
      {
        *((volatile u32 *) 0xA4600030) = dev->pulse;
      }
      if (old->page_size != dev->page_size)
      {
        *((volatile u32 *) 0xA4600028) = dev->page_size;
      }
    }
    gPiCurrentDev[a] = dev;
  }
  *((s32 *) dst) = *((volatile s32 *) ((dev->addr | offset) | 0xA0000000));
  return 0;
}
