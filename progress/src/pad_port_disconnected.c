extern unsigned char gContPort0Found;
extern void *gControllerInputContext;

/* Returns 1 if the controller in slot arg0 reports not-connected (bit 3 of its status byte clear); when port 0 has no controller it returns 0. */
s32 pad_port_disconnected(s32 slot)
{
  u8 *status;
  int bit;

  if (gContPort0Found != 0)
  {
    status = (u8 *) (((char *) (gControllerInputContext) + ((slot & 0xFF) * 4)) + 0xF);
    bit = 8;
    return ((*status) & bit) == 0;
  }
  if (gContPort0Found || gControllerInputContext)
  {
    return 0;
  }
  else
  {
    return 0;
  }
  if (1)
  {
    do
    {
    }
    while (0);
  }
}
