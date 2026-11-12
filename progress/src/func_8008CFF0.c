extern u32 osRomBase;
extern char rom_read_assert_file[];
extern char rom_read_assert_msg[];
s32 func_800914E0(void *, void *, s32);

/* Reads one 32-bit word from the cartridge (ROM) at romOffset, relative to osRomBase,
 * through the uncached cart window, into *dst. Waits until the PI DMA/IO is idle first.
 * Asserts when dst is NULL. Always returns 0. */
s32 func_8008CFF0(s32 romOffsetArg, s32 *dstArg)
{
  s32 *dst;
  s32 romOffset;
  romOffset = romOffsetArg;
  dst = dstArg;
  if (dst == NULL)
  {
    func_800914E0(rom_read_assert_file, rom_read_assert_msg, 0x3D);
  }
  while ((*((vu32 *) 0xA4600010)) & 3)
  {
  }

#ifdef PORT
  *dst = *((s32 *) (uintptr_t) (((*((u32 *) &osRomBase)) | romOffset) | 0xA0000000));
#else
  *dst = *((s32 *) (((*((u32 *) &osRomBase)) | romOffset) | 0xA0000000));
#endif
  do { } while (0);
  return 0;
}
