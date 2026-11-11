typedef struct SceneSlot {
    u8 pad0[4];
    s16 w;
} SceneSlot;

extern SceneSlot *gSceneSlot0;
extern s32 gSceneSlot1;

s32 view_get_ctx_id();
void *gfx_get_dl(void *ctx);
void gfx_set_dl(void *ctx, void *dl);
s32 func_80005C48();
s32 osVirtualToPhysical();

/* Adds a Set Colour Image command for the scene's frame buffer to the current
 * view's display list, then stores the list pointer back into the view. */
void gfx_set_color_image(void) {
    void *ctx;
    void *dl;
    void *cmd;
    void *image;

    ctx = (void *)view_get_ctx_id();
    dl = gfx_get_dl(ctx);
    cmd = dl;
    dl += 8;
    image = (void *)func_80005C48(gSceneSlot1);
    *(s32 *)((char *)cmd + 0) = (s32)(((gSceneSlot0->w - 1) & 0xFFF) | 0xFF100000);
    *(s32 *)((char *)cmd + 4) = osVirtualToPhysical(image);
    gfx_set_dl(ctx, dl);
}
