void func_8004CEB4(s32, void *, u16 *, s32, s32, s32, s32, s32, s32);
void draw_palette_sprite(void *, s16, s16, void *);
typedef struct 
{
  u8 p[6];
  u16 x;
  u16 y;
} Image;
typedef struct 
{
  Image *image;
} ImageRef;
typedef struct 
{
  s32 p;
  ImageRef *b;
} TileRef;
typedef struct Node
{
  void *next;
  u8 p[0x24];
  Image *img;
} Node;
typedef struct 
{
  u8 p[12];
  void *list;
  u8 z[0x21a];
  s8 ix;
} HudState;
typedef struct { u8 f; u8 pad[39]; } RecordEntry;
typedef struct { u8 pad[0x48]; RecordEntry e[4]; } RecordTable;
extern HudState *gSelectState;
extern u8 D_800A167C[];
extern u8 D_800A1681;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern RecordTable *gRecords;
extern u8 D_800A57B4[];
/* Draws the HUD position icons: walks the node list (8 slots), drawing each slot's tile at
 * its node position. Slots 5 and 6 use a special tile when the record flag 16 is set. */
void func_80069158(void)
{
  u8 idx = 0;
  char slot5;
  Node *node = gSelectState->list;
  u8 *index_tbl = D_800A167C;
  TileRef **tiles = (TileRef **) (gOrderState + 0x87f8);
  Image *img;
  short sel;
  u16 rect[4];
  TileRef **pick;
  short h;
  do
  {
    img = node->img;
    if (((idx & 255) == 6) && (gRecords->e[gSelectState->ix].f & 16))
    {
      sel = D_800A1681;
      goto draw;
    }
    if (((idx & 255) == 5) && (gRecords->e[gSelectState->ix].f & 16))
    {
      sel = index_tbl[0];
      rect[0] = (img->x + tiles[index_tbl[slot5 = 5]]->b->image->x) + 16;
      rect[1] = img->y;
      pick = (TileRef **)(sel * 4 + (u32)tiles);
      rect[2] = (*pick)->b->image->x;
      h = (*pick)->b->image->y;
      rect[3] = h;
      draw_palette_sprite((void *)(((unsigned char *)node + 4)), (s16)(rect[0] - 12), (s16)(img->y + 6), (void *)(D_800A57B4));
      func_8004CEB4(*((s32 *) (gStreamState + 0x1032a)), (*pick)->b->image, rect, 0, 255, 255, 255, 255, 0);
      sel = index_tbl[5];
    }
    else
    {
      sel = D_800A167C[idx & 255];
    }
    draw:
    rect[0] = img->x;

    rect[1] = img->y;
    rect[2] = tiles[sel]->b->image->x;
    rect[3] = tiles[sel]->b->image->y;
    func_8004CEB4(*((s32 *) (gStreamState + 0x1032a)), tiles[sel]->b->image, rect, 0, 255, 255, 255, 255, 0);
    node = node->next;
    idx++;
  }
  while ((idx & 255) < 8);
}
