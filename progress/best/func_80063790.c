typedef struct 
{
  s32 w[175];
  u8 colors[8];
} Record;
typedef struct 
{
  u8 b[0x20000];
} B;
extern B D_800C02AE;
extern B D_800AE850;
extern u8 *D_800A11B0;
extern u8 *D_800A1468;
extern u8 *D_800A14D0;
extern f64 D_800A5698;
extern u8 *D_800D0634;
extern void func_8005937C(u8, u16);
extern void func_8005C198(void);
extern void func_80061740(Record);
extern void func_8006185C(s32, s32);
extern void func_80062184(Record, s32);
extern void func_80062E68(void);
extern void func_8004D08C(s32, u8, s16, s16, f32, f32, u8, u8);
extern s32 func_800592AC(u16);
void func_80063790(void)
{
  char *__repair_addr;
  u8 *state;
  u8 *base;
  u8 *entry;
  u8 *src;
  Record *new_var;
  u8 *dst;
  u8 *colors;
  s32 index;
  s32 count;
  u8 i;
  s32 temp;
  f64 scale;
  Record record;
  state = *((u8 **) (D_800C02AE.b + 0x325A));
  entry = (*((u8 **) (state + 0x10))) + (((s16) (*((s16 *) (state + 2)))) * 0x14);
  count = entry[0xE] - entry[0xD];
  if (!D_800A1468[0x245])
  {
    *((u16 *) ((*((u8 **) (D_800C02AE.b + 0x32F2))) + 0x20)) = count;
    base = D_800D0634;
    index = count * 0x2c4;
    base += index;
    __repair_addr = (char *) (base + 0x14);
    func_8005937C(entry[0xE], *((u16 *) __repair_addr));
    if (count != (*((s32 *) (D_800AE850.b + 0x5550))))
    {
      if (*((s32 *) D_800A11B0))
      {
        if (D_800A5698)
        {
          func_8005C198();
        }
        else
        {
          func_8005C198();
        }
      }
      if (!D_800A1468[0x2BE])
      {
        base = D_800D0634 + index;
        func_80061740(*((Record *) base));
        *((u32 *) (D_800AE850.b + 0x5550)) = count;
      }
    }
    *((u16 *) ((*((u8 **) (D_800C02AE.b + 0x32F2))) + 0x22)) = 0;
  }
  else
  {
    func_8006185C(func_800592AC(*((u16 *) ((*((u8 **) (D_800C02AE.b + 0x32F2))) + 0x20))), 0);
  }
  count = *((u16 *) ((*((u8 **) (D_800C02AE.b + 0x32F2))) + 0x20));
  base = D_800D0634 + (count * 0x2c4);
  new_var = &(*((Record *) base));
  record = *new_var;
  if (((*((s16 *) ((*((u8 **) (D_800C02AE.b + 0x325A))) + 2))) == 1) && D_800A1468[0x245])
  {
    func_80062E68();
  }
  func_80062184(record, 1);
  if ((!D_800A1468[0x24D]) && (!D_800A1468[0x2BE]))
  {
    colors = record.colors;
    i = 0;
    if (i < (*((u16 *) (((u8 *) (&record)) + 0x14))))
    {
      scale = D_800A5698;
    }
    for (; i < (*((u16 *) (((u8 *) (&record)) + 0x14))); i++)
    {
      s32 count;
      count = *((u16 *) ((*((u8 **) (D_800C02AE.b + 0x32F2))) + 0x20));
      temp = 1 << (i & 255);
      if (((D_800C02AE.b + 0x327E)[count] & temp) != temp)
      {
        if (((((count == 0) & (i == 6)) || ((count == 1) & (i == 4))) || ((count == 5) & (i == 6))) || ((count == 6) & (i == 5)))
        {
          temp = 200;
        }
        else
        {
        }
        func_8004D08C(*((s32 *) (D_800C02AE.b + 0x1032A)), i, *((s16 *) D_800A14D0), (*((u16 *) (D_800A14D0 + 2))) + ((i & 255) * D_800A14D0[8]), (f32) (((f64) (*((f32 *) (D_800A14D0 + 4)))) - scale), *((f32 *) (D_800A14D0 + 4)), colors[i], temp);
      }
      else
      {
        temp = 255;
        temp = 130;
        func_8004D08C(*((s32 *) (D_800C02AE.b + 0x1032A)), i, *((s16 *) D_800A14D0), (*((u16 *) (D_800A14D0 + 2))) + ((i & 255) * D_800A14D0[8]), (f32) (((f64) (*((f32 *) (D_800A14D0 + 4)))) - scale), *((f32 *) (D_800A14D0 + 4)), colors[i & 255], temp);
      }
    }

  }
}
