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
extern ObjA *D_800A1468;
extern Tbl *D_800C3508;
extern void *D_800C35A0;
extern u8 D_800A5F64[];
extern u8 D_800A5F70[];
extern void func_8005A360(s32);
extern void func_800595EC(void *);
extern void func_80053A78(void);
extern void func_80062B70(void);
extern void func_80062DF4(void);
extern void func_80064E48(void);
extern void func_80064E50(void);
extern void func_80070A34(void);
extern void func_8007A29C(void);
extern void func_8007A9A8(void);
extern void func_8007AA94(void);
s32 func_8007A01C(s32 arg0)
{
  u32 scratch[1];
  unsigned short idx;
  s8 state;
  s32 mode;
  void *p;
  state = D_800A1468->state;
  idx = D_800C3508->b[3] * 20;
  if (state != 0)
  {
    D_800A1468->state = --state;
    func_8005A360(arg0);
    D_800A1468->cb0 = func_8007A29C;
    D_800A1468->cb1 = func_8007A9A8;
    D_800A1468->cb2 = func_8007AA94;
    mode = *((u16 *) (((u8 *) D_800C35A0) + 30));
    switch (mode)
    {
      case 0:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 5;
        break;

      case 1:

      case 2:

      case 3:

      case 4:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 5;
        break;

      case 5:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 7;
        break;

    }

  }
  else
  {
    D_800A1468->state = 0;
    D_800A1468->flag = -1;
    mode = *((u16 *) (((u8 *) D_800C35A0) + 30));
    switch (mode)
    {
      case 1:

      case 2:

      case 3:

      case 4:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 0;
        func_800595EC(D_800A5F64);
        D_800A1468->cb0 = func_80064E48;
        D_800A1468->cb1 = func_80064E50;
        break;

      case 0:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 0;
        func_800595EC(D_800A5F64);
        D_800A1468->cb0 = func_80062B70;
        D_800A1468->cb1 = func_80062DF4;
        break;

      case 5:
        p = D_800C3508->base;
        *((s32 *) (((u8 *) (*((void **) ((((u8 *) p) + idx) + 4)))) + 20)) = 1;
        func_800595EC(D_800A5F70);
        D_800A1468->cb0 = func_80070A34;
        func_80053A78();
        break;

    }

  }
  return 0;
}
