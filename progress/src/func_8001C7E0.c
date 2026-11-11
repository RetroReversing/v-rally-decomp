extern char gOrderState[];
extern char gStreamState[];
extern s32 D_8009CE8C;
extern s32 D_8009CE90;
extern s32 D_8009CE94;

/* Saves three of the object's per-frame values (+0xDC, +0x128, +0x174) into the
 * D_8009CE8C/CE90/CE94 tables at the current slot, when the stream state matches one of
 * the three recording cases (the object's +0x90 type against the stream's track type). */
void func_8001C7E0(void *obj) {
    s32 slot;
    s32 *dst0;
    s32 *dst1;
    s32 *dst2;
    slot = *(s32 *)(*(char **)(*(char **)(gOrderState + 0x23D0) + 0x1C));
    slot &= -(slot != 6);
    if ((u32)slot < 4) {
        if (*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0xE) == 2 &&
            !(*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x12) & 1) &&
            *(s32 *)((char *)obj + 0x90) == 3) {
            dst0 = (s32 *)((char *)&D_8009CE8C + slot * 12);
            dst0[0] = *(s32 *)((char *)obj + 0xDC);
            dst1 = (s32 *)((char *)&D_8009CE90 + slot * 12);
            dst1[0] = *(s32 *)((char *)obj + 0x128);
            dst2 = (s32 *)((char *)&D_8009CE94 + slot * 12);
            dst2[0] = *(s32 *)((char *)obj + 0x174);
        } else if (*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0xE) == *(s32 *)((char *)obj + 0x90) &&
                   (*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x12) & 1) &&
                   *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0xE) == 2) {
            dst0 = (s32 *)((char *)&D_8009CE8C + slot * 12);
            dst0[0] = *(s32 *)((char *)obj + 0xDC);
            dst1 = (s32 *)((char *)&D_8009CE90 + slot * 12);
            dst1[0] = *(s32 *)((char *)obj + 0x128);
            dst2 = (s32 *)((char *)&D_8009CE94 + slot * 12);
            dst2[0] = *(s32 *)((char *)obj + 0x174);
        } else if (*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0xE) == 1 &&
                   *(s32 *)((char *)obj + 0x90) == *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0xE)) {
            dst0 = (s32 *)((char *)&D_8009CE8C + slot * 12);
            dst0[0] = *(s32 *)((char *)obj + 0xDC);
            dst1 = (s32 *)((char *)&D_8009CE90 + slot * 12);
            dst1[0] = *(s32 *)((char *)obj + 0x128);
            dst2 = (s32 *)((char *)&D_8009CE94 + slot * 12);
            dst2[0] = *(s32 *)((char *)obj + 0x174);
        }
    }
}
