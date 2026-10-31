extern u8 D_800C02AE;
s32 func_80034FF0(void *, s32);
void *func_80040260(s32, s16, s16, s32, void *, s32);
void *func_8004240C(s32);
extern void *D_800C35A0;
extern void *D_800C7F84;
extern void func_8003ED04(void);
extern void func_8003ED94(void);
extern void func_8003EE84(void);
extern void func_8003EF20(void);
void func_8003E6D8(s32 arg0, s32 arg1)
{
  char *__repair_addr;
  s32 sp1C;
  void *owner;
  s32 result;
  u32 sp24;
  s32 sp2C;
  s32 temp_fp;
  s16 temp_s0;
  s16 temp_s0_2;
  s16 temp_s1_2;
  s16 temp_s2_2;
  s16 temp_s3;
  s32 var_s3;
  void *temp_s1;
  s32 temp_s2;
  s32 temp_s6_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  u16 temp_s6;
  u16 temp_v1;
  u32 var_s1;
  u32 temp_t0;
  void *temp_a0;
  void *temp_s4;
  void *temp_v0;
  void *temp_v0_2;
  void *mgr;
  mgr = D_800C7F84;
  owner = *((void **) (((char *) mgr) + 0x178));
  temp_v0 = (void *) owner;
  temp_fp = *((s16 *) (((char *) temp_v0) + 8));
  temp_v1 = *((u16 *) (((char *) D_800C35A0) + 0x1E));
  sp1C = (*((s16 *) (((char *) temp_v0) + 0xA))) + 6;
  var_s3 = temp_fp + 0x14;
  if (temp_v1 != 7)
  {
    temp_s6 = *((u16 *) (((char *) D_800C35A0) + 0xE));
    switch (temp_s6)
    {
      case 1:
        if (temp_v1 == 0)
      {
        __repair_addr = (char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28));
        if ((*((u8 *) (((char *) __repair_addr) + 0x48))) & 1)
        {
          temp_s4 = func_80040260(arg0, (s16) var_s3, (s16) sp1C, 5, &func_8003ED04, (s32) temp_s6);
          result = func_80034FF0(temp_s1, 0);
          owner = D_800C7F84;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 0;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, (s16) (temp_fp + 0x1C), (s16) sp1C, 5, &func_8003ED04, (s32) temp_s6);
          result = func_80034FF0(temp_s1, 0);
          owner = D_800C7F84;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 1;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, (s16) (temp_fp + 0x24), (s16) sp1C, 5, &func_8003ED04, (s32) temp_s6);
          result = func_80034FF0(temp_s1, 0);
          owner = D_800C7F84;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 2;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          return;
        }
      }
      else
      {
        var_s1 = 0;
        if ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) D_800C35A0) + 0x32))) * 0x28))) + 0x48))) & 4)
        {
          do
          {
            temp_s0 = sp1C + (((s16) var_s1) * 0xB);
            var_s1 += 1;
            temp_s4 = func_80040260(arg0, 0x1C, temp_s0, 5, &func_8003ED94, 1);
            result = func_80034FF0(temp_s1, 0);
            owner = D_800C7F84;
            *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
            *((s16 *) (((char *) temp_s4) + 0x78)) = 0;
            *((u16 *) (((char *) temp_s4) + 0x76)) = var_s1;
            *((void **) (((char *) temp_s4) + 0xA8)) = owner;
            temp_s4 = func_80040260(arg0, 0x24, temp_s0, 5, &func_8003ED94, 1);
            result = func_80034FF0(temp_s1, 0);
            owner = D_800C7F84;
            *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
            *((s16 *) (((char *) temp_s4) + 0x78)) = 1;
            *((u16 *) (((char *) temp_s4) + 0x76)) = var_s1;
            *((void **) (((char *) temp_s4) + 0xA8)) = owner;
            temp_s4 = func_80040260(arg0, 0x2C, temp_s0, 5, &func_8003ED94, 1);
            result = func_80034FF0(temp_s1, 0);
            owner = D_800C7F84;
            *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
            *((s16 *) (((char *) temp_s4) + 0x78)) = 2;
            *((u16 *) (((char *) temp_s4) + 0x76)) = var_s1;
            *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          }
          while (var_s1 < 4U);
          return;
        }
      }
        break;

      case 2:
        sp24 = 1;
        temp_s6_2 = arg1 + 0x4C;
        arg1 = 0;
        sp2C = 1;
        do
      {
        temp_v0_2 = func_8004240C(sp2C);
        temp_a0 = *((void **) (((char *) temp_v0_2) + 0x178));
        D_800C7F84 = temp_v0_2;
        var_s3 = *((s16 *) (((char *) temp_a0) + 8));
        sp1C = (*((s16 *) (((char *) temp_a0) + 0xA))) + 6;
        if (!((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1))
        {
          var_s3 += 0x14;
          if ((*((s32 *) (((char *) temp_v0_2) + 0xC))) == 3)
          {
            var_s3 -= 0xE;
          }
        }
        if (((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 0) && ((*((u8 *) (((char *) (D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + sp24)) + 0x31))) * 0x28))) + 0x48))) & 4))
        {
          temp_s2_2 = var_s3 + 8;
          temp_s0_2 = sp1C + 0xA;
          temp_s4 = func_80040260(arg0, temp_s2_2, temp_s0_2, 5, &func_8003EF20, 1);
          temp_s1_2 = var_s3 + 0x10;
          result = func_80034FF0((void *) temp_s6_2, 0);
          owner = D_800C7F84;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 0;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, temp_s1_2, temp_s0_2, 5, &func_8003EF20, 1);
          temp_s3 = var_s3 + 0x18;
          result = func_80034FF0((void *) temp_s6_2, 0);
          owner = (*((void **) (((char *) temp_s4) + 0xA8)) = D_800C7F84);
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 1;
          temp_s4 = func_80040260(arg0, temp_s3, temp_s0_2, 5, &func_8003EF20, 1);
          result = func_80034FF0((void *) temp_s6_2, 0);
          owner = D_800C7F84;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = result;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 2;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, temp_s2_2, temp_s0_2, 5, &func_8003EE84, 1);
          temp_v0_3 = func_80034FF0((void *) temp_s6_2, 0);
          owner = D_800C7F84;
          *((u8 *) (((char *) temp_s4) + 0x90)) = 0xFE;
          *((u8 *) (((char *) temp_s4) + 0x91)) = 0xD5;
          *((s8 *) (((char *) temp_s4) + 0x92)) = 0x1E;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = temp_v0_3;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 0;
          *((s16 *) (((char *) temp_s4) + 0x76)) = arg1;
          *((u8 *) (((char *) temp_s4) + 0x93)) = 0xFF;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, temp_s1_2, temp_s0_2, 5, &func_8003EE84, 1);
          temp_v0_4 = func_80034FF0((void *) temp_s6_2, 0);
          owner = D_800C7F84;
          *((u8 *) (((char *) temp_s4) + 0x90)) = 0xFE;
          *((u8 *) (((char *) temp_s4) + 0x91)) = 0xD5;
          *((s8 *) (((char *) temp_s4) + 0x92)) = 0x1E;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = temp_v0_4;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 1;
          *((s16 *) (((char *) temp_s4) + 0x76)) = arg1;
          *((u8 *) (((char *) temp_s4) + 0x93)) = 0xFF;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
          temp_s4 = func_80040260(arg0, temp_s3, temp_s0_2, 5, &func_8003EE84, 1);
          var_s1 = func_80034FF0((void *) temp_s6_2, 0);
          owner = D_800C7F84;
          *((s16 *) (((char *) temp_s4) + 0x78)) = 2;
          *((u8 *) (((char *) temp_s4) + 0x90)) = 0xFE;
          *((u8 *) (((char *) temp_s4) + 0x91)) = 0xD5;
          *((s8 *) (((char *) temp_s4) + 0x92)) = 0x1E;
          *((s32 *) (((char *) temp_s4) + 0xA4)) = var_s1;
          *((s16 *) (((char *) temp_s4) + 0x76)) = arg1;
          *((u8 *) (((char *) temp_s4) + 0x93)) = 0xFF;
          *((void **) (((char *) temp_s4) + 0xA8)) = owner;
        }
        sp2C += 2;
        arg1 += 1;
        temp_t0 = sp24 + 1;
        sp24 = temp_t0;
      }
      while (temp_t0 < 3U);
        break;

    }

  }
}
