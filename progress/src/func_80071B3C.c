extern unsigned char D_800B6819;
extern int gLeague;
extern s32 gRecords;
s32 func_80057B40();void *select_get_entry(u32);
void select_propagate_values(s32, u32, u32);
s32 hud_setup_stage_results();
void func_80061F34(void *, void *);
s32 stream_state_update();
s32 func_8008A0D8();
s32 func_8008A270();
s32 func_8008A290();
extern s8 D_8009E260;
extern s8 D_800A14D6;
extern s8 D_800A14D7;
extern s8 D_800A14D8;
extern u8 gStreamPhase;
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_8006A24C;
void func_800416EC();
static inline u16 *inline_fn()
{
  return (u16 *) (gRecords + 0x1E);
}

void func_80071B3C(void)
{
  s32 pad[2];
  char *new_var;
  char *__repair_addr;
  s32 temp_a1_3;
  s32 new_var8;
  s32 var_v0;
  s32 var_a0;
  s32 var_a3;
  s32 var_v0_2;
  int new_var2;
  u16 new_var6;
  u16 temp_a0_2;
  u16 temp_s2;
  int new_var9;
  char *new_var3;
  u32 temp_a0;
  u32 var_v1;
  u8 temp_s0;
  s32 new_var4;
  s32 new_var7;
  u8 temp_s1;
  void *temp_v0;
  u16 *new_var5;
  var_a3 = 0;
  if (D_800B6819 != 0)
  {
    var_a0 = 4;
    var_v0 = 8;
    goto scan;
    found:
    var_a3 = 1;

    goto scanned;
  }
  else
  {
    var_a0 = 8;
    var_v0 = 0;
  }
  scan:
  temp_a0 = var_a0 & 0xFFFF;

  var_v1 = 0;
  if (temp_a0 != 0)
  {
    var_v0_2 = var_v0 & 0xFFFF;
    new_var = ((char *) gOrderState) + 0x7DC0;
    do
    {
      if (((u16 *) new_var)[var_v0_2 + var_v1] != 0)
      {
        new_var += (s32) 0x7DC0;
        goto found;
      }
      var_v1++;
    }
    while (var_v1 < temp_a0);
  }
  scanned:
  ;

  ;
  ;
  ;
  ;
  ;
  ;
  ;
  new_var8 = var_a3;
  ;
  new_var2 = 3;
  ;
  ;
  ;
  if (!(new_var8 & 0xff))
  {
    if (var_a3)
    {
      func_8008A0D8((s32) gLeague, 0x28, 0);
      temp_v0 = select_get_entry(new_var2);
      ((s8 *) temp_v0)[0xF] = 0x50;
      ((s8 *) temp_v0)[0x10] = 0x50;
      ((s8 *) temp_v0)[0x11] = 0x50;
    }
    else
    {
      func_8008A0D8((s32) gLeague, 0x28, 0);
      temp_v0 = select_get_entry(new_var2);
      ((s8 *) temp_v0)[0xF] = 0x50;
      ((s8 *) temp_v0)[0x10] = 0x50;
      ((s8 *) temp_v0)[0x11] = 0x50;
    }
  }
  else
  {
    func_8008A0D8((s32) gLeague, 0x28, 1, var_a3);
  }
  new_var3 = (gStreamState + 0x10386) + ((*((u16 *) (gRecords + 0x1E))) * 4);
  temp_a1_3 = *((s32 *) new_var3);
  new_var4 = gRecords;
  var_v0_2 = gRecords + 0x2E;
  __repair_addr = (char *) (((((u32) (*((u16 *) (gRecords + 0x20)))) * 0x2C4) + temp_a1_3) + ((*((u16 *) (gRecords + 0x22))) << 6));
  *((u8 *) var_v0_2) = *((u8 *) (__repair_addr + 0x37));
  func_80061F34(new_var4, temp_a1_3);
  func_8008A270((s32) gLeague, 4, 0x14);
  func_8008A290((s32) gLeague, 4, 0x10000, (s32) (&func_8006A24C));
  stream_state_update();
  if ((*((u16 *) (gRecords + 0xE))) < 2U)
  {
    func_8008A0D8((s32) gLeague, 0x27, 0);
    ((s8 *) select_get_entry(2))[0x41] = 0;
    select_propagate_values(2, 1, 5);
  }
  hud_setup_stage_results();
  if (((s32) gStreamPhase) < new_var2)
  {
    if (new_var9 = gStreamPhase == 0)
    {
      if (gStreamPhase == 0)
      {
        D_8009E260 = 4;
        temp_s2 = *((u16 *) (gRecords + 0xE));
        ;
        temp_s0 = *((u8 *) (gRecords + 0x21));
        temp_s1 = *((u8 *) (gRecords + 0x23));
        new_var7 = gRecords;
        *((u16 *) (gRecords + 0xE)) = 1U;
        if ((*((s32 *) (gRecords + 0x20))) == 0x20001)
        {
          *((u16 *) (gRecords + 0x20)) = 1U;
          *((u16 *) (gRecords + 0x22)) = 2U;
        }
        else
          if ((*((s32 *) (new_var7 + 0x20))) == 0x40000)
        {
          new_var5 = (u16 *) (gRecords + 0x20);
          *inline_fn() = 4U;
          *new_var5 = 0U;
          *((u16 *) (gRecords + 0x22)) = 1U;
        }
        else
          if ((*((s32 *) (gRecords + 0x20))) == 0x50001)
        {
          *((u16 *) (gRecords + 0x20)) = 0xAU;
          *((u16 *) (gRecords + 0x22)) = 0U;
        }
        temp_a0_2 = *((u16 *) (gRecords + 0x20));
        new_var6 = *((u16 *) (gRecords + 0x22));
        D_800A14D6 = (s8) (*((u16 *) (gRecords + 0x1E)));
        D_800A14D7 = (s8) temp_a0_2;
        D_800A14D8 = (s8) new_var6;
        func_800416EC();
        D_8009E260 = 1;
        *((u16 *) (gRecords + 0x1E)) = 5U;
        *((u16 *) (gRecords + 0x20)) = (u16) temp_s0;
        *((u16 *) (gRecords + 0x22)) = (u16) temp_s1;
        *((u16 *) (gRecords + 0xE)) = temp_s2;
      }
    }
  }
  func_80057B40(0x2A, 3, 0, 0);
}
