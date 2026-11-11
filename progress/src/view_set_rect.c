typedef struct { s16 x; s16 y; s16 w; s16 h; } Rect5500;
typedef struct { s16 x0; s16 y0; s16 x1; s16 y1; Rect5500 r; u8 pad10[0xC]; void *vp; } View5500;
typedef struct { s16 pad[2]; s16 w; s16 h; } Screen5500;
typedef struct { u32 w0; u32 w1; } Gfx5500;
s32 view_get_ctx_id(void *);
Gfx5500 *gfx_get_dl(s32);
void gfx_set_dl(s32, Gfx5500 *);
void func_8000DEF0(void *, Rect5500 *);
u32 osVirtualToPhysical(void *);
extern Screen5500 *gSceneSlot0;

/* Sets a view's rectangle from rect, clipping the view's edges to the screen,
 * and appends the texture-setup and viewport/scissor commands for it to the
 * display list of the view's context. */
void view_set_rect(void *vv, Rect5500 *r)
{
  View5500 *view = vv;
  s32 ctx_id;
  Gfx5500 *gdl;
  View5500 *new_var;
  Gfx5500 *cmd;
  s32 t;
  s32 ry;
  ctx_id = view_get_ctx_id(view);
  gdl = gfx_get_dl(ctx_id);
  view->r.x = r->x;
  view->r.y = r->y;
  view->r.w = r->w;
  view->r.h = r->h;
  t = view->r.x;
  if (view->r.x >= 0)
  {
    view->x0 = view->r.x;
    if ((t + view->r.w) <= gSceneSlot0->w)
    {
      view->x1 = view->x0 + view->r.w;
    }
  }
  else
  {
    view->x1 = view->r.w + view->r.x;
  }
  new_var = view;
  ry = view->r.y;
  if (view->r.y >= 0)
  {
    view->y0 = view->r.y;
    if ((ry + view->r.h) <= gSceneSlot0->h)
    {
      view->y1 = view->y0 + view->r.h;
    }
  }
  else
  {
    new_var->y1 = view->r.w + view->r.y;
  }
  func_8000DEF0(view->vp, r);
  cmd = gdl++;
  cmd->w0 = 0xDC080008;
  cmd->w1 = osVirtualToPhysical(view->vp);
  {
  Gfx5500 *cmd;
  cmd = gdl++;
  cmd->w0 = (0xED000000 | ((((s32) (((f32) view->x0) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) view->y0) * 4.0f)) & 0xFFF);
  cmd->w1 = ((((s32) (((f32) view->x1) * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) view->y1) * 4.0f)) & 0xFFF);
  }
  gfx_set_dl(ctx_id, gdl);
}
