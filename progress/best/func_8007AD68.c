#define SLOT_STATE (D_800C3508->teams[team].slots[arg1].obj->state)
typedef struct 
{
  s32 pad0;
  struct 
  {
    u8 pad[0x2C];
    s32 state;
  } *obj;
  s32 pad8;
} Slot;
typedef struct 
{
  u8 pad[8];
  Slot *slots;
  u8 pad2[8];
} Team;
typedef struct 
{
  u8 pad[3];
  u8 cur;
  u8 pad4[0xC];
  Team *teams;
} League;
extern League *D_800C3508;
extern u8 *D_800C35A0;
extern u8 *D_800A1468;
extern void func_800407D0(void);
extern void func_800595EC(void *);
extern s32 func_8005A388(s32, s32);
extern void func_8006F0E0(u8, u8 *);
extern void func_8007A688(void);
extern u8 D_800A5FB8[];
extern u8 D_800A5FC4[];
extern u8 D_800A5FD0[];
extern void func_800635A0(void);
extern void func_80063790(void);
extern void func_8006556C(void);
extern void func_80065860(void);
extern void func_80070C34(void);
extern void func_8007159C(void);
extern void func_8007A29C(void);
extern void func_8007A9A8(void);
extern void func_8007AA94(void);
s32 func_8007AD68(s32 arg0, s32 arg1)
{
  char *__repair_addr;
  u8 team;
  int new_var;
  u8 *new_var2;
  s8 idx;
  D_800A1468[0x245] = 0;
  func_8007A688();
  __repair_addr = (char *) ((D_800C35A0 + ((D_800C35A0 + ((s8) D_800A1468[0x228]))[0x32] * 0x28)) + 0x4E);
  *((s16 *) __repair_addr) = D_800A1468[0x237];
  func_8006F0E0(D_800A1468[0x228], D_800A1468);
  team = D_800C3508->cur;
  if (((s8) D_800A1468[0x228]) < ((*((u16 *) (D_800C35A0 + 0xE))) - 1))
  {
    if (func_80065860)
    {
      D_800A1468[0x228]++;
      func_8005A388(arg0, arg1);
    }
    else
    {
      D_800A1468[0x228]++;
      func_8005A388(arg0, arg1);
    }
    {
      u8 *s = D_800A1468;
      u8 *g = D_800C35A0;
      *((void **) (s + 0x288)) = func_8007A29C;
      *((void **) (s + 0x28C)) = func_8007A9A8;
      *((void **) (s + 0x290)) = func_8007AA94;
      switch (*((u16 *) (g + 0x1E)))
      {
        case 1:

        case 2:

        case 3:

        case 4:
          SLOT_STATE = 5;
          break;

        case 0:
          SLOT_STATE = 5;
          break;

        case 5:
          SLOT_STATE = 7;
          break;

        default:
          return 0;

      }

    }
  }
  else
  {
    new_var = 0x228;
    D_800A1468[new_var] = 0;
    ((s8 *) D_800A1468)[0x22B] = -1;
    switch (*((u16 *) (D_800C35A0 + 0x1E)))
    {
      case 1:

      case 2:

      case 3:

      case 4:
        SLOT_STATE = 2;
        func_800595EC(D_800A5FB8);
        *((void **) (D_800A1468 + 0x288)) = func_8006556C;
        *((void **) (D_800A1468 + 0x28C)) = func_80065860;
        break;

      case 0:
        SLOT_STATE = 2;
        func_800595EC(D_800A5FC4);
        new_var2 = D_800A1468 + 0x288;
        *((void **) new_var2) = func_800635A0;
        *((void **) (D_800A1468 + 0x28C)) = func_80063790;
        break;

      case 5:
        SLOT_STATE = 3;
        func_800595EC(D_800A5FD0);
        *((void **) (D_800A1468 + 0x288)) = func_80070C34;
        *((void **) (D_800A1468 + 0x28C)) = func_8007159C;
        func_800407D0();
        break;

      default:
        return 0;

    }

  }
  return 0;
}

