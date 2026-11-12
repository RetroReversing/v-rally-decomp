extern u32 D_800A49D0;
u8 *textSkipToEntry();
u8 *func_8002B344();
u8 *func_8002B540();
s32 resolve_path();
u32 func_80081664();
s32 heap_free_stub();
s32 order_lookup_info();

/* Loads a file's text into a buffer, upper-cases its letters, then runs the two
 * parsing passes over it. With a second argument, also checks the second pass and
 * returns 0 on failure. Returns 1 on success. */
s32 text_load_and_parse(u8 *name, u8 *key)
{
  u32 length;
  u32 sp14;
  u8 *start;
  u32 flag;
  u8 *end;
  u8 *p;
  s32 c;
  resolve_path(&D_800A49D0);
#ifdef PORT
  start = (u8 *)(uintptr_t) func_80081664(1, name);
#else
  start = (u8 *) func_80081664(1, name);
#endif
  order_lookup_info(name, &length, &sp14);
  end = start + length;
  {
    for (p = start; p < end; p++)
    {
      c = *p;
      if (((u32) (c - 0x61)) < 0x1A)
      {
        *p = c & (~0x20);
      }
    }

  }
  p = textSkipToEntry(start, end, (u8 *) (&flag));
  if ((*((u8 *) (&flag))) != 0)
  {
    p = func_8002B540(p, end);
  }
  if (key != NULL)
  {
    p = func_8002B344(p, (0, end), key, (u8 *) (&flag));
    if ((*((u8 *) (&flag))) == 0)
    {
      heap_free_stub(start);
      return 0;
    }
    func_8002B540(p, end);
  }
  heap_free_stub(start);
  return 1;
}
