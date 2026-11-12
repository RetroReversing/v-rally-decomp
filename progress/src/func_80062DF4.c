extern unsigned char D_800B0D98;void *textObjGet(u32);
s32 group_set_color();
void draw_palette_sprite(void *, s16, s16, void *);
s32 format_to_buffer();
extern char D_800A567C[];
extern char gOrderState[];

/* Formats D_800B0D98 into a 4-character label and draws it with the text object
 * 5 colour and position. */
void func_80062DF4(void)
{
    s8 label_buf[5];
    void *text_obj;

    text_obj = textObjGet(5);
    group_set_color(text_obj, *((u8 *) (((char *) text_obj) + 0xB)), *((u8 *) (((char *) text_obj) + 0xC)), *((u8 *) (((char *) text_obj) + 0xD)), (s32) (*((u8 *) (((char *) text_obj) + 0xE))));
    label_buf[4] = 0;
    format_to_buffer(label_buf, &D_800A567C, D_800B0D98);
    draw_palette_sprite((void *)(text_obj), (s16)(*((s16 *) (((char *) text_obj) + 6))), (s16)(*((s16 *) (((char *) text_obj) + 8))), (void *)(label_buf));
}
