typedef void (*SpriteHook)(void *);
void add_label_sprites(s32,s32,s32,SpriteHook,u8*,u16,u8*);
extern char gStreamState[];
void timer_display_update(void *);

/* Places the timer labels for the HUD mode in hud->mode (offset 0xE): mode 1 sets the label
 * positions from the layout box (offset 0x178 of the context), mode 2 places them only while
 * the state at 0x1E is zero, then draws them at (x, y) with timer_display_update. */
void func_8003D8F4(s32 owner, s32 sprites) {
    char *ctx;
    char *layout;
    char *hud;
    s32 x;
    s32 xAlt;
    s32 y;
    s32 dy;

    ctx = *((char **)(gStreamState + 0x7CD6));
    layout = *((char **)(ctx + 0x178));
    x = *((s16 *)(layout + 8));
    xAlt = x + 0x14;
    y = (*((s16 *)(layout + 0xA))) + 6;
    dy = (*((s16 *)(layout + 0xE))) - 8;
    hud = *((char **)(gStreamState + 0x32F2));
    switch (*((u16 *)(hud + 0xE))) {
    case 1:
        if ((*((u16 *)(hud + 0x1E))) == 0) {
            x += 0x4A;
            add_label_sprites((s32)(owner), x, y, &timer_display_update, (u8 *)(sprites), 0, 0);
            return;
        } else {
            x += 0x1C;
            y = y + dy - 0xE;
        }
        add_label_sprites((s32)(owner), x, y, &timer_display_update, (u8 *)(sprites), 0, 0);
        break;
    case 2:
        if ((*((u16 *)(hud + 0x1E))) != 0) {
            return;
        }
        if (*((u16 *)(hud + 0x12)) & 1) {
            y = y + dy;
        } else {
            if ((*((s32 *)(ctx + 0xC))) == 3) {
                xAlt = x + 4;
            }
            x = xAlt;
            y += dy;
        }
        y -= 0x1A;
        add_label_sprites((s32)(owner), x, y, &timer_display_update, (u8 *)(sprites), 0, 0);
        break;
    }
}
