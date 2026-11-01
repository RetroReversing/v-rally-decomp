typedef struct Ent { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Ent;
typedef struct Obj { u8 pad[0xC]; s32 type; u8 pad2[0x178 - 0x10]; Ent *ent; } Obj;
typedef struct Mgr { u8 pad[0xE]; u16 mode; u8 pad2[2]; u16 flags; } Mgr;
typedef struct Spr { u8 pad[0x78]; s16 frame; u8 pad2[0xA4 - 0x7A]; void *tex; } Spr;
extern Obj *D_800C7F84;
extern Mgr *D_800C35A0;
extern void func_8003C8A4(void);
Obj *func_8004240C(s32);
Spr *func_80040260(s32, s16, s16, s16, void *, s32);
void *func_80034FF0(s32, s32);

void func_8003C968(s32 arg0, s32 arg1, u16 arg2)
{
  Obj *obj;
  Ent *e;
  Mgr *mgr;
  Spr *spr;
  s32 x, y, w, h;
  s32 lx, ty;
  u32 rx;
  u16 mode;

  obj = func_8004240C(((arg2 - 1) * 2) | 1);
  e = obj->ent;
  D_800C7F84 = obj;
  mgr = D_800C35A0;
  x = e->x;
  y = e->y;
  w = e->w;
  mode = mgr->mode;
  lx = x + 0x14;
  ty = y + 6;
  rx = w - 0x10;
  h = e->h;
  switch (mode)
  {
    case 1:
      spr = func_80040260(arg0, w - 0x2D, y + 0x1A, 2, func_8003C8A4, 0);
      spr->tex = func_80034FF0(arg1 + 0x4C, 0);
      spr->frame = 0;
      spr = func_80040260(arg0, rx + 0xFFEA, y + 0x1A, 2, func_8003C8A4, 0);
      spr->tex = func_80034FF0(arg1 + 0x4C, 0);
      spr->frame = 1;
      break;
    case 2:
      if (mgr->flags & 1)
      {
        spr = func_80040260(arg0, w + 8, ty, 2, func_8003C8A4, 0);
        spr->tex = func_80034FF0(arg1 + 0x4C, 0);
        spr->frame = 0;
        spr = func_80040260(arg0, w + 0xF, ty, 2, func_8003C8A4, 0);
        spr->tex = func_80034FF0(arg1 + 0x4C, 0);
        spr->frame = 1;
      }
      else
      {
        if (obj->type == 3)
        {
          lx = x + 6;
        }
        spr = func_80040260(arg0, lx + 0x1A, h - 0x12, 2, func_8003C8A4, 0);
        spr->tex = func_80034FF0(arg1 + 0x4C, 0);
        spr->frame = 0;
        spr = func_80040260(arg0, lx + 0x21, h - 0x12, 2, func_8003C8A4, 0);
        spr->tex = func_80034FF0(arg1 + 0x4C, 0);
        spr->frame = 1;
      }
      break;
  }
}
