/* Refreshes the centring offset (+0x70) of object obj from the current state's table entry.
 * When the attached data at +0x24 is present, it sets bit 4 of the flags at +0x80; a data
 * flag 0x100 resets the state index (+0x7A) to 6 and clears bit 4 again. The offset is then
 * minus half the 16-bit size field of the state entry. */
void func_8003F34C(void *obj)
{
  char *p;
  void *data;
  char *tbl;
  s32 idx;

  p = *(char **)((char *)obj + 0xA8);
  data = *(void **)(p + 0x24);
  if (data != NULL)
  {
    *(s32 *)((char *)obj + 0x80) |= 4;
    if (*(s32 *)((char *)data + 0x14) & 0x100)
    {
      *(s16 *)((char *)obj + 0x7A) = 6;
      *(s32 *)((char *)obj + 0x80) &= ~4;
    }
    tbl = *(char **)(*(char **)((char *)obj + 0xA4) + 4);
    idx = *(s16 *)((char *)obj + 0x7A);
    *(s16 *)((char *)obj + 0x70) = -(*(u16 *)(*(char **)(tbl + idx * 4) + 6) >> 1);
  }
}
