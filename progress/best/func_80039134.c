extern u8 *D_800C35A0;
extern u8 *D_800C7F84;
extern s32 func_80034FF0(s32, s32);
extern void func_8003C6D8(s32, s32, s32);
extern void *func_80040260(s32, s16, s16, s32, void *, s32);
extern void *func_8004240C(s32);
extern void func_8003BA58(void);
extern void func_8003BADC(void);
typedef struct 
{
  unsigned char pad_0[120];
  short field_78;
  short field_7A;
  unsigned char pad_7C[23];
  signed char field_93;
  unsigned char pad_94[12];
  int field_A0;
  int field_A4;
  void *field_A8;
} __repair_record_temp_s3;
void func_80039134(s32 arg0, s32 arg1)
{
  u8 *a0;
  u8 idx;
  u8 *entry;
  u16 temp_s0;
  s32 temp_s1;
  s32 temp_s2;
  s32 temp_s6;
  s32 temp_t1;
  u32 temp_v0;
  s32 temp_s5;
  u32 temp_s2_loop;
  void *temp_s3;
  void *temp_t0;
  void *temp_v0_p;
  void *temp_v1;
  u32 var_s1;
  a0 = D_800C35A0;
  arg1 = arg1;
  if ((*((u16 *) (a0 + 0x1E))) != 7)
  {
    temp_s5 = *((u16 *) (a0 + 0xE));
    switch (temp_s5)
    {
      case 1:
      {
        idx = a0[0x32];
        entry = a0 + (idx * 0x28);
        ((__repair_record_temp_s3 *) temp_s3)->field_A8 = D_800C7F84;
        if (entry[0x48] & 2)
        {
          temp_v0_p = func_8004240C(1);
          temp_t0 = *((void **) (((u8 *) temp_v0_p) + 0x178));
          temp_v1 = (void *) temp_t0;
          D_800C7F84 = (u8 *) temp_v0_p;
          temp_s2_loop = *((s16 *) (((u8 *) temp_v1) + 0xE));
          temp_s1 = (*((s16 *) (((u8 *) temp_v1) + 0xC))) - 0x66;
          temp_s0 = temp_s2_loop - 0x54;
          temp_s3 = func_80040260(arg0, temp_s1, temp_s0, 5, 0, temp_s5);
          temp_s2 = arg1 + 0x4C;
          ((__repair_record_temp_s3 *) temp_s3)->field_A0 = 2;
          ((__repair_record_temp_s3 *) temp_s3)->field_A4 = func_80034FF0(temp_s2, 0);
          ((__repair_record_temp_s3 *) temp_s3)->field_7A = 0xC;
          ((__repair_record_temp_s3 *) temp_s3)->field_A8 = D_800C7F84;
          ((__repair_record_temp_s3 *) temp_s3)->field_93 = 0x64;
          func_8003C6D8(arg0, arg1, 0);
          temp_s3 = func_80040260(arg0, temp_s1, temp_s0, 5, func_8003BADC, temp_s5);
          ((__repair_record_temp_s3 *) temp_s3)->field_78 = 0;
          ((__repair_record_temp_s3 *) temp_s3)->field_A4 = func_80034FF0(temp_s2, 0);
          ((__repair_record_temp_s3 *) temp_s3)->field_7A = 8;
          ((__repair_record_temp_s3 *) temp_s3)->field_A8 = D_800C7F84;
        }
      }
        break;

      case 2:
      {
        temp_s6 = arg1 + 0x4C;
        temp_s5 = 1;
        temp_s2_loop = 1;
        do
        {
          a0 = D_800C35A0;
          idx = a0[temp_s2_loop + 0x31];
          entry = a0 + (idx * 0x28);
          if (entry[0x48] & 2)
          {
            temp_t0 = func_8004240C(temp_s5);
            temp_v0_p = *((void **) (((u8 *) temp_t0) + 0x178));
            a0 = D_800C35A0;
            D_800C7F84 = (u8 *) temp_t0;
            temp_t1 = 0;
            var_s1 = (*((s16 *) (((u8 *) temp_v0_p) + 8))) + (*((s16 *) (((u8 *) temp_v0_p) + 0xC)));
            temp_s1 = *((s16 *) (((u8 *) temp_v0_p) + 0xE));
            temp_s1 = ((*((s16 *) (((u8 *) temp_v0_p) + 0xA))) + temp_s1) + (-0x38);
            if (!((*((u16 *) (a0 + 0x12))) & 1))
            {
              var_s1 -= 0x10;
              temp_v0 = *((s32 *) (((u8 *) temp_t0) + 0xC));
              temp_v0 ^= 1;
              temp_v0 = temp_v0 < 1;
              temp_v0 = -temp_v0;
              temp_t1 = temp_v0 & 0x14;
            }
            temp_s0 = (var_s1 + (-0x39)) + temp_t1;
            temp_s3 = func_80040260(arg0, temp_s0, temp_s1, 5, func_8003BA58, 1);
            ((__repair_record_temp_s3 *) temp_s3)->field_A4 = func_80034FF0(temp_s6, 0);
            ((__repair_record_temp_s3 *) temp_s3)->field_A0 = 2;
            ((__repair_record_temp_s3 *) temp_s3)->field_7A = 0xD;
            ((__repair_record_temp_s3 *) temp_s3)->field_A8 = D_800C7F84;
            func_8003C6D8(arg0, arg1, temp_s2_loop);
            temp_s3 = func_80040260(arg0, temp_s0, temp_s1, 5, func_8003BADC, 1);
            ((__repair_record_temp_s3 *) temp_s3)->field_78 = 0;
            ((__repair_record_temp_s3 *) temp_s3)->field_A4 = func_80034FF0(temp_s6, 0);
            ((__repair_record_temp_s3 *) temp_s3)->field_7A = 0xA;
          }
          a0 = D_800C35A0;
          temp_s2_loop++;
          temp_s5 += 2;
        }
        while ((*((u16 *) (a0 + 0xE))) >= temp_s2_loop);
      }
        break;

    }

  }
}

