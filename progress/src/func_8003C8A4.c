s32 func_8003A594(void *, s32, s32);
s32 format_to_buffer(void *, void *, s32);
extern u8 D_8009FE30[];
extern u8 D_800A4B40[];
extern u8 *g_camera;

/* Updates a race HUD element from the camera's target. While the target's 0x300 flags are clear, it
 * shows the target's place (formatting the digits the first time), and otherwise it flags the element
 * as hidden (bit 4 of the HUD flags, cleared on the visible path). */
void func_8003C8A4(void *hud) {
    s32 place;
    u8 *target;
    s32 flags;

    target = *(u8 **)(g_camera + 0x24);
    if (target != NULL) {
        flags = *(s32 *)(((u8 *)hud) + 0x80) & ~4;
        *(s32 *)(((u8 *)hud) + 0x80) = flags;
        if (!(*(s32 *)(target + 0x14) & 0x300)) {
            place = *(s32 *)(*(u8 **)(target + 0x6C) + 0x10);
            if (*(u16 *)(((u8 *)hud) + 0x78) == 0) {
                format_to_buffer(D_8009FE30, D_800A4B40, (s16) place);
            }
            func_8003A594(((u8 *)hud), (s16) place, 1 - *(u16 *)(((u8 *)hud) + 0x78));
            *(s16 *)(((u8 *)hud) + 0x7A) = D_8009FE30[*(u16 *)(((u8 *)hud) + 0x78)] - 0x30;
            return;
        }
        *(s32 *)(((u8 *)hud) + 0x80) = flags | 4;
    }
}
