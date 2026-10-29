#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  s16 pad0;
  s16 index;
  u8 pad4[0xA];
  void *ptr;
} T3508;
typedef struct 
{
  u8 pad0[0x204];
  u32 x204;
  u32 x208;
  s16 x20c;
  s8 x20e;
  u8 pad210[0x40];
  u8 x24f;
  u8 pad250[0x38];
  void (*f288)(void);
  void (*f28c)(void);
  void (*f290)(void);
} Obj;
typedef struct 
{
  u8 pad0[0x10];
  Obj *obj;
} Node;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800A5CE4[] __attribute__((aligned(4)));
extern u8 D_800A5D18[] __attribute__((aligned(4)));
extern u8 D_800A5D24[] __attribute__((aligned(4)));
extern Obj *D_800A1468;
extern s8 D_800A16D4;
extern volatile short func_80047F94(void);
extern void func_80053A78();
extern void func_8005A360(s32, s32);
extern void func_8005C198(s32, s32);
extern void func_8006E8A0(void);
extern void func_8006F424(void);
extern void func_8006F75C(void);
extern void func_8007086C(s32, s32);
extern void func_80070C34(void);
extern void func_8007159C(void);
extern void func_80071B3C(void);
extern void func_80071E08(void);
extern void func_80072364(void);
s32 func_80072090(s32 a0, s32 a1)
{
  s32 mode = (D_800AE850[0x7FC9]) ? (4) : (8);
  T3508 *p = *((T3508 **) (D_800C02AE + 0x325A));
  Node *n = (Node *) (((u8 *) p->ptr) + (((s32) p->index) * 20));
  s32 state;
  if ((*((s32 *) (D_800AE850 + 0x8030))) != 3)
  {
    func_8005C198(*((s32 *) (D_800AE850 + 0x8030)), mode);
    __builtin_memcpy(&D_800A1468->x204, D_800A5D18, 11);
    func_8005A360(a0, a1);
    state = 4;
    D_800A16D4 = 0;
    D_800A1468->f288 = func_80071B3C;
    D_800A1468->f290 = func_80071E08;
    D_800A1468->f28c = func_80072364;
    func_80047F94();
  }
  else
    if (D_800A1468->x24f != mode)
  {
    __builtin_memcpy(&D_800A1468->x204, (u32 *) D_800A5CE4, 9);
    func_8005A360(a0, a1);
    state = 3;
    *((s32 *) (D_800AE850 + 0x8030)) = 5;
    D_800A1468->f288 = func_80070C34;
    D_800A1468->f28c = func_8007159C;
  }
  else
  {
    func_80053A78();
    state = 0;
    __builtin_memcpy(&D_800A1468->x204, D_800A5D24, 10);
    func_8007086C(0, 0);
    *((s32 *) (D_800AE850 + 0x8030)) = 5;
    D_800AE850[0x7FCA] = 0;
    func_8006F424();
    func_8006E8A0();
    func_8006F75C();
  }
  *((s32 *) (((u8 *) (*((void **) (((u8 *) n) + 4)))) + 0x14)) = state;
  return 0;
}
