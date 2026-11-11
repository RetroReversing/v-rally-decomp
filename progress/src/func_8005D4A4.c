typedef struct Tex
{
  char pad0[6];
  u16 w;
  u16 h;
} Tex;
typedef struct Img
{
  s32 pad0;
  Tex **tex;
} Img;
typedef struct Elem
{
  char pad0[0x24];
  Img **imgs;
  char pad28[0x37 - 0x28];
  u8 alpha;
} Elem;
extern u8 **D_800B55E4;
extern void *find_object_by_id(s32);
extern void func_8004CEB4(s32, Tex *, s16 *, u8, s32, s32, s32, s32, s32);

/* Draws the four corner overlay images of the HUD. split is the split-screen
 * flag: in split mode the images are drawn at 0.625 scale and moved to the
 * half-screen positions, otherwise at 1.25 scale on the full screen. */
void func_8005D4A4(s32 split)
{
  s16 rect[4];
  f32 scale;
  s32 handle;
  u8 *base;
  Tex **tex;
  Elem *e;
  scale = 1.25f;
  if (split & 0xFF)
  {
    scale = 0.625f;
  }
  base = *D_800B55E4;
  e = (Elem *) (base + 12);
  rect[0] = 0;
  rect[1] = (split & 0xFF) ? (135) : (269);
  rect[2] = (*e->imgs[3]->tex)->w * scale;
  rect[3] = (*e->imgs[3]->tex)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) find_object_by_id(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[3]->tex, rect, e->alpha, 0, 0, 100, 100, 0);
  e = (Elem *) (base + 68);
  rect[0] = 0;
  rect[1] = (split & 0xFF) ? (187) : (375);
  rect[2] = (*e->imgs[3]->tex)->w * scale;
  tex = e->imgs[3]->tex;
  rect[3] = (*tex)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) find_object_by_id(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[3]->tex, rect, e->alpha, 100, 100, 200, 200, 0);
  e = (Elem *) (base + 12);
  if (split & 0xFF)
  {
    rect[0] = 160;
    rect[1] = 135;
  }
  else
  {
    rect[0] = 320;
    rect[1] = 269;
  }
  rect[2] = (*e->imgs[0x17]->tex)->w * scale;
  rect[3] = (*e->imgs[0x17]->tex)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) find_object_by_id(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[0x17]->tex, rect, e->alpha, 0, 0, 100, 100, 0);
  e = (Elem *) (base + 68);
  if (split & 0xFF)
  {
    rect[0] = 160;
    rect[1] = 187;
  }
  else
  {
    rect[0] = 320;
    rect[1] = 375;
  }
  rect[2] = (*e->imgs[0x17]->tex)->w * scale;
  rect[3] = (*e->imgs[0x17]->tex)->h * scale;
  handle = *((s32 *) (((u8 *) find_object_by_id(1)) + 0x178));
  func_8004CEB4(handle, *e->imgs[0x17]->tex, rect, e->alpha, 100, 100, 200, 200, 0);
}
