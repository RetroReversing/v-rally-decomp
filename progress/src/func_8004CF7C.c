void *list_nth_node(void *, s32);
s32 func_8004CEB4(s32, void *, s16 *, u8, s32, s32, s32, s32, s32);
extern void *gStreamList;

#define NODE_Q(t) (*(void ***)((u8 *)*(void ***)((u8 *)(t) + 0xC) + 4))

/* Draws a sprite for the object with id itemId from the list at gStreamList. The sprite's
 * position is (x, y) and its size comes from the object's w/h scaled by scale. */
void func_8004CF7C(s32 drawCtx, u16 itemId, s16 x, s16 y, f32 scale, u8 alpha, u16 colour) {
    s16 rect[4];
    void *found;
    u8 alphaByte;
    s32 colourByte;
    alphaByte = alpha;
    colourByte = colour;
    found = list_nth_node(gStreamList, itemId);
    if (found != NULL) {
        rect[0] = x;
        rect[1] = y;
        rect[2] = (s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(found) + 6) * scale);
        rect[3] = (s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(found) + 8) * scale);
        func_8004CEB4(drawCtx, *NODE_Q(found), rect, alphaByte, colourByte & 0xFF, colourByte & 0xFF, colourByte & 0xFF, colourByte & 0xFF, 0);
    }
}
