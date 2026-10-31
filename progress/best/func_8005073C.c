typedef struct 
{
  s32 a[10];
} Copy40;
s32 func_8004F3C4();
s32 func_8008E13C(s32, s32, s32);
extern void *D_800A1234;
extern void *D_800A1238;
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
void func_8005073C(void *arg0)
{
  void *sp14;
  s32 pad[2];
  s32 temp_v1;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 var_v1;
  u16 temp_a0;
  u16 temp_v1_2;
  u32 var_s2;
  u8 temp_s6;
  void *temp_fp;
  void *temp_s0;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_s1_3;
  void *temp_s5;
  void *temp_v1_3;
  void *var_a2;
  void *var_a3;
  void *var_s3;
  void *var_v1_2;
  func_8004F3C4();
  if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1E))) == 0)
  {
    temp_s6 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x48)))) + 3));
    if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x1A))) == 1)
    {
      temp_fp = D_800A1238;
      temp_v1 = temp_s6 * 0x44;
      temp_s5 = D_800A1234;
      temp_s0 = temp_fp + temp_v1;
      temp_s1 = temp_s5 + temp_v1;
      if ((*((u16 *) (((char *) temp_s0) + 8))) & 0x10)
      {
        var_v1 = (*((u16 *) (((char *) temp_s0) + 0xA))) != 5;
      }
      else
      {
        var_v1 = 1;
      }
      temp_a0 = *((u16 *) (((char *) temp_s0) + 8));
      if ((temp_a0 & 0x80) && ((*((u16 *) (((char *) temp_s1) + 8))) & 0x80))
      {
        *((u16 *) (((char *) temp_s0) + 8)) = (u16) (temp_a0 & 0xFF7F);
        var_v1 = 0;
        *((u16 *) (((char *) temp_s1) + 8)) = (u16) ((*((u16 *) (((char *) temp_s1) + 8))) & 0xFEFF);
      }
      var_v1 &= -(!((*((u16 *) (((char *) temp_s1) + 8))) & 2));
      if (var_v1 && (((temp_v1_2 = *((u16 *) (((char *) temp_s0) + 0xE)), (((u16) (*((u16 *) (((char *) temp_s1) + 0xE)))) < temp_v1_2) != 0)) || (temp_v1_2 == 0)))
      {
        var_s2 = 0;
        if ((*((u16 *) (((char *) temp_s5) + 0x110))) != 0)
        {
          sp14 = temp_s1 + 0x3C;
          var_s3 = temp_fp;
          do
          {
            temp_s0 = var_s3;
            *((u16 *) (((char *) temp_s0) + 8)) = 0U;
            *((s16 *) (((char *) temp_s0) + 0xA)) = 0;
            *((u16 *) (((char *) temp_s0) + 0xC)) = 0U;
            *((u16 *) (((char *) temp_s0) + 0xE)) = (u16) (*((u16 *) (((char *) temp_s1) + 0xE)));
            func_8008E13C(*((s32 *) (((char *) temp_s0) + 0)), *((s32 *) (((char *) temp_s1) + 0)), ((*((s32 *) (((char *) temp_s1) + 0x10))) + 3) & (~3));
            func_8008E13C(*((s32 *) (((char *) temp_s0) + 4)), *((s32 *) (((char *) temp_s1) + 4)), ((*((s32 *) (((char *) temp_s1) + 0x14))) + 3) & (~3));
            var_a3 = temp_s0 + 0x1C;
            if (var_s2 != temp_s6)
            {
              var_v1_2 = *(*((void ***) (((char *) (&D_800AE850)) + 0x73F0)));
              if ((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE))) == 2)
              {
                if (var_s2 == 1)
                {
                  var_v1_2 = *((void **) (((char *) (*((void **) (((char *) var_v1_2) + 4)))) + 4));
                }
                temp_s1_2 = *((void **) (((char *) var_v1_2) + 4)); temp_v1_3=(void *)temp_s1_2;
                *((s32 *) (((char *) (*((void **) (((char *) temp_v1_3) + 0x5C)))) + 0x6C)) = 0;
                *((s32 *) (((char *) (*((void **) (((char *) temp_v1_3) + 0x30)))) + 0x6C)) = 0;
              }
              *((u16 *) (((char *) temp_s0) + 0xC)) = (u16) (*((u16 *) (((char *) temp_s0) + 0xE)));
              var_a3 = temp_s0 + 0x1C;
            }
            *((Copy40 *) (temp_s0 + 0x1C)) = *((Copy40 *) (temp_s1 + 0x1C));
            *((s32 *) (((char *) temp_s0) + 0x18)) = (s32) (*((s32 *) (((char *) temp_s1) + 0x18)));
            *((u16 *) (((char *) temp_s0) + 8)) = (u16) (((*((u16 *) (((char *) temp_s0) + 8))) | 0x211) & 0xFBFF);
            var_s3 = temp_fp + (var_s2 * 0x44);
            var_s2 += 1;
          }
          while (var_s2 < ((u16) (*((u16 *) (((char *) temp_s5) + 0x110)))));
        }
        *((s32 *) (((char *) arg0) + 0x14)) = (s32) ((*((s32 *) (((char *) arg0) + 0x14))) | 0x4000);
      }
      else
      {
        *((u16 *) (((char *) temp_s0) + 8)) = (u16) (((*((u16 *) (((char *) temp_s0) + 8))) | 0x201) & 0xFBFF);
        *((s32 *) (((char *) arg0) + 0x14)) = (s32) ((*((s32 *) (((char *) arg0) + 0x14))) & (~0x4000));
        *((s16 *) (((char *) temp_s0) + 0xC)) = 0;
      }
      if ((*((u8 *) (((char *) (&D_800A73E0)) + 0x6C01))) != 0)
      {
        if (temp_s0)
        {
          temp_v1_4 = temp_s6 * 0x44;
          *((s16 *) (((char *) (temp_fp + temp_v1_4)) + 0xA)) = 4;
          *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x6C)) = 1;
          temp_s1_2 = temp_s5 + temp_v1_4;
          *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x30)))) + 0x6C)) = 1;
          *((s16 *) (((char *) temp_s1_2) + 0xA)) = 1;
          *((s16 *) (((char *) temp_s1_2) + 0xC)) = 0;
          *((s16 *) (((char *) temp_s1_2) + 0xE)) = 0;
          *((u16 *) (((char *) temp_s1_2) + 8)) = (u16) (((*((u16 *) (((char *) temp_s1_2) + 8))) | 0x400) & 0xFDFF);
          return;
        }
        else
        {
          temp_v1_4 = temp_s6 * 0x44;
          *((s16 *) (((char *) (temp_fp + temp_v1_4)) + 0xA)) = 4;
          *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x6C)) = 1;
          temp_s1_2 = temp_s5 + temp_v1_4;
          *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x30)))) + 0x6C)) = 1;
          *((s16 *) (((char *) temp_s1_2) + 0xA)) = 1;
          *((s16 *) (((char *) temp_s1_2) + 0xC)) = 0;
          *((s16 *) (((char *) temp_s1_2) + 0xE)) = 0;
          *((u16 *) (((char *) temp_s1_2) + 8)) = (u16) (((*((u16 *) (((char *) temp_s1_2) + 8))) | 0x400) & 0xFDFF);
          return;
        }
      }
      temp_v1_5 = temp_s6 * 0x44;
      *((s16 *) (((char *) (temp_fp + temp_v1_5)) + 0xA)) = 3;
      *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x6C)) = 0;
      temp_s1_3 = temp_s5 + temp_v1_5;
      *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x30)))) + 0x6C)) = 0;
      *((s16 *) (((char *) temp_s1_3) + 0xA)) = 3;
      *((s16 *) (((char *) temp_s1_3) + 0xC)) = 0;
      *((s16 *) (((char *) temp_s1_3) + 0xE)) = 0;
      *((u16 *) (((char *) temp_s1_3) + 8)) = (u16) ((*((u16 *) (((char *) temp_s1_3) + 8))) | 0x600);
      return;
    }
    if (((*((u16 *) (((char *) (&D_800AE850)) + 0x2410))) & 2) || ((*((u16 *) (((char *) (&D_800AE850)) + 0x2454))) & 2))
    {
      *((s16 *) (((char *) (&D_800AE850)) + 0x2416)) = 0;
      *((s16 *) (((char *) (&D_800AE850)) + 0x245A)) = 0;
    }
  }
}
