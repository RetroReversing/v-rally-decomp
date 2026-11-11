extern s32 gStreamState;
extern s32 gOrderState;
extern s32 make_rect_set(s32);
extern void rect_set_set_scale(s32, f32, f32, f32);
extern void rect_set_set_item_pos(s32, s32, s32);

/* Builds the HUD rectangle set from the rectangle list in the stream state (at +0x103BA),
 * stores it in the HUD state (gOrderState), scales it by 1.0 and places its item at (0x80, 0x30).
 * Also sets the HUD's 0x2EE and 0 fields and clears the stream's +0x8116 flag and sets +0x8117
 * to 0x19. */
void rect_hud_setup(void) {
    s32 rect_list;
    s32 rect_set;
    f32 one;

    rect_list = *(s32 *)((s8 *)&gStreamState + 0x103BA);
    *(s32 *)((s8 *)&gOrderState + 0x1CFC) = rect_list;
    rect_set = make_rect_set(rect_list);
    one = 1.0f;
    *(s32 *)((s8 *)&gOrderState + 0x1D00) = rect_set;
    rect_set_set_scale(rect_set, one, one, one);
    rect_set_set_item_pos(*(s32 *)((s8 *)&gOrderState + 0x1D00), 0x80, 0x30);
    *(s16 *)((s8 *)&gOrderState + 0x1D04) = 0x2EE;
    *(s16 *)((s8 *)&gOrderState + 0x1D06) = 0;
    *((s8 *)&gStreamState + 0x8116) = 0;
    *((s8 *)&gStreamState + 0x8117) = 0x19;
}
