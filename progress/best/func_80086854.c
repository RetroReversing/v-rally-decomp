typedef struct 
{
  s32 count;
  s32 *a;
  s32 *b;
  s32 *c;
} S_func_80086854_arg0;
typedef struct 
{
  u8 pad[0x134];
} Obj;
extern s32 D_800B0100;
extern Obj *D_800B68F0;
extern void func_8008989C(void *, void *, s32);
extern void func_800885CC(void *);
extern s32 func_80089554(void *, s32);
s32 func_80086854(S_func_80086854_arg0 *arg0)
{
  s32 stride;
  s32 i;
  s32 stamp;
  Obj *obj;
  int new_var2;
  int new_var;
  s32 id;
  s32 extra[2];
  new_var = arg0->count;
  if (((u32) arg0->a) < 0x400U)
  {
    func_8008989C(&arg0->a, arg0, 5);
    func_8008989C(arg0->a, arg0, new_var);
    func_8008989C(arg0->b, arg0, new_var);
    func_8008989C(arg0->c, arg0, new_var);
  }
  new_var2 = new_var;
  stamp = D_800B0100;
  i = 0;
  D_800B0100 = stamp + 1;
  if (new_var2 > 0)
  {
    do
    {
      stride = i * 4;
      if (arg0->a[i] != 0)
      {
        id = func_80089554(arg0, i);
        obj = (Obj *) (((u8 *) D_800B68F0) + (id * 0x134));
        func_800885CC(obj);
        *((void **) (((u8 *) obj) + 0x70)) = arg0;
        *((s32 *) (((u8 *) obj) + 0x34)) = (*((s32 *) (((u8 *) obj) + 0x84)) = *((s32 *) (stride + ((int) arg0->b))));
        *((s32 *) (((u8 *) obj) + 0x30)) = (*((s32 *) (((u8 *) obj) + 0x80)) = *((s32 *) (((u8 *) arg0->c) + (i * 4))));
        {
          s32 value = arg0->a[i];
          *((s32 *) (((u8 *) obj) + 0x40)) = stamp;
          *((s32 *) (((u8 *) obj) + 0x78)) = value;
          *((s32 *) ((u8 *) obj)) = value;
        }
      }
      i++;
    }
    while (i < new_var2);
  }
  return stamp;
}
