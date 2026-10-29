#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  u8 pad[0xA];
} Data10;
typedef struct 
{
  u8 pad[0x20];
  s32 state;
} State4;
typedef struct 
{
  u8 pad[0x4];
  State4 *p4;
} Obj10;
typedef struct 
{
  u8 pad[0x10];
  Obj10 *p10;
} Root;
typedef struct 
{
  u8 pad[0x288];
  void (*f288)(void);
  void (*f28c)(void);
} Config;
typedef struct 
{
  s32 a;
  s32 b;
  s16 c;
  s8 d;
} Params;
extern s32 D_8009F640;
extern Config *D_800A1468;
extern Params D_800A5450;
extern Params D_800A545C;
extern Params D_800A5468;
extern Params D_800A5474;
extern u8 D_800AE850[];
extern Root *D_800C3508;
extern s32 D_800C3558;
void func_80084AF4(void);
void func_80084AD8(void);
s32 func_80084DD4(s32);
void func_8005A338(s32, s32);
void func_8002FB64(void);
void func_8005E1B8(void);
s32 func_800857C0(s32, s32);
void func_8005E68C(void);
void func_8005E6AC(void);
void func_8005E820(void);
s32 func_8005D96C(s32 arg0, s32 arg1)
{
  s32 s0;
  s32 s1;
  u32 mask;
  s32 s2;
  u32 s4;
  void (*new_var)(void);
  u8 temp;
  Root *r;
  func_80084AF4();
  func_80084AD8();
  if ((func_80084DD4(0) == 0) || ((temp = D_800AE850[0x7D50]) == 0))
  {
    ;
    D_800C3508->p10->p4->state = 1;
    ;
    __builtin_memcpy(((u8 *) D_800A1468) + 0x1f8, &D_800A5450, 11);
    func_8005A338(arg0, arg1);
    new_var = func_8005E68C;
    D_800A1468->f288 = new_var;
    D_800A1468->f28c = func_8005E6AC;
    goto done;
  }
  if ((short) (mask = D_8009F640 & 0x8000))
  {
    ;
    D_800C3508->p10->p4->state = 2;
    ;
    __builtin_memcpy(((u8 *) D_800A1468) + 0x1f8, &D_800A545C, 10);
    func_8005A338(arg0, arg1);
    return 0;
  }
  s2 = 1;
  if (D_800C3558 == 0)
  {
    D_800C3508->p10->p4->state = 3;
    ;
    __builtin_memcpy(((u8 *) D_800A1468) + 0x1f8, &D_800A5468, 11);
    func_8005A338(arg0, arg1);
    return 0;
  }
  s1 = 0;
  if (mask < temp)
  {
    s4 = temp;
    do
    {
      s0 = s1 & 255;
      if (func_80084DD4(s0))
      {
        s2 &= -(func_800857C0(s0, 2) != 0);
      }
      s1++;
    }
    while ((s1 & 255) < s4);
  }
  if ((s2 & 255) != 0)
  {
    func_80084AF4();
    func_80084AD8();
    func_8002FB64();
    D_800C3508->p10->p4->state = 5;
    r = D_800A1468;
    __builtin_memcpy(((u8 *) r) + 0x1f8, &D_800A5474, 9);
    func_8005A338(arg0, arg1);
    func_8005E1B8();
  }
  else
  {
    func_8005A338(arg0, arg1);
    D_800A1468->f28c = func_8005E820;
  }
done:
  return 0;
}
