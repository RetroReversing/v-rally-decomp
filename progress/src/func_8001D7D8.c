void font_set_color(void *, s32, s32, s32, u8);
extern s32 D_800B6170;
extern void *D_800C3524;

/* If D_800B6170 is set, applies the colour from record fields +0x93 (r), +0xDF (g),
 * +0x12B (b) and +0x177 (a) to the item at D_800C3524. */
void func_8001D7D8(void *rec) {
    if (D_800B6170 != 0) {
        font_set_color(D_800C3524, (s32)((u8)(*(u8 *)((char *)rec + 0x93))), (s32)((u8)(*(u8 *)((char *)rec + 0xDF))), (s32)((u8)(*(u8 *)((char *)rec + 0x12B))), (u8)((s32) *(u8 *)((char *)rec + 0x177)));
    }
}
