extern s32 D_800A18E0[];
extern s32 D_800AE850[];
extern s32 D_800B0BA0;
extern u8 D_800B4174[];
extern s32 D_800C02AE[];
extern void func_8007F270(void);
extern s32 func_80080430(void *);
extern s32 osCreateMesgQueue(void *, void *, s32);
extern s32 func_8008BA40(s32);
extern s32 osSetEventMesg(s32, void *, s32);
s32 func_8007F278(void)
{
  volatile u16 *new_var;
  {
    s32 *v1;
    s32 v0;
    v1 = (s32 *) (((u8 *) D_800AE850) + 0x5910);
    v0 = 0xE;
    do
    {
      *v1 = 0;
      v0 = v0 - 1;
      v1 = v1 + 1;
    }
    while (v0 != 0);
  }
  {
    u32 s1;
    u8 *s0;
    s32 *s2;
    u32 s3;
    s1 = 0;
    s3 = (u32) (&func_8007F270);
    s0 = ((u8 *) D_800AE850) + 0x5910;
    s2 = (s32 *) (((u8 *) D_800C02AE) + 0x7D8A);
    do
    {
      *s2 = (s32) s3;
      func_80080430(s0);
      osCreateMesgQueue(s0 + 0x14, s0 + 0x2C, 0xC);
      new_var = (volatile u16 *) (s0 + 0xE);
      *new_var = (u16) s1;
      *((volatile u16 *) (s0 + 0xC)) = 0;
      s0 = s0 + 0x5C;
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
    while (s1 < 0x38);
  }
  {
    s32 evt;
    volatile s32 *headp;
    s32 *cursor;
    s32 idx;
    s32 event;
    s32 ret;
    evt = func_8008BA40(0);
    headp = D_800A18E0;
    D_800B0BA0 = evt;
    ret = 1;
    if ((*headp) != 0)
    {
      u8 *base;
      base = D_800B4174;
      cursor = D_800A18E0;
      idx = *cursor;
      cursor += 1;
      for (;;)
      {
        event = *cursor;
        cursor += 1;
        osSetEventMesg(event, (void *) ((idx * 0x5C) + ((u32) base)), 0);
        idx = *cursor;
        if (idx == 0)
        {
 do { } while (0);
          break;
        }
        cursor += 1;
      }

    }
    return ret;
  }
}
