extern u8 D_800C02AE[];
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
#define GAME (*(Game **)&D_800C02AE[0x32F2])
#define CUR_CAR (*(Car **)&D_800C02AE[0x7CD6])
void func_8003BEBC(void *);
Pack *func_80034FF0(s32, s32);
Spr *func_80040260(Spr *, s16, s16, s16, void *, s32);
Car *func_8004240C(s32);

static inline f32 to_f(s32 v)
{
    return v;
}

void func_8003C0CC(Spr *spr, s32 arg1)
{
    Car *car;
    Dim *d;
    Pack *pk;
    Tex *tex;
    f32 s;
    f32 fx;
    f32 fy;

    if (GAME->mode != 7) {
        car = func_8004240C((GAME->count << 1) | 1);
        d = car->dim;
        CUR_CAR = car;
        spr = func_80040260(spr, (s16)d->w / 2, (s16)d->h / 2, 4, func_8003BEBC, 0);
        spr->sx = 0x100;
        spr->sy = 0x100;
        spr->flags |= 4;
        pk = func_80034FF0(arg1 + 0x4C, 0);
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
