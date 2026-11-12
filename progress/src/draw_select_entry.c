typedef struct SelectEntry {
    u8 pad00[4];
    u16 id;
    s16 x;
    s16 y;
    u8 group;
    u8 r, g, b, a;
} SelectEntry;

extern char stream_state[];
void *pool_get_item(s32 pool, u16 id);
void group_set_color(void *owner, u8 r, u8 g, u8 b, u8 a);
void draw_palette_sprite(void *, s16, s16, void *);

/* Draws one select-screen entry at its position. Entry 0x1C7 is never drawn.
 * When highlight is set the group is drawn in the highlight colour, otherwise
 * in the entry's own colour. */
void draw_select_entry(SelectEntry *entry, s32 highlight) {
    if (entry->id != 0x1C7) {
        if (highlight & 0xFF) {
            group_set_color(entry, 0xDC, 0xDC, 0xE, 0xFF);
        } else {
            group_set_color(entry, entry->r, entry->g, entry->b, entry->a);
        }
        draw_palette_sprite(entry, entry->x, entry->y,
                      pool_get_item(*(s32 *)(stream_state + 0x807A), entry->id));
    }
}
