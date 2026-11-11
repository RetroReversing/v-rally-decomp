typedef struct { u8 pad[8]; u16 count; } AnimFrame;
typedef struct { AnimFrame *frame; } AnimTrack;
typedef struct { u8 pad[4]; AnimTrack *track; } AnimRef;
typedef struct { u8 pad[0xC]; AnimRef *anim; } Item;
typedef struct { u8 pad[0xA]; s16 x; u8 padC[2]; s16 y; } Box;
typedef struct { u8 pad[0x178]; Box *box; } GameObj;
typedef struct {
  u8 pad0[0xC];
  u8 seg0[4];
  u16 angle;
  u8 pad12[2];
  s32 angle_step;
  s32 offset_a;
  u8 pad1C[0x14];
  Item *left_item;
  u8 pad34[0x10];
  u8 seg1[4];
  s16 angle2;
  u8 pad4A[0x1E];
  Item *right_item;
  u8 pad6C[0x10];
  s32 offset_b;
} Sprite;
void func_80048394(void *, void *, void *, s32, s32);
void drawPanelFill(s32, s32, void *, void *);

/* Advances the sprite's angle (a full turn is 0x1000 units, stored as 0x600 steps)
   and draws its two segments: seg0 at the object's left edge, seg1 placed after it
   using the frame counts of the two attached items. */
void func_80048878(GameObj *obj, Sprite *s)
{
  s16 angle;
  s32 offset;
  s32 w_left;
  s32 w_right;
  s32 width;
  void *p;

  angle = s->angle + s->angle_step;
  if (angle < 0) angle += 0x1000;
  angle = (angle * 0x600) / 0x1000;
  s->angle = angle;
  s->angle2 = angle;
  offset = -s->offset_b - s->offset_a;
  w_right = s->right_item->anim->track->frame->count;
  w_left = s->left_item->anim->track->frame->count;
  p = s->seg0;
  func_80048394(s, p, obj, obj->box->x + offset, 0);
  if (offset != 0)
    drawPanelFill(obj->box->x, offset, p, obj);
  {
    void *q = s->seg1;
    func_80048394(s, q, obj, obj->box->x + offset + w_left, 0);
    width = offset + w_left + w_right;
    if (width < 0) width = 0;
    drawPanelFill(obj->box->x + width, obj->box->y, q, obj);
  }
}
