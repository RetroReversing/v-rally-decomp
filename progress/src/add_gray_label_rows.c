typedef void (*SpriteHook)(void *);
typedef struct Cfg3E {
    u8 pad0[8];
    s16 x;
    s16 y;
    u8 padC[2];
    s16 h;
} Cfg3E;

typedef struct View3E {
    u8 pad0[0x178];
    Cfg3E *cfg;
} View3E;

typedef struct Game3E {
    u8 pad0[0xE];
    u16 mode;
    u8 pad10[0xE];
    u16 state;
} Game3E;

extern View3E *g_camera;
extern Game3E *gRecords;
void add_label_sprites(s32, s32, s32, SpriteHook, u8 *, u16, u8 *);
void func_8003B7BC(void *);

/* Adds four grey label rows above the HUD anchor while the record screen is in
 * its idle state (mode 1, state 0). Each row is brighter than the one before. */
void add_gray_label_rows(void *sprite_list, s32 tex_table)
{
    u8 col[4];
    u32 row;
    s32 x;
    s32 y;
    s32 h;
    Cfg3E *cfg = g_camera->cfg;

    x = cfg->x + 0x14;
    y = cfg->y + 6;
    h = cfg->h;
    if (gRecords->mode == 1 && gRecords->state == 0) {
        h -= 8;
        for (row = 0; row < 4; row++) {
            switch (row) {
            case 0:
                col[0] = 0x78;
                col[1] = 0x78;
                col[2] = 0x78;
                col[3] = 0xFF;
                break;
            case 1:
                col[0] = 0xA0;
                col[1] = 0xA0;
                col[2] = 0xA0;
                col[3] = 0xFF;
                break;
            case 2:
                col[0] = 0xC8;
                col[1] = 0xC8;
                col[2] = 0xC8;
                col[3] = 0xFF;
                break;
            case 3:
                col[0] = 0xF0;
                col[1] = 0xF0;
                col[2] = 0xF0;
                col[3] = 0xFF;
                break;
            }
            add_label_sprites((s32)(sprite_list), x, y + h - (6 - row) * 10 + 2, func_8003B7BC, (u8 *)(tex_table), row, col);
        }
    }
}
