#define CACHE_HEAD (*(CacheNode **)(gGameState + 0x4564))
#define CACHE_FREE (*(CacheNode **)(gGameState + 0x4568))
#define CACHE_CHUNK_SIZE (*(s32 *)(gGameState + 0x4578))
#define CACHE_TABLE (*(CacheRequest **)(gGameState + 0x457C))

typedef struct ListLink { struct ListLink *next; struct ListLink **prev; } ListLink;
typedef struct CacheNode
{
  ListLink link;
  u32 start;
  s32 phys;
  void *data;
} CacheNode;
typedef struct CacheRequest { s32 w[6]; } CacheRequest;

extern u8 gGameState[];
extern u8 stream_state[];
extern u32 cacheTick;
extern u32 cacheTableIndex;
#ifdef PORT
typedef uintptr_t VAddr;
#else
typedef s32 VAddr;
#endif
extern s32 osVirtualToPhysical(VAddr);
extern void al_link_push(ListLink *, ListLink **);
extern void alUnlink(void *);
extern void dmaCopyChunks(s32, void *, u32, CacheRequest);

static __inline__ void cacheSendRequest(u32 address, void *data, u32 size, CacheRequest *request)
{
  dmaCopyChunks(address, data, size, *request);
}

/* Translates a virtual address to a physical one. Looks for a cached chunk that
 * covers the range; if none does, takes a free node, maps the chunk and sends a
 * request to the cache DMA. Returns the physical address plus the sub-word offset. */
s32 cacheVirtToPhys(s32 addr, s32 size, void *state)
{
  u32 a = (u32)addr;
  s32 end;
  s32 chunk;
  s32 start;
  s32 sum;
  void *data;
  CacheNode *walker;
  CacheNode *old;
  s32 delta;

  if ((*((u32 *) (stream_state + 0x339A))) & 1)
  {
    return osVirtualToPhysical((VAddr)a);
  }
  end = a + size;
  old = 0;
  walker = CACHE_HEAD;
  if (walker != 0)
  {
    chunk = CACHE_CHUNK_SIZE;
    while (walker != 0)
    {
      start = walker->start;
      sum = start + chunk;
      if (a < ((u32) start))
      {
        break;
      }
      if (sum >= end)
      {
        walker->phys = cacheTick;
#ifdef PORT
        data = (void *)((u8 *)walker->data + (a - walker->start));
#else
        data = (void *)((u32)walker->data + a - walker->start);
#endif
        return osVirtualToPhysical((VAddr)data);
      }
      old = walker;
      walker = (CacheNode *)walker->link.next;
    }
  }

  /* Not cached: take a free node and insert it into the list. */
  walker = CACHE_FREE;
  if (walker == 0)
  {
    return osVirtualToPhysical((VAddr)CACHE_HEAD);
  }
  CACHE_FREE = (CacheNode *)walker->link.next;
  alUnlink(walker);
  if (old != 0)
  {
    al_link_push(&walker->link, &old->link.next);
  }
  else
  {
    if (CACHE_HEAD != 0)
    {
      old = CACHE_HEAD;
      CACHE_HEAD = walker;
      walker->link.next = &old->link;
      walker->link.prev = 0;
      old->link.prev = &walker->link.next;
    }
    else
    {
      CACHE_HEAD = walker;
      walker->link.next = 0;
      walker->link.prev = 0;
    }
  }

  delta = a & 1;
  cacheSendRequest((walker->start = (a -= delta)),
                   (walker->phys = cacheTick, (data = walker->data)),
                   CACHE_CHUNK_SIZE,
                   &CACHE_TABLE[cacheTableIndex++]);
  return osVirtualToPhysical((VAddr)data) + delta;
}
