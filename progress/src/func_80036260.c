u64 osGetTime(void);
s32 rand_next15(void);
s32 rand_seed(s32);
extern u8 stream_state[];

/* Fills a table of random placement records, one 20-byte record per entry, with its
 * count taken from the table header at stream_state. Each record gets one of three size
 * classes (the bounds bytes at +1..+6), three random s16 positions (at +0, +2, +4) and a
 * random byte at +12. The random generator is seeded from the current time first. */
void func_80036260(s16 *out)
{
  s32 temp_ret_2;
  s32 temp_ret_3;
  s32 temp_ret_4;
  s32 temp_s3;
  s32 temp_v1;
  s32 size_a = 0;
  s32 size_b = 0;
  s32 count;
  s32 temp_a1;
  s32 last;
  s8 *var_s0;
  s8 lo_a;
  count = *((s32 *) ((*((void **) (stream_state + 0x7E6E))) + 8));
  rand_seed((s32) osGetTime());
  if (!(count--))
  {
    return;
  }
  ;
  do
  {
    ;
    switch (rand_next15() % 3)
    {
      case 0:
        size_a = 0x50;
        size_b = 0x8c;
        break;

      case 1:
        size_a = 0x28;
        size_b = 0x64;
        break;

      case 2:
        size_a = 0x80;
        size_b = 0xb4;
        break;

      case 3:
        size_a = 0x64;
        size_b = 0x82;
        break;

      default:
        break;

    }

    lo_a = size_a - 5;
    (((s8 *) out) + 12)[4] = lo_a;
    (((s8 *) out) + 12)[5] = lo_a;
    (((s8 *) out) + 12)[6] = size_a + 5;
    (((s8 *) out) + 12)[1] = size_b - 5;
    (((s8 *) out) + 12)[2] = size_b - 5;
    (((s8 *) out) + 12)[3] = size_b + 10;
    temp_ret_2 = rand_next15();
    *out = temp_ret_2 % 8191;
    temp_ret_3 = rand_next15();
    *((s16 *) ((((s8 *) out) + 12) - 10)) = temp_ret_3 % 2047;
    temp_ret_4 = rand_next15();
    *((s16 *) ((((s8 *) out) + 12) - 8)) = temp_ret_4 % 8191;
    last = rand_next15();
    temp_a1 = count--;
    (((s8 *) out) + 12)[0] = (last % 50) + 20;
    var_s0 += 20;
    out += 10;
  }
  while (temp_a1);
}
