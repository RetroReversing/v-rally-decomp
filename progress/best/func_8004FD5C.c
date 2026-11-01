#define memset func_80097E30
extern signed char D_800C836C;
extern char *D_800C35A0;
s32 func_80022184();
s32 func_80022A90();
s32 func_80022A98();
s32 func_8007EAA0();
s32 func_80097E30(s32, s32, s32);
extern s32 D_8009D540;
extern char D_800AE850[];
extern char D_800C02AE[];
typedef struct 
{
  int value;
} __repair_field_0;
typedef struct 
{
  unsigned char pad_0[4];
  int field_4;
  unsigned char pad_8[16];
  int field_18;
  unsigned char pad_1C[244];
  unsigned short field_110;
  short field_112;
} __repair_record_arg0;
s32 func_8004FD5C(void *arg0, s32 arg1)
{
  s32 var_s1;
  s32 temp_v0;
  s32 var_s6;
  s32 var_v0;
  u16 temp_a0;
  u32 var_s4;
  u16 *new_var2;
  u16 var_v0_2;
  u32 var_s2;
  u32 var_s2_2;
  void *temp_v0_2;
  void *var_a2;
  void *var_a3;
  char *new_var;
  void *var_s0;
  void *var_s0_2;
  void *var_s1_2;
  void *var_s1_3;
  
  u16 cfg2c;
  var_s1 = arg1;
  cfg2c = *((u16 *) (D_800C35A0 + 0x2C));
  D_800C836C = 0;
  var_s6 = 0;
  if (cfg2c & 1)
  {
    var_s1 = D_8009D540 * 0xA0;
  }
  var_v0 = 0;
  if (func_80022184(D_800AE850 + 0x7320) != 0)
  {
    ((__repair_record_arg0 *) arg0)->field_112 = var_s1;
    var_s0 = *(*((void ***) (D_800AE850 + 0x73F0)));
    new_var = (char *) (*((void **) (D_800C02AE + 0x32F2)));
    if (var_s0 != NULL)
    {
      do
      {
        temp_v0 = func_80022A90(var_s0);
        var_s0 = *((void **) (((char *) var_s0) + 4));
        var_s6 = temp_v0;
      }
      while (var_s0 != NULL);
    }
    var_s4 = 4;
    if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) == 0)
    {
      var_s4 = ((__repair_record_arg0 *) arg0)->field_110;
    }
    var_s2 = 0;
    temp_v0_2 = arg0;
    do
    {
      new_var2 = (u16 *) (((char *) temp_v0_2) + 8);
      ((__repair_field_0 *) arg0)->value = 0;
      ((__repair_record_arg0 *) arg0)->field_4 = 0;
      ((__repair_record_arg0 *) arg0)->field_18 = 0;
      temp_a0 = (*((u16 *) (((char *) temp_v0_2) + 8))) & 0xF9FF;
      *new_var2 = temp_a0;
      var_v0_2 = temp_a0 | 8;
      if ((*((u16 *) ((var_s0_2 = new_var) + 0x1E))) == 0)
      {
        if (((*((u16 *) (var_s0_2 + 0x1A))) == 0) && (((u16) ((__repair_record_arg0 *) arg0)->field_110) >= var_s2))
        {
          var_v0_2 = temp_a0 | 8;
          goto block_12;
        }
      }
      else
      {
        block_12:
        *((u16 *) (((char *) temp_v0_2) + 8)) = var_v0_2;

      }
      var_s2 += 1;
      temp_v0_2 += 0x44;
    }
    while (var_s2 < 4U);
    var_s2_2 = 0;
    if (var_s4 != 0)
    {
      var_s1_2 = arg0;
      do
      {
        if (!((*((u16 *) (((char *) var_s1_2) + 8))) & 1))
        {
          *((s32 *) (((char *) var_s1_2) + 0x10)) = (s32) (var_s6 *= 4);
          *((s16 *) (((char *) var_s1_2) + 0xA)) = 3;
          *((s32 *) (((char *) var_s1_2) + 0x14)) = (s32) ((var_s1 + 1) * 4);
          ((__repair_field_0 *) var_s1_2)->value = func_8007EAA0(1, ((*((s32 *) (((char *) var_s1_2) + 0x10))) + 3) & (~3));
          if (var_s2_2 < ((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))))
          {
            *((s32 *) (((char *) var_s1_2) + 4)) = func_8007EAA0(1, ((*((s32 *) (((char *) var_s1_2) + 0x14))) + 3) & (~3));
          }
          else
          {
            *((s32 *) (((char *) var_s1_2) + 4)) = 0;
          }
          memset(((__repair_field_0 *) var_s1_2)->value, 0, *((s32 *) (((char *) var_s1_2) + 0x10)));
          if (var_s2_2 < ((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE)))))
          {
            memset(*((s32 *) (((char *) var_s1_2) + 4)), 0, *((s32 *) (((char *) var_s1_2) + 0x14)));
          }
          *((s16 *) (((char *) var_s1_2) + 0xC)) = 0;
          *((s16 *) (((char *) var_s1_2) + 0xE)) = 0;
        }
        *((u16 *) (((char *) var_s1_2) + 8)) |= 1;
        var_s1_2 += 0x44;
      }
      while (var_s2_2 < var_s4);
    }
    var_s0_2 = *(*((void ***) (D_800AE850 + 0x73F0)));
    var_s2 = 0;
    if (var_s4 != 0)
    {
      var_s1_3 = arg0;
      do
      {
        func_80022A98(var_s0_2, ((__repair_field_0 *) var_s1_3)->value);
        var_a3 = var_s1_3 + 0x1C;
        temp_v0_2 = ((*((u8 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) + var_s2)) + 0x32))) * 0x28) + (*((void **) (D_800C02AE + 0x32F2)));
        var_a2 = temp_v0_2 + 0x44;
        do {
        ((__repair_field_0 *) var_a3)->value = (s32) ((__repair_field_0 *) var_a2)->value;

        *((s32 *) (((char *) var_a3) + 4)) = (s32) (*((s32 *) (((char *) var_a2) + 4)));
        *((s32 *) (((char *) var_a3) + 8)) = (s32) (*((s32 *) (((char *) var_a2) + 8)));
        *((s32 *) (((char *) var_a3) + 0xC)) = (s32) (*((s32 *) (((char *) var_a2) + 0xC)));
        var_s2_2 += 1;
        var_a2 = (var_a3 = 0x10);
        } while (var_a2 != (temp_v0_2 + 0x64));
        ((__repair_field_0 *) var_a3)->value = (s32) ((__repair_field_0 *) var_a2)->value;
        *((s32 *) (((char *) var_a3) + 4)) = (s32) (*((s32 *) (((char *) var_a2) + 4)));
        var_s2 += 1;
        *((s32 *) (((char *) var_s1_3) + 0x18)) = (s32) (*(*((s32 **) (((char *) var_s0_2) + 0x88))));
        var_s0_2 = *((void **) (((char *) var_s0_2) + 4));
        var_s1_3 += 0x44;
      }
      while (var_s2 < var_s4);
    }
    var_v0 = 1;
  }
  return var_v0;
}

