extern u8 g_dark_mode;
extern s16 D_800B5B50;
extern s32 gPadFlags;
extern char *g_camera;
s32 getCounterValue();
typedef struct { u8 pad[0x10]; s32 x0; s32 p14; s32 x1; s32 p1c; s32 z0; s32 z1; u8 p28[8]; } Box;
typedef struct { Box *boxes; u16 n; } BoxList;
typedef struct { u8 pad[0xE0]; f32 x; f32 y; f32 z; } Pos;

/* Returns the box in the list that contains pos (x/z test only). The hint box is tried first;
 * if pos is still inside it, it is returned without a scan. Also clears D_800B5B50 on the way. */
Box *boxListFind(BoxList *list, Pos *pos, Box *hint)
{
  char pad[8];
  s32 i;
  s32 n;
  Box *boxes;

  if (hint != NULL && !(pos->x < hint->x0) && !(hint->x1 < pos->x) && !(pos->z < hint->z0) && !(hint->z1 < pos->z)) {
    if ((getCounterValue(*(s32 *)(g_camera + 0x24)) < 50 && g_dark_mode == 0) || (gPadFlags & 0x800)) {
      D_800B5B50 = 0;
    }
    return hint;
  }
  n = list->n;
  D_800B5B50 = 0;
  i = 0;
  if (n > 0) {
    boxes = list->boxes;
    do {
      if (!(pos->x < boxes[i].x0) && !(boxes[i].x1 < pos->x) && !(pos->z < boxes[i].z0) && !(boxes[i].z1 < pos->z)) return &boxes[i];
      i++;
    } while (i < n);
  }
  return NULL;
}
