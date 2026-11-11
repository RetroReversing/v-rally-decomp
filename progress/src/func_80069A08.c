typedef struct { u32 w0, w1; } Gfx;
typedef struct { s32 x, y, z; } Vec3i;
typedef struct {
    char pad0[0x38];
    char mtx[0xD4];      /* 0x38 */
    f32 f10C, f110, f114; /* 0x10C */
    Vec3i eye;           /* 0x118 */
    Vec3i at;            /* 0x124 */
    f32 f130, f134, f138; /* 0x130 */
    char pad13C[0x3C];
    void *dl;            /* 0x178 */
} Camera;
typedef struct { char pad[0x14]; Gfx *gfx; } DLBuf;
typedef struct { char pad[0x104]; u16 persp; char pad106[0x52]; char light0[0x10]; char light1[0x10]; } View;
typedef struct { char pad[4]; s16 width; } FrameBuf;
typedef struct { char pad[0x44]; u16 a44[4]; u16 a4C[4]; u16 a54[4]; } Players;
typedef struct { char pad[0x237]; u8 track; } GameState;

#define GCMD(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }

void func_80022668(s32, s32);
void *find_object_by_id(s32);
DLBuf *view_get_ctx_id(void *);
void view_set_rect(void *, s16 *);
Gfx *gfx_get_dl(DLBuf *);
void gfx_set_dl(DLBuf *, Gfx *);
void *func_80005C48(FrameBuf *);
u32 osVirtualToPhysical(void *);
void camera_refresh_and_copy(void *, s16 *);
void *mtx_pool_alloc(void);
void guMtxF2L(void *, void *);
void guMtxIdent(void *);
void func_8001C1A8(f32 *, void *);
void obj_mtx_visible(void *, void *, void *);
void gfx_push_mtx(DLBuf *, void *);
void draw_item_bar(void *, s32, f32, s32, s32);
void stream_load_slot_text(u8);
s32 func_80084DD4(u8);
void func_80015C74(void *, s32);
void func_80017B38(void *, s32, DLBuf *, void *);

extern s32 D_800A11B0;
extern Camera *g_camera;
extern Vec3i D_800A1694;
extern Vec3i D_800A16A0;
extern s16 D_800A16AC[4];
extern FrameBuf *gSceneSlot1;
extern u32 D_800B706C;
extern char D_800C8380[];
extern f32 D_800A1584[];
extern f32 D_800A158C;
extern char D_800A159C[];
extern f32 D_800A15D0;
extern s32 D_800C5E50;
extern GameState *gSelectState;
extern s32 D_800AFB40;
extern s32 D_800B5AF4;
extern s32 D_800AFA68;
extern Players *gContCtx;
extern char D_800ADFB0[];
extern char D_800ADFEC[];

