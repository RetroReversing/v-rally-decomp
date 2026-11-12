#ifdef PORT
typedef unsigned long uintptr_t;
typedef struct { uintptr_t w0, w1; } DLGfx;
#define GADDR(x) ((uintptr_t)(x))
#else
typedef struct { u32 w0, w1; } DLGfx;
#define GADDR(x) ((s32)(x))
#endif
#define LOAD_S32(p,o) (*(s32*)((char*)(p)+(o)))
#define LOAD_F32(p,o) (*(f32*)((char*)(p)+(o)))
#define LOAD_S16(p,o) (*(s16*)((char*)(p)+(o)))
#define LOAD_U16(p,o) (*(u16*)((char*)(p)+(o)))
#define LOAD_PTR(p,o) (*(char**)((char*)(p)+(o)))
#define GBI_CMD(pkt,a,b) { DLGfx *_g = (DLGfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} Triple;
extern Triple g_main_cam_eye;
extern Triple g_main_cam_at;
extern Triple g_sub_cam_eye;
extern Triple g_sub_cam_at;
extern f32 D_800A16B8;
extern f32 D_800A16BC;
extern f32 D_800A16C4;
extern f32 D_800A16C8;
extern u16 D_800A16AC;
extern u16 D_800A16AE;
extern s16 D_800A16B2;
extern u8 gStreamReady;
extern char *gSceneSlot1;
extern char *D_800AFA64;
extern char *g_camera;
extern int D_800B706C;
extern int rebase_base_addr;
extern int D_8009D4E8;
extern int *D_800C8374;
extern char hud_ident_mtx[];
extern char D_800ADFB0[];
char *find_object_by_id(int);
DLGfx *gfx_get_dl(int);
void gfx_set_dl(int, DLGfx *);
int view_get_ctx_id(int);
int mtx_pool_alloc(void);
int obj_get_owner(void *);
int osVirtualToPhysical(int);
void view_set_rect(s32, void *, void *);
void camera_refresh_and_copy(void *, void *);
void guMtxF2L(void *, s32);
void guMtxIdent(void *);
void view_write_fog_cmds(s32);
void draw_object_parts(void *, s32, s32, s32, void *);
void heap_free_stub(s32);
/* Repositions the two cameras from the scene's keyframe table, then emits
 * the scene's display list for the main view and the HUD. */
