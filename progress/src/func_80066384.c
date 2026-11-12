void *select_get_entry(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 hud_draw_stats_panel();
s32 race_render_scene();
extern char stream_state[];
static inline u16 *stream_count_ptr(char *stream)
{
  return (u16 *) (((char *) (*((void **) (stream + 0x32F2)))) + 0xE);
}

/* Draws list 1 the same way as draw_record_list, but only when the stream has at least one
 * record. Runs the two finishing draw calls first. */
void func_80066384(void)
{
  s32 index;
  void *list_node;
  void *item;
  u8 red;
  u8 green;
  u8 blue;
  u8 alpha;

  race_render_scene();
  hud_draw_stats_panel();
  list_node = select_get_entry(1);
  index = 0;
  if (*stream_count_ptr(stream_state) == 0)
  {
    return;
  }
  do
  {
    item = *((void **)((char *)list_node + 0x28));
    if (*((u8 *)list_node + 0x42) != 0)
    {
      red = 0xDC;
      green = 0xDC;
      blue = 0xE;
      alpha = *((u8 *)item + 0xE);
      group_set_color(item, red, green, blue, alpha);
    }
    else
    {
      red = *((u8 *)item + 0xB);
      green = *((u8 *)item + 0xC);
      blue = *((u8 *)item + 0xD);
      alpha = *((u8 *)item + 0xE);
      group_set_color(item, red, green, blue, alpha);
    }
    draw_palette_sprite((void *)(item), (s16)(*((s16 *)((char *)item + 6))), (s16)(*((s16 *)((char *)item + 8))),
                  (void *)(*((char **)(stream_state + 0x32F2)) + 0x44 + 0x28 * *((u8 *)*((char **)(stream_state + 0x32F2)) + (index & 0xFF) + 0x32)));
    index += 1;
    list_node = *((void **)list_node);
  } while ((u32)(index & 0xFF) < (u32)*stream_count_ptr(stream_state));
}
