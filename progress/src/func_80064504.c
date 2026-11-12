void *select_get_entry(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 hud_draw_stats_panel();
s32 race_render_scene();
extern void *gRecords;

/* Walks the linked list of list 1, and for each node draws its item at the
 * position stored in the item, using the record name for each of the
 * gRecords->count entries. Ends with two finishing calls. */
void func_80064504(void)
{
  s32 i;
  void *node;
  void *item;

  node = select_get_entry(1);
  i = 0;
  if (((u16 *) (((char *) gRecords) + 0xE))[0] != 0)
  {
    do
    {
      item = *((void **) (((char *) node) + 0x28));
      if (*((u8 *) (((char *) node) + 0x42)) != 0)
      {
        group_set_color(item, 0xDC, 0xDC, 0xE, *((u8 *) (((char *) item) + 0xE)));
      }
      else
      {
        group_set_color(item, *((u8 *) (((char *) item) + 0xB)), *((u8 *) (((char *) item) + 0xC)), *((u8 *) (((char *) item) + 0xD)), *((u8 *) (((char *) item) + 0xE)));
      }
      draw_palette_sprite((void *)(item), (s16)(*((s16 *) (((char *) item) + 6))), (s16)(*((s16 *) (((char *) item) + 8))), (void *)(((char *) gRecords) + (((((u8 *) (((char *) gRecords) + (i & 0xFF)))[0x32]) * 0x28) + 0x44)));
      i += 1;
      node = *((void **) node);
    } while ((u8) i < *((u16 *) (((char *) gRecords) + 0xE)));
  }
  race_render_scene();
  hud_draw_stats_panel();
}
