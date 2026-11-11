typedef void (*SpriteHook)(void *);
typedef struct { u16 h0, h2, type, width, height; u8 a, b; u32 c; u8 **pal, **image; u32 x, y; } Tex3;
typedef struct { u8 count, pad[3]; Tex3 **tex; } Pack3;
typedef struct { u8 pad0[0xE]; u16 count; u8 pad10[2]; u16 flags; u8 pad14[0xA]; u16 mode; } Screen3F;
typedef struct { u8 pad0[8]; s16 pos[2]; s16 w; s16 h; } Info3F;
typedef struct { u8 pad0[0x178]; Info3F *info; } Car3F;
typedef struct { u8 pad0[0x70]; s16 ofs; u8 pad72[0xA4 - 0x72]; Pack3 *pack; Car3F *car; } Spr3F;
extern Screen3F *gRecords;
extern Car3F *g_camera;
extern Car3F *find_object_by_id(s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern Pack3 *getTexturePack(s32, s32);
extern void func_8003F11C(void *);
extern void func_8003F34C(void *);
extern void obj_update_timer(void *);

/* Spawns the three position sprites for each car in the race list. Only runs in
 * race modes (not mode 0 or 7). The sprites are placed relative to the car's
 * info block and the reference car g_camera, and use the pack at bankBase + 0x4C. */
void func_8003F834(s32 layer, s32 bankBase)
{
  u32 slot;
  u32 count;
  s32 j;
  Car3F *car;
  s16 *pos;
  s16 x;
  s16 y;
  Spr3F *spr;
  Pack3 *pack;
  if (gRecords->mode != 0 && gRecords->mode != 7)
  {
    count = gRecords->count;
    if (count != 0)
    {
    slot = 1;
    j = 1;
    do
    {
      car = find_object_by_id((slot - 1) * 2 + 1);
      pos = car->info->pos;
      x = car->info->w / 2;
      y = car->info->h / 4;
      if (gRecords->count == 2 && (gRecords->flags & 1))
      {
        y += 8;
      }
      spr = ((Spr3F *)sprite_create((void *)(layer), pos[0] + x, pos[1] + y, (s16)(15), func_8003F11C, 1));
      spr->pack = getTexturePack(bankBase + 0x4C, 0);
      spr->car = car;
      x = g_camera->info->w / 2;
      y = g_camera->info->h / 3;
      if (gRecords->count == 2 && (gRecords->flags & 1))
      {
        y += 12;
      }
      spr = ((Spr3F *)sprite_create((void *)(layer), pos[0] + x, pos[1] + y, (s16)(15), func_8003F34C, 1));
      pack = getTexturePack(bankBase + 0x4C, 0);
      spr->pack = pack;
      spr->ofs = -(pack->tex[0]->height >> 1);
      spr->car = car;
      x = g_camera->info->w / 2;
      y = g_camera->info->h / 2;
      if (gRecords->count == 2 && (gRecords->flags & 1))
      {
        y += 8;
      }
      spr = ((Spr3F *)sprite_create((void *)(layer), pos[0] + x, pos[1] + y, (s16)(15), obj_update_timer, 1));
      spr->pack = getTexturePack(bankBase + 0x4C, 0);
      spr->car = car;
      spr->ofs = -(spr->pack->tex[0]->height >> 1);
      slot++;
      j += 2;
    } while (slot <= count);
    }
  }
}
