#define PTR_78(a) (*(u8 **)((u8 *)(a) + 0x78))
#define IDX1(i) (((i) + D_8009EB80 * 4) << 3)
#define IDX2(i) (D_8009EB80 * 0xD8 + (i) * 0x12)
extern s32 D_8009EB80;
extern u8 D_8009EC44[];
extern u8 D_8009EC6C[];
extern u8 D_8009EC6E[];
extern u8 D_8009EC6F[];
extern u8 D_8009EC70[];
extern u8 D_8009EC71[];
extern u8 D_8009EC72[];
extern u8 D_8009EC73[];
extern u8 D_8009EC74[];
extern u8 D_8009EC75[];
extern u8 D_8009EC76[];
extern u8 D_8009EC77[];
extern u8 D_8009EC78[];
extern u8 D_8009EC79[];
extern u8 D_8009EC7A[];
extern u8 D_8009EC7B[];
extern u8 D_8009EC7C[];
extern u8 D_8009EC7D[];
extern u8 D_8009F32C[];
extern u8 D_8009F32E[];
extern u8 D_8009F32F[];
extern u8 D_8009F330[];
extern u8 D_8009F331[];
extern u8 D_8009F332[];
extern u8 D_8009F333[];
s32 func_80031F2C(void *arg0)
{
  s32 p;
  s32 i;
  s32 end;
  s32 q;
  void *new_var2 = arg0;
  u8 *new_var;
  PTR_78(arg0)[0x1B] = 0;
  p = (s32)(D_8009EC44 + D_8009EB80 * 5);
  new_var = ((u8 *) arg0) + 0x8C;
  end = p + 5;
  do
  {
    if ((*((u8 *) p)) == (*((u16 *) (((u8 *) arg0) + 0x8C))))
    {
      goto not_in_table;
    }
    p++;
  }
  while (p < end);
  for (i = 0; i <= (4 - 1); i++)
  {
    if ((*((u16 *) (D_8009F32C + IDX1(i)))) == (*((u16 *) new_var)))
    {
      if (!((*((u16 *) (((u8 *) arg0) + 0xA))) & 0x100))
      {
        PTR_78(arg0)[0xE] = 0;
        PTR_78(arg0)[0xF] = 0;
        PTR_78(arg0)[0x14] = *((u8 *) (IDX1(i) + ((s32) D_8009F32E)));
        PTR_78(arg0)[0x16] = 0;
        PTR_78(arg0)[0x15] = 0;
        PTR_78(arg0)[0x17] = *((u8 *) (IDX1(i) + ((s32) D_8009F32F)));
        PTR_78(arg0)[0x1B] = *((u8 *) (IDX1(i) + ((s32) D_8009F330)));
      }
      else
      {
        PTR_78(arg0)[0xE] = 0;
        PTR_78(arg0)[0xF] = 0;
        PTR_78(arg0)[0x14] = *((u8 *) (IDX1(i) + ((s32) D_8009F331)));
        PTR_78(arg0)[0x16] = 0;
        PTR_78(arg0)[0x15] = 0;
        PTR_78(arg0)[0x17] = *((u8 *) (IDX1(i) + ((s32) D_8009F332)));
        PTR_78(arg0)[0x1B] = *((u8 *) (IDX1(i) + ((s32) D_8009F333)));
      }
      return 1;
    }
  }

  i = 0;
  q = D_8009EB80 * 0xD8;
  for (;;)
  {
    if ((*((u16 *) (D_8009EC6C + q))) == 0)
    {
      return 0;
    }
    if ((*((u16 *) (D_8009EC6C + q))) == (*((u16 *) (((u8 *) arg0) + 0x8C))))
    {
      break;
    }
    i++;
    q += 0x12;
    if (!(i < 0xC))
    {
      break;
    }
  }

  end = i;
  if ((*((u16 *) (((u8 *) arg0) + 0xA))) & 0x100)
  {
    PTR_78(arg0)[0xE] = *((u8 *) (IDX2(i) + ((s32) D_8009EC76)));
    new_var2 = arg0;
    PTR_78(new_var2)[0xF] = *((u8 *) (IDX2(i) + ((s32) D_8009EC77)));
    PTR_78(new_var2)[0x14] = *((u8 *) (IDX2(i) + ((s32) D_8009EC78)));
    PTR_78(new_var2)[0x16] = *((u8 *) (IDX2(i) + ((s32) D_8009EC79)));
    PTR_78(new_var2)[0x15] = *((u8 *) (IDX2(i) + ((s32) D_8009EC7A)));
    PTR_78(new_var2)[0x17] = *((u8 *) (IDX2(i) + ((s32) D_8009EC7B)));
    PTR_78(new_var2)[0x1B] = *((u8 *) (IDX2(end = i) + ((s32) D_8009EC7D)));
    PTR_78(new_var2)[0x1A] = *((u8 *) (IDX2(end) + ((s32) D_8009EC7C)));
  }
  else
  {
    PTR_78(new_var2)[0xE] = *((u8 *) (IDX2(end) + ((s32) D_8009EC6E)));
    PTR_78(new_var2)[0xF] = *((u8 *) (IDX2(end) + ((s32) D_8009EC6F)));
    PTR_78(new_var2)[0x14] = *((u8 *) (IDX2(end) + ((s32) D_8009EC70)));
    PTR_78(new_var2)[0x16] = *((u8 *) (IDX2(end) + ((s32) D_8009EC71)));
    PTR_78(new_var2)[0x15] = *((u8 *) (IDX2(end) + ((s32) D_8009EC72)));
    PTR_78(new_var2)[0x17] = *((u8 *) (IDX2(end) + ((s32) D_8009EC73)));
    PTR_78(new_var2)[0x1B] = *((u8 *) (IDX2(end) + ((s32) D_8009EC75)));
    PTR_78(new_var2)[0x1A] = *((u8 *) (IDX2(end) + ((s32) D_8009EC74)));
  }
  return 1;
  not_in_table:
  *((u16 *) (((u8 *) new_var2) + 0xA)) |= 0x800;

  PTR_78(new_var2)[0xE] = 0;
  PTR_78(new_var2)[0xF] = 0;
  PTR_78(new_var2)[0x14] = 0x32;
  PTR_78(new_var2)[0x16] = 0;
  PTR_78(new_var2)[0x15] = 0;
  PTR_78(new_var2)[0x17] = 0x32;
  PTR_78(new_var2)[0x1B] = 0;
  return 1;
}


