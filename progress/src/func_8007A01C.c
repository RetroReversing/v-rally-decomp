typedef struct ObjA
{
  u8 pad0[0x228];
  s8 state;
  u8 pad229[2];
  s8 flag;
  u8 pad22c[0x5c];
  void (*cb0)(void);
  void (*cb1)(void);
  void (*cb2)(void);
} ObjA;
typedef struct Tbl
{
  u8 b[0x10];
  u8 *base;
} Tbl;
extern ObjA *gSelectState;
extern Tbl *gLeague;
extern void *gRecords;
extern u8 D_800A5F64[];
extern u8 D_800A5F70[];
extern void select_reset_text(s32, s32);
extern void func_800595EC(void *);
extern void records_restore_from_order(void);
extern void func_80062B70(void);
extern void func_80062DF4(void);
extern void func_80064E48(void);
extern void hud_draw_counter_text(void);
extern void func_80070A34(void);
extern void func_8007A29C(void);
extern void func_8007A9A8(void);
extern void func_8007AA94(void);

/* Steps the countdown in gSelectState and, while it runs, keeps the league entry
 * for the current record mode set to its value. When the countdown ends it
 * clears the state, sets the entry for the mode and installs the next callbacks. */
s32 func_8007A01C(s32 arg0, s32 arg1)
{
  u32 scratch[1];
  unsigned short entry_off;
  s8 state;
  s32 mode;
  void *league_base;
  state = gSelectState->state;
  entry_off = gLeague->b[3] * 20;
  if (state != 0)
  {
    gSelectState->state = --state;
    select_reset_text(arg0, arg1);
    gSelectState->cb0 = func_8007A29C;
    gSelectState->cb1 = func_8007A9A8;
    gSelectState->cb2 = func_8007AA94;
    mode = *((u16 *) (((u8 *) gRecords) + 30));
    switch (mode)
    {
      case 0:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 5;
        break;

      case 1:

      case 2:

      case 3:

      case 4:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 5;
        break;

      case 5:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 7;
        break;

    }

  }
  else
  {
    gSelectState->state = 0;
    gSelectState->flag = -1;
    mode = *((u16 *) (((u8 *) gRecords) + 30));
    switch (mode)
    {
      case 1:

      case 2:

      case 3:

      case 4:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 0;
        func_800595EC(D_800A5F64);
        gSelectState->cb0 = func_80064E48;
        gSelectState->cb1 = hud_draw_counter_text;
        break;

      case 0:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 0;
        func_800595EC(D_800A5F64);
        gSelectState->cb0 = func_80062B70;
        gSelectState->cb1 = func_80062DF4;
        break;

      case 5:
        league_base = gLeague->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) league_base) + entry_off) + 4)))) + 20)) = 1;
        func_800595EC(D_800A5F70);
        gSelectState->cb0 = func_80070A34;
        records_restore_from_order();
        break;

    }

  }
  return 0;
}
