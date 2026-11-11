void *select_get_entry(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 func_8006090C();
s32 func_8006A438();
extern void *gRecords;

/* Draws every node of list 1 with its item's colour and position, then runs the two
 * finishing draw calls. The node's flag byte at +0x42 picks a fixed colour and size. */
void func_80072364(void)
{
  s32 index;
  void *list_node;
  void *item;

  list_node = select_get_entry(1);
  index = 0;
  if (((u16 *) (((char *) gRecords) + 0xE))[0] != 0)
  {
    do
    {
      item = *((void **) (((char *) list_node) + 0x28));
      if (*((u8 *) (((char *) list_node) + 0x42)) != 0)
      {
        group_set_color(item, 0xDC, 0xDC, 0xE, *((u8 *) (((char *) item) + 0xE)));
      }
      else
      {
        group_set_color(item, *((u8 *) (((char *) item) + 0xB)), *((u8 *) (((char *) item) + 0xC)), *((u8 *) (((char *) item) + 0xD)), *((u8 *) (((char *) item) + 0xE)));
      }
      draw_palette_sprite((void *)(item), (s16)(*((s16 *) (((char *) item) + 6))), (s16)(*((s16 *) (((char *) item) + 8))), (void *)(((char *) gRecords) + (((((u8 *) (((char *) gRecords) + (index & 0xFF)))[0x32]) * 0x28) + 0x44)));
      index += 1;
      list_node = *((void **) list_node);
    } while ((u8) index < *((u16 *) (((char *) gRecords) + 0xE)));
  }
  func_8006A438();
  func_8006090C();
}
