s32 hud_spawn_sprite_group();
extern char stream_state[];

/* For each entry in the stream state's active list (count at +0xE, entries from +1), when the entry's
 * state byte at +0x1E is not 7 and the entry's group record has flag 2 set, spawns a sprite group for it. */
void func_8003E628(s32 arg0, s32 arg1)
{
  char *record;
  s32 index;
  s32 i;
  u16 count;
  if ((*((u16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0x1E))) != 7)
  {
    count = *((u16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0xE));
    i = 1;
    if (count != 0)
    {
      do
      {
        index = i & 0xFFFF;
        record = (char *) ((*((void **) (stream_state + 0x32F2))) + ((*((u8 *) (((char *) ((*((void **) (stream_state + 0x32F2))) + index)) + 0x31))) * 0x28));
        if ((*((u8 *) (record + 0x48))) & 2)
        {
          hud_spawn_sprite_group(arg0, arg1, index);
        }
        i += 1;
      }
      while (count >= ((u32) (i & 0xFFFF)));
    }
  }
}
