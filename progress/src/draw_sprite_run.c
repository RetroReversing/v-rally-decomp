extern u8 gGameState[];
typedef struct { u32 w0; u32 w1; } GfxCmd;
typedef struct { u8 pad[0x14]; GfxCmd *dl; u8 pad18[0x6C]; u32 mode; } Render;
typedef struct { u8 r; u8 g; u8 b; u8 pad3[0xF]; u16 idx; u8 pad14[4]; } Item;
typedef struct { u8 pad[0xF]; u8 fmt; struct { u8 pad[4]; u32 *data; } *tex; } TexRec;
void render_state_apply(Render *, s32);
void gfx_set_texture(Render *, u32, u8);
u32 func_800199DC(Render *, s32, Item *);
void setEntryCoordsFromSize(Render *, u16);
void func_80006984(Render *, u16, u8, u8, u8);

/* Draws a run of textured sprites. For each item: binds its texture, emits the
 * sprite quad with func_800199DC, then colours its four corner vertices from the
 * item's r/g/b. The run is bracketed by a geometry-mode command and a mode change. */
void draw_sprite_run(Item *items, u32 n_items, Render *rs, s32 obj)
{
  s32 pad[1];
  Render *cur;
  GfxCmd *geom;
  TexRec *tex_rec;
  u32 i;
  u32 vtx;

  cur = rs;
  {
    GfxCmd *geom_cmd = cur->dl++;
    geom_cmd->w0 = 0xD9FFF9FF;
    geom_cmd->w1 = 0;
  }
  cur->mode &= 0xFCFFFFFF;
  render_state_apply(cur, 1);
  for (i = 0; i < n_items; items++) {
    tex_rec = (TexRec *)(*(u8 **)(*(u8 **)(gGameState + 0x6C14) + 0x24) + items->idx * 0x14);
    i++;
    gfx_set_texture(rs, *tex_rec->tex->data, tex_rec->fmt);
    render_state_apply(rs, 0);
    vtx = func_800199DC(rs, obj, items);
    setEntryCoordsFromSize(rs, vtx);
    func_80006984(rs, vtx, items->r, items->g, items->b);
    func_80006984(rs, vtx + 1, items->r, items->g, items->b);
    func_80006984(rs, vtx + 2, items->r, items->g, items->b);
    func_80006984(rs, vtx + 3, items->r, items->g, items->b);
  }
  {
    u32 mode = rs->mode;
    mode &= 0xFCFFFFFF;
    rs->mode = mode | 0x01000000;
  }
  render_state_apply(rs, 0);
  geom = cur->dl;
  cur->dl = geom + 1;
  geom->w0 = 0xD9FFFFFF;
  geom->w1 = 0x400;
}
