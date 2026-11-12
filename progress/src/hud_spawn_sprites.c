typedef void (*SpriteHook)(void *);
extern u8 *gRecords;
extern u8 *g_camera;
extern s32 getTexturePack(s32, s32);
extern void func_8003C6D8(void *, s32, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern void *find_object_by_id(s32);
extern void func_8003BA58(void *);
extern void func_8003BADC(void *);
typedef struct 
{
  u8 pad_0[0x78];
  s16 unk78;
  s16 unk7A;
  u8 pad_7C[0x17];
  s8 unk93;
  u8 pad_94[0xC];
  s32 unkA0;
  s32 unkA4;
  void *unkA8;
} Obj;
typedef struct 
{
  s16 unk0[4];
  s16 unk8;
  s16 unkA;
  s16 unkC;
  s16 unkE;
} Rect;

/* Spawns the HUD sprites for the current screen mode: mode 1 adds one pair of
 * marker sprites, mode 2 adds a pair per player (1..N) whose flag at 0x48 is set,
 * each pair being a draw sprite plus its clear hook. Does nothing on screen 7. */
void hud_spawn_sprites(void *arg0, s32 arg1)
{
  s32 mode;
  u8 *g = gRecords;
  u32 i;
  s32 k;
  int new_var;
  s16 x;
  s16 y;
  Obj *o;
  u8 *t;
  Rect *r;
  s32 add;
  s32 sx;
  u8 *new_var2;
  s32 sy;
  if ((*((u16 *) (g + 0x1E))) == 7)
  {
    return;
  }
  mode = *((u16 *) (g + 0xE));
  switch (mode)
  {
    case 1:
      new_var2 = g + g[0x32] * 0x28;
      if (new_var2[0x48] & 2)
    {
      u8 *t1;
      Rect *r1;
      s32 cx;
      s32 cy;
      t1 = find_object_by_id(1);
      r1 = *((Rect **) (t1 + 0x178));
      g_camera = t1;
      sx = r1->unkC;
      cy = r1->unkE;
      y = sx - 0x66;
      x = cy - 0x54;
      o = ((void *)sprite_create(arg0, y, x, 5, (SpriteHook)(0), mode));
      o->unkA4 = getTexturePack(arg1 + 0x4C, 0);
      o->unk7A = 0xC;
      o->unkA0 = 2;
      o->unkA8 = g_camera;
      o->unk93 = 0x64;
      func_8003C6D8(arg0, arg1, 0);
      o = ((void *)sprite_create(arg0, y, x, 5, func_8003BADC, mode));
      o->unk78 = 0;
      o->unkA4 = getTexturePack(arg1 + 0x4C, 0);
      o->unk7A = 8;
      o->unkA8 = g_camera;
    }
      break;

    case 2:
      for (i = 1, k = 1; i <= (*((u16 *) (gRecords + 0xE))); i++, k += 2)
    {
      g = gRecords;
      g += (g + i)[0x31] * 0x28;
      if (g[0x48] & 2)
      {
        t = find_object_by_id(i * 2 - 1);
        r = *((Rect **) (t + 0x178));
        g_camera = t;
        add = 0;
        sx = r->unk8 + r->unkC;
        sy = r->unkA + r->unkE;
        if (!((*((u16 *) (gRecords + 0x12))) & 1))
        {
          sx -= 0x10;
          new_var2 = t + 0xC;
          add = (-((*((s32 *) new_var2)) == 1)) & 0x14;
        }
        x = (u16)sx + (u16)-0x39 + add;
        y = sy - 0x38;
        o = ((void *)sprite_create(arg0, x, y, 5, func_8003BA58, 1));
        o->unkA4 = getTexturePack(arg1 + 0x4C, 0);
        o->unk7A = 0xD;
        o->unkA0 = 2;
        o->unkA8 = g_camera;
        func_8003C6D8(arg0, arg1, i);
        o = ((void *)sprite_create(arg0, x, y, 5, func_8003BADC, 1));
        o->unk78 = 0;
        o->unkA4 = getTexturePack(arg1 + 0x4C, 0);
        o->unk7A = 0xA;
        o->unkA8 = g_camera;
      }
    }

      break;

  }

}
