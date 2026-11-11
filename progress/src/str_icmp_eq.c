s32 func_80082314();

/* Case-insensitive, slash-normalised string equality: returns 1 when the two
 * strings match up to the end of arg0 and arg1 is also terminated there. */
u8 str_icmp_eq(u8 *arg0, u8 *arg1)
{
  u8 *var_s2;
  u8 *var_s1;
  u8 var_s0;
  u8 var_a0;

  var_s2 = arg1;
  var_s1 = arg0;
  var_a0 = *var_s1;
  if (var_a0 != 0) {
    do {
      var_s0 = func_80082314(var_a0);
      if (var_s0 != (u8) func_80082314(*var_s2)) {
        return 0;
      }
      var_s1++;
      var_s2++;
      var_a0 = *var_s1;
    } while (var_a0 != 0);
  }
  return *var_s2 == 0;
}
