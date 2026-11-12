typedef struct VRViewport { s16 x, y, w, h; u8 pad08[0x24]; void *frame; } VRViewport;
typedef struct VRStripTex { u8 pad00[6]; u16 width, height; u8 pad0A[2]; u16 stripHeight; } VRStripTex;
typedef struct VRStripSlot { VRStripTex *tex; } VRStripSlot;
typedef struct VRStreamData { u8 pad00[4]; VRStripSlot *slot; } VRStreamData;
typedef struct VRStreamEntry { u8 pad00[0x0C]; VRStreamData *data; } VRStreamEntry;
extern char stream_state[];
extern s16 *gSceneSlot0;
void *list_nth_node(void **, s32);
void set_both_subobj_s16(void *, s16);
void viewport_build_dl(VRViewport *, s16, s16, u8);
void draw_rect_strips(void *, void *);

/* Looks up stream entry `index` and attaches it to the viewport at ctx+0x178.
 * Entries that are 512 or more wide, or exactly as wide as the screen, are
 * drawn as one viewport at (x, y); the others are drawn as a strip of rows. */
void stream_draw_entry(void *ctx, s32 index, s16 x, s16 y)
{
    VRViewport *vp;
    VRStreamEntry *entry;
    VRStripTex *tex;
    u16 width;

    vp = *(VRViewport **)((u8 *)ctx + 0x178);
#ifdef PORT
    entry = list_nth_node(*(void ***)(stream_state + 0x7672), index & 0xFFFF);
#else
    entry = list_nth_node((void **)*(s32 *)(stream_state + 0x7672), index & 0xFFFF);
#endif
    if (entry != NULL) {
        vp->frame = entry;
        tex = entry->data->slot->tex;
        width = tex->width;
        if ((width >= 0x200U) || (width == gSceneSlot0[2])) {
            set_both_subobj_s16(*(void **)((u8 *)ctx + 0x178), 5);
            viewport_build_dl(*(VRViewport **)((u8 *)ctx + 0x178), x, y, 0);
            return;
        }
        set_both_subobj_s16(*(void **)((u8 *)ctx + 0x178), 0);
        draw_rect_strips(*(void **)((u8 *)ctx + 0x178), tex);
    }
}
