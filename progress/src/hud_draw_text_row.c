void *textObjGet(u32);
s32 group_set_color(void *, s32, s32, s32, s32);
void draw_palette_sprite(void *, s16, s16, void *);
extern s32 D_800A550C;

/* Sets text object 0 to opaque red, then draws the string D_800A550C with the object's
   own x (+6) and y (+8, plus 0x10) position. */
void hud_draw_text_row(void)
{
    void *text;

    text = textObjGet(0);
    group_set_color(text, 0xFF, 0, 0, 0xFF);
    draw_palette_sprite(text, (s16)(*(s16 *)((char *)text + 6)), (s16)((s16)(*(u16 *)((char *)text + 8) + 0x10)), (void *)(&D_800A550C));
}
