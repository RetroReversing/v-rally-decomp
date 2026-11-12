void *func_8002B180();

/* Skips to the next text entry from `pos` via func_8002B180. Sets *isSection to 0 at end of text or on a '[' section header, otherwise 1. Returns the new position. */
#ifdef PORT
uintptr_t textSkipToEntry(s8 *pos, uintptr_t end, s8 *isSection)
#else
u32 textSkipToEntry(s8 *pos, u32 end, s8 *isSection)
#endif
{
  s8 *var_a0;
  var_a0 = func_8002B180(pos);
#ifdef PORT
  if (((uintptr_t) var_a0) >= end)
#else
  if (((u32) var_a0) >= end)
#endif
  {
    *isSection = 0;
 do { var_a0 = (s8 *) end; } while (0);
  }
  else
    if ((*var_a0) == 0x5B)
  {
    *isSection = 0;
  }
  else
  {
    *isSection = 1;
  }
#ifdef PORT
  return (uintptr_t) var_a0;
#else
  return (u32) var_a0;
#endif
}
