extern u8 *D_800D0634;
u8 func_8006B9E0(u8,u8);
void func_8006BF30(s32,s32,s32,s32);
extern s32 D_8009D540;
extern f64 D_800A5878;
extern f64 D_800A5880;
extern f64 D_800A5888;
extern char D_800C02AE[];
extern char D_800C70D4[];
extern char D_800C7125[];
void func_8006C024(s32 arg0, s32 arg1)
{
  s16 packet_index0;

  u16 *sp14;
  f64 temp_fs0;
  f64 temp_fs1;
  f64 temp_fv1;
  s16 temp_s2_2;
  s32 temp_s2;
  s16 temp_a1;
  s16 var_s0;
  s32 record_offset;
  u8 temp_a0;
  s32 temp_s0;
  s16 temp_s0_2;
  s32 __repair_phase_temp_s0_2;
  s32 temp_s5;
  u32 temp_s6;
  u8 *frame_record;
  s32 var_a0;
  s32 var_s3;
  u32 temp_t0;
  u8 packed_byte;
  u8 temp_t1;
  int new_var4;
  u8 temp_t1_2;
  

  s8 new_var2;
  int new_var3;
  void *var_a2; void *var_s1;
  
  char *frame_table;
  char *table_base;
  var_a0 = arg0 & 0xFF;
  var_s0 = arg1 & 0xFF;
  temp_fs0 = D_800A5878;
  temp_s6 = (u32)(D_800D0634 + (var_a0 * 0x2C4));
  temp_s5 = func_8006B9E0(var_a0, var_s0) & 0xFF;
temp_fs1 = (f64)temp_s5 * D_800A5880;
  temp_s0 = var_s0;
  var_s3 = 0;
  frame_table = D_800C02AE + 0x5A8A;
  sp14 = (u16 *)(frame_table + temp_s5 * 2);
  frame_record = (u8 *)(((temp_s0 * 4) + temp_s6));
    table_base = D_800C7125;
  decode_next:
  {
    new_var4 = var_s3 & 0xFF;
    temp_fv1 = temp_fs1 + (((f64) new_var4) * D_800A5888);
    if (!(temp_fs0 <= temp_fv1))
    {
      var_a0 = (s32) temp_fv1;
      new_var3 = temp_s5 * 8;
    }
    else
    {
      
        
          
   var_a0 = (s32) (temp_fv1 - temp_fs0); var_a0 |= 0x80000000;
      do { new_var3 = temp_s5 * 8; } while (0);  
          
        
      
    }
    temp_a0 = 0xFF;
    new_var3 = new_var3 + temp_s5;
    temp_a0 = var_a0 & temp_a0;
    temp_s0_2 = var_s3 & 0xFF;
    if ((((((temp_s0_2 * 3) + new_var3) * 4) - (temp_a0 * 8)) & 0xFF) == 4)
    {
void *temp_v0;

      temp_v0 = (char*)table_base + temp_a0;
      packed_byte = *((u8 *) (((char *) temp_v0) + 0));
      temp_t1 = *((u8 *) (((char *) temp_v0) + 1));
      
      temp_t0 = (temp_a0 = (u8)(packed_byte >> 4));
      temp_t0 = temp_t0 & 0xC;
      if (((temp_t1 < 0xFFU) | (((u32) (temp_a0 & 0xFF)) < 0xFU)) != 0)
      {
        temp_t0 >>= 2;
        packet_index0 = temp_s0_2;
        var_s1 = ((temp_a0 & 0xF3) * 0xE) + D_800C70D4;
        temp_s2 = (temp_t1 * 4) + temp_t0;
        func_8006BF30(packet_index0, 0, arg0 & 0xFF, temp_s0);
do {         var_a2 = (void *)(temp_s6 + ((packet_index0 * 0x10) + (temp_s0 << 6)));         *((s8 *) (((char *) var_a2) + 0x32)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xA) & 0x1F) + 0x41);         do { *((s8 *) (((char *) var_a2) + 0x33)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) - (-0))))) >> 5) & 0x1F) + 0x41); } while (0);         temp_s0_2 = temp_s2;         *((s8 *) (((char *) var_a2) + 0x34)) = (new_var2 = (s8) (((*((u8 *) (((char *) var_s1) + 1))) & 0x1F) + 0x41));         *((s8 *) (((char *) var_a2) + 0x38)) = 1;
        if (temp_s2 & 1)
        {
          new_var4 = -(s16)temp_s2;
          temp_s0_2 = new_var4;
        }
 } while (0);
        goto block_13;
      }
    }
    else
    {
void *temp_v0_2;

      temp_v0_2 = (void*)((u32)temp_a0+(u32)table_base);
      temp_t1_2 = *((u8 *) (((char *) temp_v0_2) + 0));
      temp_t0 = (*((u8 *) (((char *) temp_v0_2) + 1))) & 0xF;
      temp_a0 = temp_t0;
      new_var3 = (temp_t1_2 < 0xFFU) | (temp_a0 < 0xFU);
      if (new_var3 != 0)
      {
        var_s1 = ((temp_a0 >> 2) * 0xE) + D_800C70D4;
        temp_s2_2 = temp_t1_2 | ((temp_t0 & 3) << 8);
        packet_index0 = temp_s0_2;
        temp_s0_2 = temp_s2_2 & 0x3FF;
        func_8006BF30(packet_index0, 0, arg0 & 0xFF, temp_s0);
        
        var_a2 = (void *)(temp_s6 + ((packet_index0 * 0x10) + (temp_s0 << 6)));
        *((s8 *) (((char *) var_a2) + 0x32)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xA) & 0x1F) + 0x41);
        *((s8 *) (((char *) var_a2) + 0x33)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 5) & 0x1F) + 0x41);

        temp_t1 = ((*((u8 *) (((char *) var_s1) + 1))) & 0x1F) + 0x41;
        *((s8 *) (((char *) var_a2) + 0x38)) = 1;
        *((s8 *) (((char *) var_a2) + 0x34)) = (s8) temp_t1;
        if (temp_s2_2 & 1)
        {
          temp_s0_2 = -temp_s2_2;
        }
        ;
        block_13:
        arg1 = *sp14; arg1 = (s32)((u32)arg1 << 16); arg1 -= (u32)temp_s0_2 << 16; arg1 >>= 16;

        *((s32 *) (((char *) var_a2) + 0x2C)) = (s32) arg1;
        *((s8 *) (((char *) var_a2) + 0x30)) = (s8) ((((u16) (*((u16 *) (((char *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xF) * 0x10));
        var_a0 = *((u32 *)((char *)frame_record + 0x22C)); var_a0 = (s32)((u32)var_a0 * (u32)D_8009D540); *((s8 *)((char *)var_a2 + 0x36)) = (s8)(((u32)var_a0 * 0xE10) / (u32)(arg1 * 0x3E8));
      }
    }
    
      

        
          do { var_s3 += 1; } while (0);
        
      
    
  }
  if (((u32) (var_s3 & 0xFF)) < 3U) goto decode_next;
}
