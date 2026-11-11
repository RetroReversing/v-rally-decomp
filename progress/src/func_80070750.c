extern unsigned char D_800B0D96;
extern unsigned char D_800B0D97;
void *textObjGet(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 formatString();
extern char D_800A5CDC[];

/* Sets the colour of text object 5 from its stored RGBA bytes, then formats the
   sum of the two counters D_800B0D96 and D_800B0D97 into a string and draws it at
   the object's stored position. */
void func_80070750(void)
{
  s8 text[5];
  void *text_obj;

  text_obj = textObjGet(5);
  group_set_color(text_obj, *((u8 *) (((char *) text_obj) + 0xB)), *((u8 *) (((char *) text_obj) + 0xC)), *((u8 *) (((char *) text_obj) + 0xD)), (s32) (*((u8 *) (((char *) text_obj) + 0xE))));
  text[4] = 0;
  formatString(text, &D_800A5CDC, D_800B0D96 + D_800B0D97);
  draw_palette_sprite((void *)(text_obj), (s16)(*((s16 *) (((char *) text_obj) + 6))), (s16)(*((s16 *) (((char *) text_obj) + 8))), (void *)(text));
}
