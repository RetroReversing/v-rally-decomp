typedef struct { s32 words[8]; } Copy32;
#ifdef PORT
typedef struct { uintptr_t w0; uintptr_t w1; } Gfx;
#else
typedef struct { u32 w0; u32 w1; } Gfx;
#endif
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

#ifdef PORT
#define gCmd(pkt, a, b) { uintptr_t *_g = (uintptr_t *)(pkt); _g[0] = (a); _g[1] = (uintptr_t)(b); }
#else
#define gCmd(pkt, a, b) { u32 *_g = (u32 *)(pkt); _g[0] = (a); _g[1] = (u32)(b); }
#endif

Gfx *gfx_get_dl(Render *);
void gfx_set_dl(Render *, Gfx *);
void *mtx_pool_alloc(void);
void buildPoseMatrix(Matrix *, Matrix *);
void obj_mtx_visible(void *, s32, Matrix *);
void mesh_build_slot_data(void);
u32 osVirtualToPhysical(void *);
void checkNearPoint(void *, Matrix *);
void light_object_vertices(void *, s32);
s32 dlAddLoadChunk(Render *);
s32 render_state_apply(Render *, s32);
s32 draw_object_dl(Actor *, s32, s32);
s32 draw_sprite_run(void *, u16, Render *, s32);
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

/* Emits the display list for one object at the given level of detail: shading setup, transform, then each model part whose flags and LOD mask allow it, plus any sprite parts and attached actors. */ s32 draw_object_lod(Object *obj, s32 lod, Render *r, s32 arg3)
{
  Matrix mtx;
  void *m;
  Gfx *dl;
  u32 dark_sel;
  s32 i;
  s16 fog_level;
  s32 part_idx;
  LodEnt *lod_ent;
  s16 near_flag;
  ModelLists *lists;
  void *cam_player;

  if (obj->lists == NULL) {
    mesh_build_slot_data();
  }
  m = mtx_pool_alloc();
  buildPoseMatrix(&mtx, &obj->transform->matrix);
  obj_mtx_visible(m, arg3, &mtx);
  {
  Gfx *start = gfx_get_dl(r);
  dl = start;
  }
  D_8009CBBC = 0;
  dark_sel = g_dark_mode;
  dark_sel = (dark_sel & -(D_800C792E & 1)) & 0xFF;
  dark_sel &= 0xFF;
  switch (lod) {
  case 0:
  case 1:
  case 2:
    if (gShadeMode == 2 && g_dark_mode == 0) {
      gCmd(dl++, 0xDE000000, D_8009C390);
    } else {
      gCmd(dl++, 0xDE000000, D_8009C328);
    }
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    if (gShadeMode == 2 && g_dark_mode == 0) {
      gCmd(dl++, 0xDE000000, D_8009C460);
    } else {
      gCmd(dl++, 0xDE000000, D_8009C3F8);
    }
    break;
  }
  gCmd(dl++, 0xF8000000, (D_800ADFB9 << 24) | (D_800ADFBB << 16) | (D_800ADFBD << 8) | 0xFF);
  if (gShadeMode == 5) {
    fog_level = D_800ADFB4 + D_800ADFC0;
    if (fog_level > 996) fog_level = 996;
    if (fog_level < 700) fog_level = 700;
    fog_level = 1000 - (1000 - fog_level) / 10;
    if (fog_level > 996) fog_level = 996;
    gCmd(dl++, 0xDB080000, ((128000 / (1000 - fog_level)) << 16) | (((500 - fog_level) * 256 / (1000 - fog_level)) & 0xFFFF));
  }
  if (isBoundingBoxVisible(arg3, obj->bounds, g_camera->vis) != 0 || lod == 0) {
    D_800B56C8 = *(Copy32 *)&obj->transform->matrix;
    cam_player = g_camera->player;
    if (cam_player != NULL && (gShadeMode == 2) & (lod < 3) && g_dark_mode == 0) {
      checkNearPoint(cam_player, &obj->transform->matrix);
      light_object_vertices(obj->lists, 0);
    }
    gCmd(dl++, 0xDA380007, osVirtualToPhysical(m));
    gCmd(dl++, 0xDB060004, osVirtualToPhysical(obj->segment));
    near_flag = lod < 3;
    for (i = 0; i < 12; i++) {
      part_idx = D_8009CBC4[i];
      lod_ent = &D_8009C5F4[g_dark_mode][lod][part_idx];
      if (obj->flags & lod_ent->mask) {
        if (obj->lists->list[part_idx] != NULL && lod_ent->a >= 0) {
          if (D_8009CBD0[D_800B5B50][dark_sel][lod][part_idx] == 1) {
            gCmd(dl++, 0xE7000000, 0);
            gCmd(dl++, 0xD9FFFFFF, 0x210405);
            gCmd(dl++, 0xE200001C, 0xC8113078);
          } else {
            gCmd(dl++, 0xE7000000, 0);
            gCmd(dl++, 0xD9FFFFFE, 0);
            gCmd(dl++, 0xE200001C, 0xC8113048);
          }
          gCmd(dl++, 0xDE000000, obj->lists->list[part_idx]);
        }
        if (obj->lists->objects[part_idx] != NULL && ((u32)~lod_ent->a >> 31) & near_flag) {
          gCmd(dl++, 0xE7000000, 0);
          gCmd(dl++, 0xD9FFFFFF, 0x210405);
          gCmd(dl++, 0xE200001C, 0xC8113078);
          gfx_set_dl(r, dl);
          dlAddLoadChunk(r);
          r->mode &= ~0x04000000;
          lists = obj->lists;
          draw_sprite_run(lists->objects[part_idx], lists->values[part_idx], r, arg3);
          if (near_flag) {
            r->mode = (r->mode & ~0x04000000) | 0x04000000;
            render_state_apply(r, 0);
          }
          dl = gfx_get_dl(r);
        }
      }
    }
    if (!D_8009BBBC) {
      gfx_set_dl(r, dl);
      for (i = 0; i < D_800C5CF8.count; i++) {
        Actor *a = D_800C5CF8.items[i];
        if (a->body->transform == obj->transform && a != g_camera->player) {
          draw_object_dl(a, D_800C72D0, arg3);
        }
      }
      dl = gfx_get_dl(r);
    }
  }
  gfx_set_dl(r, dl);
  return 1;
}
