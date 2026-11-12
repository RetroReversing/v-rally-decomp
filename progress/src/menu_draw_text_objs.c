extern u8 stream_state[];
extern u8 *gSelectState;
extern s32 gSelectStepHandle;
void *pool_get_item(s32, s32);
void *textObjGet(u32);
void group_set_color(void *, u32, u32, u32, u32);
void draw_palette_sprite(void *, s16, s16, void *);
void text_obj_highlight(s32);

typedef struct {
    s32 w[4];
} Args;

/* Draws every text object in the list (count in arg5). The selected object is
 * drawn in the highlight colour; when fade_flag is set, unselected objects are
 * dimmed to half brightness and marked with text_obj_highlight. Each object is
 * then drawn at its stored x/y with the texture from pool_get_item. */
void menu_draw_text_objs(Args args, s32 arg4, s32 count) {
    u8 idx;
    u8 *obj;
    s32 fade_flag;

    fade_flag = *((u8 *)&args + 0x2C7);
    idx = 0;
    if (*(u16 *)&count != 0) {
        do {
            obj = textObjGet(idx);
            if (idx == *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x22) && gSelectState[0x245] != 0) {
                group_set_color(obj, 0xDC, 0xDC, 0xE, 0xFF);
            } else {
                if (fade_flag != 0 && (*(u8 *)(stream_state + 0x327E + *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x20)) & (1 << idx)) != (1 << idx)) {
                    group_set_color(obj, obj[0xB] >> 1, obj[0xC] >> 1, obj[0xD] >> 1, obj[0xE] >> 1);
                    text_obj_highlight(idx);
                } else {
                    group_set_color(obj, obj[0xB], obj[0xC], obj[0xD], obj[0xE]);
                }
            }
            draw_palette_sprite((void *)(obj), (s16)(*(s16 *)(obj + 6)), (s16)(*(s16 *)(obj + 8)), (void *)(pool_get_item(gSelectStepHandle, ((u8 *)&args)[idx * 64 + 0x37] + 0x1E4)));
            idx++;
        } while (idx < *(u16 *)&count);
    }
}
