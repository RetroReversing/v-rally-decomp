typedef void (*SpriteHook)(void *);
typedef struct Pos
{
  u8 pad00[8];
  s16 f8;
  s16 fA;
  s16 fC;
  s16 fE;
} Pos;
typedef struct Obj
{
  u8 pad00[0xC];
  s32 type;
  u8 pad10[0x178 - 0x10];
  Pos *pos;
} Obj;
typedef struct Widget
{
  u8 pad00[0x76];
  s16 id;
  u8 pad78[0x90 - 0x78];
  u8 col[4];
  u8 pad94[0xA4 - 0x94];
  s32 text;
  Obj *obj;
} Widget;
typedef struct Game
{
  u8 pad00[0xE];
  u16 mode;
  u8 pad10[2];
  u16 opts;
  u8 pad14[0x1E - 0x14];
  u16 state;
} Game;
extern Game *gRecords;
extern Obj *g_camera;
extern void hud_update_digit(void *);
extern void func_8003B008(void *);
extern void timer_refresh_display(void *);
extern void func_8003AE84(void *);
extern void objSyncNeighborTimer(void *);
extern void func_8003AF74(void *);
extern void func_8003A9AC(void *, s32, s32, SpriteHook, s32, u16, u8 *);
extern s32 getTexturePack(s32, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
static __inline__ s32 make_label(void *a, s32 x, s32 y, SpriteHook cb, s32 text, s32 count) { count--; func_8003A9AC(a,x,y,cb,text,count,0); return count; }
/* Builds the HUD label and value widgets for the current object's row. Mode 1 is
   the standings column (one row, or three rows while racing); mode 2 is the
   timing panel. Positions come from the object's Pos block. */
void func_8003D9C8(void *ctx, s32 str_base, s32 n_items)
{
  Obj *obj = g_camera;
  Game *g = gRecords;
  Pos *pos = obj->pos;
  u16 row = 0;
  s32 cnt = n_items;
  s32 top = pos->fA;
  s32 left = pos->f8;
  s32 height = pos->fE;
  s32 row_base = top + 6;
  u16 row_step;
  s32 lbl_x;
  s32 lbl_y;
  s32 val_x;
  s32 text_key;
  Widget *w;
  Obj *cur_obj;
  s32 wi;
  switch (g->mode)
  {
    case 1:
      if (g->state == 0)
    {
      s32 label_y;
      n_items = make_label(ctx, left + 0x4D, (label_y = top + height - 0x12), hud_update_digit, str_base, n_items);
      row_base = (s16)label_y;
      w = ((Widget *)sprite_create(ctx, g_camera->pos->f8 + 0x44, row_base, (s16)(2), func_8003B008, 0));
      w->text = getTexturePack(str_base + 0x4C, 0);
      w->id = n_items;
      w->obj = g_camera;
    }
    else
    {
      row_step = 11;
      row = 2;
      do
      {
        func_8003A9AC(ctx, g_camera->pos->f8 + 0x5F, row_base + row_step, hud_update_digit, str_base, row, 0);
        w = ((Widget *)sprite_create(ctx, g_camera->pos->f8 + 0x56, row_step + row_base, (s16)(2), func_8003B008, 0));
        w->text = getTexturePack(str_base + 0x4C, 0);
        row_step += 11;
        w->id = row;
        row++;
        w->obj = g_camera;
      }
      while (row < 5);
    }
      break;

    case 2:
      wi = left;
      if (!(g->opts & 1))
    {
      wi = wi + 0x16;
      if (obj->type == 3)
      {
        wi = wi - 0xE;
      }
    }
      if (gRecords->state == 0)
    {
      s32 label_y;
      pos = g_camera->pos;
      label_y = pos->fA;
      label_y += pos->fE;
      label_y -= 0x12;
      n_items = make_label(ctx, wi + 0x39, label_y, hud_update_digit, str_base, cnt);
      row_base = (s16)label_y;
      w = ((Widget *)sprite_create(ctx, wi + 0x2E, row_base, (s16)(2), func_8003B008, 0));
      w->text = getTexturePack(str_base + 0x4C, 0);
      w->id = n_items;
      w->obj = g_camera;
    }
    else
    {
      lbl_x = wi + 0x31;
      lbl_y = row_base + 10;
      func_8003A9AC(ctx, lbl_x, lbl_y, timer_refresh_display, str_base, row, 0);
      val_x = (s16) (wi + 0x28);
      w = ((Widget *)sprite_create(ctx, val_x, lbl_y, (s16)(2), func_8003AE84, 0));
      text_key = str_base + 0x4C;
      w->text = getTexturePack(text_key, 0);
      cur_obj = g_camera;
      w->col[0] = 0xFE;
      w->col[1] = 0xD5;
      w->col[2] = 0x1E;
      w->col[3] = 0xFF;
      w->obj = cur_obj;
      func_8003A9AC(ctx, lbl_x, row_base, objSyncNeighborTimer, str_base, row, 0);
      w = ((Widget *)sprite_create(ctx, val_x, row_base, (s16)(2), func_8003AF74, 0));
      w->text = getTexturePack(text_key, 0);
      w->obj = g_camera;
    }
      break;

  }

}
