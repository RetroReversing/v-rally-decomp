/* Per-frame update for a race HUD element, using the same layout as func_8003C8A4. While the
 * target's race timer (0x18) is 0x65 or more, it counts down the elements' display state. Below that,
 * it just decrements the timer. Then it looks up the element's track entry and sets its x offset to
 * minus half its width. */
void func_8003F05C(void *object) {
    u8 *hud = object;
    u8 *target;
    u8 *raceInfo;
    s32 flags;
    s32 timer;
    u8 *entryTable;
    u8 *entry;
    s32 index;

    target = *(u8 **)(*(u8 **)(hud + 0xA8) + 0x24);
    if (target != 0) {
        flags = *(s32 *)(hud + 0x80) | 4;
        *(s32 *)(hud + 0x80) = flags;
        raceInfo = *(u8 **)(target + 0x70);
        timer = *(s32 *)(raceInfo + 0x18);
        if (timer >= 0x65) {
            *(s32 *)(hud + 0x80) = flags & ~4;
            *(s16 *)(hud + 0x7A) = *(s32 *)(*(u8 **)(target + 0x70) + 0x10);
            if (*(s32 *)(*(u8 **)(target + 0x70) + 0x14) == 2) {
                *(s32 *)(hud + 0xA0) |= 0x40;
            } else {
                *(s32 *)(hud + 0xA0) &= ~0x40;
            }
            *(s32 *)(*(u8 **)(target + 0x70) + 0x18) -= 1;
        } else {
            if (timer > 0) {
                *(s32 *)(raceInfo + 0x18) = timer - 1;
            }
        }
        entryTable = *(u8 **)(hud + 0xA4);
        index = *(s16 *)(hud + 0x7A);
        entry = *(u8 **)(*(s32 *)(entryTable + 4) + index * 4);
        *(s16 *)(hud + 0x70) = -(*(u16 *)(entry + 6) >> 1);
    }
}
