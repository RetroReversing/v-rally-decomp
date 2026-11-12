typedef void (*SpriteHook)(void *);
void add_label_sprites(s32,s32,s32,SpriteHook,u8*,u16,u8*);
extern char stream_state[];
void func_8003AD18(void *);

/* Adds the position label sprites for the HUD of one view (arg0), using the view's text
 * block (arg1). The layout depends on the HUD mode (1 or 2) and whether the label is
 * shown with its value (hud + 0x1E != 0). */
void hudAddLabels(s32 view, u8 *text)
{
    u8 col[4];
    u8 *car;
    u8 *hud;
    s32 x;
    s32 xr;
    s32 y;
    s32 yr;
    s32 xl;
    s32 yl;
    s32 mode;

    car = *(u8 **)(stream_state + 0x7CD6);
    x = *(s16 *)(*(u8 **)(car + 0x178) + 8);
    y = *(s16 *)(*(u8 **)(car + 0x178) + 0xA);
    yr = *(s16 *)(*(u8 **)(car + 0x178) + 0xC);
    xr = *(s16 *)(*(u8 **)(car + 0x178) + 0xE);
    col[0] = 0xFE;
    col[1] = 0xD5;
    col[2] = 0x1E;
    col[3] = 0xFF;
    hud = *(u8 **)(stream_state + 0x32F2);
    mode = *(u16 *)(hud + 0xE);
    xl = x + 0x14;
    yl = y + 6;
    switch (mode) {
    case 1:
        if (*(u16 *)(hud + 0x1E) == 0) {
            yl = *(s16 *)(*(u8 **)(car + 0x178) + 0xA) + xr - 0x12;
            add_label_sprites((s32)(view), xl, yl, &func_8003AD18, (u8 *)(text), 0, col);
        } else {
            add_label_sprites((s32)(view), yr - 0x4A, yl, &func_8003AD18, (u8 *)(text), 0, 0);
        }
        break;
    case 2:
        if (*(u16 *)(hud + 0x1E) == 0) {
            yl = *(s16 *)(*(u8 **)(car + 0x178) + 0xA) + 2;
            if (*(u16 *)(hud + 0x12) & 1) {
                xl = x + 0x14;
            } else if (*(s32 *)(car + 0xC) == 3) {
                xl = x + 0x18;
            } else {
                xl = x + 0x28;
            }
            xl -= 0x14;
            yl = yl + xr - 0x14;
            add_label_sprites((s32)(view), xl, yl, &func_8003AD18, (u8 *)(text), 0, col);
        } else {
            if (*(u16 *)(hud + 0x12) & 1) {
                if (*(s32 *)(car + 0xC) == 3) {
                    yl = y + 4;
                }
                xl = x;
                yl += xr;
                yl -= 0x11;
            } else {
                if (*(s32 *)(car + 0xC) == 3) {
                    xl = x + 6;
                }
                yl = xr - 0x1C;
            }
            add_label_sprites((s32)(view), xl, yl, &func_8003AD18, (u8 *)(text), 0, 0);
        }
        break;
    }
}
