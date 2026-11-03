#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
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

Gfx *func_80006008(Render *);
void func_80006014(Render *, Gfx *);
void *func_8001BD1C(void);
void func_8002DFF4(Matrix *, Matrix *);
void func_80010BFC(void *, s32, Matrix *);
void func_8001AAB4(void);
u32 osVirtualToPhysical(void *);
void func_8007B2A4(void *, Matrix *);
void func_8007B4A4(ModelLists *, s32);
s32 func_80006230(Render *);
s32 func_80009964(Render *, s32);
s32 func_80016B3C(Actor *, s32, s32);
s32 func_80019F9C(void *, u16, Render *, s32);
s32 isBoundingBoxVisible(s32, s16 *, s32);
extern u8 D_800C7926;
extern u8 D_800C792E;
extern Cam *D_800C7F84;
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
extern s32 D_8009FF30;

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
  m = func_8001BD1C();
  func_8002DFF4(&mtx, &obj->transform->matrix);
  func_80010BFC(m, arg3, &mtx);
  {
  Gfx *start = func_80006008(r);
  gfx = start;
  }
  D_8009CBBC = 0;
  sel = D_800C7926;
  sel = (sel & -(D_800C792E & 1)) & 0xFF;
  sel &= 0xFF;
  switch (lod) {
  case 0:
  case 1:
  case 2:
    if (D_8009FF30 == 2 && D_800C7926 == 0) {
      gCmd(gfx++, 0xDE000000, D_8009C390);
    } else {
      gCmd(gfx++, 0xDE000000, D_8009C328);
    }
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    if (D_8009FF30 == 2 && D_800C7926 == 0) {
      gCmd(gfx++, 0xDE000000, D_8009C460);
    } else {
      gCmd(gfx++, 0xDE000000, D_8009C3F8);
    }
    break;
  }
  gCmd(gfx++, 0xF8000000, (D_800ADFB9 << 24) | (D_800ADFBB << 16) | (D_800ADFBD << 8) | 0xFF);
  if (D_8009FF30 == 5) {
    v = D_800ADFB4 + D_800ADFC0;
    if (v > 996) v = 996;
    if (v < 700) v = 700;
    v = 1000 - (1000 - v) / 10;
    if (v > 996) v = 996;
    gCmd(gfx++, 0xDB080000, ((128000 / (1000 - v)) << 16) | (((500 - v) * 256 / (1000 - v)) & 0xFFFF));
  }
  if (isBoundingBoxVisible(arg3, obj->bounds, D_800C7F84->vis) != 0 || lod == 0) {
    D_800B56C8 = *(Copy32 *)&obj->transform->matrix;
    cam = D_800C7F84->player;
    if (cam != NULL && (D_8009FF30 == 2) & (lod < 3) && D_800C7926 == 0) {
      func_8007B2A4(cam, &obj->transform->matrix);
      func_8007B4A4(obj->lists, 0);
    }
    gCmd(gfx++, 0xDA380007, osVirtualToPhysical(m));
    gCmd(gfx++, 0xDB060004, osVirtualToPhysical(obj->segment));
    near = lod < 3;
    for (i = 0; i < 12; i++) {
      idx = D_8009CBC4[i];
      ent = &D_8009C5F4[D_800C7926][lod][idx];
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
          func_80006014(r, gfx);
          func_80006230(r);
          r->mode &= ~0x04000000;
          lists = obj->lists;
          func_80019F9C(lists->objects[idx], lists->values[idx], r, arg3);
          if (near) {
            r->mode = (r->mode & ~0x04000000) | 0x04000000;
            func_80009964(r, 0);
          }
          gfx = func_80006008(r);
        }
      }
    }
    if (!D_8009BBBC) {
      func_80006014(r, gfx);
      for (i = 0; i < D_800C5CF8.count; i++) {
        Actor *a = D_800C5CF8.items[i];
        if (a->body->transform == obj->transform && a != D_800C7F84->player) {
          func_80016B3C(a, D_800C72D0, arg3);
        }
      }
      gfx = func_80006008(r);
    }
  }
  func_80006014(r, gfx);
  return 1;
}

