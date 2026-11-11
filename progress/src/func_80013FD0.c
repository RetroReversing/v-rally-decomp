extern s32 D_800B727C;
extern void *D_800B681C;
extern void *gTimeSampleState;
extern char D_800B5C80[];
extern s32 (*D_8009BB24)();
u64 osGetTime();
u64 __udivdi3();
static inline int nextSlotIndex(s32 index)
{
  return (index + 1) & 3;
}

/* Advances a four-entry ring of 0x118-byte records. Calls the hook at D_8009BB24,
 * makes the current slot the active one, clears the next slot's two header words,
 * and stores the elapsed time (osGetTime scaled to 1/3000 units) in the active record. */
void func_80013FD0(void)
{
  char *base;
  s32 idx;
  void *slot;
  void *next;
  void *cur;
  u64 ret;
  D_8009BB24();
  base = D_800B5C80;
  idx = D_800B727C;
  slot = base + (idx * 0x118);
  idx = nextSlotIndex(idx);
  D_800B681C = slot;
  next = base + (idx * 0x118);
  D_800B727C = idx;
  gTimeSampleState = next;
  ((s32 *) next)[1] = 0;
  ((s32 *) next)[0] = 0;
  do
  {
    ret = osGetTime(base);
  }
  while (0);
  cur = gTimeSampleState;
  *((u64 *) (((char *) cur) + 8)) = __udivdi3(ret << 6, (u64) 0xBB8);
}
