s32 func_8000BA38();
extern char D_800C02AE[];
typedef struct { u8 pad[6]; u16 w; u16 h; } Dim;
typedef struct { u8 pad[0x10]; u8 pos[0xC]; Dim *dim; } Spr;
typedef struct { u8 pad[0xC]; Spr *spr; s16 x; s16 y; u8 scale; u8 pct; u8 r; u8 g; u8 b; } Elem;
typedef struct { u8 pad[0x10]; u16 x; u16 y; } Pt;

void func_800370E8(Pt *a, Pt *b, Elem *e)
{
  s16 dx;
  s16 dy;
  s16 x;
  s16 y;
  u16 ny;

  dx = b->x - a->x;
  dy = b->y - a->y;
  e->x = a->x + dx * e->pct / 100;
  e->y = ny = a->y + dy * e->pct / 100;
  x = dx;
  y = dy;
  switch (e->scale) {
  case 200:
    x = e->x - e->spr->dim->w;
    y = ny - e->spr->dim->h;
    break;
  case 150:
    x = e->x - e->spr->dim->w * 3 / 4;
    y = ny - e->spr->dim->h * 3 / 4;
    break;
  case 100:
    x = e->x - (e->spr->dim->w >> 1);
    y = ny - (e->spr->dim->h >> 1);
    break;
  case 75:
    x = e->x - e->spr->dim->w * 3 / 8;
    y = ny - e->spr->dim->h * 3 / 8;
    break;
  case 50:
    x = e->x - (e->spr->dim->w >> 2);
    y = ny - (e->spr->dim->h >> 2);
    break;
  case 25:
    x = e->x - (e->spr->dim->w >> 3);
    y = ny - (e->spr->dim->h >> 3);
    break;
  }
  func_8000BA38(*(s32 *)(*(char **)(D_800C02AE + 0x7CD6) + 0x178), x, y, e->spr->pos, 0, e->scale, e->r, e->g, e->b, 0x87);
}
