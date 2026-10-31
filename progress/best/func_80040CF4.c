typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
} Rect;
typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
} __attribute__((packed)) PackedRect;
typedef struct 
{
  u8 pad[12];
  s32 id;
} Item;
extern void func_800424A4(Item *, void *);
extern u8 D_800C02AE[];
extern s16 D_8009FFD8;
extern s16 D_8009FFDA;
extern u16 D_8009FFDC;
extern u16 D_8009FFDE;
extern u16 D_8009FF38[];
extern u16 D_8009FF3A[];
extern u16 D_8009FF3C[];
extern u16 D_8009FF3E[];
extern u16 D_8009FF40[];
extern u16 D_8009FF42[];
extern u16 D_8009FF44[];
extern u16 D_8009FF46[];
extern u16 D_8009FF48[];
extern u16 D_8009FF4A[];
extern u8 D_800A4C30[];
extern u8 D_800A4C38[];
extern u8 D_800A4C40[];
extern u8 D_800A4C48[];
extern u8 D_800A4C50[];
extern u8 D_800A4C58[];
extern u8 D_800A4C60[];
static inline static static static static static static int inline_fn(u8 arg0, int arg1)
{
  return arg0 != arg1;
}

void func_80040CF4(u8 arg0)
{
  Rect r;
  u8 sp27;
  short sp2C;
  int new_var4;
  u8 sp3F;
  u8 sp37;
  Item *temp_v0_10;
  Item *temp_v0_11;
  int new_var;
  Item *temp_v0_13;
  Item *temp_v0_15;
  Item *temp_v0_2;
  Item *temp_v0_3;
  Item *temp_v0_4;
  Item *temp_v0_5;
  Item *temp_v0_6;
  Item *temp_v0_7;
  Item *temp_v0_8;
  Item *temp_v0_9;
  s16 temp_fp;
  s32 temp_s3;
  s16 temp_s3_2;
  s16 temp_s4;
  void *new_var3;
  unsigned int temp_s5;
  u8 *new_var2;
  s16 temp_s5_2;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_4;
  s32 temp_s1_2;
  s32 temp_v0;
  s32 temp_v0_12;
  s32 temp_v0_14;
  u16 var_a2;
  int var_a3;
  u32 temp_s0;
  u32 temp_s1;
  u8 temp_t0;
  void *temp_s2;
  temp_s2 = *((u8 **) (D_800C02AE + 0x32F2));
  temp_fp = D_8009FFD8;
  new_var4 = 0x30;
  sp27 = arg0;
  temp_t0 = ((u8 *) temp_s2)[15];
  temp_s1 = D_8009FFDC << 0x10;
  temp_s5 = (s16) D_8009FFDC;
  sp37 = temp_t0;
  sp3F = temp_t0 - 1;
  temp_s0 = D_8009FFDE << 0x10;
  new_var = (sp37 * 2) | 1;
  temp_s3 = (s16) D_8009FFDE;
  if (inline_fn(sp37, 0))
  {
    r.x = (temp_v0 = temp_fp);
    r.w = temp_s5;
    r.h = temp_s3;
    temp_v0 = sp3F * 0x14;
    r.y = (u16) sp2C;
    temp_v0_2 = func_80042078(&r, 5, *((u16 *) (((u8 *) D_8009FF38) + temp_v0)), *((u16 *) (((u8 *) D_8009FF3A) + temp_v0)), 2);
    func_800424A4(temp_v0_2, D_800A4C30);
    temp_v0_2->id = 0;
  }
  switch (sp37)
  {
    case 1:
      r.x = temp_v0;
      sp2C = (s32) D_8009FFDA;
      r.w = temp_s5;
      r.h = temp_s3;
      temp_s0_2 = sp3F * 0x14;
      r.y = (u16) sp2C;
      temp_v0_3 = (*((Item **) (D_800C02AE + 0x7CD6)) = func_80042078(&r, 0, *((u16 *) (((u8 *) D_8009FF3C) + temp_s0_2)), *((u16 *) (((u8 *) D_8009FF3E) + temp_s0_2)), 2));
      func_800424A4(temp_v0_3, D_800A4C38);
      new_var2 = ((u8 *) D_8009FF40) + temp_s0_2;
      temp_v0_3->id = (s32) sp37;
      temp_v0_4 = func_80042078(&r, 0, *((u16 *) new_var2), *((u16 *) (((u8 *) D_8009FF42) + temp_s0_2)), 2);
      func_800424A4(temp_v0_4, D_800A4C40);
      temp_v0_4->id = 2;
      break;

    case 2:
      temp_s4 = temp_fp + 0x20;
      if ((*((u16 *) (((u8 *) temp_s2) + 18))) & 1)
    {
      temp_s5_2 = temp_s5 - 0x38;
      temp_s0_3 = temp_s3 / 2;
      temp_s3_2 = temp_s0_3 - 1;
      r.x = temp_s4;
      r.w = temp_s5_2;
      r.h = temp_s3_2;
      temp_s1_2 = sp3F * 0x14;
      r.y = (u16) sp2C;
      temp_v0_10 = &r;
      temp_v0_5 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF3C) + temp_s1_2)), *((u16 *) (((u8 *) D_8009FF3E) + temp_s1_2)), (s32) sp37);
      func_800424A4(temp_v0_5, D_800A4C38);
      temp_v0_5->id = 1;
      new_var3 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF40) + temp_s1_2)), *((u16 *) (((u8 *) D_8009FF42) + temp_s1_2)), (s32) sp37);
      *((Item **) (D_800C02AE + 0x7CD6)) = temp_v0_5;
      temp_v0_6 = new_var3;
      func_800424A4(temp_v0_6, D_800A4C40);
      temp_v0_6->id = (s32) sp37;
      r.x = temp_s4;
      r.y = (sp2C + temp_s0_3) + 1;
      r.w = temp_s5_2;
      r.h = temp_s3_2;
      temp_v0_7 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF3C) + temp_s1_2)), *((u16 *) (((u8 *) D_8009FF3E) + temp_s1_2)), (s32) sp37);
      func_800424A4(temp_v0_7, D_800A4C48);
      temp_v0_7->id = 3;
      var_a2 = *((u16 *) (((u8 *) D_8009FF40) + temp_s1_2));
      var_a3 = *((u16 *) (((u8 *) D_8009FF42) + temp_s1_2));
    }
    else
    {
      temp_s1_2 = ((s32) (temp_s5 + (temp_s1 >> 0x1F))) >> 1;
      temp_s4 = temp_s1_2 - 1;
      r.x = temp_fp;
      r.w = temp_s4;
      r.h = temp_s3;
      temp_s0_4 = sp3F * 0x14;
      r.y = (u16) sp2C;
      *((Item **) (D_800C02AE + 0x7CD6)) = (temp_v0_8 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF3C) + temp_s0_4)), *((u16 *) (((u8 *) D_8009FF3E) + temp_s0_4)), (s32) sp37));
      func_800424A4(temp_v0_8, D_800A4C38);
      temp_v0_8->id = 1;
      temp_v0_9 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF40) + temp_s0_4)), *((u16 *) (((u8 *) D_8009FF42) + temp_s0_4)), (s32) sp37);
      func_800424A4(temp_v0_9, D_800A4C40);
      temp_v0_9->id = (s32) sp37;
      r.x = (temp_fp + temp_s1_2) + 1;
      r.y = (u16) sp2C;
      r.w = temp_s4;
      r.h = temp_s3;
      temp_v0_10 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF3C) + temp_s0_4)), *((u16 *) (((u8 *) D_8009FF3E) + temp_s0_4)), (s32) sp37);
      func_800424A4(temp_v0_10, D_800A4C48);
      temp_v0_10->id = 3;
      var_a2 = *((u16 *) (((u8 *) D_8009FF40) + temp_s0_4));
      var_a3 = *((u16 *) (((u8 *) D_8009FF42) + temp_s0_4));
    }
      temp_v0_11 = func_80042078(temp_v0_10, 0, var_a2, var_a3, (s32) sp37);
      func_800424A4(temp_v0_11, D_800A4C50);
      temp_v0_11->id = 4;
      break;

  }

  if (inline_fn(sp37, 0) && (sp27 == 0))
  {
    *((PackedRect *) temp_v0_10) = *((PackedRect *) (&D_8009FFD8));
    temp_v0_12 = sp3F * 0x14;
    temp_v0_13 = func_80042078(temp_v0_10, 5, *((u16 *) (((u8 *) D_8009FF44) + temp_v0_12)), *((u16 *) (((u8 *) D_8009FF46) + temp_v0_12)), 2);
    func_800424A4(temp_v0_13, D_800A4C58);
    do
    {
      temp_v0_13->id = new_var;
      *((PackedRect *) temp_v0_10) = *((PackedRect *) (&D_8009FFD8));
    }
    while (0);
    if (((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 14))) == 2) && ((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 18))) & 1))
    {
      r.x = ((u16) r.x) + 0x18;
      r.w = ((u16) r.w) - new_var4;
    }
    temp_v0_14 = sp3F * 0x14;
    temp_v0_15 = func_80042078(temp_v0_10, 0, *((u16 *) (((u8 *) D_8009FF48) + temp_v0_14)), *((u16 *) (((u8 *) D_8009FF4A) + temp_v0_14)), 2);
    func_800424A4(temp_v0_15, D_800A4C60);
    temp_v0_15->id = (sp37 * 2) + 2;
  }
}
