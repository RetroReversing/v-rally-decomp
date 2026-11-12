typedef struct Info
{
  u16 h[7];
} Info;
typedef struct Rec
{
  u8 pad[0xC];
  s32 time;
} Rec;
typedef struct Stage
{
  u8 pad0[0x15];
  u8 first;
  u8 pad16[0xA];
  Rec rec[8][4];
  u8 pad220[0x2C];
  Info info[8];
  u8 pad2BC[8];
} Stage;
typedef struct Sel
{
  u8 pad0[0x1E];
  u16 mode;
  u16 course;
  u16 stage;
  u8 pad24[0xA];
  u8 car;
} Sel;
typedef struct CarInfo
{
  u8 a;
  u8 b;
  u8 c;
  u8 pad;
  f32 speed;
  u8 pad8[0x14];
} CarInfo;
typedef struct Item
{
  u8 pad[4];
  u16 val;
} Item;
typedef struct Hdr
{
  u8 pad[2];
  s16 type;
} Hdr;
extern struct 
{
  u8 pad[0x1300];
  CarInfo cars[16];
} gOrderState;
extern Sel *gRecords;
extern Hdr *gLeague;
extern Stage *gSlotTableB[];
extern u8 gFlagMasks[];
extern u8 D_800A1530[];
extern u8 gMaskSlot[];
extern u16 D_800A1504[];
extern u16 D_800A150C[];
extern u16 D_800A1514[];
extern u16 D_800A1520[];
extern u16 D_800A1528;
extern u16 D_800A152A;
extern u16 D_800A152C;
extern s8 *gSelectState;
extern u8 D_800A14D5;
extern volatile u32 D_800A14DC;
void select_flush_pending(void);void *textObjGet(u32);
void list_set_flag2_at_index(s32);
u8 classifyStreamCode(Info *);

/* Fills the stage result HUD: the stage's rank, the car's stat bars (a, b, c)
 * and speed class, and the average of the three best split times (D_800A14DC).
 * Sets two flags in gSelectState that the HUD reads. */
void hud_setup_stage_results(void)
{
  u8 n;
  u8 i;

  u16 mode;
  Sel *sel;
  Stage *base0;
  Stage *q;
  short new_var;
  Item *it;
  n = classifyStreamCode(&((Stage **) 0x800D0634)[gRecords->mode][gRecords->course].info[gRecords->stage]);
  select_flush_pending();
  gSelectState[0x233] = -1;
  ((Item *)textObjGet(5))->val = D_800A1504[D_800A1530[n]];
  ((Item *)textObjGet(13))->val = D_800A150C[gOrderState.cars[gRecords->car].a];
  ((Item *)textObjGet(9))->val = D_800A1514[gOrderState.cars[gRecords->car].b];
  ((Item *)textObjGet(7))->val = D_800A1520[gOrderState.cars[gRecords->car].c];
  it = textObjGet(11);
  {
    if (gOrderState.cars[gRecords->car].speed <= 118.0f)
    {
      it->val = D_800A1528;
    }
    else
      if (gOrderState.cars[gRecords->car].speed <= 132.0f)
    {
      it->val = D_800A152A;
    }
    else
    {
      it->val = D_800A152C;
    }
  }
  mode = gRecords->mode;
  if (((((u32) (mode - 1)) < 2) || (((u32) (mode - 3)) < 2)) || ((gRecords->course < 8) && ((((u8 *) 0x800C832C)[gRecords->course] & (1 << gRecords->stage)) != (1 << gRecords->stage))))
  {
    D_800A14D5 = 1;
  }
  else
  {
    D_800A14D5 = 0;
  }
  sel = gRecords;
  base0 = *((Stage **) 0x800D0634);
  D_800A14DC = 0;
  mode = sel->mode;
  for (i = 0; i < 3; i++)
  {
    if (mode == 5)
    {
      if (sel->course < 8)
      {
        D_800A14DC += base0[sel->course].rec[sel->stage][i].time;
      }
      else
      {
        #ifdef PORT
        q = (Stage *) ((u8 *) base0 + gMaskSlot[sel->course] * sizeof(Stage));
#else
        q = (Stage *) (gMaskSlot[sel->course] * sizeof(Stage) + (u32) base0);
#endif
        {
          s32 st = sel->stage - 2;
          new_var = i;
          D_800A14DC += q->rec[q->first + st][new_var].time;
        }
      }
    }
    else
    {
      D_800A14DC += gSlotTableB[mode][sel->course].rec[sel->stage][i].time;
    }
  }

  if ((gRecords->mode != 5) || (D_800A14D5 == 0))
  {
    D_800A14DC /= 3;
  }
  if ((gLeague->type == 4) && (gRecords->stage == 0))
  {
    list_set_flag2_at_index(1);
  }
  gSelectState[0x22B] = -1;
}
