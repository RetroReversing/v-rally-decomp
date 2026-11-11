void draw_sprite_obj(void *a0, s16 a1, s16 a2, void *a3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8, s32 s9);
extern char gStreamState[];

/* Moves a HUD marker toward its source position (arg0: x at +0x10, y at +0x12; the marker
 * record arg1 holds its own x/y at +0x10/+0x12 and its colour at +0x16..+0x18), then draws
 * the marker sprite for the current track object. */
void func_80036FD8(void *srcPos, void *marker)
{
  s16 markerY;
  s32 targetX;
  s32 targetY;
  void *trackObj;
  unsigned long slotY;
  u16 srcY;
  void *sprite;
  void *texInfo;
  char *markerX;
  int stepX;
  trackObj = *((void **) (((char *) (*((void **) (gStreamState + 0x7CD6)))) + 0x178));
  targetX = ((s16) (*((u16 *) (((char *) trackObj) + 0xC)))) / 2;
  srcY = *((u16 *) (((char *) srcPos) + 0x12));
  slotY = *((u16 *) (((char *) trackObj) + 0xE));
  markerX = ((char *) marker) + 0x10;
  *((u16 *) markerX) = (u16) (targetX + (((s32) (((s16) (targetX - (*((u16 *) (((char *) srcPos) + 0x10))))) * 0x19)) >> 5));
  targetY = ((s32) (((s16) slotY) + (((u32) (slotY << 0x10)) >> 0x1F))) >> 1;
  stepX = ((s16) (targetY - srcY)) * 0x19;
  sprite = *((void **) (((char *) marker) + 0xC));
  markerY = targetY;
  markerY = markerY + (((s32) stepX) >> 5);
  *((s16 *) (((char *) marker) + 0x12)) = markerY;
  texInfo = *((void **) (((char *) sprite) + 0x1C));
  draw_sprite_obj(*((void **) (((char *) (*((void **) (gStreamState + 0x7CD6)))) + 0x178)), (s16) ((*((u16 *) markerX)) - (*((u16 *) (((char *) texInfo) + 6)))), (s16) (markerY - (*((u16 *) (((char *) texInfo) + 8)))), sprite + 0x10, 8, 0x64, (s32) (*((u8 *) (((char *) marker) + 0x16))), (s32) (*((u8 *) (((char *) marker) + 0x17))), (s32) (*((u8 *) (((char *) marker) + 0x18))), 0xD2);
}
