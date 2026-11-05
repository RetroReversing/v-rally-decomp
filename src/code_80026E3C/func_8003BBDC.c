#include "decompdecomp_snapshot_8003bbdc.h"
#line 1 "func.c"
typedef void (*SpriteHook)(void);
typedef struct { u8 p[0xE]; u16 count; } State;
typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
typedef struct { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Rect;
typedef struct { u8 pad[0xC]; s32 kind; u8 pad2[0x168]; Rect *rect; } Obj;
typedef struct { u8 pad[0xA4]; void *pack; void *obj; } Widget;
extern Pack3 *func_80034FF0(s32 id, s32 extra, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
extern Obj *func_8004240C(int arg0);
extern u8 func_800556C4(void *arg0);
extern void func_80055738(void *);
extern u8 *D_800C35A0;
extern Obj *D_800C7F84;
extern void func_8003BB6C(void);
extern void func_8003C864(void);
static inline u8 *inline_fn(u8 arg0)
{
  return D_800C35A0 + (arg0 * 40);
}

static inline int inline_fn2(s32 arg0, int arg1)
{
  return arg0 - arg1;
}

void func_8003BBDC(s32 arg0, s32 arg1, s32 arg2)
{
  State *g = (State *)D_800C35A0;
  u16 mode = *((u16 *) ((u8 *)g + 0x1E));
  Pack3 *pack;
  s32 width;
  u32 count;
  u32 i;
  Obj *obj;
  s32 xa;
  Rect *r;
  s32 x;
  s32 y;
  s32 w;
  s32 k;
  u16 h;
  Widget *wd;
  x = 5;
  if ((mode != 7) && ((mode != 0) & (mode != x)))
  {
    pack = func_80034FF0(arg1 + 0x4C, 0, mode);
    func_80055738(pack);
    count = g->count;
    width = pack->tex[0]->width;
    for (i = 1; i <= count; i++)
    {
      obj = func_8004240C(inline_fn2(i * 2, 1));
      r = obj->rect;
      D_800C7F84 = obj;
      x = (*r).x;
      w = r->w;
      y = r->y;
      xa = x + 0x14;
      k = inline_fn2(w, 0x10);
      h = inline_fn2(r->h, 8);
      switch (g->count)
      {
        case 1:
          ((Widget *)func_80040260((void *)(arg0), inline_fn2(inline_fn2(k, width), 0x18), 0x1B, (u16)(arg2), (SpriteHook)(func_8003BB6C), 0))->pack = pack;
          func_800556C4(pack);
          if (inline_fn(D_800C35A0[0x32])[0x48] & 1)
          {
            wd = ((Widget *)func_80040260((void *)(arg0), inline_fn2(w, 0x66), y + 7, (u16)(arg2), (SpriteHook)(func_8003C864), 0));
            wd->pack = pack;
            wd->obj = D_800C7F84;
            func_800556C4(pack);
          }
          break;
        case 2:
          if ((*((u16 *) (D_800C35A0 + 0x12))) & 1)
          {
            ((Widget *)func_80040260((void *)(arg0), inline_fn2(w, 0x12), y + 7, (u16)(arg2), (SpriteHook)(func_8003BB6C), 0))->pack = pack;
            func_800556C4(pack);
          }
          else
          {
            if (obj->kind == 3)
            {
              xa = x + 6;
            }
            ((Widget *)func_80040260((void *)(arg0), xa, h + 0xFFF7, (u16)(arg2), (SpriteHook)(func_8003BB6C), 0))->pack = pack;
            func_800556C4(pack);
          }
          break;
      }
    }
  }
}

