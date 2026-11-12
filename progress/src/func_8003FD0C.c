extern u8 *gRecords;
extern struct O *g_camera;
typedef struct R
{
  u8 pad[8];
  u16 x;
  u16 y;
  u16 w;
  u16 h;
} R;
typedef struct O
{
  u8 pad[0x178];
  R *r;
} O;
extern u8 stream_state[];
O *find_object_by_id();
void gfx_draw_fill_rect();

/* Draws the viewport divider bar while the record state at gRecords+14 is 2. arg0 picks
 * the view (0 uses view 5, otherwise view 6). If bit 0 of the flags at gRecords+18 is
 * set, it draws a horizontal bar across the middle of the view, with an end cap at the
 * right. Otherwise it draws a vertical bar at the view's centre. */
void func_8003FD0C(s32 arg0)
{
  s16 bar[4];
  u8 bar_color[4];
  bar_color[0] = 0;
  bar_color[1] = 0;
  bar_color[2] = 0;
  bar_color[3] = 255;
  if (*(u16 *)(gRecords + 14) == 2)
  {
    if (!(arg0 & 0xFF))
      g_camera = find_object_by_id(5);
    else
      g_camera = find_object_by_id(6);
    if (*(u16 *)(gRecords + 18) & 1)
    {
      bar[0] = g_camera->r->x + 32;
      bar[1] = g_camera->r->y + (s16)g_camera->r->h / 2 - 1;
      bar[2] = g_camera->r->w - 32;
      bar[3] = g_camera->r->y + (s16)g_camera->r->h / 2 + 1;
      g_camera = find_object_by_id(5);
      gfx_draw_fill_rect(g_camera->r, bar, bar_color);
      bar[0] = g_camera->r->x + g_camera->r->w - 32;
      bar[1] = g_camera->r->y;
      bar[2] = g_camera->r->x + g_camera->r->w - 16;
      bar[3] = g_camera->r->h;
      gfx_draw_fill_rect(g_camera->r, bar, bar_color);
    }
    else
    {
      bar[0] = g_camera->r->x + (s16)g_camera->r->w / 2 - 1;
      bar[1] = g_camera->r->y;
      bar[2] = g_camera->r->x + (s16)g_camera->r->w / 2 + 1;
      bar[3] = g_camera->r->h;
      gfx_draw_fill_rect(g_camera->r, bar, bar_color);
    }
  }
}
