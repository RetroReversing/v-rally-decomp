extern u8 D_800C02AE[];
extern s16 D_8009CB34[];
extern u16 D_8009C4E6[];
typedef struct 
{
  u8 *data;
  u16 count;
} S_func_80019608_arg0;
void func_80019314(u8 *arg0, s32 *arg1, s32 *arg2, s32 arg3);
static inline static s16 *inline_fn(s32 arg0, char *arg1, s32 arg2, int arg3)
{
  return (s16 *) (arg0 + ((s32)arg1 + (arg2 * arg3)));
}

void func_80019608(S_func_80019608_arg0 *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4)
{
  s32 i;
  s16 *new_var2;
  s32 off;
  s32 k;
  s32 base;
  s32 flags;
  s32 val;
  u16 *new_var;
  k = 0;
  off = 0;
  for (i = 0; i < arg0->count; i++)
  {
    base = D_800C02AE[0x7678] * 17;
    new_var2 = D_8009CB34;
    if ((*inline_fn(off, (char *) new_var2, base, 2)) >= 0)
    {
      if (arg4 & (*(new_var = &D_8009C4E6[(base + i) * 2])))
      {
        switch (i - 3)
        {
          case 0:
            if ((*((u16 *) (D_800C02AE + 0x767E))) & 0x8000)
          {
            goto next;
          }
            break;

          case 1:
            if ((*((u16 *) (D_800C02AE + 0x767E))) & 0x4000)
          {
            goto next;
          }
            break;

          case 2:
            if ((*((u16 *) (D_800C02AE + 0x767E))) & 0x800)
          {
            goto next;
          }
            break;

          case 3:
            if ((*((u16 *) (D_800C02AE + 0x767E))) & 0x2000)
          {
            goto next;
          }
            break;

          case 4:
            if ((*((u16 *) (D_800C02AE + 0x767E))) & 0x1000)
          {
            goto next;
          }
            break;

          case 5:

          case 6:

          case 7:

          case 8:
            break;

        }

        base = D_800C02AE[0x7678];
        {
          val = *((s16 *) (off + ((s32)new_var2 + (base * 34))));
          func_80019314(arg0->data + k, arg1 + val, arg2 + val, arg3);
        }
      }
    }
    next:
    off += 2;

    k += 0x24;
  }

}
