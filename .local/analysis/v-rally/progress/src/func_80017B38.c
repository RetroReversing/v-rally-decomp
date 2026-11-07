typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { f32 m[4][4]; } MtxF;
typedef struct Item { u8 pad0[4]; struct Item *parent; u8 v8[0x40]; MtxF mtx; u8 pad88[8]; s32 p90; } Item;
typedef struct { u8 pad0[0x10]; Item **items; } Obj0;
typedef struct { u8 pad0[0x14]; Gfx *dl; u8 pad18[0x60]; s16 x78; } Render;
typedef struct { u8 pad0[0x80]; MtxF m; } Cam;
typedef struct { u8 pad0[0x178]; void *p178; } Global;
extern Global *D_800C7F84;
extern u8 D_800AFA6B;
extern MtxF D_800B5B00;
extern MtxF D_800B65A8;
extern u8 D_800ADFC7;
extern u8 D_800ADFC9;
extern u8 D_800ADFCB;
extern u32 D_8009C0A8;
extern f32 D_8009C228;
void func_800056FC(void *);
void func_80005F14(Render *, s32);
Gfx *func_80006008(Render *);
void func_80006014(Render *, Gfx *);
void func_80010BFC(void *, Cam *, MtxF *);
void *func_8001BD1C(void);
void func_8001C2C0(MtxF *, void *, MtxF *);
void guMtxIdentF(MtxF *);
void guRotateF(MtxF *, f32, f32, f32, f32);
u32 osVirtualToPhysical(void *);

void func_80017B38(Obj0 *obj, s32 unused, Render *r, Cam *cam)
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

  func_800056FC(D_800C7F84->p178);
  r->x78 = 0;
  guMtxIdentF(&D_800B65A8);
  m = &D_800B65A8;
  guRotateF(m, D_8009C228, 0.0f, 1.0f, 0.0f);
  D_8009C228 += 4.0f;
  func_80010BFC(0, cam, m);
  rr = r;
  rr->x78 = 0;
  g = func_80006008(rr);
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
      func_8001C2C0(&it->parent->mtx, it->v8, &it->mtx);
      p = func_8001BD1C();
      func_80010BFC(p, cam, &it->mtx);
    } else {
      p = func_8001BD1C();
      it->mtx = *m;
      func_80010BFC(p, cam, m);
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          D_800B5B00.m[j][k] = cam->m.m[j][k];
        }
      }
    }
    cmd = g++;
    cmd->w0 = 0xDA380007;
    cmd->w1 = osVirtualToPhysical(p);
    func_80006014(rr, g);
    func_80005F14(rr, obj->items[i]->p90);
    g = func_80006008(rr);
    if (i == 0) {
      func_80006014(rr, g);
      {
        Gfx *c = rr->dl++;
        c->w0 = 0xDE000000;
        c->w1 = (u32)&D_8009C0A8;
      }
      g = func_80006008(rr);
    }
  }
  {
    u32 *c = (u32 *)g++;
    c[0] = 0xFB000000;
    c[1] = (D_800ADFC7 << 24) | (D_800ADFC9 << 16) | (D_800ADFCB << 8) | 0xFF;
  }
  func_80006014(rr, g);
}
