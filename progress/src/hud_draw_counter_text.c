extern u8 D_800B0D94;
extern u8 D_800B0D95;
extern char D_800A56BC[];
void *textObjGet(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 format_to_buffer();

/* Draws the counter text object 5: sets its colour from bytes +0xB..+0xE, formats the
 * sum of two counter bytes into a 4-character buffer, then draws the object at its
 * position (+6, +8) with that buffer. */
void hud_draw_counter_text(void)
{
    s8 buf[5];
    void *text;

    text = textObjGet(5);
    group_set_color(text, *((u8 *)(((char *)text) + 0xB)), *((u8 *)(((char *)text) + 0xC)), *((u8 *)(((char *)text) + 0xD)), (s32)(*((u8 *)(((char *)text) + 0xE))));
    buf[4] = 0;
    format_to_buffer(buf, &D_800A56BC, D_800B0D94 + D_800B0D95);
    draw_palette_sprite((void *)(text), (s16)(*((s16 *)(((char *)text) + 6))), (s16)(*((s16 *)(((char *)text) + 8))), (void *)(buf));
}
