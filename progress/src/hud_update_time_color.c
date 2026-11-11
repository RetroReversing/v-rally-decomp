typedef struct HudItem {
    u8 pad00[0x80];
    s32 flags;
    u8 pad84[0x0C];
    u8 r, g, b, a;
    u8 pad94[0x14];
    void *parent;
} HudItem;

/* Sets the colour of a HUD time display from the time value of its parent's
 * record: a good time is green, a bad one is red. The item's flag bit 4 is
 * set while the colour is updated and cleared afterwards. */
void hud_update_time_color(HudItem *item)
{
    s32 time;
    void *rec;

    rec = *(void **)((char *)item->parent + 0x24);
    if (rec) {
        item->flags |= 4;
        time = *(s32 *)((char *)*(void **)((char *)rec + 0x6C) + 12);
        if (time > 0x36EE80) {
            do {
                if (time <= 0x36EE89) {
                    item->r = 10;
                    item->g = 200;
                    item->b = 10;
                    item->a = 255;
                } else {
                    item->r = 250;
                    item->g = 50;
                    item->b = 10;
                    item->a = 255;
                }
            } while (0);
            item->flags &= ~4;
        }
    }
}
