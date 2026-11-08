extern u8 D_800C721E[],D_800C70D4[];
extern u8 D_800C02AE[];
extern s32 D_8009D540;
extern const f64 D_800A57F0;
extern f64 D_800A57F8;
extern f64 D_800A5800;
void func_8006BF30(s32, s32, s32, s32);
void func_8006BA44(s32 incoming_category, s32 arg1)
{
  u8 arg0 = (u8) incoming_category;
  u16 *sp14;
  u32 row_index;
  u8 *coordinate_table;
  u32 coordinate_address;
  f64 temp_fs1;
  f64 threshold;
  f64 temp_fv1;
  s32 temp_a1;
  s32 temp_s2;
  s32 nine;
  s32 hv;
  s32 temp_s2_2;
  u8 temp_a0;
  s32 temp_s0;
  s32 temp_s3;
  s32 temp_s5;
  s32 temp_s6;
  s32 var_a2;
  s32 var_s4;
  u32 var_t0;
  s32 var_v1;
  s32 __repair_subtotal;
  u32 temp_a0_2;
  u8 temp_t1;
  u8 temp_t1_2;
  void *temp_fp;
  void *temp_v0;
  void *packet;
  u8 *packet_table;
  void *temp_v0_2;
  int new_var;
  void *var_a2_2;
  var_a2 = 0;
  var_t0 = 0;
  var_v1 = arg1;
  temp_s6 = ((s32 *) 0x800D0634)[arg0];
  switch (arg0)
  {
    case 1:
      var_t0 = 0x32;
      break;

    case 2:
      var_a2 = 4;
      var_t0 = 0x36;
      break;

    case 3:
      var_a2=9; var_t0=0x3B; break;

    case 4:
      var_a2 = 0xF;
      var_t0 = 0x41;
      break;

  }

  var_v1 = (u32)var_v1 + (u32)var_a2;
  temp_s2 = var_v1;
  var_s4 = 0;
  threshold = D_800A57F0;
  temp_s3 = arg1 & 0xFF;
  row_index = var_t0 + temp_s3;
  coordinate_table = D_800C02AE + 0x5A8A;
  sp14 = (u16*)(coordinate_table + row_index*2);
  temp_fp = (void *) ((u32)(temp_s3 * 4) + (u32)temp_s6);
  temp_s5 = temp_s2 & 0xFF;
  temp_fs1 = ((f64) temp_s5) * D_800A57F8;
  packet_table = D_800C721E;
decode_next:
  {
    temp_fv1 = temp_fs1 + (((f64) (var_s4 & 0xFF)) * D_800A5800);
    if (!(threshold <= temp_fv1))
    {
      new_var = (s32) temp_fv1;
    }
    else
    {
      new_var = (s32)(temp_fv1 - threshold);       new_var = (u32)new_var | 0x80000000U;
    }
    __repair_subtotal = temp_s5 * 8;     __repair_subtotal += temp_s5;
    temp_a0 = new_var & 0xFF;
    temp_s0 = var_s4 & 0xFF;
    if ((((((temp_s0 * 3) + __repair_subtotal) * 4) - (temp_a0 * 8)) & 0xFF) == 4)
    {
      packet = (void *) (packet_table - (-temp_a0));
      temp_t1 = ((u8 *) packet)[1];
      temp_a0 = ((u8) ((u8 *) packet)[0]) >> 4;
      var_t0 = temp_a0 & 0xC;
      if (((temp_t1 < 0xFFU) | (((u32) (temp_a0 & 0xFF)) < 0xFU)) != 0)
      {
        var_t0 >>= 2;
        temp_v0 = (void *) (D_800C70D4 + ((temp_a0 & 0xF3) * 0xE));
        hv = (temp_t1 * 4) + var_t0;
        func_8006BF30(temp_s0, arg0 & 0xFF, 0, temp_s3);
        var_a2_2 = (void *) (((s8 *) temp_s6) + ((temp_s0 * 0x10) + (temp_s3 << 6)));
        ((s8 *) var_a2_2)[0x32] = (s8) (((((u16) (*((u16 *) temp_v0))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2_2)[0x33] = (s8) (((((u16) (*((u16 *) temp_v0))) >> 5) & 0x1F) + 0x41);
        temp_s0 = hv;
        temp_t1 = (((u8 *) temp_v0)[1] & 0x1F) + 0x41;
        ((s8 *) var_a2_2)[0x38] = 1;
        ((s8 *) var_a2_2)[0x34] = (s8) temp_t1;
        if (hv & 1)
        {
          temp_s0 = -((s16) hv);
        }
        temp_a1 = *sp14; temp_a1 -= temp_s0; temp_a1 = (s32)((u32)temp_a1 << 16); temp_a1 >>=16;
        *((s32 *) (((s8 *) var_a2_2) + 0x2C)) = (s32) temp_a1;
        ((s8 *) var_a2_2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) temp_v0) + 2)))) >> 0xC) + ((((u16) (*((u16 *) temp_v0))) >> 0xF) * 0x10));
        new_var = *((s32 *)((s8*)temp_fp + 0x22C)); new_var = (u32)new_var * (u32)D_8009D540; ((s8*)var_a2_2)[0x36] = (s8)(((u32)new_var * 0xE10U) / (u32)(temp_a1 * 0x3E8));
      }
    }
    else
    {
      temp_v0_2 = (void *) ((u32)temp_a0 + (u32)packet_table);
      temp_t1_2 = ((u8 *) temp_v0_2)[0];
      temp_a0_2 = ((u8 *) temp_v0_2)[1] & 0xF;
      __repair_subtotal = (temp_t1_2 < 0xFFU) | ((temp_a0 = temp_a0_2) < 0xFU);
      if (__repair_subtotal != 0)
      {
        temp_v0 = (void *) (D_800C70D4 + ((temp_a0 >> 2) * 0xE));
        temp_s2_2 = temp_t1_2 | ((temp_a0_2 & 3) << 8);
        func_8006BF30(temp_s0, arg0 & 0xFF, 0, temp_s3);
        var_a2_2 = (void *) (((s8 *) temp_s6) + ((temp_s0 * 0x10) + (temp_s3 << 6)));
        ((s8 *) var_a2_2)[0x32] = (s8) (((((u16) (*((u16 *) temp_v0))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2_2)[0x33] = (s8) (((((u16) (*((u16 *) temp_v0))) >> 5) & 0x1F) + 0x41);
        temp_s0 = temp_s2_2;
        temp_t1 = (((u8 *) temp_v0)[1] & 0x1F) + 0x41;
        ((s8 *) var_a2_2)[0x38] = 1;
        ((s8 *) var_a2_2)[0x34] = (s8) temp_t1;
        if (temp_s2_2 & 1)
        {
          temp_s0 = -temp_s2_2;
        }
        temp_a1 = *sp14; temp_a1 -= temp_s0; temp_a1 = (s32)((u32)temp_a1 << 16); temp_a1 >>=16;
        *((s32 *) (((s8 *) var_a2_2) + 0x2C)) = (s32) temp_a1;
        ((s8 *) var_a2_2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) temp_v0) + 2)))) >> 0xC) + ((((u16) (*((u16 *) temp_v0))) >> 0xF) * 0x10));
        new_var = *((s32 *)((s8*)temp_fp + 0x22C)); new_var = (u32)new_var * (u32)D_8009D540; ((s8*)var_a2_2)[0x36] = (s8)(((u32)new_var * 0xE10U) / (u32)(temp_a1 * 0x3E8));
      }
} var_s4 += 1;
  }
  if (((u32) ((hv = temp_s2_2 = var_s4) & 0xFF)) < 3U) goto decode_next;
}

