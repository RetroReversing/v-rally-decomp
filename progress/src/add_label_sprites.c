typedef struct
{
  u8 pad0[0x76];
  u16 n;
  u16 part;
  s16 sub;
  u8 pad7C[0x14];
  u8 col[4];
  u8 pad94[0x10];
  s32 tex;
  void *owner;
} Spr;
extern void *g_camera;
s32 getTexturePack(void *, s32);
void *sprite_create(void *, s16, s16, s32, void (*)(void *), s32);
extern void func_8003A73C(void *);

/* Adds the five-part sprite row for one label at (x, y) into sprite_list. Part 0
 * gets a 0xD sub-sprite after it, part 2 a 0xC one; every sprite copies the
 * colour when col is given. */
void add_label_sprites(void *sprite_list, s32 x, s32 y, void (*hook)(void *), u8 *tex_table, u16 n, u8 *col)
{
  Spr *spr;
  u32 i;
  void *tex;
  tex = (void *) (tex_table + 0x4C);
  for (i = 0; i < 5; i++)
  {
    spr = sprite_create((void *)sprite_list, x, y, 2, hook, 0);
    spr->part = i;
    x += 7;
    spr->tex = getTexturePack(tex, 0);
    spr->n = n;
    spr->owner = g_camera;
    if (col != 0)
    {
      spr->col[0] = col[0];
      spr->col[1] = col[1];
      spr->col[2] = col[2];
      spr->col[3] = col[3];
    }
    if (i == 0)
    {
      spr = sprite_create((void *)sprite_list, x, y, 2, func_8003A73C, 0);
      x += 4;
      spr->tex = getTexturePack(tex, 0);
      spr->n = n;
      spr->sub = 0xD;
      spr->owner = g_camera;
      if (col != 0)
      {
        spr->col[0] = col[0];
        spr->col[1] = col[1];
        spr->col[2] = col[2];
        spr->col[3] = col[3];
      }
    }
    if (i == 2)
    {
      spr = sprite_create((void *)sprite_list, x, y, 2, func_8003A73C, 0);
      x += 5;
      spr->tex = getTexturePack((void *) (tex_table + 0x4C), 0);
      spr->n = n;
      spr->sub = 0xC;
      spr->owner = g_camera;
      if (col != 0)
      {
        spr->col[0] = col[0];
        spr->col[1] = col[1];
        spr->col[2] = col[2];
        spr->col[3] = col[3];
      }
    }
  }
}
