/* Scales the stream's rect when the order flag in gOrderState is set. */
void rect_set_set_scale(void *rect, f32 sx, f32 sy, s32 sz);
extern u8 gOrderState[];
extern u8 gStreamState[];

void order_apply_rect_scale(void *obj) {
    if (*(s32 *)(gOrderState + 0x7920) != 0) {
        rect_set_set_scale(*(void **)(gStreamState + 0x3276), (f32) *(s32 *)((u8 *)obj + 0x90), (f32) *(s32 *)((u8 *)obj + 0xDC), 0);
    }
}
