extern u8 *gRecords;
extern char gRecordTier[];
extern char stream_state[];

/* Field access helpers for a packed 14-byte record and for a 0x28-byte gRecords entry. */
#define REC_U16(r, off) (*(u16 *)((char *)(r) + (off)))
#define REC_U8(r, off) (*(u8 *)((char *)(r) + (off)))
#define ENT_S8(e, off) (*(s8 *)((char *)(e) + (off)))
#define ENT_S16(e, off) (*(s16 *)((char *)(e) + (off)))
#define ENT_S32(e, off) (*(s32 *)((char *)(e) + (off)))

/* Unpacks packed record idx from the table at stream_state + 0x6E26 into gRecords[idx]:
 * a 32-bit word and several bit fields are split out, and three colour digits are
 * stored as 0x41-based letters. */
void unpackRecord(u8 idx)
{
  s32 temp_a0;
  s32 temp_a3;
  s32 temp_v1;
  u16 temp_a0_3;
  u8 temp_v0;
  u32 temp_a2_2;
  void *temp_a0_2;
  void *temp_a1;
  void *temp_a2;
  void *temp_t0;
  void *dest;
  u16 value;
  temp_a0 = idx;
  temp_t0 = (temp_a0 * 0xE) + (stream_state + 0x6E26);
  temp_a2 = gRecords;
  temp_a3 = temp_a0 * 0x28;
  temp_a2 += temp_a3;
  ENT_S16(temp_a2, 0x52) = (u16) (REC_U16(temp_t0, 8));
  ENT_S32(temp_a2, 0x68) = (s32) ((REC_U16(temp_t0, 0xA)) + ((REC_U16(temp_t0, 0xC)) << 0x10));
  temp_v0 = ((u16) (REC_U16(temp_t0, 4))) >> 8;
  temp_v1 = temp_v0 & 0x7F;
  ENT_S8(temp_a2, 0x48) = (s8) (temp_v1 & 0x1F);
  *(gRecordTier + temp_a0) = (s8) (((s32) (temp_v1 - (temp_v0 & 0x1F))) >> 5);
  dest = gRecords;
  value = REC_U16(temp_t0, 4);
  dest += temp_a3;
  ENT_S8(dest, 0x4D) = value >> 15;
  ENT_S8(gRecords + temp_a3, 0x44) = (s8) (((unsigned long long) ((((u16) (REC_U16(temp_t0, 0))) >> 0xA) & 0x1F)) + 0x41);
  ENT_S8(gRecords + temp_a3, 0x45) = (s8) (((((u16) (REC_U16(temp_t0, 0))) >> 5) & 0x1F) + 0x41);
  ENT_S8(gRecords + temp_a3, 0x46) = (s8) (((REC_U8(temp_t0, 1)) & 0x1F) + 0x41);
  ENT_S8(gRecords + temp_a3, 0x47) = 0;
  value = REC_U16(temp_t0, 2);
  temp_a0_2 = gRecords;
  {
    u16 hi = REC_U16(temp_t0, 0);
    u16 v12 = value >> 0xC;
    temp_a0_2 += temp_a3;
    ENT_S16(temp_a0_2, 0x4E) = (s16) (v12 + (hi >> 0xF) * 0x10);
  }
  temp_a2_2 = REC_U8(temp_t0, 5);
  value = REC_U16(temp_t0, 2);
  ENT_S8(temp_a0_2, 0x54) = (s8) (temp_a2_2 & 3);
  ENT_S8(gRecords + temp_a3, 0x55) = (s8) (((u32) (temp_a2_2 & 0xC)) >> 2);
  ENT_S8(gRecords + temp_a3, 0x56) = (s8) (((u32) (temp_a2_2 & 0x30)) >> 4);
  ENT_S8(gRecords + temp_a3, 0x57) = (s8) (temp_a2_2 >> 6);
  temp_a0_3 = REC_U16(temp_t0, 2);
  temp_a1 = gRecords + temp_a3;
  ENT_S16(temp_a1, 0x60) = (s16) (((temp_a0_3 & 7) * 0xA) - 0x14);
  ENT_S16(temp_a1, 0x62) = (s16) (((((u32) (temp_a0_3 & 0x38)) >> 3) * 0xA) - 0x14);
  ENT_S16(temp_a1, 0x64) = (s16) (((((u32) (temp_a0_3 & 0x1C0)) >> 6) * 0xA) - 0x14);
  ENT_S16(temp_a1, 0x66) = (s16) (((((u32) (temp_a0_3 & 0xE00)) >> 9) * 0xA) - 0x14);
  temp_a2_2 = REC_U8(temp_t0, 6);
  ENT_S8(temp_a1, 0x58) = (s8) (temp_a2_2 & 3);
  ENT_S8(gRecords + temp_a3, 0x59) = (s8) (((u32) (temp_a2_2 & 0xC)) >> 2);
  ENT_S8(gRecords + temp_a3, 0x5A) = (s8) (((u32) (temp_a2_2 & 0x30)) >> 4);
  ENT_S8(gRecords + temp_a3, 0x5B) = temp_a2_2 >> 6;
  temp_a2_2 = REC_U8(temp_t0, 7);
  ENT_S8(gRecords + temp_a3, 0x5C) = (s8) (temp_a2_2 & 3);
  ENT_S8(gRecords + temp_a3, 0x5D) = (s8) (((u32) (temp_a2_2 & 0xC)) >> 2);
  ENT_S8(gRecords + temp_a3, 0x5E) = (s8) (((u32) (temp_a2_2 & 0x30)) >> 4);
  ENT_S8(gRecords + temp_a3, 0x5F) = (s8) (temp_a2_2 >> 6);
}
