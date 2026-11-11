extern int D_800B0BCC;
s32 order_table_swap();
s32 strncmp();
extern char D_800A5010[];
extern char D_800A5018[];
extern char gOrderState[];

/* For each of the `count` entries (0x14 bytes apart, from D_800B0BCC) whose 4-byte name matches neither
 * tag D_800A5010 nor D_800A5018, calls order_table_swap with the entry index and the running count of such entries. */
void func_800522B0(s32 count)
{
  char pad[8];
  s32 temp_a1;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  var_s2 = 0;
  var_s0 = 0;
  if (count > 0)
  {
    var_s1 = 0;
    do
    {
      if ((strncmp(D_800B0BCC + var_s1, &D_800A5010, 4) == 0) || (strncmp(D_800B0BCC + var_s1, &D_800A5018, 4) == 0))
      {
        temp_a1 = var_s2 & 0xFFFF;
        var_s2 += 1;
 do { order_table_swap(var_s0 & 0xFFFF, temp_a1); } while (0);
      }
      var_s0 += 1;
      var_s1 += 0x14;
    }
    while (var_s0 < count);
  }
}
