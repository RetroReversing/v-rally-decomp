extern char gOrderState[];
extern char gStreamState[];
s32 make_rect_set();
s32 rect_set_set_item_pos();
void rect_set_set_scale(s32, f32, f32, f32);
void func_8000C22C(void *, s32, s32, s32, u8);

/* Sets up a HUD object: stores the stream's id and creates its rect set (at +0x40),
 * sets it to white with full alpha, then fills 12 pairs of 16-bit positions (x from 0x20
 * in steps of 8, y from -0x140) and sets the value at +0x3C from the gOrderState block
 * (0 unless it is 1). Marks the object active (+0x48 = 1). */
void func_80073640(char *obj) {
    s32 xPos;
    s32 yPos;
    u32 i;

    *(s32 *)(obj + 0x44) = *(s32 *)(gStreamState + 0x103BA);
    *(s32 *)(obj + 0x40) = make_rect_set(*(s32 *)(gStreamState + 0x103BA));
    rect_set_set_scale(*(s32 *)(obj + 0x40), 1.0f, 1.0f, 1.0f);
    func_8000C22C((void *)(*(s32 *)(obj + 0x40)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    rect_set_set_item_pos(*(s32 *)(obj + 0x40), 0x80, 0x30);
    i = 0;
    yPos = -0x140;
    xPos = 0x20;
    do {
        *(s16 *)(obj + 0xC + i * 2) = xPos;
        xPos += 8;
        *(s16 *)(obj + 0x24 + i * 2) = yPos;
        i++;
    } while (i < 0xC);
    if (*(s32 *)(gOrderState + 0x8030) != 1) {
        *(s32 *)(obj + 0x3C) = 0;
    } else {
        *(s32 *)(obj + 0x3C) = *(s32 *)(gOrderState + 0x8030);
    }
    *(s32 *)(obj + 0x48) = 1;
}
