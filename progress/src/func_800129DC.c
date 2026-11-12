extern signed char D_800C8200;
extern short D_800C8202;
extern int D_800C8204;
extern int D_800C820C;
extern int D_800C8208;
extern int D_800C8210;
extern unsigned char D_800C81FD;
extern int D_800C81F8;
extern unsigned short D_800C8236;
extern char stream_state[];
extern char D_8009BA70[];
extern char D_800A40BC[];
extern char D_800A40C4[];
extern char D_800A40D0[];
extern char D_800A40DC[];

s32 make_rect_set();
void rect_set_set_item_pos();
void rect_set_set_scale(s32, f32, f32, f32);
void font_set_color(void *, s32, s32, s32, u8);
s32 getTexturePack();
void resolve_path();
s32 func_80081664();

/* Resets the state block, then builds the two overlay rect sets (each with its
   own loaded resource) at full opacity. If the mode byte is 5, it also loads the
   resource at D_800A40DC and stores its result in D_800C81F8. */
void func_800129DC(void *state)
{
    s32 opacity=255;
    void *rect;
    s32 set_a;
    s32 set_a_rect;
    s32 set_b;
    s32 set_b_rect;

    *(s32 *)((char *)state + 0x8C) = 0;
    *(s16 *)((char *)state + 0x84) = 0;
    D_800C8200 = 0;
    D_800C8202 = 0;
    resolve_path(&D_800A40BC);
    set_a = func_80081664(6, &D_800A40C4);
    D_800C8204 = set_a;
    set_a_rect = make_rect_set(set_a);
    D_800C820C = set_a_rect;
    rect_set_set_scale(set_a_rect, 1.0f, 1.0f, 1.0f);
    rect = *(void **)&D_800C820C;
    font_set_color((void *)(rect), (s32)(opacity), (s32)(opacity), (s32)(opacity), (u8)(opacity));
    rect_set_set_item_pos(D_800C820C, 0x80, 0x30);
    set_b = func_80081664(6, &D_800A40D0);
    D_800C8208 = set_b;
    set_b_rect = make_rect_set(set_b);
    D_800C8210 = set_b_rect;
    rect_set_set_scale(set_b_rect, 1.0f, 1.0f, 1.0f);
    rect = *(void **)&D_800C8210;
    font_set_color((void *)(rect), (s32)(opacity), (s32)(opacity), (s32)(opacity), (u8)(opacity));
    rect_set_set_item_pos(D_800C8210, 0x80, 0x33);
    if (D_800C81FD == 5) {
        resolve_path(&D_800A40DC);
        D_800C81F8 = getTexturePack(*(s32 *)(D_8009BA70 + (D_800C8236 * 4)), 0);
        return;
    }
    D_800C81F8 = 0;
}
