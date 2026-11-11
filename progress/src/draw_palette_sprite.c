typedef struct { u8 pad0[4]; u8 r, g, b; } Col;
typedef struct { u8 start, count; } Rng;
typedef struct { u8 p0[0xD0]; Rng rng[1]; u8 p1[0x14-0+0]; } GX;
typedef struct { u8 p[0xA]; s8 idx; u8 q; u8 t; u8 s; u8 r; u8 pad; f32 w10; f32 f14; u16 h18; } Arg;
extern u8 *gSelectState;
extern struct { u8 p[4]; s16 w; } *gSceneSlot0;
extern u8 D_800A73E0[];
s32 view_get_ctx_id(void *);
void func_8000C22C(void *, s32, s32, s32, u8);
s32 func_8000C9B0(void *, void *, u8, f32, u8);
u16 func_8000CC04(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
/* Palette range of a draw entry: the entry's idx selects a 2-byte range record at +0xD0 in the palette block. */
#define RNG(g, a) ((Rng *)((g) + (s16)(((Arg *)(a))->idx * 2) + 0xD0))
/* Colour slot i in the palette block (4-byte slots from +0xE4). */
#define COL(g, i) (*(Col **)((g) + (i) * 4 + 0xE4))

/* Draws one palette-animated sprite. When x is 0x7FFF the x position is centred
 * from the sprite's measured width (screen 0x280 wide, else 0x140). If the palette
 * fade flag at +0x24D is set, the range's colours are faded toward the entry's
 * colour before and after the draw. */
void draw_palette_sprite(void *entry, s16 x, s16 y, void *tex) {
    u8 i;
    u8 r = 0, g = 0, b = 0;
    if (x == 0x7FFF) {
        Rng *range = RNG(gSelectState, entry);
        s16 w = func_8000C9B0((void *)(gSelectState + (range->start * 4 + 0xE4)), (void *)(tex), (u8)(range->count), (f32)(((Arg *)entry)->w10), (u8)(0));
        if (gSceneSlot0->w == 0x280) { u32 u = gSceneSlot0->w - w; x = (s16)((u + (u >> 31)) >> 1); }
        else { u32 u = 0x140 - w; x = (s16)((u + (u >> 31)) >> 1); }
    }
    if (gSelectState[0x24D] != 0) {
        Rng *range = RNG(gSelectState, entry);
        Col *c;
        c = COL(gSelectState, range->start);
        i = range->start;
        r = c->r; g = c->g; b = c->b;
        while (i < RNG(gSelectState, entry)->start + RNG(gSelectState, entry)->count) {
            func_8000C22C((void *)(COL(gSelectState, i)), (s32)(r >> 3), (s32)(g >> 3), (s32)(b >> 3), (u8)(((Arg *)entry)->r));
            i++;
        }
    }
    func_8000CC04((void *)(gSelectState + (RNG(gSelectState, entry)->start * 4 + 0xE4)), (void *)(view_get_ctx_id((void *)(*(s32*)(D_800A73E0+0x6ba0)))), (s16)(x), (s16)(y), (void *)(tex), (u8)(RNG(gSelectState, entry)->count), (f32)(((Arg *)entry)->w10), (f32)(((Arg *)entry)->f14), (u16)(((Arg *)entry)->h18), (u8)(0));
    if (gSelectState[0x24D] != 0) {
        i = RNG(gSelectState, entry)->start;
        while (i < RNG(gSelectState, entry)->start + RNG(gSelectState, entry)->count) {
            func_8000C22C((void *)(COL(gSelectState, i)), (s32)(r), (s32)(g), (s32)(b), (u8)(((Arg *)entry)->r));
            i++;
        }
    }
}
