typedef struct { u8 v[6]; } Bytes6;
typedef struct { u8 v[6][3]; } Bytes18;
extern Bytes6 D_800A4A98;
extern Bytes6 D_800A4AA0;
extern Bytes18 D_800A4AA8;
extern void *D_800C60D4;
typedef struct { u8 pad[4]; void **data; } Res;
typedef struct { u8 pad[0x10]; u8 obj[0x94]; Res *res; } Obj;
typedef struct { u8 pad[0xC]; Obj *obj; s16 x; s16 y; u8 a; u8 b; u8 r; u8 g; u8 bl; } Spr;
extern void *poolAllocHeadNode(void);
extern Spr *poolAllocNode(void *, s32);
extern Res *getTexturePack(void *, s32);
extern Obj *poolAlloc(s32, s32);
extern void func_8000A5EC(void *, void *, s32, s32, s32, s32, s32);

/* Builds the HUD sprite set for the results screen: two fixed sprites at the top of the
   screen (resources at +0x2AC and +0x390), five sprites from +0x2F8 and one from +0x344,
   each tinted from the per-index alpha/colour tables. */
void func_80036C48(u8 *hud_data)
{
    Bytes6 tint_b;
    Bytes6 alpha_tbl;
    Bytes18 rgb_tbl;
    u8 i;

    tint_b = D_800A4A98;
    alpha_tbl = D_800A4AA0;
    rgb_tbl = D_800A4AA8;
    D_800C60D4 = poolAllocHeadNode();

    {
        Spr *spr;
        Res *res;
        Obj *obj;
        spr = poolAllocNode(D_800C60D4, 28);
        res = getTexturePack(hud_data + 0x2AC, 0);
        obj = poolAlloc(6, 176);
        spr->obj = obj;
        obj->res = res;
        func_8000A5EC(spr->obj->obj, *res->data, 1, 0, 0, 0, 0);
        spr->a = 100;
        spr->b = 0;
        spr->r = 255;
        spr->g = 255;
        spr->bl = 255;
        spr->x = 128;
        spr->y = 128;
    }
    {
        Spr *spr;
        Res *res;
        Obj *obj;
        spr = poolAllocNode(D_800C60D4, 28);
        res = getTexturePack(hud_data + 0x390, 0);
        obj = poolAlloc(6, 176);
        spr->obj = obj;
        obj->res = res;
        func_8000A5EC(spr->obj->obj, *res->data, 1, 0, 0, 0, 0);
        spr->x = 0;
        spr->y = 0;
        spr->a = 100;
        spr->b = 0;
        spr->r = 255;
        spr->g = 255;
        spr->bl = 255;
    }
    for (i = 0; i < 5; i++) {
        Spr *spr;
        Res *res;
        Obj *obj;
        res = getTexturePack(hud_data + 0x2F8, 0);
        spr = poolAllocNode(D_800C60D4, 28);
        obj = poolAlloc(6, 176);
        spr->obj = obj;
        obj->res = res;
        func_8000A5EC(spr->obj->obj, *res->data, 1, 0, 0, 0, 0);
        spr->x = 0;
        spr->y = 0;
        spr->a = alpha_tbl.v[i];
        spr->b = tint_b.v[i];
        spr->r = rgb_tbl.v[i][0];
        spr->g = rgb_tbl.v[i][1];
        spr->bl = rgb_tbl.v[i][2];
    }
    {
        Spr *spr;
        Res *res;
        Obj *obj;
        spr = poolAllocNode(D_800C60D4, 28);
        res = getTexturePack(hud_data + 0x344, 0);
        obj = poolAlloc(6, 176);
        spr->obj = obj;
        obj->res = res;
        func_8000A5EC(spr->obj->obj, *res->data, 1, 0, 0, 0, 0);
        spr->x = 0;
        spr->y = 0;
        spr->a = alpha_tbl.v[i];
        spr->b = tint_b.v[i];
        spr->r = rgb_tbl.v[i][0];
        spr->g = rgb_tbl.v[i][1];
        spr->bl = rgb_tbl.v[i][2];
    }
}
