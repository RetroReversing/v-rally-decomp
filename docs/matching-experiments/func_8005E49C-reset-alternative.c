typedef struct Obj
{
  unsigned char pad0[0x49];
  u8 b49;
  u8 b4A;
} Obj;
typedef struct Entry
{
  unsigned char pad0[4];
  void *item;
} Entry;
typedef struct Inner
{
  unsigned char pad0[4];
  void *p4;
  unsigned char pad8[0x3c];
  Entry *p44;
} Inner;
typedef struct Root
{
  unsigned char pad0[0x10];
  Inner *inner;
} Root;
typedef struct G1468
{
  unsigned char pad0[0x1F8];
  s32 x1f8;
  s32 x1fc;
  s8 x200;
  unsigned char pad201[0x8b];
  void (*cb)(void);
} G1468;
typedef struct Item
{
  unsigned char pad0[0x2c];
  s32 x2c;
} Item;
typedef struct A5474
{
  s32 a;
  s32 b;
  s8 c;
} A5474;
extern Root *D_800C3508;
extern s32 D_800C3558;
extern s32 D_800C8328;
extern G1468 *D_800A1468;
extern s32 D_800A14BC[];
extern A5474 D_800A5474;
extern void func_8002FB64(void);
extern void func_80038F64(s32);
extern s32 func_80057810(s32);
extern void func_800578E0(s32);
extern void func_8005A338(s32, s32, ...);
extern void func_8005E1B8(void);
extern void func_8006ECB4(void);
extern void func_8006F75C(void);
extern void func_80084AD8(void);
extern void func_80084AF4(s32);
extern s32 func_80084DD4(s32);
extern s32 func_80084E10(void);
extern s32 func_800857C0(s32, s32);
extern void func_8005E820(void);
s32 func_8005E49C(s32 arg0, s32 arg1)
{
  s32 s0;
  s32 s1;
  s32 s2;
  s32 s3;
  s32 s4;
  s32 s5;
  Obj *o;
  u8 *new_var;
  Inner *in;
  Item *it;
  o = (Obj *) D_800C3508->inner;
  s4 = arg0;
  s5 = arg1;
  D_800C3558 = (o->b4A - o->b49) + 1;
  func_80038F64(D_800C3558 & 0xFF);
  s2 = 1;
  func_8006ECB4();
  s1 = 0;
  func_8006F75C();
  func_800578E0(D_800C8328);
  D_800C8328 = func_80057810(D_800A14BC[D_800C3558]);
  {
    u8 count = func_80084E10();
    if (count)
    {
      s3 = count;
      do
      {
        s0 = s1 & 0xFF;
        if (func_80084DD4(s0))
        {
          s2 &= -(func_800857C0(s0, 2) != 0);
        }
        s1++;
      }
      while (((u32) (s1 & 0xFF)) < ((u32) s3));
    }
  }
  if (s2 & 0xFF)
  {
    s1 = 0;
    func_80084AF4(s4);
    func_80084AD8();
    func_8002FB64();
    in = D_800C3508->inner;
    do
    {
      it = (Item *) (*((void **) ((((char *) D_800C3508->inner->p44) + ((s1 & 0xFF) * 12)) + 4)));
      it->x2c = 5;
      s1++;
    }
    while (((u32) (s1 & 0xFF)) < 3);
    new_var = ((u8 *) D_800A1468) + 0x1F8;
    *((s32 *) (((u8 *) D_800C3508->inner->p4) + 0x20)) = 5;
    __builtin_memcpy(&D_800A1468->x1f8, &D_800A5474, 9);
    func_8005A338(s4, s5);
    func_8005E1B8();
  }
  else
  {
    func_8005A338(s4, s5);
    D_800A1468->cb = func_8005E820;
  }
  return 0;
}
