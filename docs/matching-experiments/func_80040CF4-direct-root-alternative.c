#define func_80042078(a,b,c,d,e) ((Item *)func_80042078(a,b,c,d,e))
#define gObj (*(Obj **)(D_800C02AE + 0x32F2))
#define gItem (*(Item **)(D_800C02AE + 0x7CD6))
typedef struct 
{
  s16 x;
  s16 y;
  u16 w;
  u16 h;
} Rect;
typedef struct 
{
  u8 pad[12];
  s32 id;
} Item;
typedef struct 
{
  u8 pad[14];
  u16 mode;
  u16 pad10;
  u16 flags;
} Obj;
typedef struct 
{
  u16 v[10];
} LayoutTbl;
extern void func_800424A4(Item *, void *);
extern u8 D_800C02AE[];
extern Rect D_8009FFD8;
extern LayoutTbl D_8009FF38[];
extern u8 D_800A4C30[];
extern u8 D_800A4C38[];
extern u8 D_800A4C40[];
extern u8 D_800A4C48[];
extern u8 D_800A4C50[];
extern u8 D_800A4C58[];
extern u8 D_800A4C60[];
void func_80040CF4(u8 arg0)
{
  Obj *o = gObj;
  s32 x = D_8009FFD8.x;
  s32 y;
  s32 w;
  s32 h;
  u8 n = o->mode;
  u8 idx = n - 1;
  Item *it;
  Rect *p;
  Rect r;
  y = D_8009FFD8.y;
  w = (s16) D_8009FFD8.w;
  h = (s16) D_8009FFD8.h;
  if (n != 0)
  {
    Item *it0;
    r.x = x;
    r.y = y;
    r.h = h;
    r.w = w;
    it0 = func_80042078(&r, 5, D_8009FF38[idx].v[0], D_8009FF38[idx].v[1], 2);
    func_800424A4(it0, D_800A4C30);
    it0->id = 0;
  }
  switch (n)
  {
    case 1:
      p = &r;
      p->x = x;
      p->y = y;
      p->h = h;
      p->w = w;
      it = func_80042078(p, 0, D_8009FF38[idx].v[2], D_8009FF38[idx].v[3], 2);
      func_800424A4(it, D_800A4C38);
      it->id = 1;
      gItem = it;
      it = func_80042078(p, 0, D_8009FF38[idx].v[4], D_8009FF38[idx].v[5], 2);
      func_800424A4(it, D_800A4C40);
      it->id = 2;
      break;

    case 2:
      if (o->flags & 1)
    {
      s16 x2 = x + 0x20;
      s16 w2 = w - 0x38;
      s32 hh = h / 2;
      s16 h2;
      h = hh - 1;
      h2 = h;
      p = &r;
      p->x = x2;
      p->y = y;
      p->w = w2;
      p->h = h2;
      it = func_80042078(p, 0, D_8009FF38[idx].v[2], D_8009FF38[idx].v[3], n);
      func_800424A4(it, D_800A4C38);
      it->id = 1;
      gItem = it;
      it = func_80042078(p, 0, D_8009FF38[idx].v[4], D_8009FF38[idx].v[5], n);
      func_800424A4(it, D_800A4C40);
      it->id = 2;
      p->x = x2;
      p->y = (hh = (y + hh) + 1);
      p->w = w2;
      p->h = h2;
      it = func_80042078(p, 0, D_8009FF38[idx].v[2], D_8009FF38[idx].v[3], n);
      func_800424A4(it, D_800A4C48);
      it->id = 3;
      it = func_80042078(p, 0, D_8009FF38[idx].v[4], D_8009FF38[idx].v[5], n);
    }
    else
    {
      s32 hw = w / 2;
      s16 w2 = hw - 1;
      s16 y2 = y;
      p = &r;
      p->x = x;
      p->y = y2;
      p->h = h;
      p->w = w2;
      it = func_80042078(p, 0, D_8009FF38[idx].v[2], D_8009FF38[idx].v[3], n);
      func_800424A4(it, D_800A4C38);
      it->id = 1;
      gItem = it;
      it = func_80042078(p, 0, D_8009FF38[idx].v[4], D_8009FF38[idx].v[5], n);
      func_800424A4(it, D_800A4C40);
      it->id = 2;
      p->x = hw;
      p->x = x + p->x;
      p->x = p->x + 1;
      p->y = y;
      p->h = h;
      p->w = w2;
      it = func_80042078(p, 0, D_8009FF38[idx].v[2], D_8009FF38[idx].v[3], n);
      func_800424A4(it, D_800A4C48);
      it->id = 3;
      it = func_80042078(p, 0, D_8009FF38[idx].v[4], D_8009FF38[idx].v[5], n);
    }
      func_800424A4(it, D_800A4C50);
      it->id = 4;
      break;

  }

  if (!(n != 0))
  {
    return;
  }
  if (!(arg0 == 0))
  {
    return;
  }
  {
    r = D_8009FFD8;
    it = func_80042078(&r, 5, D_8009FF38[idx].v[6], D_8009FF38[idx].v[7], 2);
    func_800424A4(it, D_800A4C58);
    it->id = (n * 2) | 1;
    {
      r = D_8009FFD8;
    }
    if ((gObj->mode == 2) && (gObj->flags & 1))
    {
      r.x += 0x18;
      r.w -= 0x30;
    }
    it = func_80042078(&r, 0, D_8009FF38[idx].v[8], D_8009FF38[idx].v[9], 2);
    func_800424A4(it, D_800A4C60);
    it->id = (n * 2) + 2;
  }
}

