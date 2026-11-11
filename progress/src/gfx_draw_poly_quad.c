typedef struct { s16 x, y, z; } VRVertex;
typedef struct { u8 rgb[4][4]; u16 vtx[4]; u8 st[4][2]; u16 tex; } VRPolyQuad;
extern u8 gOrderState[];
void func_80008CB8(void *, u16, u8, u8, s32);
void vtx_pool_set_uv(void *, u16, u8, u8);
void vtx_pool_add(void *, void *, s32, u16 *);
void gfx_set_texture(void *, s32, u8);
void gfx_add_quad(void *, u16, u16, u16, s32);
void gfx_sync_render_state(void *, s32);

/* Draws one textured, coloured quad from a polygon record: sets the render mode and
 * texture, maps the four corner vertices into the vertex pool, then sets each corner's
 * colour and UVs and emits the quad. */
void gfx_draw_poly_quad(void *gfx, VRPolyQuad *poly, VRVertex *verts)
{
    u16 out[4];
    VRVertex e[4];
    u8 *mat;

    *((u32*)((u8*)gfx+0x84)) = (*((u32*)((u8*)gfx+0x84)) & 0xFCFFFFFF) | 0x1000000;
    mat = *((u8**)(gOrderState+0x237C)) + poly->tex * 0x14;
    gfx_set_texture(gfx, **((s32**)(*((u8**)(mat+0x10))+4)), mat[0xF]);
    gfx_sync_render_state(gfx, 0);
    e[0] = verts[poly->vtx[3]];
    e[1] = verts[poly->vtx[2]];
    e[2] = verts[poly->vtx[0]];
    e[3] = verts[poly->vtx[1]];
    vtx_pool_add(gfx, e, 4, out);
    func_80008CB8(gfx, out[0], poly->rgb[3][0], poly->rgb[3][1], poly->rgb[3][2]);
    func_80008CB8(gfx, out[1], poly->rgb[2][0], poly->rgb[2][1], poly->rgb[2][2]);
    func_80008CB8(gfx, out[2], poly->rgb[0][0], poly->rgb[0][1], poly->rgb[0][2]);
    func_80008CB8(gfx, out[3], poly->rgb[1][0], poly->rgb[1][1], poly->rgb[1][2]);
    vtx_pool_set_uv(gfx, out[0], poly->st[3][0], poly->st[3][1]);
    vtx_pool_set_uv(gfx, out[1], poly->st[2][0], poly->st[2][1]);
    vtx_pool_set_uv(gfx, out[2], poly->st[0][0], poly->st[0][1]);
    vtx_pool_set_uv(gfx, out[3], poly->st[1][0], poly->st[1][1]);
    gfx_add_quad(gfx, out[3], out[2], out[1], out[0]);
}
