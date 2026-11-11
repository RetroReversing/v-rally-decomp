void func_8004CF7C(s32, s32, s16, s16, f32, s32, s32);
void group_set_color(void *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
void *list_advance(u32, void *);
extern void *gSelectState;
extern s32 D_800A54D4;
extern s32 gStreamState;
extern s32 D_800D05D8;

/* Draws select-screen slot `slot`: walks to its list node, paints the node's box colour, then either draws the highlighted sprite (highlight in the low 16 bits) or the plain label. The fade flag at gSelectState+0x24D decides whether the sprite is drawn. */
void func_8005EE50(s32 slot, s32 highlight)
{
  void *info;
  void *node;
  void *listHead;
  s32 fadeOff;
  s8 spriteId;
  u16 sx;
  u16 sy;

  listHead = *((void **) (((u8 *) (&gStreamState)) + 0x325A));
  node = list_advance(slot - (*((u8 *) (((*((u8 **) (((u8 *) listHead) + 0x10))) + (((s16 *) listHead)[1] * 0x14)) + 0xD))), (void *)(*((void **) (((u8 *) gSelectState) + 0xC))));
  info = *((void **) (((u8 *) node) + 0x28));
  sx = ((u16 *) info)[3];
  sy = ((u16 *) info)[4];
  fadeOff = highlight;
  spriteId = fadeOff - 1;
  if ((*((u8 *) (((u8 *) node) + 0x42))) != 0)
  {
    group_set_color(((u8 *) node) + 4, 0xDC, 0xDC, 0xE, 0xFF);
    spriteId = fadeOff + 7;
  }
  else
  {
    group_set_color(((u8 *) node) + 4, *((u8 *) (((u8 *) node) + 0xF)), *((u8 *) (((u8 *) node) + 0x10)), *((u8 *) (((u8 *) node) + 0x11)), 0xFF);
  }
  if ((highlight << 0x10) != 0)
  {
    fadeOff = 0x24D;
    if (((s16) sx) < 0)
    {
      sx = -sx;
    }
    if (((s16) sy) < 0)
    {
      sy = -sy;
    }
    if ((*((u8 *) (((u8 *) gSelectState) + fadeOff))) == 0)
    {
      func_8004CF7C(D_800D05D8, (u16) spriteId, (s16) (sx - 0x60), (s16) sy, 1.0f, 0, 0xFF);
    }
  }
  else
  {
    draw_palette_sprite((void *)(((u8 *) node) + 4), (s16)((s16) sx), (s16)((s16) sy), (void *)(&D_800A54D4));
  }
}
