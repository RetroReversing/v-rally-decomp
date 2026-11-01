extern u8 D_800A73E0[];
typedef struct { u32 w0; u32 w1; } GfxCmd;
typedef struct { u8 pad[0x14]; GfxCmd *dl; u8 pad18[0x6C]; u32 mode; } Render;
typedef struct { u8 r; u8 g; u8 b; u8 pad3[0xF]; u16 idx; u8 pad14[4]; } Item;
typedef struct { u8 pad[0xF]; u8 fmt; struct { u8 pad[4]; u32 *data; } *tex; } TexRec;
void func_80009964(Render *, s32);
void func_80009164(Render *, u32, u8);
u32 func_800199DC(Render *, s32, Item *);
void func_80008D70(Render *, u16);
void func_80006984(Render *, u16, u8, u8, u8);

void func_80019F9C(Item *items, u32 count, Render *r, s32 arg3)
{
  s32 pad[1];
  Render *g;
  GfxCmd *cmd;
  TexRec *rec;
  u32 i;
  u32 v;

  g = r;
  {
    GfxCmd *c0 = g->dl++;
    c0->w0 = 0xD9FFF9FF;
    c0->w1 = 0;
  }
  g->mode &= 0xFCFFFFFF;
  func_80009964(g, 1);
  for (i = 0; i < count; items++) {
    rec = (TexRec *)(*(u8 **)(*(u8 **)(D_800A73E0 + 0x6C14) + 0x24) + items->idx * 0x14);
    i++;
    func_80009164(r, *rec->tex->data, rec->fmt);
    func_80009964(r, 0);
    v = func_800199DC(r, arg3, items);
    func_80008D70(r, v);
    func_80006984(r, v, items->r, items->g, items->b);
    func_80006984(r, v + 1, items->r, items->g, items->b);
    func_80006984(r, v + 2, items->r, items->g, items->b);
    func_80006984(r, v + 3, items->r, items->g, items->b);
  }
  {
    u32 m = r->mode;
    m &= 0xFCFFFFFF;
    r->mode = m | 0x01000000;
  }
  func_80009964(r, 0);
  cmd = g->dl;
  g->dl = cmd + 1;
  cmd->w0 = 0xD9FFFFFF;
  cmd->w1 = 0x400;
}
