/* Heap block header (0x14 bytes) followed by the payload. Blocks form a list
   from heapRegionHead, each block's next points at the following block. */
typedef struct Node Node;
struct Node
{
  Node *next;
  Node *prev;
  u8 x8[2];
  u8 used;
  u8 busy;
  u8 xc[4];
  u32 field10;
};
extern Node *heapRegionHead;
extern u32 heapRegionFreeSize;
extern u32 gHeapCallerRa;
extern void (*heapPanicFn)(void *);
extern void *heapInitBlock(void *, u32);
extern u32 heapMaxFreeSize(Node *);
/* Allocates `size` bytes from the heap region. Picks the smallest free block that fits
   (splitting it when the rest is large enough) and returns its payload, or 0. */
void *heapAlloc(void *arg0, u32 arg1)
{
  Node *block = arg0;
  u32 size = arg1;
  Node *best;
  u32 best_size;
  Node *a0;
  loop: { Node *head = heapRegionHead; if (head == 0) goto done; if (head == block) goto done; if (heapRegionFreeSize < size) goto done; if (heapMaxFreeSize(head) < size + 0x14) goto done; block = heapRegionHead; goto loop; } done: size = (size + 3) & ~3;
  a0 = (Node *) (((u8 *) block) - 0x14);
  if (size == 0)
  {
    heapPanicFn(((u8 *) gHeapCallerRa) - 4);
    for (;;)
    {
      ;
    }

  }
  best = 0;
  if (a0->busy == 0)
  {
    u32 end = ((u32) a0->next) - 0x14;
    best_size = end - ((u32) a0);
    if ((size + 0x1c) < best_size)
    {
      a0->busy = 1;
      block = (Node *) (((u8 *) a0) + 0x14);
      heapInitBlock(block, best_size);
    }
    else
    {
      block = 0;
    }
  }
  else
  {
    block = (Node *) (((u8 *) a0) + 0x14);
  }
  best_size = 0x7fffffff;
  if (block != 0)
  {
    do
    {
      if (block->used == 0)
      {
        u32 end = ((u32) block->next) - 0x14;
        u32 span = end - ((u32) block);
        if ((span >= size) && ((span < best_size) || (best == 0)))
        {
          best_size = span;
          best = block;
        }
      }
      block = block->next;
    }
    while (block != 0);
  }
  if (best != 0)
  {
    u32 total = size + 0x14;
    if (best_size >= total)
    {
      Node *v0 = best->next;
      block = (Node *) (((u8 *) best) + total);
      v0->prev = block;
      block->next = v0;
      block->prev = best;
      block->x8[0] = 0;
      block->x8[1] = 0;
      block->used = 0;
      block->busy = 0;
      block->field10 = 0;
      best->next = block;
    }
    best->used = 1;
    best->field10 = 0;
    best = (Node *) (((u8 *) best) + 0x14);
  }
  return best;
}
