/* Reads a 1- or 2-byte packed value from src (a set high bit marks the two-byte form) and stores it at obj+0xA4. Returns the advanced src. */
void *decodeVarLenAndStore(void *obj, u8 *src)
{
  u8 first;
  s32 high;
  s32 second;

  first = *src++;
  if (first < 0x80)
  {
    *(s16 *)((u8 *)obj + 0xA4) = first;
  }
  else
  {
    high = (first & 0x7F) << 8;
    *(s16 *)((u8 *)obj + 0xA4) = high;
    second = *src++;
    *(s16 *)((u8 *)obj + 0xA4) = high + second;
  }
  return src;
}
