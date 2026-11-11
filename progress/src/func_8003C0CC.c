typedef void (*SpriteHook)(void *);
extern u8 gStreamState[];
typedef struct { u16 h0, h2, type, width, height; } Tex;
typedef struct { u8 count, pad[3]; Tex **tex; } Pack;
typedef struct { u8 pad[0xE]; u16 count; u8 pad2[0xE]; u16 mode; } Game;
typedef struct { u8 pad[0xC]; u16 w, h; } Dim;
typedef struct { u8 pad[0x178]; Dim *dim; } Car;
typedef struct {
    u8 pad[0x70];
    s16 x, y;
    u8 pad74[4];
    s16 unk78;
    u8 pad7A[6];
    u32 flags;
    u8 pad84[0x14];
    s16 sx, sy;
    u8 pad9C[4];
    u32 flags2;
    Pack *pack;
} Spr;
#define GAME_STATE (*(Game **)&gStreamState[0x32F2])
#define CURRENT_CAR (*(Car **)&gStreamState[0x7CD6])
void func_8003BEBC(void *);
Pack *getTexturePack(s32, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
Car *find_object_by_id(s32);

static inline f32 to_f(s32 v)
{
    return v;
}

/* Adds the car preview sprite to the display list `list` unless the game mode
   is 7. The car is picked from the current player count; the sprite is scaled to
   1.0 and its position is set so that its texture is centred on the origin. The
   texture pack is loaded from file id arg1 + 0x4C. */
void func_8003C0CC(void *list, s32 pack_id)
{
    Spr *spr;
    Car *car;
    Dim *dim;
    Pack *pk;
    Tex *tex;
    f32 s;
    f32 fx;
    f32 fy;

    if (GAME_STATE->mode != 7) {
        car = find_object_by_id((GAME_STATE->count << 1) | 1);
        dim = car->dim;
        CURRENT_CAR = car;
        spr = sprite_create(list, (s16)dim->w / 2, (s16)dim->h / 2, (s16)(4), func_8003BEBC, 0);
        spr->sx = 0x100;
        spr->sy = 0x100;
        spr->flags |= 4;
        pk = getTexturePack(pack_id + 0x4C, 0);
        s = 1024.0f / to_f(spr->sx);
        spr->pack = pk;
        tex = pk->tex[0];
        fx = s * to_f(tex->width) * 0.5f;
        fy = s * to_f(tex->height) * 0.5f;
        spr->sy = spr->sx;
        spr->unk78 = 1;
        spr->flags2 |= 4;
        spr->x = -fx;
        spr->y = -fy;
    }
}
