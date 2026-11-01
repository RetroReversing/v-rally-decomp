typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
typedef struct { u8 pad[8]; s16 x, y, w, h; } Rect;
typedef struct { u8 pad[0xC]; s32 kind; u8 pad2[0x168]; Rect *rect; } Obj;
typedef struct { u8 pad[0xA4]; void *pack; void *obj; } Widget;
extern Pack3 *func_80034FF0(s32 id, s32 extra, s32);
extern Widget *func_80040260(s32 arg0, s16 arg1, s16 arg2, u16 arg3, void *arg4, s32);
extern Obj *func_8004240C(int arg0);
extern u8 func_800556C4(void *arg0);
extern void func_80055738(void *);
extern u8 *D_800C35A0;
extern Obj *D_800C7F84;
extern void func_8003BB6C(void);
extern void func_8003C864(void);
void func_8003BBDC(s32 arg0, s32 arg1, s32 arg2)
{
  u8 *g = D_800C35A0;
  u16 mode = *(u16 *)(g + 0x1E);
  Pack3 *pack;
  s32 width;
  u32 count;
  u32 i;
  Obj *obj;
  Rect *r;
  s32 x, y, w, xa, k;
  u16 h;
  Widget *wd;

  if ((mode != 7) && ((mode != 0) & (mode != 5)))
  {
    pack = func_80034FF0(arg1 + 0x4C, 0, mode);
    func_80055738(pack);
    count = *(u16 *)(g + 0xE);
    width = pack->tex[0]->width;
    for (i = 1; i <= count; i++)
    {
      obj = func_8004240C(i * 2 - 1);
      r = obj->rect;
      D_800C7F84 = obj;
      x = r->x;
      w = r->w;
      y = r->y;
      h = r->h - 8;
      xa = x + 0x14;
      k = w - 0x10;
      switch (*(u16 *)(g + 0xE))
      {
      case 1:
        func_80040260(arg0, k - width - 0x18, 0x1B, arg2, func_8003BB6C, 0)->pack = pack;
        func_800556C4(pack);
        if ((D_800C35A0 + D_800C35A0[0x32] * 40)[0x48] & 1)
        {
          wd = func_80040260(arg0, w - 0x66, y + 7, arg2, func_8003C864, 0);
          wd->pack = pack;
          wd->obj = D_800C7F84;
          func_800556C4(pack);
        }
        break;
      case 2:
        if (*(u16 *)(D_800C35A0 + 0x12) & 1)
        {
          func_80040260(arg0, w - 0x12, y + 7, arg2, func_8003BB6C, 0)->pack = pack;
        }
        else
        {
          if (obj->kind == 3)
            xa = x + 6;
          func_80040260(arg0, xa, h + 0xFFF7, arg2, func_8003BB6C, 0)->pack = pack;
        }
        func_800556C4(pack);
        break;
      }
    }
  }
}
