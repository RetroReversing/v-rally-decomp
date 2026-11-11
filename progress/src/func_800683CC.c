void *select_get_entry(s32);
void group_set_color(void *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
void func_8006874C(s8);
extern u8 *gSelectState;
extern s32 D_800A1630;
extern u8 gStreamState[];

/* Redraws the selected entry's item, if the selection index is below 4. Then
 * writes any pending value (D_800A1630, -1 when none) into the entry it belongs
 * to, and finishes by updating the selection with the item's index. */
void func_800683CC(void)
{
    u8 *item;
    s32 pending;
    s32 offset;

    if (gSelectState[0x229] < 4)
    {
        item = *(u8 **)((u8 *)select_get_entry(0) + 0x28);
        group_set_color(item, item[11], item[12], item[13], 255);
        offset = (s8) gSelectState[0x229] * 5 * 8 + 0x44;
        draw_palette_sprite((void *)(item), (s16)(*(s16 *)(item + 6)), (s16)(*(s16 *)(item + 8)), (void *)(*(s32 *)(gStreamState + 0x32F2) + offset));
    }
    pending = D_800A1630;
    if (pending != -1)
    {
        u8 *entry = *(u8 **)(gStreamState + 0x325A);
        *(u8 *)(*(s32 *)(entry + 16) + *(s16 *)(entry + 2) * 20 + 14) = pending;
        D_800A1630 = -1;
    }
    {
        u8 *sel = *(u8 **)(gStreamState + 0x32F2);
        sel += (s8) gSelectState[0x229];
        func_8006874C((s8) sel[0x32]);
    }
}
