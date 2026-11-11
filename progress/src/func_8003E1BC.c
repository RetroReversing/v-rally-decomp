typedef void (*SpriteHook)(void *);
typedef struct Pos {
    u8 pad00[8];
    s16 x8;
    s16 xA;
    s16 xC;
    s16 xE;
} Pos;
typedef struct Obj {
    u8 pad00[0xC];
    s32 type;
    u8 pad10[0x178 - 0x10];
    Pos *pos;
} Obj;
typedef struct Widget {
    u8 pad00[0x7A];
    s16 kind;
    u8 pad7C[0x90 - 0x7C];
    u8 r, g, b, a;
    u8 pad94[0xA4 - 0x94];
    s32 text;
    Obj *obj;
} Widget;
typedef struct Game {
    u8 pad00[0xE];
    u16 mode;
    u8 pad10[2];
    u16 opts;
    u8 pad14[0x1E - 0x14];
    u16 state;
} Game;
extern Game *gRecords;
extern Obj *g_camera;
extern void marker_update_color(void *);
extern void func_8003E0D4(void *);
extern void func_8003E134(void *);
extern s32 getTexturePack(s32, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);

/* Adds the record-screen widgets next to the camera object. Mode 1 adds four numbered rows.
 * Mode 2 adds a highlighted row and a plain row, shifted left unless the opts flag says otherwise. */
void func_8003E1BC(s32 parent, s32 msg_base)
{
    Obj *cam;
    Pos *pos;
    Widget *w;
    u32 row;
    s32 x;
    s32 y;
    s32 col_x;

    cam = g_camera;
    pos = cam->pos;
    x = pos->x8;
    y = pos->xA + 6;
    col_x = x + 0x14;
    switch (gRecords->mode) {
    case 1:
        if (gRecords->state != 0) {
            for (row = 0; row < 4; row++) {
                w = ((Widget *)sprite_create((void *)(parent), col_x, y + row * 0xB, (u16)(5), marker_update_color, 1));
                w->text = getTexturePack(msg_base + 0x4C, 0);
                w->kind = row + 1;
                w->obj = g_camera;
            }
        }
        break;
    case 2:
        if (gRecords->state != 0) {
            if (!(gRecords->opts & 1)) {
                if (cam->type == 3) {
                    col_x = x + 6;
                }
            } else {
                col_x = x;
            }
            w = ((Widget *)sprite_create((void *)(parent), col_x, y + 0xA, (u16)(5), func_8003E0D4, 1));
            w->text = getTexturePack(msg_base + 0x4C, 0);
            w->obj = g_camera;
            w->r = 0xFE;
            w->g = 0xD5;
            w->b = 0x1E;
            w->a = 0xFF;
            w = ((Widget *)sprite_create((void *)(parent), col_x, y, (u16)(5), func_8003E134, 1));
            w->text = getTexturePack(msg_base + 0x4C, 0);
            w->obj = g_camera;
        }
        break;
    }
}
