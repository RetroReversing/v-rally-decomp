extern unsigned char D_800B0D94;
extern unsigned char D_800B0D95;
extern unsigned char D_800B0D96;
extern unsigned char D_800B0D97;
extern unsigned char D_800B0D98;
s32 stream_refresh_car_flags();
extern char *gRecords;

/* Sets the achievement-style bits in the records header flags byte (0x2F):
 * bit 0x01 when any of the first four entries is at 100 or above, and bits
 * 0x08, 0x04 and 0x02 from the summed or single counters at 100 or above. */
void func_80054740(void)
{
  s32 idx;
  char *records;
  char *entry;

  idx = 0;
  do {
    records = gRecords;
    entry = records + (idx & 0xFF) * 0x28;
    if (*(u16 *)(entry + 0x52) >= 0x65) {
      *(u8 *)(records + 0x2F) |= 1;
    }
    idx++;
  } while ((u8)idx < 4);
  if (D_800B0D94 + D_800B0D95 >= 0x64) {
    *(u8 *)(gRecords + 0x2F) |= 8;
  }
  if (D_800B0D96 + D_800B0D97 >= 0x64) {
    *(u8 *)(gRecords + 0x2F) |= 4;
  }
  if (D_800B0D98 >= 0x64) {
    *(u8 *)(gRecords + 0x2F) |= 2;
  }
  stream_refresh_car_flags(records, idx);
}
