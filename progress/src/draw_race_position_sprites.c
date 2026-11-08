typedef void (*SpriteHook)(void *);
static inline s32 carflag(u8 *g, u32 i) { u8 *c = g + (g + i)[0x31] * 40; return c[0x48] & 8; }
#define CARFLAG(i) carflag(D_800C35A0, i)
typedef struct Tex3
{
  u16 h0;
  u16 h2;
  u16 type;
  u16 width;
  u16 height;
  u8 a;
  u8 b;
  u32 c;
  u8 **pal;
  u8 **image;
  u32 x;
  u32 y;
} Tex3;
typedef struct 
{
  u8 count;
  u8 pad[3];
  Tex3 **tex;
} Pack3;
typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
} Rect;
typedef struct 
{
  u8 pad[8];
  Rect r;
} RectHolder;
typedef struct 
{
  u8 pad[0x178];
  RectHolder *rh;
} Node;
typedef struct 
{
  u8 pad0[0x70];
  s16 ox;
  s16 oy;
  u8 pad74[6];
  s16 frame;
  u8 pad7C[0x17];
  u8 alpha;
  u8 pad94[4];
  s16 sx;
  s16 sy;
  u8 pad9C[4];
  s32 mode;
  Pack3 *pack;
  Node *node;
} Spr;
extern u8 *D_800C35A0;
extern Node *D_800C7F84;
Pack3 *func_80034FF0(s32 id, s32 extra);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
Node *func_8004240C(s32 arg0);
void func_8003F05C(void *);
void func_8003EFF8(void *);

/* Draws the position sprite for each of the first few cars (sprite pack base_id+0x4C),
 * plus a flag sprite beside it for cars with CARFLAG set. Skipped in the late race state
 * when fewer than 3 cars are left. */
void draw_race_position_sprites(s32 list, s32 base_id)
{
  u32 car_count;
  s32 dy;
  Rect *rect;
  Spr *pos_spr;
  Spr *flag_spr;
  Tex3 *tex;
  u32 n;
  u32 i;
  s16 x;
  s16 y;
  s32 half_w;
  s32 half_h;
  s32 few;
  dy = 0;
  flag_spr = NULL;
  if (((*((u16 *) (D_800C35A0 + 0x1E))) == 7) && ((*((u16 *) (D_800C35A0 + 0xE))) < 3))
  {
    return;
  }
  car_count = D_800C35A0[0xF];
  if (car_count < 3)
  {
    i = 1;
    if (i <= car_count)
    for (n = car_count; i <= n; i++)
    {
      few = n < 3;
      D_800C7F84 = func_8004240C(((i - 1) * 2) | 1);
      rect = &D_800C7F84->rh->r;
      x = rect->x;
      y = rect->y;
      switch (n)
      {

        case 1:
          dy = 0x4C;
          x = rect->w / 2;
          y = (rect->h / 5) - 16;
          break;

        case 2:
          if ((*((u16 *) (D_800C35A0 + 0x12))) & 1)
        {
          dy = 0x20;
          x += rect->w / 2;
          y = (y + (rect->h / 3)) - 20;
        }
        else
        {
          dy = 0x5C;
          x += rect->w / 2;
          y = (y + (rect->h / 5)) + 12;
        }
          break;

      }

      if (CARFLAG(i))
      {
        flag_spr = ((Spr *)func_80040260((void *)(list), x, y + 10, (s16)(8), func_8003F05C, 1));
        flag_spr->pack = func_80034FF0(base_id + 0x4C, 0);
        flag_spr->mode = 2;
        flag_spr->node = D_800C7F84;
        flag_spr->alpha = 0xB4;
      }
      pos_spr = ((Spr *)func_80040260((void *)(list), x, rect->y + dy, (s16)(8), func_8003EFF8, 1));
      pos_spr->pack = func_80034FF0(base_id + 0x4C, 0);
      pos_spr->frame = 5;
      pos_spr->node = D_800C7F84;
      tex = pos_spr->pack->tex[pos_spr->frame];
      half_w = tex->width >> 1;
      half_h = tex->height >> 1;
      if (n < 2)
      {
        pos_spr->ox = -half_w;
        pos_spr->oy = -half_h;
        if (CARFLAG(i))
        {
          flag_spr->oy = -(pos_spr->pack->tex[flag_spr->frame]->height >> 1);
        }
      }
      else
        if (few)
      {
        if ((*((u16 *) (D_800C35A0 + 0x12))) & 1)
        {
          pos_spr->sx = 0x480;
          pos_spr->sy = 0x480;
          if (CARFLAG(i))
          {
            flag_spr->sx = 0x480;
            flag_spr->sy = 0x480;
          }
          pos_spr->ox = (half_w / 4) - half_w;
        }
        else
        {
          pos_spr->ox = -(pos_spr->pack->tex[0]->width >> 1);
        }
        pos_spr->oy = -(pos_spr->pack->tex[0]->height >> 1);
        if (CARFLAG(i))
        {
          flag_spr->oy = -(pos_spr->pack->tex[0]->height >> 1);
        }
      }
      else
      {
        pos_spr->sx = 0x800;
        pos_spr->sy = 0x800;
      }
    }

  }
}
