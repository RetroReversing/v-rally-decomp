typedef struct 
{
  u8 *data;
  u16 count;
} Obj197;
typedef struct 
{
  u16 a;
  u16 mask;
} MaskEnt;
extern s16 D_8009CB34[][17];
extern MaskEnt D_8009C4E6[][17];
extern u8 D_800C7926;
extern u16 D_800C792C;
void func_80019440(void *, void *, void *, s32, void *);
void func_800197A4(Obj197 *obj, s32 *arg1, void *arg2, s32 arg3, u32 mask, s32 *arg5)
{
  s32 i;
  s16 v;
  int new_var;
  for (i = 0; i < obj->count; i++)
  {
    if (D_8009CB34[D_800C7926][i] < 0)
    {
      continue;
    }
    if (!(mask & D_8009C4E6[D_800C7926][i].a))
    {
      continue;
    }
    switch (i)
    {
      case 3:
        if (D_800C792C & 0x8000)
      {
        continue;
      }
        break;

      case 4:
        if (D_800C792C & 0x4000)
      {
        continue;
      }
        break;

      case 5:
        if (D_800C792C & 0x800)
      {
        continue;
      }
        break;

      case 6:
        if (D_800C792C & 0x2000)
      {
        continue;
      }
        break;

      case 7:
        if (D_800C792C & 0x1000)
      {
        continue;
      }
        break;

      case 8:

      case 9:

      case 10:

      case 11:
        break;

    }

    new_var = i * 0x24;
    v = D_8009CB34[D_800C7926][i];
    func_80019440(obj->data + new_var, arg1 + v, arg2, arg3, arg5 + v);
  }

}

