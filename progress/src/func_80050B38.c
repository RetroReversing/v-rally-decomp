extern void *gRecords;
extern char D_800B5B70;
extern unsigned char D_800C81FC;
extern unsigned char D_800C7FA0;
extern int D_800B6B00;
extern short D_800B0D68;
extern short D_800C5CE8;
extern signed char D_800B0D6C;
extern signed char D_800C5CEC;
extern unsigned char D_800B6818;
s32 flag_test_bit0(void *);
void initRaceSession(void);
s32 func_80022BE8(void *, s32);
s32 func_80022F78(void *);
s32 init_car_from_record(void *, void *, void *);
s32 func_8004F3C4(void);
s32 func_8004F55C(s32 *);
short func_8004FD5C(s32 *, s32);
extern s32 gRecordTimeScale;
extern s32 *gCarEntries;
extern s32 *gSlotTable;
extern u8 D_800A17F0;
extern char gOrderState[];
extern char gStreamState[];

/* Per-frame record-screen update: loads the record state from gRecords, then either
 * runs the state-8 branch (refresh the displayed record entry), or sets up both record
 * tables and clears the new-record flags of the four entries. Anything else only
 * resets the table selector and reruns the table update. */
void func_80050B38(void)
{
  s32 *temp_a0;
  short temp_v0_2;
  char *new_var2;
  u8 var_a1;
  int new_var;
  s32 var_v1;
  u16 temp_a0_2;
  u16 temp_v1;
  u8 temp_v0;
  void *var_s0;
  if (flag_test_bit0(gOrderState + 0x7320) == 0)
  {
    initRaceSession();
  }
  func_8004F3C4();
  temp_v1 = *((u16 *) (gRecords + 0x1E));
  new_var2 = gOrderState;
  if (temp_v1 != 7)
  {
    if ((temp_v1 == 8) && (D_800A17F0 == 0))
    {
      if (D_800C81FC != 0)
      {
        func_80022F78(*((void ***) (gOrderState + 0x73F0)));
        var_s0 = *(*((void ***) (new_var2 + 0x73F0)));
        temp_v0_2 = (double) (*gCarEntries);
        if (D_800C7FA0 == 1)
        {
          var_s0 = *((void **) (((u8 *) var_s0) + 4));
        }
        func_80022BE8(var_s0, *gCarEntries);
        {
          void *p = *((void **) (((u8 *) var_s0) + 0x54));
          void *r = gRecords;
          ;
          *((s32 *) 0x800B6B00) = 5;
          *((s32 *) (((u8 *) p) + 0x50)) = 0;
          init_car_from_record(var_s0, r + (((*((u8 *) (r + 0x32))) * 0x28) + 0x44), r);
        }
      }
    }
    else
      if (flag_test_bit0((void *) (&D_800B5B70)) != 0)
    {
      temp_a0 = (s32 *) (gOrderState + 0x2408);
      gCarEntries = temp_a0;
      gSlotTable = (s32 *) (gStreamState + 0x592A);
      func_8004F55C(temp_a0);
      func_8004F55C(gSlotTable);
      temp_v0 = *((u8 *) (gRecords + 0xF));
      *((s16 *) (gOrderState + 0x2518)) = (s16) temp_v0;
      *((s16 *) (gStreamState + 0x5A3A)) = (s16) temp_v0;
      temp_a0_2 = *((u16 *) (gRecords + 0x1E));
      if (temp_a0_2 == 0)
      {
        if ((*((u16 *) (gRecords + 0x1A))) != 0)
        {
          *((s8 *) (gOrderState + 0x251C)) = 0;
          *((s8 *) (gStreamState + 0x5A3E)) = 0;
          func_8004FD5C(gCarEntries, gRecordTimeScale * 0x1C2);
          func_8004FD5C(gSlotTable, gRecordTimeScale * 0x1C2);
          var_a1 = 0;
          do
          {
            if (D_800C7FA0)
            {
              temp_v0_2 = var_a1 * 0x44;
              *((u16 *) ((gOrderState + 0x2410) + temp_v0_2)) |= 0x100;
              *((u16 *) ((gStreamState + 0x5932) + temp_v0_2)) |= 0x100;
              var_a1++;
            }
            else
            {
              temp_v0_2 = var_a1 * 0x44;
              *((u16 *) ((gOrderState + 0x2410) + temp_v0_2)) |= 0x100;
              *((u16 *) ((gStreamState + 0x5932) + temp_v0_2)) |= 0x100;
              var_a1++;
            }
          }
          while (var_a1 < 4);
          return;
        }
        goto block_18;
      }
      if ((temp_a0_2 == 5) && ((*((u8 *) (gOrderState + 0x7FC8))) == 0))
      {
        func_8004F3C4();
      }
      block_18:
      *((s8 *) (gOrderState + 0x251C)) = 0;

      func_8004FD5C(gCarEntries, gRecordTimeScale * 0x1C2);
    }
  }
}
