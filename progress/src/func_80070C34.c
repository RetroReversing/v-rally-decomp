extern s8 gStreamPhase;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern u8 *gLeague;
extern void *gRecords;
extern void func_80057B40();void *select_get_entry(u32);
extern void func_8005937C(s32, u16);void text_obj_set_enabled(u32);void func_8005A6E0(u32);
extern void func_8005BB5C();
extern void select_clear_slots();
typedef struct 
{
  u32 w[177];
} CarRecord;
extern void func_80061740(CarRecord);
extern void func_80062304(void);
extern void func_8008A0D8(void *, u16, s32);
extern void func_8008A104(void *, u16, s32, s32);

/* Finishes the race results screen. Each car gets its row label (the player's
   row uses the highlight set) and a colour from the standings. The leader index
   is picked from the cars that are not finished, then the result message is
   shown and that car's record is handed to the results panel. */
void func_80070C34(void)
{
  int __repair_literal;
  CarRecord record;
  s32 s3;
  s32 car;
  s32 kind = 3;
  s32 color;
  s32 lbl_hi;
  s32 car_off;
  s32 lbl_lo;
  char *new_var;
  s32 car_stride;
  s32 result;
  select_clear_slots();
  s3 = -1;
  func_8005BB5C();
  car = 0;
  __repair_literal = 0;
  kind = __repair_literal;
  if (((s32) (*((u16 *) (gStreamState + 0x1037a)))) > kind)
  {
    kind = 3;
    color = 0x50;
    lbl_hi = 0x15;
    car_off = 0;
    lbl_lo = 9;
    car_stride = 0;
    do
    {
      if ((*((s16 *) (gLeague + 2))) == kind)
      {
        func_8005937C(lbl_hi, *(u16 *)((u8 *)&(*((CarRecord **) (gStreamState + 0x1039a)))[car] + 0x14));
      }
      else
      {
        func_8005937C(lbl_lo, *(u16 *)((u8 *)&(*((CarRecord **) (gStreamState + 0x1039a)))[car] + 0x14));
      }
      if ((*((s16 *) (gLeague + 2))) == 2)
      {
        func_8008A104(gLeague, lbl_lo, 1, 1);
      }
      if ((((*((u16 *) (gRecords + 0x20))) >= 8) & (car < 8)) || ((car >= 8) && ((*((u16 *) (gRecords + 0x20))) < 8)))
      {
        func_8008A104(gLeague, ((*((s16 *) (gLeague + 2))) == kind) ? (lbl_hi) : (lbl_lo), 0, 0);
        ((u8 *) select_get_entry(car))[0x41] = 0;
      }
      else
        if ((*((s16 *) (gLeague + 2))) == kind)
      {
        if (*((u16 *) ((gOrderState + 0x7dc0) + car_off)))
        {
          func_8008A0D8(gLeague, lbl_hi, 0);
          {
            u8 *q = select_get_entry(car);
            q[0xf] = color;
            q[0x10] = color;
            q[0x11] = color;
          }
        }
        else
          if (s3 < 0)
        {
          s3 = car;
        }
        else
        {
        }
      }
      else
      {
        s3 = (((*((u16 *) (gRecords + 0x20))) < 8) ^ 1) << 3;
      }
      lbl_hi++;
      car_off += 2;
      lbl_lo++;
      car++;
      car_stride += 0x2c4;
    }
    while (car < ((s32) (*((u16 *) (gStreamState + 0x1037a)))));
  }
  {
    u8 *p = gLeague;
    u8 *q;
    ((*((u8 **) (gLeague + 0x10))) + ((*((s16 *) (p + 2))) * 0x14))[0xe] = ((*((u8 **) (gLeague + 0x10))) + ((*((s16 *) (p + 2))) * 0x14))[0xd] + s3;
    if ((*((s16 *) (gLeague + 2))) == 2)
    {
      func_80062304();
      if (!s3)
      {
        func_8005A6E0(0x1c);
        result = 0x1b;
      }
      else
      {
        func_8005A6E0(0x1b);
        result = 0x1c;
      }
    }
    else
      if (!s3)
    {
      func_8005A6E0(0x13);
      result = 0x12;
    }
    else
    {
      func_8005A6E0(0x12);
      result = 0x13;
    }
  }
  text_obj_set_enabled(result);
  *((s32 *) (gOrderState + 0x1cf8)) = s3;
  record = *((CarRecord *) (((char *) (*((u8 **) (gStreamState + 0x1039a)))) + (s3 * 0x2c4)));
  func_80061740(record);
  if ((*((s16 *) (gLeague + 2))) == 3)
  {
    gStreamPhase = 0;
    func_80057B40(0x22, 3, 0, 0);
  }
}
