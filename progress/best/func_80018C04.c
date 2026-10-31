extern u8 D_800C7926;
extern s16 D_800B5B50;
extern s32 D_8009D538;
extern char *D_800C7F84;
s32 func_8001FEE8();
static inline static s32 inline_fn(void *arg0)
{
  return *((s32 *) (((char *) arg0) + 0x24));
}

void *func_80018C04(void *arg0, void *arg1, void *arg2)
{
  char pad[8];
  s32 i;
  s32 n;
  char *new_var;
  if (arg2 != NULL)
  {
    if ((!((*((f32 *) (((char *) arg1) + 0xE0))) < ((f32) (*((s32 *) (((char *) arg2) + 0x10)))))) && (!(((f32) (*((s32 *) (arg2 + 0x18)))) < (*((f32 *) (((char *) arg1) + 0xE0))))))
    {
      if ((!((*((f32 *) (((char *) arg1) + 0xE8))) < ((f32) (*((s32 *) (((char *) arg2) + 0x20)))))) && (!(((f32) inline_fn(arg2)) < (*((f32 *) (((char *) arg1) + 0xE8))))))
      {
        if (((func_8001FEE8(*((s32 *) (D_800C7F84 + 0x24))) < 0x32) && (D_800C7926 == 0)) || (D_8009D538 & 0x800))
        {
          D_800B5B50 = 0;
        }
        return arg2;
      }
    }
  }
  n = *((u16 *) (arg0 + 4));
  D_800B5B50 = 0;
  i = 0;
  if (n > 0)
  {
    do
    {
    }
    while (0);
    do
    {
      if ((*((f32 *) (new_var = ((char *) arg1) + 0xE0))) < ((f32) (*((s32 *) ((*((char **) arg0)) + 0x10)))))
      {
        goto inc;
      }
      if (((f32) (*((s32 *) (arg2 + 0x18)))) < (*((f32 *) (((char *) arg1) + 0xE0))))
      {
        goto inc;
      }
      if ((*((f32 *) (((char *) arg1) + 0xE8))) < ((f32) (*((s32 *) ((*((char **) arg0)) + 0x20)))))
      {
        n += 0;
        goto inc;
        arg2 = *((char **) arg0);
      }
      if (!(((f32) (*((s32 *) ((*((char **) arg0)) + 0x24)))) < (*((f32 *) (((char *) arg1) + 0xE8)))))
      {
        return *((char **) arg0);
      }
      inc:
      i++;

      arg2 += 0x30;
    }
    while (i < n);
  }
  return NULL;
}
