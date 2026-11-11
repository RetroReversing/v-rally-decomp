extern s32 D_800B7070; extern u32 gRecordTimeScale; extern u8 D_800A54B0[]; extern u8 gStreamState[];void *textObjGet(u32); extern s32 group_set_color(void *,u8,u8,u8,s32); void draw_palette_sprite(void *, s16, s16, void *); extern s32 formatString(s32 *,u8 *,s32);

/* Counts the timer down by one tick per call (once it reaches zero it stops the timer
 * entry), then formats the seconds value into a string and draws it with text object 5. */
void func_8005E6AC(void)
{
 s32 text_len;
 u8 *stream_entry;
 u8 *timer_entry;
 s32 remaining;
 void *text;
 u32 seconds;

 stream_entry = *(u8 **)(gStreamState + 0x325A);
 timer_entry = *(u8 **)(stream_entry + 0x10) + *(s16 *)(stream_entry + 2) * 20;
 if (D_800B7070 > 0)
 {
  remaining = D_800B7070 - 1;
  D_800B7070 = remaining;
  if (remaining == 0)
  {
   *(s32 *)(timer_entry + 0x10) = 1;
   *(s16 *)(stream_entry + 4) = 0;
  }
 }
 else
 {
  *(s32 *)(timer_entry + 0x10) = 1;
 }
 seconds = D_800B7070 / gRecordTimeScale;

 formatString(&text_len, D_800A54B0, seconds & 0xffff);
 text = textObjGet(5);
 group_set_color(text, *((u8 *)text + 0xB), *((u8 *)text + 0xC), *((u8 *)text + 0xD), *((u8 *)text + 0xE));
 draw_palette_sprite((void *)(text), (s16)(*(s16 *)((u8 *)text + 6)), (s16)(*(s16 *)((u8 *)text + 8)), (void *)(&text_len));
}
