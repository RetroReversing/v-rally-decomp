typedef void (*SpriteHook)(void *);
typedef struct Ent { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Ent;
typedef struct Obj { u8 pad[0xC]; s32 type; u8 pad2[0x178 - 0x10]; Ent *ent; } Obj;
typedef struct Mgr { u8 pad[0xE]; u16 mode; u8 pad2[2]; u16 flags; } Mgr;
typedef struct Spr { u8 pad[0x78]; s16 frame; u8 pad2[0xA4 - 0x7A]; void *tex; } Spr;
extern Obj *g_camera;
extern Mgr *gRecords;
extern void func_8003C8A4(void *);
Obj *find_object_by_id(s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
void *getTexturePack(s32, s32);

/* Adds the two HUD marker sprites for slot 'slot' to the list 'sprite_list',
 * placed by the record mode: a pair beside the slot in mode 1, a pair under
 * the slot in mode 2 (or beside it when the record has no flag bit set). */
void func_8003C968(void *sprite_list, s32 tex_table, u16 slot)
{
  Obj *obj;
  Ent *ent;
  Mgr *hud;
  Spr *spr;
  s32 x, y, w, h;
  s32 lx, ty;
  u32 rx;
  u16 mode;

  obj = find_object_by_id(((slot - 1) * 2) | 1);
  ent = obj->ent;
  g_camera = obj;
  hud = gRecords;
  x = ent->x;
  y = ent->y;
  w = ent->w;
  mode = hud->mode;
  lx = x + 0x14;
  ty = y + 6;
  rx = w - 0x10;
  h = ent->h;
  switch (mode)
  {
    case 1:
      spr = ((Spr *)sprite_create(sprite_list, w - 0x2D, y + 0x1A, (s16)(2), func_8003C8A4, 0));
      spr->tex = getTexturePack(tex_table + 0x4C, 0);
      spr->frame = 0;
      spr = ((Spr *)sprite_create(sprite_list, rx + 0xFFEA, y + 0x1A, (s16)(2), func_8003C8A4, 0));
      spr->tex = getTexturePack(tex_table + 0x4C, 0);
      spr->frame = 1;
      break;
    case 2:
      if (hud->flags & 1)
      {
        spr = ((Spr *)sprite_create(sprite_list, w + 8, ty, (s16)(2), func_8003C8A4, 0));
        spr->tex = getTexturePack(tex_table + 0x4C, 0);
        spr->frame = 0;
        spr = ((Spr *)sprite_create(sprite_list, w + 0xF, ty, (s16)(2), func_8003C8A4, 0));
        spr->tex = getTexturePack(tex_table + 0x4C, 0);
        spr->frame = 1;
      }
      else
      {
        if (obj->type == 3)
        {
          lx = x + 6;
        }
        spr = ((Spr *)sprite_create(sprite_list, lx + 0x1A, h - 0x12, (s16)(2), func_8003C8A4, 0));
        spr->tex = getTexturePack(tex_table + 0x4C, 0);
        spr->frame = 0;
        spr = ((Spr *)sprite_create(sprite_list, lx + 0x21, h - 0x12, (s16)(2), func_8003C8A4, 0));
        spr->tex = getTexturePack(tex_table + 0x4C, 0);
        spr->frame = 1;
      }
      break;
  }
}