void func_80069A08(void)
{
    DLBuf *buf;
    Gfx *gfx;
    View *view;
    void *mtx;
    void *m;
    u32 zaddr;
    s32 i;

    func_80022668(D_800A11B0, 0);
    g_camera = find_object_by_id(3);
    buf = view_get_ctx_id(g_camera->dl);

    g_camera = find_object_by_id(3);
    g_camera->eye = D_800A1694;
    g_camera->at = D_800A16A0;
    g_camera->f130 = 0.0f;
    g_camera->f134 = 100.0f;
    g_camera->f138 = 0.0f;
    g_camera->f10C = 0.4f;
    g_camera->f110 = 0.4f;
    g_camera->f114 = 1.0f;
    view_set_rect(g_camera->dl, D_800A16AC);

    g_camera = find_object_by_id(1);
    g_camera->eye = D_800A1694;
    g_camera->at = D_800A16A0;
    g_camera->f130 = 0.0f;
    g_camera->f134 = 100.0f;
    g_camera->f138 = 0.0f;
    g_camera->f10C = 0.4f;
    g_camera->f110 = 0.4f;
    g_camera->f114 = 1.0f;

    gfx = gfx_get_dl(buf);
    GCMD(gfx++, 0xE7000000, 0);
    GCMD(gfx++, 0xE3000A01, 0x300000);
    zaddr = D_800B706C - 0x80000000;
    GCMD(gfx++, 0xFE000000, zaddr);
    GCMD(gfx++, 0xFF100000 | ((gSceneSlot1->width - 1) & 0xFFF), zaddr);
    GCMD(gfx++, 0xF7000000, 0xFFFCFFFC);
    GCMD(gfx++, 0xF6000000 | (((gSceneSlot1->width - 1) & 0x3FF) << 14) | (((D_800A16AC[3] - 1) & 0x3FF) << 2),
         ((D_800A16AC[0] & 0x3FF) << 14) | ((D_800A16AC[1] & 0x3FF) << 2));
    GCMD(gfx++, 0xE7000000, 0);
    GCMD(gfx++, 0xFF100000 | ((gSceneSlot1->width - 1) & 0xFFF), osVirtualToPhysical(func_80005C48(gSceneSlot1)));
    GCMD(gfx++, 0xF7000000, 0x10001);
    GCMD(gfx++, 0xF6000000 | (((gSceneSlot1->width - 1) & 0x3FF) << 14) | (((D_800A16AC[3] - 1) & 0x3FF) << 2),
         ((D_800A16AC[0] & 0x3FF) << 14) | (((D_800A16AC[1] + 60) & 0x3FF) << 2));
    GCMD(gfx++, 0xE3000A01, 0);
    gfx_set_dl(buf, gfx);

    view = find_object_by_id(3);
    camera_refresh_and_copy(find_object_by_id(3), D_800A16AC);
    buf = view_get_ctx_id(((Camera *)view)->dl);
    gfx = gfx_get_dl(buf);
    m = mtx_pool_alloc();
    guMtxF2L(((Camera *)view)->mtx, m);
    guMtxIdent(D_800C8380);
    GCMD(gfx++, 0xDB0E0000, view->persp);
    GCMD(gfx++, 0xDA380003, (u32)D_800C8380);
    GCMD(gfx++, 0xDC08000A, (u32)view->light0);
    GCMD(gfx++, 0xDC08030A, (u32)view->light1);
    GCMD(gfx++, 0xE7000000, 0);
    gfx_set_dl(buf, gfx);

    g_camera = find_object_by_id(3);
    buf = view_get_ctx_id(g_camera->dl);
    g_camera = find_object_by_id(1);
    mtx = g_camera->mtx;
    g_camera = find_object_by_id(3);
    m = mtx_pool_alloc();
    D_800A1584[0] = -90.0f;
    D_800A158C += 4.0f;
    func_8001C1A8(D_800A1584, D_800A159C);
    D_800A15D0 = 80.0f;
    obj_mtx_visible(m, g_camera->mtx, D_800A159C);
    gfx_push_mtx(buf, m);
    GCMD(buf->gfx++, 0xFB000000, -1);
    draw_item_bar(g_camera->dl, 0, 4.0f, 0, 0xFF);

    if (D_800C5E50 == -1) {
        stream_load_slot_text(gSelectState->track);
        D_800C5E50 = gSelectState->track;
        D_800B5AF4 = gSelectState->track;
        D_800AFB40 = 0;
        for (i = 0; i < 4; i++) {
            if (func_80084DD4(i) != 0) {
                gContCtx->a4C[i] &= 0x7FFF;
                gContCtx->a44[i] &= 0x7FFF;
                gContCtx->a54[i] &= 0x7FFF;
            }
        }
    } else if (D_800C5E50 != gSelectState->track) {
        if (D_800B5AF4 != gSelectState->track) {
            D_800B5AF4 = gSelectState->track;
            D_800AFB40 = 0;
        }
        D_800AFB40++;
        if (D_800AFB40 >= 13) {
            func_80015C74(D_800ADFB0, 0);
            stream_load_slot_text(gSelectState->track);
            D_800C5E50 = gSelectState->track;
            D_800AFB40 = 0;
        }
        for (i = 0; i < 4; i++) {
            if (func_80084DD4(i) != 0) {
                gContCtx->a4C[i] &= 0x7FFF;
                gContCtx->a44[i] &= 0x7FFF;
                gContCtx->a54[i] &= 0x7FFF;
            }
        }
    }
    if (D_800C5E50 == gSelectState->track) {
        D_800AFA68 += 50;
        if (D_800AFA68 >= 256) {
            D_800AFA68 = 255;
        } else {
            for (i = 0; i < 4; i++) {
                if (func_80084DD4(i) != 0) {
                    gContCtx->a4C[i] &= 0x7FFF;
                    gContCtx->a44[i] &= 0x7FFF;
                    gContCtx->a54[i] &= 0x7FFF;
                }
            }
        }
    } else if (D_800AFA68 > 0) {
        D_800AFA68 -= 50;
        if (D_800AFA68 < 0) {
            D_800AFA68 = 0;
        }
    }
    func_80017B38(D_800ADFEC, 0, buf, mtx);
}
