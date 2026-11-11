s32 str_len();
s32 copyStringAligned();
s32 str_ncat();
extern u8 gRacerLogCount;
extern char D_800A5220[];
extern char gOrderState[];

/* Appends one racer's record to the race log and bumps the count. Each 28-byte
 * entry (based at +0x1300) holds three status bytes, two floats and a name built
 * from the car's name buffer plus the suffix string at D_800A5220. */
void racer_log_add(void *car)
{
  s32 *field;
  char *name;
  s32 i;
  s32 idx;

  i = 1;
  while (((u32)(i & 0xFF)) <= (6U - 1))
  {
    i += 1;
  }
  i += 1;
  idx = gRacerLogCount * 0x1C;
  field = (s32 *)(((char *)car) + 0x128);
  if (gRacerLogCount)
  {
  }
  *((s8 *)((gOrderState + 0x1300) + idx)) = *((s32 *)(((char *)car) + 0x90));
  idx = gRacerLogCount * 0x1C;
  *((s8 *)((gOrderState + 0x1301) + idx)) = *((s32 *)(((char *)car) + 0xDC));
  name = ((char *)car) + 0x1C8;
  idx = gRacerLogCount * 0x1C;
  i += 1;
  *((s8 *)((gOrderState + 0x1302) + idx)) = *field;
  idx = gRacerLogCount * 0x1C;
  *((f32 *)((gOrderState + 0x1304) + idx)) = (f32)(*((s32 *)(((char *)car) + 0x174)));
  *((f32 *)((gOrderState + 0x1308) + idx)) = (f32)(*((s32 *)(((char *)car) + 0x1C0)));
  str_ncat(name, D_800A5220, str_len(name, car));
  copyStringAligned((gRacerLogCount * 0x1C) + (gOrderState + 0x130C), name);
  gRacerLogCount += 1;
}
