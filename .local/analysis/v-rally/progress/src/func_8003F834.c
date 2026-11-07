typedef void (*SpriteHook)(void *);
typedef struct { u16 h0, h2, type, width, height; u8 a, b; u32 c; u8 **pal, **image; u32 x, y; } Tex3;
typedef struct { u8 count, pad[3]; Tex3 **tex; } Pack3;
typedef struct { u8 pad0[0xE]; u16 count; u8 pad10[2]; u16 flags; u8 pad14[0xA]; u16 mode; } Screen3F;
typedef struct { u8 pad0[8]; s16 pos[2]; s16 w; s16 h; } Info3F;
typedef struct { u8 pad0[0x178]; Info3F *info; } Car3F;
typedef struct { u8 pad0[0x70]; s16 ofs; u8 pad72[0xA4 - 0x72]; Pack3 *pack; Car3F *car; } Spr3F;
extern Screen3F *D_800C35A0;
extern Car3F *D_800C7F84;
extern Car3F *func_8004240C(s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
extern Pack3 *func_80034FF0(s32, s32);
extern void func_8003F11C(void *);
extern void func_8003F34C(void *);
extern void func_8003F2CC(void *);
void func_8003F834(s32 arg0, s32 arg1)
{
  u32 i;
  u32 n;
  s32 j;
  Car3F *car;
  s16 *pos;
  s16 x;
  s16 y;
  Spr3F *spr;
  Pack3 *pack;
  if (D_800C35A0->mode != 0 && D_800C35A0->mode != 7)
  {
    n = D_800C35A0->count;
    if (n != 0)
    {
    i = 1;
    j = 1;
    do
    {
      car = func_8004240C((i - 1) * 2 + 1);
      pos = car->info->pos;
      x = car->info->w / 2;
      y = car->info->h / 4;
      if (D_800C35A0->count == 2 && (D_800C35A0->flags & 1))
      {
        y += 8;
      }
      spr = ((Spr3F *)func_80040260((void *)(arg0), pos[0] + x, pos[1] + y, (s16)(15), func_8003F11C, 1));
      spr->pack = func_80034FF0(arg1 + 0x4C, 0);
      spr->car = car;
      x = D_800C7F84->info->w / 2;
      y = D_800C7F84->info->h / 3;
      if (D_800C35A0->count == 2 && (D_800C35A0->flags & 1))
      {
        y += 12;
      }
      spr = ((Spr3F *)func_80040260((void *)(arg0), pos[0] + x, pos[1] + y, (s16)(15), func_8003F34C, 1));
      pack = func_80034FF0(arg1 + 0x4C, 0);
      spr->pack = pack;
      spr->ofs = -(pack->tex[0]->height >> 1);
      spr->car = car;
      x = D_800C7F84->info->w / 2;
      y = D_800C7F84->info->h / 2;
      if (D_800C35A0->count == 2 && (D_800C35A0->flags & 1))
      {
        y += 8;
      }
      spr = ((Spr3F *)func_80040260((void *)(arg0), pos[0] + x, pos[1] + y, (s16)(15), func_8003F2CC, 1));
      spr->pack = func_80034FF0(arg1 + 0x4C, 0);
      spr->car = car;
      spr->ofs = -(spr->pack->tex[0]->height >> 1);
      i++;
      j += 2;
    } while (i <= n);
    }
  }
}
