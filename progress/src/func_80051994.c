#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
s32 dl_reserve_vertices(void*,s32);
s32 gfx_set_quad_pos(void*,s32,s16,s16,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 gfx_set_quad_uv(void*,s32,u16,u16,s32,s32,s32,s32,s32,s32);

/* Submits a box of vertices around the sprite centre, sized from the object's
 * extents (0x110, 0x118) and the sprite size, then appends two triangle
 * commands to the display list in ctx. Returns the vertex slot used. */
s32 func_80051994(void* ctx, void* obj, void* sprite, void* style)
{
    struct { f32 x, y, z; } half;
    u32 id;

    half.x = F(obj,f32,0x110) * (f32)F(sprite,u16,2) * 0.5f;
    half.y = (f32)(F(sprite,u16,4) >> 1);
    half.z = F(obj,f32,0x118) * (f32)F(sprite,u16,2) * 0.5f;
    id = (u16)dl_reserve_vertices(ctx, 4);
    gfx_set_quad_pos(ctx, id, (s16)(s32)((f32)F(sprite,s16,6) - half.x), (s16)(s32)((f32)F(sprite,s16,8) + half.y), (s32)(s16)(s32)((f32)F(sprite,s16,10) - half.z), (s32)(s16)(s32)((f32)F(sprite,s16,6) - half.x), (s32)(s16)(s32)((f32)F(sprite,s16,8) - half.y), (s32)(s16)(s32)((f32)F(sprite,s16,10) - half.z), (s32)(s16)(s32)((f32)F(sprite,s16,6) + half.x), (s32)(s16)(s32)((f32)F(sprite,s16,8) - half.y), (s32)(s16)(s32)((f32)F(sprite,s16,10) + half.z), (s32)(s16)(s32)((f32)F(sprite,s16,6) + half.x), (s32)(s16)(s32)((f32)F(sprite,s16,8) + half.y), (s32)(s16)(s32)((f32)F(sprite,s16,10) + half.z));
    gfx_set_quad_uv(ctx, (u16)id, F(style,u16,6), F(style,u16,8), F(style,u16,6), 0, 0, 0, 0, F(style,u16,8));
    {
        u32 *gfx = (u32 *)(F(ctx,u8*,0x14));
        F(ctx,u8*,0x14) += 8;
        gfx[0] = ((((u32)((id & 31) * 2) & 0xFF) << 16) | (((u32)(((id & 31) + 1) * 2) & 0xFF) << 8) | ((u32)(((id & 31) + 2) * 2) & 0xFF)) | ((u32)(0x07 & 0xFF) << 24);
        gfx[1] = (((u32)((id & 31) * 2) & 0xFF) << 16) | (((u32)(((id & 31) + 2) * 2) & 0xFF) << 8) | ((u32)(((id & 31) + 3) * 2) & 0xFF);
    }
    return id;
}
