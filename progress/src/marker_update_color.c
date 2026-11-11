/* Sets the RGBA colour at +0x90 of the marker: a highlight colour when the marker's id (+0x7A)
   matches the id of the current entry in the chain at +0xA8, otherwise plain white. Does nothing
   if the chain has no current entry or that entry's state at +0x20 is not 0. */
void marker_update_color(void *marker)
{
  void *temp_v0;
  void *temp_a1;

  temp_v0 = *((void **) (((char *) marker) + 0xA8));
  temp_v0 = *((void **) (((char *) temp_v0) + 0x24));
  if (temp_v0 != NULL)
  {
    temp_a1 = *((void **) (((char *) temp_v0) + 0x6C));
    if (*((s32 *) (((char *) temp_a1) + 0x20)) == 0)
    {
      if (*((s16 *) (((char *) marker) + 0x7A)) == *((s32 *) (((char *) temp_a1) + 8)))
      {
        *((u8 *) (((char *) marker) + 0x90)) = 0xFE;
        *((u8 *) (((char *) marker) + 0x91)) = 0xD5;
        *((u8 *) (((char *) marker) + 0x92)) = 0x1E;
        *((u8 *) (((char *) marker) + 0x93)) = 0xFF;
      }
      else
      {
        *((u8 *) (((char *) marker) + 0x90)) = 0xFF;
        *((u8 *) (((char *) marker) + 0x91)) = 0xFF;
        *((u8 *) (((char *) marker) + 0x92)) = 0xFF;
        *((u8 *) (((char *) marker) + 0x93)) = 0xFF;
      }
    }
  }
}
