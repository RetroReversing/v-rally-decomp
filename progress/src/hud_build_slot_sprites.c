typedef struct 
{
  s16 pad0[4];
  s16 x;
  s16 y;
} Pos;
typedef struct 
{
  u8 pad0[0xC];
  s32 type;
  u8 pad10[0x168];
  Pos *pos;
} Mgr;
typedef struct 
{
  u8 flags;
  u8 pad[0x27];
} Slot;
typedef struct 
{
  u8 pad0[0xE];
  u16 mode;
  u8 pad10[2];
  u16 flags12;
  u8 pad14[0xA];
  u16 state;
  u8 pad20[0x11];
  u8 sel[0x17];
  Slot slots[4];
} Game;
typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
typedef void (*SpriteHook)(void *);
typedef struct 
{
  u8 pad0[0x76];
  u16 n;
  s16 part;
  u8 pad7A[0x16];
  u8 r;
  u8 g;
  u8 b;
  u8 a;
  u8 pad94[0x10];
  Pack3 *tex;
  Mgr *owner;
} Spr;
extern Game *D_800C35A0;
extern Mgr *D_800C7F84;
Pack3 *func_80034FF0(s32, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
struct N;
struct N *func_8004240C(s32);
extern void func_8003ED04(void *);
extern void func_8003ED94(void *);
extern void func_8003EE84(void *);
extern void func_8003EF20(void *);

/* Builds the position-HUD sprites for the race: mode 1 draws the slot rows,
 * mode 2 draws the three-part sprite set plus the coloured overlay for each
 * manager that a slot in the HUD selects. */
void hud_build_slot_sprites(s32 pool, s32 tex_base)
{
  SpriteHook hook;
  s32 mid_part;
  s32 mid_part2;
  s32 row_tex;
  s32 tex_first;
  s32 tex_mid;
  s32 tex_id;
  s16 left_x;
  Pos *pos;
  Pos *start_pos;
  Mgr *m;
  Spr *s;
  s32 x;
  s32 base_x;
  s32 y;
  u32 slot_idx;
  u32 rows_done;
  u32 row_no;
  s32 mgr_key;
  s16 yy;
  s16 x_mid;
  s16 x_right;
  u16 state;
  u16 mode;

  start_pos = D_800C7F84->pos;
  base_x = start_pos->x;
  x = base_x + 0x14;
  y = start_pos->y + 6;
  state = D_800C35A0->state;
  if (state == 7)
  {
    return;
  }
  mode = D_800C35A0->mode;
  switch (mode)
  {
    case 1:
      if (state == 0)
    {
      if (D_800C35A0->slots[D_800C35A0->sel[1]].flags & 1)
      {
        s = func_80040260((void *)pool, x, y, 5, func_8003ED04, mode);
        tex_first = (s32) ((u32)tex_base + 0x4CU);
        s->tex = func_80034FF0(tex_first, 0);
        s->part = 0;
        s->owner = D_800C7F84;
        s = func_80040260((void *)pool, base_x + 0x1C, y, 5, func_8003ED04, mode);
        tex_mid = (s32) ((u32)tex_base + 0x4CU);
        s->tex = func_80034FF0(tex_mid, 0);
        s->part = 1;
        s->owner = D_800C7F84;
        s = func_80040260((void *)pool, base_x + 0x24, y, 5, func_8003ED04, mode);
        s->tex = func_80034FF0(tex_mid, 0);
        s->part = 2;
        s->owner = D_800C7F84;
      }
    }
    else
    {
      rows_done = 0;
      if (D_800C35A0->slots[D_800C35A0->sel[1]].flags & 4)
      {
        hook = func_8003ED94;
        mid_part = 1;
        row_tex = (s32)((u32)tex_base + 0x4CU);
mode1_rows:
        {
          yy = y + (rows_done * 11);
          s = func_80040260((void *)pool, 0x1C, yy, 5, hook, mid_part);
          s->tex = func_80034FF0(row_tex, 0);
          s->part = 0;
          row_no = rows_done + 1;
          s->n = row_no;
          s->owner = D_800C7F84;
          s = func_80040260((void *)pool, 0x24, yy, 5, hook, mid_part);
          s->tex = func_80034FF0(row_tex, 0);
          s->part = mid_part;
          s->n = row_no;
          s->owner = D_800C7F84;
          s = func_80040260((void *)pool, 0x2C, yy, 5, hook, mid_part);
          s->tex = func_80034FF0(row_tex, 0);
          s->part = 2;
          s->n = row_no;
          s->owner = D_800C7F84;
        }
        rows_done = row_no;
        if (rows_done < 4) goto mode1_rows;
      }
    }
      break;

    case 2:
      slot_idx = 1;
      mgr_key = 1;
      tex_id = (u32)tex_base + 0x4CU;
      mid_part2 = 1;
      tex_base = 0;
      do
    {
      m = (Mgr *)func_8004240C(mgr_key);
      pos = m->pos;
      D_800C7F84 = m;
      x = pos->x;
      y = pos->y + 6;
      if (!(D_800C35A0->flags12 & 1))
      {
        x += 0x14;
        if (m->type == 3)
        {
          x -= 0xE;
        }
      }
      if ((D_800C35A0->state != 0) && (D_800C35A0->slots[D_800C35A0->sel[slot_idx]].flags & 4))
      {
        left_x = (s16)(x + 8);
        yy = y + 10;
        s = func_80040260((void *)pool, left_x, yy, 5, func_8003EF20, mid_part2);
        x_mid = x + 0x10;
        s->tex = func_80034FF0(tex_id, 0);
        s->part = 0;
        s->owner = D_800C7F84;
        s = func_80040260((void *)pool, x_mid, yy, 5, func_8003EF20, mid_part2);
        x_right = x + 0x18;
        s->tex = func_80034FF0(tex_id, 0);
        s->part = mid_part2;
        s->owner = D_800C7F84;
        s = func_80040260((void *)pool, x_right, yy, 5, func_8003EF20, mid_part2);
        s->tex = func_80034FF0(tex_id, 0);
        s->part = 2;
        s->owner = D_800C7F84;
        s = func_80040260((void *)pool, left_x, yy, 5, func_8003EE84, mid_part2);
        s->tex = func_80034FF0(tex_id, 0);
        s->owner = D_800C7F84;
        s->part = 0;
        s->n = tex_base;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
        s = func_80040260((void *)pool, x_mid, yy, 5, func_8003EE84, mid_part2);
        s->tex = func_80034FF0(tex_id, 0);
        s->owner = D_800C7F84;
        s->part = mid_part2;
        s->n = tex_base;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
        s = func_80040260((void *)pool, x_right, yy, 5, func_8003EE84, mid_part2);
        s->tex = func_80034FF0(tex_id, 0);
        s->owner = D_800C7F84;
        s->part = 2;
        s->n = tex_base;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
      }
      mgr_key += 2;
      tex_base++;
      slot_idx++;
    }
    while (slot_idx < 3);
      break;

  }

}
