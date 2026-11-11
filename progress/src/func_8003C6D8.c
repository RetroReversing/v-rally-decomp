typedef void (*SpriteHook)(void *);
s32 getTexturePack();
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
void *find_object_by_id();
void func_8003C698(void *);
extern void *g_camera;
extern char *gRecords;

/* Spawns the sprite(s) for the record screen, positioned from the camera's view rect.
 * The mode in gRecords[0xE] picks the layout: 1 = one sprite, 2 = a new camera view
 * with a sprite offset by its bonus, anything else does nothing. */
void func_8003C6D8(s32 ctx, s32 slot, s32 arg2)
{
  s32 spriteId;
  char *rec;
  s16 x;
  s16 y;
  s32 bonus;
  s32 sprite;
  s32 posY;
  s32 *new_var2;
  void *cam;
  void *camera;
  s32 id;
  u16 flags;
  rec = *((char **) (((char *) g_camera) + 0x178));
  x = *((s16 *) (rec + 0x8));
  y = *((s16 *) (rec + 0xA));
  sprite = x + (*((s16 *) (rec + 0xC)));
  posY = y + (*((s16 *) (rec + 0xE)));
  switch (*((u16 *) (gRecords + 0xE)))
  {
    case 1:
      sprite = (s32) ((void *)sprite_create((void *)(ctx), (s16) (sprite - 0x26), (s16) (posY - 0x22), 3, func_8003C698, 0));
      id = (spriteId = getTexturePack(slot + 0x4C, 0));
      camera = g_camera;
      *((s32 *) (((char *) sprite) + 0xA4)) = id;
      break;

    case 2:
      cam = find_object_by_id(((arg2 - 1) * 2) | 1, x, y, arg2);
      bonus = 0;
      flags = *((u16 *) (gRecords + 0x12));
      g_camera = cam;
      if (!(flags & 1))
    {
      new_var2 = (s32 *) (((char *) cam) + 0xC);
      sprite -= 0x10;
      bonus = (-((*new_var2) == 1)) & 0x14;
    }
      sprite = (s32) ((void *)sprite_create((void *)(ctx), (s16) ((sprite + 0xFFEEU) + bonus), (s16) (posY - 0x1A), 3, func_8003C698, 0));
      id = getTexturePack(slot + 0x4C, 0);
      camera = g_camera;
      *((s32 *) (((char *) sprite) + 0xA4)) = id;
      *((s16 *) (((char *) sprite) + 0x98)) = 0x600;
      *((s16 *) (((char *) sprite) + 0x9A)) = 0x600;
      break;

    default:
      return;

  }

  *((void **) (((char *) sprite) + 0xA8)) = camera;
}
