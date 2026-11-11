typedef struct 
{
  u8 pad0[0x22C];
  u8 current;
  u8 frame;
} VRQueueHead;
typedef struct 
{
  u8 pad0[0x44];
  s32 count;
  u8 pad1[0x94];
  s32 x;
  u8 pad2[0x48];
  s32 y;
} VRItem;
typedef struct 
{
  u8 pad0[0xE4];
  s32 results[256];
} VRResultBlock;
typedef struct 
{
  u8 pad0[0x134];
  s32 values[256];
} VRValueBlock;
extern VRQueueHead *gSelectState;
extern u8 D_800A5260;
s32 resolve_path(u8 *);
s32 func_80081664(s32, void *);
s32 make_rect_set(s32);
void rect_set_set_scale(s32, f32, f32, f32);
void rect_set_set_item_pos(s32, s32, s32);
void func_8000C22C(void *, s32, s32, s32, u8);

/* Queues one result rect per entry of the item (three entries per group, 0xE4
 * bytes each), stores them in the current queue slot and advances the frame. */
void func_80058C04(VRItem *item)
{
  s32 i;
  s32 count;
  s32 entry_off;
  unsigned int a1;
  count = item->count;
  i = 0;
  if (count > 0)
  {
    s32 limit = count;
    do
    {
      i += 3;
    }
    while (((u8) i) < limit);
  }
  resolve_path(&D_800A5260);
  i = 0;
  *((u8 *) ((((u8 *) gSelectState) + 0xD0) - (-(gSelectState->frame * 2)))) = gSelectState->current;
  *((s8 *) ((((u8 *) gSelectState) + 0xD1) - (-(gSelectState->frame * 2)))) = item->count / 3;
  if ((item->count / 3) > 0)
  {
    do
    {
      entry_off = ((u8) i) * 0xE4;
      a1 = entry_off + 0x4C;
      ((VRValueBlock *) gSelectState)->values[gSelectState->current] = func_80081664(6, ((u8 *) item) + a1);
      ((VRResultBlock *) gSelectState)->results[gSelectState->current] = make_rect_set(((VRValueBlock *) gSelectState)->values[gSelectState->current]);
      rect_set_set_scale(((VRResultBlock *) gSelectState)->results[gSelectState->current], 1.0f, 1.0f, 1.0f);
      i++;
      rect_set_set_item_pos(((VRResultBlock *) gSelectState)->results[gSelectState->current], *((s32 *) ((entry_off + ((s32) item)) + 0xDC)), *((s32 *) ((entry_off + ((s32) item)) + 0x128)));
      func_8000C22C((void *)(((VRResultBlock *) gSelectState)->results[gSelectState->current]), (s32)(200), (s32)(200), (s32)(200), (u8)(255));
      gSelectState->current++;
    }
    while (((u8) i) < (item->count / 3));
  }
  gSelectState->frame++;
}
