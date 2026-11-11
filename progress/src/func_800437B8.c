s32 getCounterValue(void *);
s32 func_80022374(void **, u8 *, s32);
s32 func_800347A4(void *, void *);
s32 race_reset(void);
s32 func_80085778(s32, s32);
extern s32 D_800A4DFC;
extern s32 D_800AE44C;
extern s32 D_800A73E0;
extern s32 gOrderState;
extern void *gRecords;
extern void **gCarList;
extern s32 gRaceState;

/* Per-car AI tick. Runs the driver into ctrl unless the car already has flag 0x80 set, clamps
   the ctrl byte at +4, and sets flag 0x80. When the race stage says the race is over for
   every car, it resets the race state. */
void func_800437B8(void *car, void *ctrl)
{
  s32 masked;
  s32 car_flags;
  s32 lane;
  s32 expected;
  s32 extra_count;
  s32 hit = 0;
  u16 race_stage;
  s32 left;
  void *cfg;
  void *node;
  void *records;
  void *it;
  if (!((*((s32 *) (((char *) car) + 0x14))) & 0x80))
  {
    if ((*(*((s32 **) (((char *) car) + 0x48)))) < 4)
    {
      node = *(*((void ***) (((char *) (&gOrderState)) + 0x72FC)));
      if (node != NULL)
      {
        loop_3:
        if ((*((s32 *) (((char *) node) + 0x24))) != car)
        {
          node = *((void **) (((char *) node) + 4));
          if (node != NULL)
          {
            goto loop_3;
          }
        }

      }
      func_80022374((void **)(node + 0x28), (u8 *)(&D_800A4DFC), 2);
      *((s32 *) (((char *) (*((void **) (((char *) car) + 0x50)))) + 4)) = 1;
      cfg = *((void **) (((char *) car) + 0x50));
      if ((*((s32 *) (((char *) cfg) + 0))) < 2)
      {
        *((s32 *) (((char *) cfg) + 0)) = 2;
      }
    }
  }
  func_800347A4(car, ctrl);
  if (((u8) (*((u8 *) (((char *) ctrl) + 4)))) >= 0x81U)
  {
    *((u8 *) (((char *) ctrl) + 4)) = 0x80U;
  }
  *((s32 *) (((char *) car) + 0x14)) = (s32) ((*((s32 *) (((char *) car) + 0x14))) | 0x80);
  if ((*(*((s32 **) (((char *) car) + 0x48)))) < 4)
  {
    records = gRecords;
    race_stage = *((u16 *) (((char *) records) + 0x1E));
    if (((race_stage == 0) | (race_stage == 5)) != 0)
    {
      it = *gCarList;
      left = 1;
      if (it != NULL)
      {
        do
        {
          if ((*(*((s32 **) (((char *) it) + 0x48)))) < 4)
          {
            left &= -(((*((s32 *) (((char *) it) + 0x14))) & 0x80) != 0);
          }
          it = *((void **) (((char *) it) + 4));
        }
        while (it != NULL);
      }
      if (left != 0)
      {
        goto block_34;
      }
    }
    else
    {
      it = *gCarList;
      left = *((u16 *) (((char *) records) + 0xE));
      extra_count = 0;
      if (it != NULL)
      {
        do
        {
          if ((*(*((s32 **) (((char *) it) + 0x48)))) < 4)
          {
            lane = getCounterValue(it);
            car_flags = *((s32 *) (((char *) it) + 0x14));
            masked = car_flags & 0x100;
            left -= masked != 0;
            if ((((masked == 0) && (((u32) (lane + 5)) < 0xBU)) && ((*((s32 *) (((char *) (*((void **) (((char *) it) + 0x6C)))) + 0x10))) == 0)) && (car_flags & 0x200))
            {
              extra_count += 1;
              left -= 1;
            }
          }
          it = *((void **) (((char *) it) + 4));
        }
        while (it != NULL);
      }
      if (left == 0)
      {
        if ((*(*((s32 **) (((char *) car) + 0x48)))) < 4)
        {
          D_800AE44C = (void *) ((*((void **) (((char *) (&D_800A73E0)) + 0x706C))) + 1);
        }
        node = *((void **) (((char *) (&D_800A73E0)) + 0x706C));
        expected = (*((u16 *) (((char *) gRecords) + 0xE))) * 0x64;
        if ((node == expected) || (node == (expected + 1)))
        {
          hit = 1;
        }
        if (((hit & 0xFF) != 0) && (extra_count != (*((u16 *) (((char *) gRecords) + 0xE)))))
        {
          block_34:
          gRaceState = 0;
          race_reset();

          func_80085778(0, 0x1000);
          func_80085778(0, 0x8000);
        }
      }
    }
  }
}
