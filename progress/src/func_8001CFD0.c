s32 text_load_and_parse();
s32 strCmp();
extern char D_800A47B4[];

/* Loads the text files named by a record's list: when the record holds more than four entries and
 * its name at +0x98 is not the empty string, calls text_load_and_parse once for each entry past the
 * fourth (entries are 0x4C bytes apart, starting at +0xE4). */
void func_8001CFD0(void *rec)
{
  char pad[8];
  s32 nameOff;
  s32 *entryOff;
  s32 *countPtr;
  s32 entryAddr;
  s32 count;
  s32 var_v0;
  s32 var_s0;
  s32 var_s3;
  s32 *var_a1;
  u32 done;
  var_v0 = *((s32 *) (((char *) rec) + 0x44));
  var_v0 = var_v0 < 4;
  if (var_v0 == 0)
  {
    var_a1 = &D_800A47B4;
    ;
    if (strCmp(rec + 0x98, &D_800A47B4) != 0)
    {
      countPtr = (s32 *) (((char *) rec) + 0x44);
      count = *countPtr;
      var_a1 = &D_800A47B4;
      var_s3 = count;
      var_v0 = count - 4;
      done = 0;
      if (var_v0 != 0)
      {
        var_v0 = count * 4;
        var_v0 = var_s3 * 5;
        var_v0 = count * 0x14;
        var_v0 = count * 0x13;
        var_s3 = count * 0x4C;
        do
        {
          nameOff = var_s3;
          var_s0 = 0xE4;
          do
          {
            ;
            var_a1 = rec + var_s0;
            text_load_and_parse(rec + nameOff, var_a1);
            var_v0 = *((s32 *) (((char *) rec) + 0x44));
            done += 1;
            var_v0 -= 4;
            var_v0 = (u32) var_v0;
            var_v0 = done < var_v0;
            var_s0 += 0x4C;
          }
          while (var_v0 != 0);
        }
        while (0);
      }
    }
  }
}
