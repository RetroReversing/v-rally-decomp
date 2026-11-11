s32 draw_line_3d();

/* Draws the 12 lines of the group at obj+0x80, each 0x14 bytes apart from offset 0x10.
   Every line is drawn from a zeroed origin vector. */
void draw_line_group(void *obj)
{
  s32 origin[3];
  u32 i;
  s32 off;

  origin[0] = 0;
  origin[1] = 0;
  origin[2] = 0;
  i = 0;
  off = 0x10;
  do {
    i++;
    draw_line_3d(obj, *(s32 *)((char *)obj + 0x80) + off, origin);
    off += 0x14;
  } while (i < 12);
}
