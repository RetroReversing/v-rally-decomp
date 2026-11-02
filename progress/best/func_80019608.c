extern u8 D_800C02AE[];
extern s16 D_8009CB34[][17];
extern u16 D_8009C4E6[][2];
typedef struct
{
  u8 *data;
  u16 count;
} S_func_80019608_arg0;
void func_80019314(u8 *arg0, s32 *arg1, s32 *arg2, s32 arg3);

void func_80019608(S_func_80019608_arg0 *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4)
{
  s32 i;
  s32 sel;
  s32 v;

  for (i = 0; i < arg0->count; i++)
  {
    sel = D_800C02AE[0x7678];
    if (D_8009CB34[sel][i] < 0)
      continue;
    if (!(arg4 & D_8009C4E6[sel * 17 + i][0]))
      continue;
    switch (i)
    {
      case 3:
        if (*(u16 *) (D_800C02AE + 0x767E) & 0x8000)
          continue;
        break;
      case 4:
        if (*(u16 *) (D_800C02AE + 0x767E) & 0x4000)
          continue;
        break;
      case 5:
        if (*(u16 *) (D_800C02AE + 0x767E) & 0x800)
          continue;
        break;
      case 6:
        if (*(u16 *) (D_800C02AE + 0x767E) & 0x2000)
          continue;
        break;
      case 7:
        if (*(u16 *) (D_800C02AE + 0x767E) & 0x1000)
          continue;
        break;
      case 8:
      case 9:
      case 10:
      case 11:
        break;
    }
    v = D_8009CB34[D_800C02AE[0x7678]][i];
    func_80019314(arg0->data + i * 36, arg1 + v, arg2 + v, arg3);
  }
}
