extern char D_800A73E0[];
extern char D_800C02AE[];
extern u8 D_8009BBBC;
extern char D_15DB10[];
extern char D_BB9470[];
void func_80015460(void *, s32);
void func_8001A19C(void *);
void func_8001AE40(void *);
void func_8004D414(s32);
void *func_8004D784(s32);
void func_80081514(void *, s32, s32);
typedef struct ObjList
{
  u8 *entries;
  u16 count;
} ObjList;
void *func_8001AF54(ObjList *arg0)
{
  ObjList *self;
  u8 *p;
  s32 i;
  s32 count0;
  u8 *flagp;
  u8 **new_var;
  char *new_var2;
  u8 *t;
  s32 *obj2;
  u8 *gp;
  u16 h;
  s32 w;
  u8 *b;
  s32 id;
  int new_var3;
  s32 pad[2];
  func_80015460(arg0, 1);
  p = arg0->entries;
  new_var3 = 0x24;
  count0 = arg0->count;
  i = 0;
  self = arg0;
  if (count0 > 0)
  {
    do
    {
      func_8001A19C(p);
      i += 1;
      p += 0x3C;
    }
    while (i < self->count);
  }
  gp = *((u8 **) (D_800C02AE + 0x7CD2));
  h = *((u16 *) (gp + 0x10));
  w = *((s32 *) (D_800C02AE + 0x3262));
  flagp = (u8 *) D_800A73E0;
  flagp += 0x6C01;
  *((void **) (D_800C02AE + 0x7CDE)) = arg0;
  b = (char *) self->entries;
  b += (s32) (((s32) h) * ((unsigned long) 0x3C));
  *((u8 **) (D_800C02AE + 0x326A)) = b;
  new_var3 = (long) 4;
  new_var = &self->entries;
  t = (*new_var) + (w * 0x3C);
  if ((*flagp) == 1)
  {
    func_8004D414(*((s32 *) (t - -0x24)));
  }
  obj2 = func_8004D784(*((s32 *) (t + 0x24)));
  if ((*flagp) == 1)
  {
    obj2[4] &= ~2;
    obj2[4] &= ~1;
    obj2[4] &= ~0x10;
  }
  else
  {
    obj2[new_var3] = (obj2[4] | 2) & (~1);
    *((s32 *) ((*((u8 **) (D_800C02AE + 0x326A))) + 0x10)) |= 4;
  }
  gp = *((u8 **) (D_800C02AE + 0x7CD2));
  h = *((u16 *) (gp + 0x10));
  b = self->entries;
  b += ((s32) h) * 0x3C;
  id = *((s32 *) (b + 0x24));
  *((u8 **) (D_800C02AE + 0x326A)) = b;
  obj2 = func_8004D784(id);
  new_var2 = D_800A73E0 + 0x6C01;
  if ((*((u8 *) new_var2)) == 1)
  {
    obj2[4] = (obj2[4] & (~2)) | 0x11;
  }
  else
  {
    obj2[4] = (w = obj2[4] & (~2)) | 1;
  }
  if (D_8009BBBC == 0)
  {
    func_8001AE40(self);
  }
  else
  {
    func_80081514(D_15DB10, D_BB9470 - D_15DB10, 1);
  }
  return arg0;
}
