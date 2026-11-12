extern u8 *gSlotTableB;
u8 func_8006B9E0(u8,u8);
void record_put_glyphs(s32,s32,s32,s32);
extern s32 gRecordTimeScale;
extern f64 D_800A5878;
extern f64 D_800A5880;
extern f64 D_800A5888;
extern char stream_state[];
extern char gRecordGlyphs[];
extern char D_800C7125[];

/* Same packed-record decode as build_record_entry, for the alternate record
 * path: category selects the record block, row picks the slot. */
void build_record_entry_alt(s32 category, s32 row)
{
  s16 packet_index0;

  u16 *sp14;
  f64 temp_fs0;
  f64 temp_fs1;
  f64 temp_fv1;
  s32 temp_s2_2;
  s32 temp_s2;
  s32 temp_a1;
  s16 var_s0;
  s32 record_offset;
  u8 temp_a0;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 __repair_phase_temp_s0_2;
  s32 temp_s5;
  u8 *temp_s6;
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
  
  void *packet, *temp_v0_2;
  char *frame_table;
  char *table_base;
  var_a0 = category & 0xFF;
  var_s0 = row & 0xFF;
  temp_fs0 = D_800A5878;
  temp_s6 = gSlotTableB + (var_a0 * 0x2C4);
  temp_s5 = func_8006B9E0(var_a0, var_s0) & 0xFF;
temp_fs1 = (f64)temp_s5 * D_800A5880;
  temp_s0 = var_s0;
  var_s3 = 0;
  frame_table = stream_state + 0x5A8A;
  sp14 = (u16 *)(frame_table + temp_s5 * 2);
#ifdef PORT
  frame_record = temp_s6 + (temp_s0 * 4);
#else
  frame_record = (u8 *)(((temp_s0 * 4) + (u32)temp_s6));
#endif
    table_base = D_800C7125;
  decode_next:
  {
    temp_fv1 = temp_fs1 + (((f64) (var_s3 & 0xFF)) * D_800A5888);
    if (!(temp_fs0 <= temp_fv1))
    {
      var_a0 = (s32) temp_fv1;
    }
    else
    {
      var_a0 = (s32)(temp_fv1 - temp_fs0);       var_a0 = (u32)var_a0 | 0x80000000U;
    }
    new_var3 = temp_s5 * 8;     new_var3 += temp_s5;
    temp_a0 = var_a0 & 0xFF;
    temp_s0_2 = var_s3 & 0xFF;
    if ((((((temp_s0_2 * 3) + new_var3) * 4) - (temp_a0 * 8)) & 0xFF) == 4)
    {
      packet = (void *) (table_base - (-temp_a0));
      temp_t1 = ((u8 *) packet)[1];
      temp_a0 = ((u8) ((u8 *) packet)[0]) >> 4;
      temp_t0 = temp_a0 & 0xC;
      if (((temp_t1 < 0xFFU) | (((u32) (temp_a0 & 0xFF)) < 0xFU)) != 0)
      {
        temp_t0 >>= 2;
        var_s1 = (void *) (gRecordGlyphs + ((temp_a0 & 0xF3) * 0xE));
        temp_s2 = (temp_t1 * 4) + temp_t0;
        record_put_glyphs(temp_s0_2, 0, category & 0xFF, temp_s0);
        var_a2 = (void *) (((s8 *) temp_s6) + ((temp_s0_2 * 0x10) + (temp_s0 << 6)));
        ((s8 *) var_a2)[0x32] = (s8) (((((u16) (*((u16 *) var_s1))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2)[0x33] = (s8) (((((u16) (*((u16 *) var_s1))) >> 5) & 0x1F) + 0x41);
        temp_s0_2 = temp_s2;
        temp_t1 = (((u8 *) var_s1)[1] & 0x1F) + 0x41;
        ((s8 *) var_a2)[0x38] = 1;
        ((s8 *) var_a2)[0x34] = (s8) temp_t1;
        if (temp_s2 & 1)
        {
          temp_s0_2 = -((s16) temp_s2);
        }
        temp_a1 = *sp14; temp_a1 -= temp_s0_2; temp_a1 = (s32)((u32)temp_a1 << 16); temp_a1 >>=16;
        *((s32 *) (((s8 *) var_a2) + 0x2C)) = (s32) temp_a1;
        ((s8 *) var_a2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) var_s1))) >> 0xF) * 0x10));
        var_a0 = *((s32 *)((s8*)frame_record + 0x22C)); var_a0 = (u32)var_a0 * (u32)gRecordTimeScale; ((s8*)var_a2)[0x36] = (s8)(((u32)var_a0 * 0xE10U) / (u32)(temp_a1 * 0x3E8));
      }
    }
    else
    {
#ifdef PORT
      temp_v0_2 = (void *) (table_base + temp_a0);
#else
      temp_v0_2 = (void *) ((u32)temp_a0 + (u32)table_base);
#endif
      temp_t1_2 = ((u8 *) temp_v0_2)[0];
      temp_t0 = ((u8 *) temp_v0_2)[1] & 0xF;
      new_var3 = (temp_t1_2 < 0xFFU) | ((temp_a0 = temp_t0) < 0xFU);
      if (new_var3 != 0)
      {
        var_s1 = (void *) (gRecordGlyphs + ((temp_a0 >> 2) * 0xE));
        temp_s2_2 = temp_t1_2 | ((temp_t0 & 3) << 8);
        record_put_glyphs(temp_s0_2, 0, category & 0xFF, temp_s0);
        var_a2 = (void *) (((s8 *) temp_s6) + ((temp_s0_2 * 0x10) + (temp_s0 << 6)));
        ((s8 *) var_a2)[0x32] = (s8) (((((u16) (*((u16 *) var_s1))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2)[0x33] = (s8) (((((u16) (*((u16 *) var_s1))) >> 5) & 0x1F) + 0x41);
        temp_s0_2 = temp_s2_2;
        temp_t1 = (((u8 *) var_s1)[1] & 0x1F) + 0x41;
        ((s8 *) var_a2)[0x38] = 1;
        ((s8 *) var_a2)[0x34] = (s8) temp_t1;
        if (temp_s2_2 & 1)
        {
          temp_s0_2 = -temp_s2_2;
        }
        temp_a1 = *sp14; temp_a1 -= temp_s0_2; temp_a1 = (s32)((u32)temp_a1 << 16); temp_a1 >>=16;
        *((s32 *) (((s8 *) var_a2) + 0x2C)) = (s32) temp_a1;
        ((s8 *) var_a2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) var_s1))) >> 0xF) * 0x10));
        var_a0 = *((s32 *)((s8*)frame_record + 0x22C)); var_a0 = (u32)var_a0 * (u32)gRecordTimeScale; ((s8*)var_a2)[0x36] = (s8)(((u32)var_a0 * 0xE10U) / (u32)(temp_a1 * 0x3E8));
      }
} do { var_s3 += 1; } while (0);
  }
  if (((u32) ((temp_s2 = temp_s2_2 = var_s3) & 0xFF)) < 3U) goto decode_next;
}
