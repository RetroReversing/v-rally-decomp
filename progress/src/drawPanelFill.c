typedef struct
{
  u8 r;
  u8 g;
  u8 b;
  u8 a;
} Color4;

typedef struct
{
  s16 x0;
  s16 y0;
  s16 x1;
  s16 y1;
} Rect;

/* Panel being drawn: its screen rect and fill colour. */
typedef struct
{
  u8 pad0[0x2C];
  Rect *rect;
  Color4 col;
} Panel;

typedef struct
{
  u8 pad0[8];
  s16 x0;
  s16 y0;
  s16 x1;
  s16 y1;
} Box;

/* Camera viewport: its box is the screen area in view. */
typedef struct
{
  u8 pad0[0x178];
  Box *box;
} Viewport;

typedef struct
{
  u32 w0;
  u32 w1;
} Gfx;

extern Viewport *g_camera;
extern s32 view_get_ctx_id(void *);
extern Gfx *gfx_get_dl(s32);
extern void gfx_set_dl(s32, Gfx *);

/* Appends the RDP commands that fill a panel's rect with its colour, scissored to
 * the camera box, to the display list. Skipped when the rect is off screen. */
#define DL_CMD(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
#define PACK_RGBA16(c) ((((c)->r << 8) & 0xF800) | (((c)->g << 3) & 0x7C0) | (((c)->b >> 2) & 0x3E) | 1)

void drawPanelFill(s32 y, s32 height, Panel *panel, Viewport *vp)
{
  Color4 c;
  Gfx *g;
  s32 h;
  u32 col;
  if ((height > 0) && (y < (g_camera->box->y0 + g_camera->box->y1)))
  {
    panel->rect->x0 = vp->box->x0;
    panel->rect->y0 = y;
    panel->rect->x1 = vp->box->x0 + vp->box->x1;
    panel->rect->y1 = y + height;
    c = panel->col;
    h = view_get_ctx_id(g_camera->box);
    g = gfx_get_dl(h);
    DL_CMD(g++, 0xE7000000, 0);
    DL_CMD(g++, 0xE3000A01, 0x300000);
    DL_CMD(g++, (0xED000000 | ((((s32) (g_camera->box->x0 * 4.0f)) & 0xFFF) << 12)) | (((s32) (g_camera->box->y0 * 4.0f)) & 0xFFF),
        ((((s32) (g_camera->box->x1 * 4.0f)) & 0xFFF) << 12) | (((s32) (g_camera->box->y1 * 4.0f)) & 0xFFF));
    DL_CMD(g++, 0xF7000000, (PACK_RGBA16(&panel->col) << 16) | PACK_RGBA16(&panel->col));
    DL_CMD(g++, (0xF6000000 | (((panel->rect->x1 - 1) & 0x3FF) << 14)) | (((panel->rect->y1 - 1) & 0x3FF) << 2),
        ((panel->rect->x0 & 0x3FF) << 14) | ((panel->rect->y0 & 0x3FF) << 2));
    DL_CMD(g++, 0xE7000000, 0);
    gfx_set_dl(h, g);
  }
}
