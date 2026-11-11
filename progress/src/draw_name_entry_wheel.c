typedef struct Draw { s32 pad[4]; s32 x[4]; s32 y[4]; s32 id[4]; u8 r[4]; u8 g[4]; u8 b[4]; u8 a[4]; s32 pad2[2]; } Draw;
typedef struct TextObj { char pad0[6]; s16 x; s16 y; char padA; u8 r; u8 g; u8 b; u8 a; } TextObj;
typedef struct NameEntry { s8 scroll; s8 sel; u8 len; char name[16]; } NameEntry;
typedef struct GameState { char pad0[0x228]; s8 cfg; char pad229[0x24D - 0x229]; u8 hide; char pad24E[0x280 - 0x24E]; NameEntry entry; } GameState;

void *textObjGet(u32);
extern char *pool_get_item(s32, s32);
extern char *find_object_by_id(s32);
extern void group_set_color(TextObj *, u8, u8, u8, u8);
void draw_palette_sprite(void *, s16, s16, void *);
extern void func_8004C370(s32, Draw *);
extern void func_8006874C(s8);
extern s32 cos_q12(s32);
extern s32 sin_q12(s32);
extern u32 gRecordTimeScale;
extern GameState *gSelectState;
extern char *gRecords;
extern u16 D_800C6F12;
extern s32 gSelectStepHandle;

/* Draws the name-entry screen: the letter wheel (A-Z, two rows around the
 * current selection), the highlight box behind it, and the name typed so far. */
void draw_name_entry_wheel(void) {
    Draw draw;
    char str[2] = "A";
    TextObj *text;
    char *msg;
    GameState *state;
    NameEntry *entry;
    s8 i;
    s8 k;
    s32 base;
    s8 c;
    s8 cur;
    s32 ang;
    s32 dx;
    s32 dy;
    s32 r;
    s32 g;
    s32 b;

    text = textObjGet(9);
    if (D_800C6F12 != 0) {
        D_800C6F12--;
        msg = pool_get_item(gSelectStepHandle, 0x136);
        group_set_color(text, 0xFF, 0, 0, D_800C6F12 * 255 / (gRecordTimeScale * 2));
        draw_palette_sprite((void *)(text), (s16)(text->x), (s16)(text->y), (void *)(msg));
    }
    state = gSelectState;
    text = textObjGet(5);
    entry = &state->entry;
    entry->name[entry->len] = entry->sel + 'A';
    if (entry->scroll > 0) {
        entry->scroll += 8;
        if (entry->scroll == 32) {
            entry->sel++;
            if (entry->sel == 26) entry->sel = 0;
            entry->scroll = 0;
        }
    } else if (entry->scroll < 0) {
        entry->scroll -= 8;
        if (entry->scroll == -32) {
            entry->sel--;
            if (entry->sel < 0) entry->sel = 25;
            entry->scroll = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        draw.id[i] = -1;
        draw.r[i] = 0x1E;
        draw.g[i] = 0x32;
        draw.b[i] = 0x8E;
        draw.a[i] = 0x80;
    }
    base = entry->scroll * 0xFFF / 832;
    c = entry->sel + 13;
    if (c >= 26) c = entry->sel - 12;
    for (k = 0; k < 2; k++) {
        cur = (u8)c - k;
        for (i = 0; i < 13; i++) {
            str[0] = cur + 'A';
            ang = (entry->sel - cur) * 0xFFF / 26 - 0x400;
            ang += base;
            dx = cos_q12(ang) * 192 / 4096;
            dy = sin_q12(ang) * 192 / 16384;
            if (cur == entry->sel) {
                r = 0xDC;
                g = 0xDC;
                b = 0xDC;
            } else {
                r = 0x14;
                if (dy < 0) {
                    g = i * 60 / 13 + r + entry->scroll * 20 / 416;
                    r = g;
                    b = g;
                } else {
                    g = 0x14;
                    b = 0x14;
                }
            }
            group_set_color(text, r, g, b, 0xFF);
            draw_palette_sprite((void *)(text), (s16)(text->x - dx), (s16)(text->y - dy), (void *)(str));
            if (k != 0) {
                if (cur == 0) cur = 25;
                else cur--;
            } else {
                if (cur < 25) cur++;
                else cur = 0;
            }
        }
    }
    if (gSelectState->hide == 0) {
        dx = cos_q12(-0x400) * 192 / 4096;
        dy = sin_q12(-0x400) * 192 / 16384;
        draw.a[0] = 0x32;
        draw.a[1] = 0xB4;
        draw.a[2] = 0x32;
        draw.a[3] = 0xB4;
        draw.x[0] = text->x + dx - 8;
        draw.x[1] = text->x + dx + 32;
        draw.x[3] = draw.x[0];
        draw.x[2] = draw.x[1];
        draw.y[0] = draw.y[1] = text->y - dy - 8;
        draw.y[2] = draw.y[3] = text->y - dy + 36;
        func_8004C370(*(s32 *)(find_object_by_id(1) + 0x178), &draw);
    }
    text = textObjGet(8);
    for (i = 0; i <= entry->len; i++) {
        str[0] = entry->name[i];
        if (i == entry->len) {
            group_set_color(text, 0xDC, 0xDC, 0x0E, 0xFF);
        } else {
            group_set_color(text, text->r, text->g, text->b, text->a);
        }
        draw_palette_sprite((void *)(text), (s16)(text->x + i * 20), (s16)(text->y), (void *)(str));
    }
    func_8006874C(((struct { char pad[0x32]; s8 arr[1]; } *)gRecords)->arr[gSelectState->cfg]);
}
