extern void *func_80042078(void *, u16, s32, s32, u16);
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
extern void func_800424A4(void *, void *);
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

/* Builds the HUD/menu widgets for the current menu mode from the screen rect
 * D_8009FFD8, using the layout table row for that mode. Each widget is created
 * with func_80042078, decorated with a graphic from D_800A4Cxx, and tagged with
 * an id. Mode 1 and 2 build the item rows (2 splits the rect when flags&1 is
 * clear); when arg0 is 0 and a mode is active it also adds the footer widgets. */
void func_80040CF4(u8 skip_footer)
{
  Obj *obj = gObj;
  s32 x = D_8009FFD8.x;
  s32 y;
  s32 w;
  s32 h;
  u8 mode = obj->mode;
  u8 layout_idx = mode - 1;
  Item *item;
  Rect r;
  y = D_8009FFD8.y;
  w = (s16) D_8009FFD8.w;
  h = (s16) D_8009FFD8.h;
  if (mode != 0)
  {
    /* shared result pointer */
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    item = func_80042078(&r, 5, D_8009FF38[layout_idx].v[0], D_8009FF38[layout_idx].v[1], 2);
    func_800424A4(item, D_800A4C30);
    item->id = 0;
  }
  switch (mode)
  {
    case 1:
    {
      Rect *p;
      p = &r;
      p->x = x;
      p->y = y;
      p->w = w;
      p->h = h;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[2], D_8009FF38[layout_idx].v[3], 2);
      func_800424A4(item, D_800A4C38);
      item->id = 1;
      gItem = item;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[4], D_8009FF38[layout_idx].v[5], 2);
      func_800424A4(item, D_800A4C40);
      item->id = 2;
      break;
    }

    case 2:
      if (obj->flags & 1)
    {
      Rect *p;
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
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[2], D_8009FF38[layout_idx].v[3], mode);
      func_800424A4(item, D_800A4C38);
      item->id = 1;
      gItem = item;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[4], D_8009FF38[layout_idx].v[5], mode);
      func_800424A4(item, D_800A4C40);
      {
      s16 next_y = y + hh + 1;
      item->id = 2;
      p->x = x2;
      p->y = next_y;
      p->w = w2;
      p->h = h2;
      }
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[2], D_8009FF38[layout_idx].v[3], mode);
      func_800424A4(item, D_800A4C48);
      item->id = 3;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[4], D_8009FF38[layout_idx].v[5], mode);
    }
    else
    {
      Rect *p;
      s16 horizontal_height;
      s32 hw = w / 2;
      s16 w2 = hw - 1;
      s16 y2 = y;
      p = &r;
      p->x = x;
      p->y = y2;
      horizontal_height = h;
      p->w = w2;
      p->h = horizontal_height;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[2], D_8009FF38[layout_idx].v[3], mode);
      func_800424A4(item, D_800A4C38);
      item->id = 1;
      gItem = item;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[4], D_8009FF38[layout_idx].v[5], mode);
      func_800424A4(item, D_800A4C40);
      item->id = 2;
      p->x = x + hw + 1;
      p->y = y;
      p->w = w2;
      p->h = horizontal_height;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[2], D_8009FF38[layout_idx].v[3], mode);
      func_800424A4(item, D_800A4C48);
      item->id = 3;
      item = func_80042078(p, 0, D_8009FF38[layout_idx].v[4], D_8009FF38[layout_idx].v[5], mode);
    }
      func_800424A4(item, D_800A4C50);
      item->id = 4;
      break;

  }

  if (!(mode != 0))
  {
    return;
  }
  if (!(skip_footer == 0))
  {
    return;
  }
  {
    r = D_8009FFD8;
    item = func_80042078(&r, 5, D_8009FF38[layout_idx].v[6], D_8009FF38[layout_idx].v[7], 2);
    func_800424A4(item, D_800A4C58);
    item->id = (mode * 2) | 1;
    {
      extern u8 D_8009FFDA[];
      r = *((Rect *) ((u32)D_8009FFDA - 2U));
    }
    if ((gObj->mode == 2) && (gObj->flags & 1))
    {
      r.x += 0x18;
      r.w -= 0x30;
    }
    item = func_80042078(&r, 0, D_8009FF38[layout_idx].v[8], D_8009FF38[layout_idx].v[9], 2);
    func_800424A4(item, D_800A4C60);
    item->id = (mode * 2) + 2;
  }
}
