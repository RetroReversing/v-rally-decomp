typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { f32 m[4][4]; } MtxF;
typedef struct Item { u8 pad0[4]; struct Item *parent; u8 v8[0x40]; MtxF mtx; u8 pad88[8]; s32 p90; } Item;
typedef struct { u8 pad0[0x10]; Item **items; } Obj0;
typedef struct { u8 pad0[0x14]; Gfx *dl; u8 pad18[0x60]; s16 x78; } Render;
typedef struct { u8 pad0[0x80]; MtxF m; } Cam;
typedef struct { u8 pad0[0x178]; void *p178; } Global;
extern Global *g_camera;
extern u8 D_800AFA6B;
extern MtxF D_800B5B00;
extern MtxF D_800B65A8;
extern u8 D_800ADFC7;
extern u8 D_800ADFC9;
extern u8 D_800ADFCB;
extern u32 D_8009C0A8;
extern f32 gItemSpinAngle;
void view_get_ctx_id(void *);
void func_80005F14(Render *, s32);
Gfx *gfx_get_dl(Render *);
void gfx_set_dl(Render *, Gfx *);
void obj_mtx_visible(void *, Cam *, MtxF *);
void *mtx_pool_alloc(void);
void mtx_concat(MtxF *, void *, MtxF *);
void guMtxIdentF(MtxF *);
void guRotateF(MtxF *, f32, f32, f32, f32);
u32 osVirtualToPhysical(void *);

/* Draws the group of five items in obj: each item gets its matrix (chained to
 * its parent when it has one, otherwise the spinning root matrix) and a
 * display-list entry; the cam matrix is copied into D_800B5B00 for the root.
 * unused is ignored; render is the output state and cam the camera. */
void func_80017B38(Obj0 *obj, s32 unused, Render *render, Cam *cam)
{
  Gfx *g;
  Gfx *cmd;
  Item *it;
  void *p;
  MtxF *m;
  Render *rr;
  s32 i;
  u32 j;
  u32 k;

  view_get_ctx_id(g_camera->p178);
  render->x78 = 0;
  guMtxIdentF(&D_800B65A8);
  m = &D_800B65A8;
  guRotateF(m, gItemSpinAngle, 0.0f, 1.0f, 0.0f);
  gItemSpinAngle += 4.0f;
  obj_mtx_visible(0, cam, m);
  rr = render;
  rr->x78 = 0;
  g = gfx_get_dl(rr);
  {
    Gfx *c = g++;
    c->w0 = 0xFB000000;
    c->w1 = D_800AFA6B | 0xFFFFFF00;
  }
  {
    Gfx *c = g++;
    c->w0 = 0xDE000000;
    c->w1 = (u32)&D_8009C0A8;
  }
  for (i = 0; i < 5; i++) {
    it = obj->items[i];
    if (it->parent != NULL) {
      mtx_concat(&it->parent->mtx, it->v8, &it->mtx);
      p = mtx_pool_alloc();
      obj_mtx_visible(p, cam, &it->mtx);
    } else {
      p = mtx_pool_alloc();
      it->mtx = *m;
      obj_mtx_visible(p, cam, m);
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          D_800B5B00.m[j][k] = cam->m.m[j][k];
        }
      }
    }
    cmd = g++;
    cmd->w0 = 0xDA380007;
    cmd->w1 = osVirtualToPhysical(p);
    gfx_set_dl(rr, g);
    func_80005F14(rr, obj->items[i]->p90);
    g = gfx_get_dl(rr);
    if (i == 0) {
      gfx_set_dl(rr, g);
      {
        Gfx *c = rr->dl++;
        c->w0 = 0xDE000000;
        c->w1 = (u32)&D_8009C0A8;
      }
      g = gfx_get_dl(rr);
    }
  }
  {
    u32 *c = (u32 *)g++;
    c[0] = 0xFB000000;
    c[1] = (D_800ADFC7 << 24) | (D_800ADFC9 << 16) | (D_800ADFCB << 8) | 0xFF;
  }
  gfx_set_dl(rr, g);
}
