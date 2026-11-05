#include "decompdecomp_snapshot_800603b4.h"
#line 1 "func.c"
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
} D_800AE850;
extern Sel *D_800C35A0;
extern Hdr *D_800C3508;
extern Stage *D_800D0634[];
extern u8 D_800C832C[];
extern u8 D_800A1530[];
extern u8 D_800A1548[];
extern u16 D_800A1504[];
extern u16 D_800A150C[];
extern u16 D_800A1514[];
extern u16 D_800A1520[];
extern u16 D_800A1528;
extern u16 D_800A152A;
extern u16 D_800A152C;
extern s8 *D_800A1468;
extern u8 D_800A14D5;
extern volatile u32 D_800A14DC;
void func_800584D4(void);void *func_800592D0(u32);
void func_8005A05C(s32);
u8 func_800602F4(Info *);
void func_800603B4(void)
{
  u8 n;
  u8 i;

  u16 mode;
  Sel *sel;
  Stage *base0;
  Stage *q;
  short new_var;
  Item *it;
  n = func_800602F4(&((Stage **) 0x800D0634)[D_800C35A0->mode][D_800C35A0->course].info[D_800C35A0->stage]);
  func_800584D4();
  D_800A1468[0x233] = -1;
  ((Item *)func_800592D0(5))->val = D_800A1504[D_800A1530[n]];
  ((Item *)func_800592D0(13))->val = D_800A150C[D_800AE850.cars[D_800C35A0->car].a];
  ((Item *)func_800592D0(9))->val = D_800A1514[D_800AE850.cars[D_800C35A0->car].b];
  ((Item *)func_800592D0(7))->val = D_800A1520[D_800AE850.cars[D_800C35A0->car].c];
  it = func_800592D0(11);
  {
    if (D_800AE850.cars[D_800C35A0->car].speed <= 118.0f)
    {
      it->val = D_800A1528;
    }
    else
      if (D_800AE850.cars[D_800C35A0->car].speed <= 132.0f)
    {
      it->val = D_800A152A;
    }
    else
    {
      it->val = D_800A152C;
    }
  }
  mode = D_800C35A0->mode;
  if (((((u32) (mode - 1)) < 2) || (((u32) (mode - 3)) < 2)) || ((D_800C35A0->course < 8) && ((((u8 *) 0x800C832C)[D_800C35A0->course] & (1 << D_800C35A0->stage)) != (1 << D_800C35A0->stage))))
  {
    D_800A14D5 = 1;
  }
  else
  {
    D_800A14D5 = 0;
  }
  sel = D_800C35A0;
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
        q = (Stage *) (D_800A1548[sel->course] * sizeof(Stage) + (u32) base0);
        {
          s32 st = sel->stage - 2;
          new_var = i;
          D_800A14DC += q->rec[q->first + st][new_var].time;
        }
      }
    }
    else
    {
      D_800A14DC += D_800D0634[mode][sel->course].rec[sel->stage][i].time;
    }
  }

  if ((D_800C35A0->mode != 5) || (D_800A14D5 == 0))
  {
    D_800A14DC /= 3;
  }
  if ((D_800C3508->type == 4) && (D_800C35A0->stage == 0))
  {
    func_8005A05C(1);
  }
  D_800A1468[0x22B] = -1;
}


