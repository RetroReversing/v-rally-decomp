typedef struct { s32 words[8]; } Copy32;
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { s32 m[16]; } Matrix;
typedef struct { char pad[0x10]; Matrix matrix; } Transform;
typedef struct {
  Gfx *list[12];
  void *objects[12];
  char pad[0x48];
  u16 values[12];
} ModelLists;
typedef struct {
  char pad[0xc];
  void *segment;
  u32 flags;
  char pad14[4];
  s16 bounds[6];
  Transform *transform;
  char pad28[0x10];
  ModelLists *lists;
} Object;
typedef struct { char pad[0x84]; u32 mode; } Render;
typedef struct { s16 a; u16 mask; } LodEnt;
typedef struct { char pad[0x24]; void *player; char pad28[0x150]; s32 vis; } Cam;
typedef struct { char pad[0x8C]; struct { char pad[0x28]; Transform *transform; } *body; } Actor;
typedef struct { u16 count; u16 pad; Actor *items[1]; } ActorList;

#define gCmd(pkt, a, b) { u32 *_g = (u32 *)(pkt); _g[0] = (a); _g[1] = (u32)(b); }

Gfx *gfx_get_dl(Render *);
void gfx_set_dl(Render *, Gfx *);
void *mtx_pool_alloc(void);
void buildPoseMatrix(Matrix *, Matrix *);
void obj_mtx_visible(void *, s32, Matrix *);
void func_8001AAB4(void);
u32 osVirtualToPhysical(void *);
void checkNearPoint(void *, Matrix *);
void func_8007B4A4(void *, s32);
s32 dlAddLoadChunk(Render *);
s32 render_state_apply(Render *, s32);
s32 func_80016B3C(Actor *, s32, s32);
s32 func_80019F9C(void *, u16, Render *, s32);
s32 isBoundingBoxVisible(s32, s16 *, s32);
extern u8 g_dark_mode;
extern u8 D_800C792E;
extern Cam *g_camera;
extern s32 D_800C72D0;
extern ActorList D_800C5CF8;
extern u8 D_800ADFB9;
extern u8 D_800ADFBB;
extern u8 D_800ADFBD;
extern u16 D_800ADFB4;
extern u16 D_800ADFC0;
extern u16 D_800B5B50;
extern Copy32 D_800B56C8;
extern u8 D_8009BBBC;
extern Gfx D_8009C328[];
extern Gfx D_8009C390[];
extern Gfx D_8009C3F8[];
extern Gfx D_8009C460[];
extern LodEnt D_8009C5F4[][7][12];
extern s16 D_8009CBBC;
extern u8 D_8009CBC4[];
extern u8 D_8009CBD0[][4][7][12];
extern s32 gShadeMode;

s32 func_8001A340(Object *obj, s32 lod, Render *r, s32 arg3)
{
  Matrix mtx;
  void *m;
  Gfx *gfx;
  u32 sel;
  s32 i;
  s16 v;
  s32 idx;
  LodEnt *ent;
  s16 near;
  ModelLists *lists;
  void *cam;

  if (obj->lists == NULL) {
    func_8001AAB4();
  }
  m = mtx_pool_alloc();
  buildPoseMatrix(&mtx, &obj->transform->matrix);
  obj_mtx_visible(m, arg3, &mtx);
  {
  Gfx *start = gfx_get_dl(r);
  gfx = start;
  }
  D_8009CBBC = 0;
  sel = g_dark_mode;
  sel = (sel & -(D_800C792E & 1)) & 0xFF;
  sel &= 0xFF;
  switch (lod) {
  case 0:
  case 1:
  case 2:
    if (gShadeMode == 2 && g_dark_mode == 0) {
      gCmd(gfx++, 0xDE000000, D_8009C390);
    } else {
      gCmd(gfx++, 0xDE000000, D_8009C328);
    }
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    if (gShadeMode == 2 && g_dark_mode == 0) {
      gCmd(gfx++, 0xDE000000, D_8009C460);
    } else {
      gCmd(gfx++, 0xDE000000, D_8009C3F8);
    }
    break;
  }
  gCmd(gfx++, 0xF8000000, (D_800ADFB9 << 24) | (D_800ADFBB << 16) | (D_800ADFBD << 8) | 0xFF);
  if (gShadeMode == 5) {
    v = D_800ADFB4 + D_800ADFC0;
    if (v > 996) v = 996;
    if (v < 700) v = 700;
    v = 1000 - (1000 - v) / 10;
    if (v > 996) v = 996;
    gCmd(gfx++, 0xDB080000, ((128000 / (1000 - v)) << 16) | (((500 - v) * 256 / (1000 - v)) & 0xFFFF));
  }
  if (isBoundingBoxVisible(arg3, obj->bounds, g_camera->vis) != 0 || lod == 0) {
    D_800B56C8 = *(Copy32 *)&obj->transform->matrix;
    cam = g_camera->player;
    if (cam != NULL && (gShadeMode == 2) & (lod < 3) && g_dark_mode == 0) {
      checkNearPoint(cam, &obj->transform->matrix);
      func_8007B4A4(obj->lists, 0);
    }
    gCmd(gfx++, 0xDA380007, osVirtualToPhysical(m));
    gCmd(gfx++, 0xDB060004, osVirtualToPhysical(obj->segment));
    near = lod < 3;
    for (i = 0; i < 12; i++) {
      idx = D_8009CBC4[i];
      ent = &D_8009C5F4[g_dark_mode][lod][idx];
      if (obj->flags & ent->mask) {
        if (obj->lists->list[idx] != NULL && ent->a >= 0) {
          if (D_8009CBD0[D_800B5B50][sel][lod][idx] == 1) {
            gCmd(gfx++, 0xE7000000, 0);
            gCmd(gfx++, 0xD9FFFFFF, 0x210405);
            gCmd(gfx++, 0xE200001C, 0xC8113078);
          } else {
            gCmd(gfx++, 0xE7000000, 0);
            gCmd(gfx++, 0xD9FFFFFE, 0);
            gCmd(gfx++, 0xE200001C, 0xC8113048);
          }
          gCmd(gfx++, 0xDE000000, obj->lists->list[idx]);
        }
        if (obj->lists->objects[idx] != NULL && ((u32)~ent->a >> 31) & near) {
          gCmd(gfx++, 0xE7000000, 0);
          gCmd(gfx++, 0xD9FFFFFF, 0x210405);
          gCmd(gfx++, 0xE200001C, 0xC8113078);
          gfx_set_dl(r, gfx);
          dlAddLoadChunk(r);
          r->mode &= ~0x04000000;
          lists = obj->lists;
          func_80019F9C(lists->objects[idx], lists->values[idx], r, arg3);
          if (near) {
            r->mode = (r->mode & ~0x04000000) | 0x04000000;
            render_state_apply(r, 0);
          }
          gfx = gfx_get_dl(r);
        }
      }
    }
    if (!D_8009BBBC) {
      gfx_set_dl(r, gfx);
      for (i = 0; i < D_800C5CF8.count; i++) {
        Actor *a = D_800C5CF8.items[i];
        if (a->body->transform == obj->transform && a != g_camera->player) {
          func_80016B3C(a, D_800C72D0, arg3);
        }
      }
      gfx = gfx_get_dl(r);
    }
  }
  gfx_set_dl(r, gfx);
  return 1;
}
