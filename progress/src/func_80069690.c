extern u8 *gRecords;
void *select_get_entry(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 select_draw_results_table();
extern void *gSelectState;
extern char stream_state[];

/* Draws the current select entry: takes its colour from the entry's sub-record
   (or uses the fixed highlight colour when the entry's flag at +0x42 is set), then
   positions it from the sub-record and calls the follow-up update for the selected index. */
void func_80069690(void)
{
  int rec_off;
  u8 red;
  u8 green;
  u8 blue;
  void *sub;
  void *entry;

  entry = select_get_entry(0);
  sub = *((void **) (((char *) entry) + 0x28));
  red = 0xDC;
  if ((*((u8 *) (((char *) entry) + 0x42))) != 0)
  {
    green = 0xDC;
    blue = 0xE;
  }
  else
  {
    red = *((u8 *) (((char *) sub) + 0xB));
    green = *((u8 *) (((char *) sub) + 0xC));
    blue = *((u8 *) (((char *) sub) + 0xD));
  }
  group_set_color(sub, red, green, blue, 0xFF);
  draw_palette_sprite((void *)(sub), (s16)(*((s16 *) (((char *) sub) + 6))), (s16)(*((s16 *) (((char *) sub) + 8))), (void *)(gRecords + (((*((s8 *) (((char *) gSelectState) + 0x22A))) * 0x28) + (rec_off = 0x44))));
  select_draw_results_table(*((s8 *) (((char *) gSelectState) + 0x22A)));
}
