typedef struct Obj
{
  u8 pad[0x7c];
  s32 count;
  void *items[16];
} Obj;
extern u8 D_800AE850[];
extern u8 D_800B7280[];
s32 func_80082438(u8 *, u8 *, s32);
Obj *func_80082578(Obj *, u8 *, s32);
void func_800826DC(Obj *);
void func_8008276C(void)
{
  u8 *new_var2;
  u8 buf[0x80];
  s32 count;
  u8 *new_var3;
  u8 *new_var;
  int done = 0;
  s32 index = 0;
  Obj *obj = *((Obj **) (D_800AE850 + 0x8AB4));
  do
  {
    u8 *dst;
    u8 *p;
    count = 0;
    new_var2 = buf;
    new_var3 = D_800AE850 - (-0x8A30);
    dst = buf;
    p = (new_var = new_var3 + index);
    do
    {
      *(dst++) = *(p++);
      index++;
      count++;
    }
    while ((((s8) D_800AE850[0x8A2F + index]) != '/') && (((s8) D_800AE850[0x8A2F + index]) != 0));
    if (((s8) new_var2[count - 1]) == '/')
    {
      buf[count] = 0;
      obj = func_80082578(obj, buf, count);
      if (((s8) D_800AE850[0x8A30 + index]) == 0)
      {
        done = 1;
      }
    }
    else
    {
      obj->count++;
      obj->items[obj->count] = (void *) func_80082438(buf, dst, count);
      done = 1;
      if ((*obj).count >= 2)
      {
        func_800826DC(obj);
      }
    }
  }
  while (!done);
}
