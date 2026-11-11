typedef struct { u8 w[4]; s16 h; } Elem6;
typedef struct { u32 a:1; u32 b:4; u32 c:1; u32 rest:26; } Flags56;
typedef struct { u8 pad[0x84]; Flags56 f; } Obj56;
typedef struct { u8 *items; u16 count; } List56;
void gfx_sync_render_state(Obj56 *, s32);
void DrawTexturedTriangle(void *arg0, u8 *arg1, Elem6 *arg2);
void gfx_draw_poly_quad(void *arg0, u8 *arg1, Elem6 *arg2);

/* Draws every 0x22-byte item in list: type 6 is a textured triangle and type 10 a
 * quad. Sets the render-state flags on obj first. */
void gfx_draw_item_list(Obj56 *obj, List56 *list, Elem6 *verts)
{
  u8 *item;
  s32 i;
  s32 n;
  item = list->items;
  n = list->count;
  obj->f.b = 1;
  *(u32 *)&obj->f = (*(u32 *)&obj->f & 0xFBFFFFFF) | 0x04000000;
  gfx_sync_render_state(obj, 1);
  for (i = 0; i < n; i++)
  {
    switch (item[3])
    {
      case 6:
        DrawTexturedTriangle(obj, item, verts);
        break;
      case 10:
        gfx_draw_poly_quad(obj, item, verts);
        break;
    }
    item += 0x22;
  }
}
