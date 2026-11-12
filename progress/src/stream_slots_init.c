extern s32 D_800A18E0[];
extern s32 gOrderState[];
extern s32 D_800B0BA0;
extern u8 D_800B4174[];
extern s32 stream_state[];
extern void stream_callback_stub(void);
extern s32 pool_node_clear(void *);
extern s32 osCreateMesgQueue(void *, void *, s32);
extern s32 stream_slot_queue_or_default(s32);
extern s32 osSetEventMesg(s32, void *, s32);

/* Initialises the 56 stream slots (0x5C bytes each, from gOrderState+0x5910): clears the
 * slot array, gives each slot a message queue and id, points each stream callback at
 * stream_callback_stub, then registers the event messages listed in D_800A18E0 (0-terminated pairs). */
/* Clears the 56 stream slots, gives each a message queue and index, points stream callbacks at stream_callback_stub, then registers the event messages in D_800A18E0. */ s32 stream_slots_init(void)
{
  volatile u16 *flagPtr;
  {
    s32 *p;
    s32 remaining;
    p = (s32 *) (((u8 *) gOrderState) + 0x5910);
    remaining = 0xE;
    do
    {
      *p = 0;
      remaining = remaining - 1;
      p = p + 1;
    }
    while (remaining != 0);
  }
  {
    u32 slotIndex;
    u8 *slotPtr;
    s32 *cbSlot;
#ifdef PORT
    uintptr_t cbFn;
#else
    u32 cbFn;
#endif
    slotIndex = 0;
#ifdef PORT
    cbFn = (uintptr_t) (&stream_callback_stub);
#else
    cbFn = (u32) (&stream_callback_stub);
#endif
    slotPtr = ((u8 *) gOrderState) + 0x5910;
    cbSlot = (s32 *) (((u8 *) stream_state) + 0x7D8A);
    do
    {
      *cbSlot = (s32) cbFn;
      pool_node_clear(slotPtr);
      osCreateMesgQueue(slotPtr + 0x14, slotPtr + 0x2C, 0xC);
      flagPtr = (volatile u16 *) (slotPtr + 0xE);
      *flagPtr = (u16) slotIndex;
      *((volatile u16 *) (slotPtr + 0xC)) = 0;
      slotPtr = slotPtr + 0x5C;
      slotIndex = slotIndex + 1;
      cbSlot = cbSlot + 1;
    }
    while (slotIndex < 0x38);
  }
  {
    s32 *evList;
    D_800B0BA0 = stream_slot_queue_or_default(0);
    if (D_800A18E0[0] != 0)
    {
      u8 *base = D_800B4174;
      evList = D_800A18E0;
      do
      {
        s32 slotIdx = *evList++;
        s32 eventMsg = *evList++;
#ifdef PORT
        osSetEventMesg(eventMsg, (void *) (base + (slotIdx * 0x5C)), 0);
#else
        osSetEventMesg(eventMsg, (void *) ((slotIdx * 0x5C) + (u32) base), 0);
#endif
      } while (*evList != 0);
    }
    return 1;
  }
}
