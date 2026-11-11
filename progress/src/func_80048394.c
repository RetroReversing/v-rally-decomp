typedef struct { u8 b[8]; } Pair;
typedef struct { u8 pad[6]; u16 n; } Frm;
typedef struct { Frm *f; } Anim0;
typedef struct { u8 pad[4]; Anim0 *a; } Anim;
typedef struct {
  u8 pad0[0xC];
  Anim *anim;
  u8 pad10[4];
  s16 x14;
  u8 pad16[6];
  s16 x1C;
  u8 pad1E[0x50 - 0x1E];
} Item;
typedef struct { Pair pos; u16 x8; u8 pad[0x2C - 0xA]; Item *cur; } Node;
typedef struct { u8 b[0x178]; Node *p; } Obj;
typedef struct { u8 pad[4]; u16 base; u8 pad6[0x24 - 6]; Item *l0; Item *l1; } Src;
extern Obj *g_camera;
extern u32 D_800AFA6C;
extern void viewport_build_dl(void *, s32, s32, s32);
/* Re-slots a camera's item run around its current position: saves the camera node's
 * position, moves it to the target's, then places three consecutive items (with their
 * scale values) starting at the item the offset falls on, and restores the position. */
void func_80048394(s32 a, Src *src, Obj *target, s32 scale)
{
  Pair saved_pos;
  Node *cam_node = g_camera->p;
  Item *frames;
  Item *item;
  s32 offset;
  s32 index;
  s32 prod;
  s32 count;

  if (D_800AFA6C & 1) {
    frames = src->l0;
  } else {
    frames = src->l1;
  }
  saved_pos = g_camera->p->pos;
  g_camera->p->pos = target->p->pos;
  count = frames->anim->a->f->n;
  offset = (s16) (src->base + target->p->x8);
  index = offset / count;
  prod = index * count;
  frames[index].x1C = scale * 4;
  frames[index].x14 = (prod - offset) * 4;
  cam_node->cur = item = &frames[index];
  viewport_build_dl(g_camera->p, 0, 0, 1);
  count = item->anim->a->f->n;
  {
    s32 rem = offset - prod;
    item[1].x1C = scale * 4;
    item[1].x14 = (count - rem) * 4;
    cam_node->cur = &frames[index + 1];
    viewport_build_dl(g_camera->p, 0, 0, 1);
    count = item[1].anim->a->f->n;
    item[2].x14 = (count * 2 - rem) * 4;
  }
  item[2].x1C = scale * 4;
  cam_node->cur = &frames[index + 2];
  viewport_build_dl(g_camera->p, 0, 0, 1);
  g_camera->p->pos = target->p->pos;
}