void race_render_scene(void)
{
  DLGfx *dl;
  s32 keyOfs;
  s32 viewSlot;
  s32 ctxId;
  char *mainCam;
  char *subCamObj;
  char *mtxDst;
  char *cam;
  char *camObj;
  char *cam2;
  char *subCam;
  char *camTmp;
  int texAddr;
  char *camTmp2;
  char *camTmp3;
  char *camTmp4;
  if (gStreamReady == 0)
  {
    return;
  }
  {
    char *sceneData;
    s32 rowStep;
    s32 rowOff;
    s32 keyBase;
    u16 *pAC = &D_800A16AC;
#define D_800A16AC (*pAC)
    sceneData = D_800AFA64;
    rowStep = LOAD_U16(sceneData, 0x88) * 2 / 3;
    rowOff = rowStep * LOAD_U16(sceneData, 0x8A);
    keyBase = LOAD_S32(sceneData, 0x4C);
    keyOfs = rowOff + keyBase;
    LOAD_F32(&g_sub_cam_eye, 0x0) = (f32) (((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][0] + LOAD_S32(sceneData, 0x24));
    D_800A16B8 = (f32) ((((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][1] + LOAD_S32(sceneData, 0x28)) - 0x12C);
    D_800A16BC = (f32) (((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][2] + LOAD_S32(sceneData, 0x2C));
    keyOfs = ++rowStep * LOAD_U16(sceneData, 0x8A) + keyBase;
    LOAD_F32(&g_sub_cam_at, 0x0) = (f32) (((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][0] + LOAD_S32(sceneData, 0x24));
    D_800A16C4 = (f32) ((((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][1] + LOAD_S32(sceneData, 0x28)) - 0x12C);
    D_800A16C8 = (f32) (((s16 (*)[3]) LOAD_PTR(sceneData, 0x54))[keyOfs][2] + LOAD_S32(sceneData, 0x2C));
    camObj = find_object_by_id(3);
    viewSlot = LOAD_S32(camObj, 0x178);
    g_camera = camObj;
    ctxId = view_get_ctx_id(viewSlot);
    camTmp = find_object_by_id(3);
    g_camera = camTmp;
    *((Triple *) (camTmp + 0x118)) = g_main_cam_eye;
    *((Triple *) (g_camera + 0x124)) = g_main_cam_at;
    LOAD_S32(g_camera, 0x130) = 0;
    LOAD_F32(g_camera, 0x134) = 100.0f;
    LOAD_S32(g_camera, 0x138) = 0;
    LOAD_F32(g_camera, 0x114) = 1.0f;
    view_set_rect(LOAD_S32(g_camera, 0x178), &D_800A16AC, &g_main_cam_at);
    camTmp2 = find_object_by_id(1);
    g_camera = camTmp2;
    *((Triple *) (camTmp2 + 0x118)) = g_sub_cam_eye;
    *((Triple *) (g_camera + 0x124)) = g_sub_cam_at;
    LOAD_S32(g_camera, 0x130) = 0;
    LOAD_F32(g_camera, 0x134) = 100.0f;
    LOAD_S32(g_camera, 0x138) = 0;
    LOAD_F32(g_camera, 0x10C) = 0.4f;
    LOAD_F32(g_camera, 0x110) = 0.4f;
    LOAD_F32(g_camera, 0x114) = 1.0f;
    dl = gfx_get_dl(ctxId);
    GBI_CMD(dl++, 0xE7000000, 0);
    GBI_CMD(dl++, 0xE3000A01, 0x300000);
    texAddr = D_800B706C + 0x80000000;
    {
      char *tex = gSceneSlot1;
      GBI_CMD(dl++, 0xFE000000, texAddr);
      GBI_CMD(dl++, ((LOAD_S16(tex, 4) - 1) & 0xFFF) | 0xFF100000, texAddr);
      GBI_CMD(dl++, 0xF7000000, 0xFFFCFFFC);
      GBI_CMD(dl++, 0xF6000000 | (((u32)(LOAD_S16(tex, 4) - 1) & 0x3FF) << 14) | (((u32)(D_800A16B2 - 1) & 0x3FF) << 2),
          ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2));
      GBI_CMD(dl++, 0xE7000000, 0);
      GBI_CMD(dl++, ((LOAD_S16(tex, 4) - 1) & 0xFFF) | 0xFF100000, osVirtualToPhysical(obj_get_owner(tex)));
    }
    GBI_CMD(dl++, 0xE3000A01, 0);
    GBI_CMD(dl++, 0xF7000000, 0x10001);
    GBI_CMD(dl++, 0xF6000000 | (((u32)(LOAD_S16(gSceneSlot1, 4) - 1) & 0x3FF) << 14) | (((u32)(D_800A16B2 - 1) & 0x3FF) << 2),
        ((D_800A16AC & 0x3FF) << 14) | ((D_800A16AE & 0x3FF) << 2));
#undef D_800A16AC
    gfx_set_dl(ctxId, dl);
    mainCam = find_object_by_id(3);
    camera_refresh_and_copy(find_object_by_id(3), &D_800A16AC);
    ctxId = view_get_ctx_id(LOAD_S32(mainCam, 0x178));
    dl = gfx_get_dl(ctxId);
    guMtxF2L(mtxDst = mainCam + 0x38, mtx_pool_alloc());
    guMtxIdent(hud_ident_mtx);
    GBI_CMD(dl++, 0xDB0E0000, LOAD_U16(mainCam, 0x104));
    GBI_CMD(dl++, 0xDA380003, GADDR(hud_ident_mtx));
    GBI_CMD(dl++, 0xDC08000A, GADDR(mainCam + 0x158));
    GBI_CMD(dl++, 0xDC08030A, GADDR(mainCam + 0x168));
    GBI_CMD(dl++, 0xE7000000, 0);
    gfx_set_dl(ctxId, dl);
    camTmp3 = find_object_by_id(3);
    viewSlot = LOAD_S32(camTmp3, 0x178);
    g_camera = camTmp3;
    ctxId = view_get_ctx_id(viewSlot);
    camTmp4 = find_object_by_id(1);
    g_camera = camTmp4;
    subCam = camTmp4 + 0x38;
    g_camera = find_object_by_id(3);
    view_write_fog_cmds(ctxId);
    draw_object_parts(D_800ADFB0, *D_800C8374, ctxId, ctxId, subCam);
    if (rebase_base_addr != 0)
    {
      heap_free_stub(rebase_base_addr);
      rebase_base_addr = 0;
      heap_free_stub(D_8009D4E8);
      D_8009D4E8 = 0;
    }
  }
}
