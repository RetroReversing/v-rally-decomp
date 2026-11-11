extern s32 D_800A18E0[];
extern s32 gOrderState[];
extern s32 D_800B0BA0;
extern u8 D_800B4174[];
extern s32 gStreamState[];
extern void func_8007F270(void);
extern s32 func_80080430(void *);
extern s32 osCreateMesgQueue(void *, void *, s32);
extern s32 func_8008BA40(s32);
extern s32 osSetEventMesg(s32, void *, s32);

/* Initialises the 56 stream slots (0x5C bytes each, from gOrderState+0x5910): clears the
 * slot array, gives each slot a message queue and id, points each stream callback at
 * func_8007F270, then registers the event messages listed in D_800A18E0 (0-terminated pairs). */
s32 func_8007F278(void)
{
  volatile u16 *slotFlag;
  {
    s32 *clear;
    s32 n;
    clear = (s32 *) (((u8 *) gOrderState) + 0x5910);
    n = 0xE;
    do
    {
      *clear = 0;
      n = n - 1;
      clear = clear + 1;
    }
    while (n != 0);
  }
  {
    u32 i;
    u8 *slot;
    s32 *callback;
    u32 handler;
    i = 0;
    handler = (u32) (&func_8007F270);
    slot = ((u8 *) gOrderState) + 0x5910;
    callback = (s32 *) (((u8 *) gStreamState) + 0x7D8A);
    do
    {
      *callback = (s32) handler;
      func_80080430(slot);
      osCreateMesgQueue(slot + 0x14, slot + 0x2C, 0xC);
      slotFlag = (volatile u16 *) (slot + 0xE);
      *slotFlag = (u16) i;
      *((volatile u16 *) (slot + 0xC)) = 0;
      slot = slot + 0x5C;
      i = i + 1;
      callback = callback + 1;
    }
    while (i < 0x38);
  }
  {
    s32 *p;
    D_800B0BA0 = func_8008BA40(0);
    if (D_800A18E0[0] != 0)
    {
      u8 *base = D_800B4174;
      p = D_800A18E0;
      do
      {
        s32 idx = *p++;
        s32 ev = *p++;
        osSetEventMesg(ev, (void *) ((idx * 0x5C) + (u32) base), 0);
      } while (*p != 0);
    }
    return 1;
  }
}
