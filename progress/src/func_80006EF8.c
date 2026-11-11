typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    u8 pad00[0x14];
    Gfx *dl;
    u8 pad18[0x70 - 0x18];
    u8 *vtx;
    u8 pad74[4];
    u16 flags;
} DlCtx;

u16 dl_reserve_vertices();

/* Adds one 4-vertex quad to the display list. The first call also emits the
 * one-time render-state setup and sets the flag in ctx->flags. Each vertex gets
 * the value and colour, then a quad command references the new vertices. */
s32 func_80006EF8(DlCtx *ctx, s16 value, s32 colour)
{
    s32 var_a2;
    s32 vi;
    s32 vtx_off;
    s32 idx;
    s32 hi;
    Gfx *cmd;
    s32 w0_base;
    s32 n;
    Gfx *cmd1;
    Gfx *cmd2;
    Gfx *cmd3;
    Gfx *cmd4;
    Gfx *cmd5;
    u16 flags;

    var_a2 = colour;
    flags = ctx->flags;
    if (!(flags & 1)) {
        cmd1 = ctx->dl;
        ctx->flags = (u16)(flags | 1);
        ctx->dl = cmd1 + 1;
        cmd1->w0 = 0xE7000000;
        cmd1->w1 = 0;
        cmd2 = ctx->dl;
        ctx->dl = cmd2 + 1;
        cmd2->w0 = 0xE3000A01;
        cmd2->w1 = 0x100000;
        var_a2 = 0xFC119BFF;
        cmd3 = ctx->dl;
        ctx->dl = cmd3 + 1;
        cmd3->w0 = 0xFC119BFF;
        cmd3->w1 = 0xFFFEFE38;
        cmd4 = ctx->dl;
        ctx->dl = cmd4 + 1;
        cmd4->w0 = 0xD9E0F9FA;
        cmd4->w1 = 0;
        cmd5 = ctx->dl;
        ctx->dl = cmd5 + 1;
        cmd5->w0 = 0xD9FFFFFF;
        cmd5->w1 = 0x200005;
    }
    vi = dl_reserve_vertices(ctx, 4, var_a2) & 0xFFFF;
    vtx_off = vi * 0x10;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 4) = value;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x14) = value;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x24) = value;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x34) = value;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 6) = 0;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x16) = 0;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x26) = 0;
    *(s16 *)((vtx_off + (s32)ctx->vtx) + 0x36) = 0;
    *(u8 *)((vtx_off + (s32)ctx->vtx) + 0xF) = 0xFF;
    *(u8 *)((vtx_off + (s32)ctx->vtx) + 0x1F) = 0xFF;
    *(u8 *)((vtx_off + (s32)ctx->vtx) + 0x2F) = 0xFF;
    *(u8 *)((vtx_off + (s32)ctx->vtx) + 0x3F) = 0xFF;
    idx = vi & 0x1F;
    hi = idx << 17;
    cmd = ctx->dl;
    w0_base = hi | ((idx + 1) << 9);
    n = idx + 2;
    n = n * 2;
    ctx->dl = cmd + 1;
    cmd->w0 = (s32)((w0_base | n) | 0x07000000);
    cmd->w1 = (s32)((hi | (n << 8)) | ((idx + 3) * 2));
    return vi;
}
