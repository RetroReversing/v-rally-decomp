extern unsigned char D_800B6819;
extern u8 *gRecords;void *textObjGet(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 format_to_buffer();
extern u8 *gSelectState;
extern char D_800A5D30[];
extern char D_800A5D38[];
extern char D_800A5D40[];
extern char gOrderState[];
extern char stream_state[];
/* Draws the HUD readout rows: four rows of text, each with a label and a record value,
 * plus per-item entries when the record count is non-zero. */
void func_80072984(void)
{
  char text_buf[44];
  s32 rec_base;
  u32 n_items;
  s32 has_items;
  u8 *flags;
  s32 row_count;
  s32 slot_base;
  s32 row_i;
  u8 j;
  u8 row;
  u32 cnt;
  s32 row_copy;
  u8 *row_flags;
  u8 *rec_tbl;
  s32 rec_idx;
  s32 rec_ofs;
  void *hdr_obj;
  void *val_obj;
  flags = (u8 *) (gSelectState + 0x24F);
  if (D_800B6819 != 0)
  {
    row_count = 4;
    slot_base = 8;
  }
  else
  {
    row_count = 8;
    slot_base = 0;
  }
  hdr_obj = textObjGet(0);
  val_obj = textObjGet(1);
  row = 0;
  cnt = row_count & 0xFF;
  n_items = cnt;
  has_items = cnt != 0;
  rec_base = slot_base & 0xFF;
  do
  {
    row_i = row;
    format_to_buffer(&text_buf, &D_800A5D30, *((u16 *) ((gOrderState + 0x7DB2) + (row_i * 4))));
    group_set_color(hdr_obj, 0xFFU, 0xFFU, 0x40U, (s32) (*((u8 *) (((char *) hdr_obj) + 0xE))));
    draw_palette_sprite((void *)(val_obj), (s16)(*((s16 *) (((char *) val_obj) + 6))), (s16)((s16) ((*((u16 *) (((char *) val_obj) + 8))) + ((flags + row_i)[1] << 5))), (void *)(&text_buf));
    rec_tbl = gRecords;
    rec_idx = *((u8 *) (((char *) (rec_tbl + row_i)) + 0x32));
    rec_ofs = rec_idx * 0x28;
    rec_ofs += 0x44;
    format_to_buffer(&text_buf, &D_800A5D38, flags[row_i + 1] + 1, rec_tbl + rec_ofs);
    draw_palette_sprite((void *)(hdr_obj), (s16)(*((s16 *) (((char *) hdr_obj) + 6))), (s16)((s16) ((*((u16 *) (((char *) hdr_obj) + 8))) + (flags[row_i + 1] << 5))), (void *)(&text_buf));
    j = 0;
    if (has_items != 0)
    {
      row_copy = row_i;
      row_flags = &flags[row_i];
      do
      {
        row_i = j & 0xFF;
        if ((*((u16 *) (((rec_base + row_i) * 2) + (gOrderState + 0x7DC0)))) != 0)
        {
          format_to_buffer(&text_buf, &D_800A5D40, (u16) (*((u8 *) (((char *) (((row_i * 4) + flags) + row_copy)) + 9))));
          group_set_color(hdr_obj, *((u8 *) (((char *) hdr_obj) + 0xB)), *((u8 *) (((char *) hdr_obj) + 0xC)), *((u8 *) (((char *) hdr_obj) + 0xD)), (s32) (*((u8 *) (((char *) hdr_obj) + 0xE))));
          draw_palette_sprite((void *)(hdr_obj), (s16)((s16) ((((u16) (*((s16 *) (((char *) hdr_obj) + 6)))) + (row_i * 0x2A)) + 0x44)), (s16)((s16) ((*((u16 *) (((char *) hdr_obj) + 8))) + (row_flags[1] << 5))), (void *)(&text_buf));
        }
        j += 1;
      }
      while (((u32) (j & 0xFF)) < n_items);
    }
    row += 1;
  }
  while (((u32) (row & 0xFF)) < 4U);
}
