typedef struct 
{
  u32 w[16];
} Mat;
typedef struct 
{
  u8 pad0[0x10];
  void *items;
} Obj0;
typedef struct 
{
  u8 pad0[0x14];
  void *dl;
} Obj2;
typedef struct 
{
  u8 pad0[0x80];
  f32 m[4][4];
} Obj3;
typedef struct 
{
  u8 pad0[4];
  void *p4;
  u8 pad8[0x88];
  s32 p90;
} Item;
typedef struct 
{
  u8 pad0[0x178];
  void *p178;
} Global;
extern Global *D_800C7F84;
extern u8 D_800AFA6B[];
extern f32 D_800B5B00[];
extern f32 D_800B65A8[];
extern u8 D_800ADFC7;
extern u8 D_800ADFC9;
extern u8 D_800ADFCB;
extern u32 D_8009C0A8;
extern f32 D_8009C228;
extern void func_800056FC(void *);
extern void func_80005F14(void *, s32);
extern void *func_80006008(void *);
extern void func_80006014(void *, void *);
extern void func_80010BFC(s32, void *, void *);
extern void *func_8001BD1C();
extern void func_8001C2C0(void *, void *, void *);
extern void guMtxIdentF(void *);
extern void guRotateF(void *, f32, f32, f32, f32);
extern u32 osVirtualToPhysical(void *);
static inline static static static static static static static void *inline_fn(Obj2 *arg0)
{
  return func_80006008(arg0);
}

void func_80017B38(Obj0 *arg0, s32 unused, Obj2 *arg2, Obj3 *arg3)
{
  char *__repair_addr;
  void *mtx;
  void *s1;
  void *p;
  void *q;
  void *new_var4;
  Item *it;
  s32 i;
  u32 j;
  f32 *dstrow = D_800B5B00;
  Obj2 *new_var2;
  u32 k;
  Obj0 *new_var;
  int new_var3;
  u8 *base;
  Obj2 *new_var5;
  func_800056FC(D_800C7F84->p178);
  mtx = D_800B65A8;
  __repair_addr = (char *) (((u8 *) arg2) + 0x78);
  *((s16 *) __repair_addr) = 0;
  guMtxIdentF(mtx);
  guRotateF(mtx, D_8009C228, 0.0f, 1.0f, 0.0f);
  D_8009C228 += 4.0f;
  func_80010BFC(0, arg3, mtx);
  new_var2 = arg2;
  *((s16 *) (((u8 *) new_var2) + 0x78)) = 0;
  s1 = inline_fn(new_var2);
  q = s1;
  s1 = ((u8 *) s1) + 8;
  new_var3 = D_800AFA6B[0] | 0xFFFFFF00;
  *((u32 *) q) = 0xFB000000;
  ;
  *(((u32 *) q) + 1) = new_var3;
  new_var4 = s1;
  q = new_var4;
  s1 = ((u8 *) s1) + 8;
  *((u32 *) q) = 0xDE000000;
  *(((u32 *) q) + 1) = (u32) (&D_8009C0A8);
  for (i = 0; i < 0x14; i += 4)
  {
    it = *((Item **) (i + ((int) arg0->items)));
    if (it->p4)
    {
      p = ((u8 *) it) + 0x48;
      func_8001C2C0(((u8 *) it->p4) + 0x48, ((u8 *) it) + 8, p);
      q = p;
      p = func_8001BD1C();
      func_80010BFC((s32) p, arg3, q);
    }
    else
    {
      p = ((u8 *) it) + 0x48;
      p = func_8001BD1C();
      *((Mat *) (((u8 *) it) + 0x48)) = *((Mat *) mtx);
      do
      {
        func_80010BFC((s32) p, arg3, mtx);
      }
      while (0);
      {
        u8 *srcrow = (u8 *) arg3;
        for (j = 0; j < 4; j++)
        {
          f32 *src = (f32 *) (srcrow + 0x80);
          f32 *dst = dstrow;
          for (k = 0; k <= (4 - 1); k++)
          {
            *(dst++) = *(src++);
          }

          srcrow += 16;
          dstrow += 4;
        }

      }
    }
    *((u32 *) s1) = 0xDA380007;
    *(((u32 *) s1) + 1) = osVirtualToPhysical(p);
    new_var5 = new_var2;
    func_80006014(new_var5, ((u8 *) s1) + 8);
    func_80005F14(new_var5, (*((Item **) (i + ((int) arg0->items))))->p90);
    s1 = inline_fn(new_var5);
    if (i == 0)
    {
      func_80006014(new_var5, s1);
      q = (u8 *) new_var5->dl;
      new_var5->dl = q + 8;
      *((u32 *) q) = 0xDE000000;
      *(((u32 *) q) + 1) = (u32) (&D_8009C0A8);
      s1 = inline_fn(new_var5);
    }
  }

  *((u32 *) s1) = 0xFB000000;
  *(((u32 *) s1) + 1) = (((((u32) D_800ADFC7) << 24) | (((u32) D_800ADFC9) << 16)) | (((u32) D_800ADFCB) << 8)) | 0xFF;
  func_80006014(new_var5, ((u8 *) s1) + 8);
}
