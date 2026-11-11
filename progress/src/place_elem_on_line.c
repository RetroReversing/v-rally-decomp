s32 draw_sprite_obj();
extern u8 *g_camera;
typedef struct { u8 pad[6]; u16 w; u16 h; } Size;
typedef struct { u8 pad[0x10]; u8 obj_head[0xC]; Size *size; } Spr;
typedef struct { u8 pad[0xC]; Spr *spr; s16 x; s16 y; u8 scale; u8 pct; u8 r; u8 g; u8 b; } Elem;
typedef struct { u8 pad[0x10]; u16 x; u16 y; } Pt;

/* Moves elem to elem->pct percent of the way from 'from' to 'to', then draws its sprite
 * centred on that point, shrunk or grown by elem->scale (a percentage). */
void place_elem_on_line(Pt *from, Pt *to, Elem *elem)
{
  s16 dx;
  s16 dy;
  s16 x;
  s16 y;
  u16 new_y;

  dx = to->x - from->x;
  dy = to->y - from->y;
  elem->x = from->x + dx * elem->pct / 100;
  elem->y = new_y = from->y + dy * elem->pct / 100;
  x = dx;
  y = dy;
  switch (elem->scale) {
  case 200:
    x = elem->x - elem->spr->size->w;
    y = new_y - elem->spr->size->h;
    break;
  case 150:
    x = elem->x - elem->spr->size->w * 3 / 4;
    y = new_y - elem->spr->size->h * 3 / 4;
    break;
  case 100:
    x = elem->x - (elem->spr->size->w >> 1);
    y = new_y - (elem->spr->size->h >> 1);
    break;
  case 75:
    x = elem->x - elem->spr->size->w * 3 / 8;
    y = new_y - elem->spr->size->h * 3 / 8;
    break;
  case 50:
    x = elem->x - (elem->spr->size->w >> 2);
    y = new_y - (elem->spr->size->h >> 2);
    break;
  case 25:
    x = elem->x - (elem->spr->size->w >> 3);
    y = new_y - (elem->spr->size->h >> 3);
    break;
  }
  draw_sprite_obj(*(s32 *)(g_camera + 0x178), x, y, elem->spr->obj_head, 0, elem->scale, elem->r, elem->g, elem->b, 0x87);
}
