void *select_get_entry(s32);
void group_set_color(void *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
void select_draw_results_table(s8);
extern u8 *gSelectState;
extern s32 D_800A1630;
extern u8 stream_state[];

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
        #ifdef PORT
        draw_palette_sprite((void *)(item), (s16)(*(s16 *)(item + 6)), (s16)(*(s16 *)(item + 8)), (void *)((uintptr_t)*(s32 *)(stream_state + 0x32F2) + offset));
#else
        draw_palette_sprite((void *)(item), (s16)(*(s16 *)(item + 6)), (s16)(*(s16 *)(item + 8)), (void *)(*(s32 *)(stream_state + 0x32F2) + offset));
#endif
    }
    pending = D_800A1630;
    if (pending != -1)
    {
        u8 *entry = *(u8 **)(stream_state + 0x325A);
        #ifdef PORT
        *(u8 *)((uintptr_t)*(s32 *)(entry + 16) + *(s16 *)(entry + 2) * 20 + 14) = pending;
#else
        *(u8 *)(*(s32 *)(entry + 16) + *(s16 *)(entry + 2) * 20 + 14) = pending;
#endif
        D_800A1630 = -1;
    }
    {
        u8 *sel = *(u8 **)(stream_state + 0x32F2);
        sel += (s8) gSelectState[0x229];
        select_draw_results_table((s8) sel[0x32]);
    }
}
