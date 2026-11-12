typedef struct Node Node;
typedef struct Asset Asset;
typedef struct Root Root;
typedef struct Camera Camera;
typedef struct SpriteFrame SpriteFrame;

struct Asset
{
  char pad0[4];
  void *frameTable;
};

struct SpriteFrame
{
  u8 pad0[6];
  u16 w;
  u16 h;
};

struct Node
{
  u32 unk0;
  Node *next;
  u8 pad08[4];
  s16 baseX;
  s16 baseY;
  u8 pad10[0x52 - 0x10];
  u16 outW;
  u8 pad54[0x5A - 0x54];
  u16 outH;
  u8 pad5C[0x70 - 0x5C];
  s16 offX;
  s16 offY;
  u8 pad74[0x7A - 0x74];
  s16 frame;
  u8 pad7C[0x80 - 0x7C];
  u32 flags;
  void (*callback)(void *);
#ifdef PORT
  void *drawFn;
#else
  u32 drawFn;
#endif
  u32 unk8c;
  u8 color[4];
  char pad94[4];
  u16 val98;
  u16 val9a;
  s16 posX;
  s16 posY;
  s32 arg;
  Asset *asset;
  char padA8[0xD0];
  s32 arg178;
};

struct Root
{
  Node *head;
  char pad4[4];
  s32 busy;
};

struct Camera
{
  u8 pad0[0x178];
  s32 gfxCtx;
};

typedef struct
{
  u8 pad0[0xF];
  u8 count;
} RecordsBlock;

extern RecordsBlock *gRecords;
extern Camera *g_camera;
extern s32 D_8009FEDC;
extern f64 D_800A4C10;
extern Root *D_800B65F8;
extern void *find_object_by_id(s32);
extern void func_8000A5EC(void *, void *, s32, s32, s32, s32, s32);
extern void func_8004CEB4(s32, void *, s16 *, s32, s32, s32, s32, s32, s32);

/* Draws the object list: for each active node, sets its frame history, runs
 * its callback under the frame's camera, then either emits a sprite (flag
 * 0x80) or calls its draw routine with the camera's gfx context. */
void draw_object_list(Root *root)
{
  u8 count;
  s32 index;
  Node *node;
  Node *next;
  Camera *saved;
  s16 rect[4];
  s32 gfx;
  f64 scale;

  count = gRecords->count;
  if (root->busy != 0)
  {
    return;
  }
  node = root->head;
  saved = g_camera;
  D_800B65F8 = root;
  if (node == NULL)
  {
    return;
  }
  index = (count - 1) * 2;
  scale = D_800A4C10;
  do
  {
    next = node->next;
    if (node->flags & 1)
    {
      if (node->callback != NULL)
      {
        g_camera = find_object_by_id(index + 1);
        node->callback(node);
      }
      *((u16 *)(((u8 *)node) + (D_8009FEDC * 2) + 0x7C)) = *((u16 *)(((u8 *)node) + 0x7A));
      g_camera = saved;
      if (!(node->flags & 4))
      {
        void *spriteData = ((u8 *)node) + 0x10;
        func_8000A5EC(spriteData, ((void **)node->asset->frameTable)[node->frame], 0, node->arg, node->posX, node->posY, 0);
        node->outW = node->val98;
        node->outH = node->val9a;
        if (node->flags & 0x80)
        {
          rect[0] = node->baseX + node->offX;
          rect[1] = node->baseY + node->offY;
          rect[2] = ((((SpriteFrame *)((void **)node->asset->frameTable)[node->frame])->w) * (*((s16 *)(((u8 *)node) + 0x98)))) * scale;
          rect[3] = ((((SpriteFrame *)((void **)node->asset->frameTable)[node->frame])->h) * (*((s16 *)(((u8 *)node) + 0x9a)))) * scale;
          gfx = saved->gfxCtx;
          func_8004CEB4(gfx, ((void **)node->asset->frameTable)[node->frame], rect, 0, node->color[0], node->color[1], node->color[2], node->color[3], 0);
        }
        else
        {
          ((void (*)(s32, s32, s32, void *, s32, void *))(node->drawFn))(saved->gfxCtx, node->baseX + node->offX, node->baseY + node->offY, spriteData, node->arg, node->color);
        }
      }
    }
    node = next;
  }
  while (node != NULL);
}
