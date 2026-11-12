typedef struct { u32 w0, w1; } Gfx;
Gfx *gfx_get_dl(s32); void gfx_set_dl(s32, Gfx *);
extern u16 D_8009C02A, D_8009C02E; extern s32 gShadeMode; extern u8 gGameState[];

/* Writes the fog and environment-colour commands for display list arg0.
 * In game mode 5 the fog range is derived from the two u16 values at
 * 0x6bd4 and 0x6be0, clamped to 0x2bc..0x3e4; other modes use the fixed
 * pair at D_8009C02A/D_8009C02E. */
void view_write_fog_cmds(s32 listId){
    Gfx *dl;
    s16 dist, fogStart;
    dl = gfx_get_dl(listId);
    { Gfx *_g = dl++; _g->w0 = 0xF8000000; _g->w1 = (gGameState[0x6bd9]<<24)|(gGameState[0x6bdb]<<16)|(gGameState[0x6bdd]<<8)|gGameState[0x6bdf]; }
    if (gShadeMode == 5) {
        dist = *(u16*)(gGameState+0x6bd4) + *(u16*)(gGameState+0x6be0);
        if (dist > 0x3e4) dist = 0x3e4;
        if (dist < 0x2bc) dist = 0x2bc;
        fogStart = 1000 - (1000 - dist) / 10;
        if (fogStart > 0x3e4) fogStart = 0x3e4;
        { Gfx *_g = dl++; _g->w0 = 0xdb080000; _g->w1 = ((0x1f400 / (1000 - fogStart)) << 16) | (((0x1f4 - fogStart) << 8) / (1000 - fogStart) & 0xffff); }
    } else {
        Gfx *_g = dl++; _g->w0 = 0xdb080000; _g->w1 = (D_8009C02A << 16) | D_8009C02E;
    }
    { Gfx *_g = dl++; _g->w0 = 0xfb000000; _g->w1 = (gGameState[0x6be7]<<24)|(gGameState[0x6be9]<<16)|(gGameState[0x6beb]<<8)|gGameState[0x6bed]; }
    gfx_set_dl(listId, dl);
}
