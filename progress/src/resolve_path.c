s32 nameNodeFind(s32, u8 *);
/* Resolves a path one component at a time, separated by '\' or '/'. Each component is looked up from the current directory (the handle at 0x800B7304); the final result handle is stored at 0x800B7308. A path that starts with a separator sets the result to the current directory. Returns 1 when the walk succeeds, 0 when a component is not found. */
s32 resolve_path(u8 *path)
{
  u8 component[16];
  s32 dir;
  s32 start;
  s32 at_end;
  s32 len;
  u8 *comp;
  u8 *src;
  u8 *dst;
  u8 ch;
  u8 c;
  u8 first;
  first = *path;
  if (((first == 0x5C) | (first == 0x2F)) != 0)
  {
    *((s32 *) 0x800B7308) = *((s32 *) 0x800B7304);
    return 1;
  }
  dir = *((s32 *) 0x800B7304);
 do { start = 0; at_end = 0; comp = component; len = 0; loop_3: dst = comp; src = (u8 *) (((u32) start) + ((u32) path)); loop_4: c = *src; src += 1; do { start += 1; } while (0); *dst = c; ch = src[-1]; len += 1; dst += 1; if ((ch != 0x5C) & (ch != 0x2F)) { if (ch != 0) { goto loop_4; } } } while (0);
  if ((c = ch) == 0)
  {
    at_end = 1;
    component[len - 1] = 0x2F;
  }
  else
    if ((*src) == 0)
  {
    at_end = 1;
  }
  comp[len] = 0;
  dir = nameNodeFind(dir, component);
  if (dir == 0)
  {
    return 0;
  }
  len = 0;
  if (at_end != 0)
  {
    *((s32 *) 0x800B7308) = dir;
    return 1;
  }
  goto loop_3;
}
