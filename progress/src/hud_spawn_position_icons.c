typedef void (*SpriteHook)(void *);
typedef struct Pos
{
  u8 pad00[8];
  s16 xA;
  s16 xE;
  s16 xC;
  s16 x8;
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
  u8 pad00[0x7A];
  s16 kind;
  u8 pad7C[0xA4 - 0x7C];
  s32 text;
  Obj *obj;
} Widget;
typedef struct Slot
{
  u8 flags;
  u8 pad[0x27];
} Slot;
typedef struct Game
{
  u8 pad00[0xE];
  u16 mode;
  u8 pad10[2];
  u16 opts;
  u8 pad14[0x1E - 0x14];
  u16 state;
  u8 pad20[0x31 - 0x20];
  u8 order[3];
  u8 pad34[0x48 - 0x34];
  Slot slots[1];
} Game;
extern Game *gRecords;
extern Obj *D_800C7F84;
extern void func_8003BA9C(void *);
extern s32 getTexturePack(s32, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern Obj *find_object_by_id(s32);

/* Adds the position icons for the cars in the race order to the HUD list.
 * Mode 1 shows the player's marker; mode 2 shows a marker and label for each
 * of the top three cars that are still racing. */
void func_8003970C(void *hud_list, s32 text_base, s32 layer)
{
  Obj *obj;
  Pos *pos;
  Widget *w;
  u32 i;
  s32 base_x;
  s32 base_y;
  s32 dx;
  u32 marker_x;
  u32 marker_y;
  s32 row_y;

  if (gRecords->state == 7)
  {
    return;
  }
  switch (gRecords->mode)
  {
    case 1:
      if (!(gRecords->slots[gRecords->order[1]].flags & 2))
      {
        return;
      }
      D_800C7F84 = find_object_by_id(1);
      base_x = D_800C7F84->pos->xC;
      base_y = D_800C7F84->pos->x8;
      row_y = base_y - 0x10;
      w = ((Widget *)sprite_create(hud_list, base_x - 0x32, row_y, (u16)(layer), func_8003BA9C, 0));
      w->text = getTexturePack(text_base + 0x4C, 0);
      w->obj = D_800C7F84;
      w = ((Widget *)sprite_create(hud_list, base_x - 0x46, base_y - 0x20, (u16)(layer), (SpriteHook)(0), 0));
      w->text = getTexturePack(text_base + 0x4C, 0);
      w->kind = 2;
      break;

    case 2:
      for (i = 1; i < 3; i++)
      {
        if (gRecords->slots[gRecords->order[i]].flags & 2)
        {
          obj = find_object_by_id(i * 2 - 1);
          pos = obj->pos;
          D_800C7F84 = obj;
          dx = 0;
          row_y = pos->x8 - 8;
          base_x = pos->xC - 0x10;
          marker_x = pos->xA + 0x14;
          marker_y = pos->xE + 6;
          if (!(gRecords->opts & 1))
          {
            base_x = pos->xC - 0x20;
            dx = (obj->type == 1) ? (0x14) : (0);
          }
          w = ((Widget *)sprite_create(hud_list, ((marker_x + base_x) - 0x1A) + dx, (marker_y + row_y) - 0xA, (u16)(layer), func_8003BA9C, 0));
          w->text = getTexturePack(text_base + 0x4C, 0);
          w->kind = 4;
          w->obj = D_800C7F84;
          w = ((Widget *)sprite_create(hud_list, ((marker_x + base_x) - 0x28) + dx, (row_y = marker_y + row_y) - 0x15, (u16)(layer), (SpriteHook)(0), 0));
          w->text = getTexturePack(text_base + 0x4C, 0);
          w->kind = 3;
        }
      }
      break;
  }
}
