s32 func_8006B924(void *, s32);
extern s32 D_800ADF30;
extern s32 D_800C3650;
extern s32 D_800C7206;
void func_8006CE1C(s32 dummy, s32 arg1)
{
int __repair_literal;

  u16 *s7 = (0, (u16 *) (&D_800C7206));
  s32 *s6 = (s32 *)&D_800ADF30;
  s32 *fp = (s32 *) (&D_800ADF30);
  u8 s0 = 0;
  u8 s2;
  u8 s3 = 0;
  s32 s1;
  s32 off;
  s32 idx;
  s32 diff;
  u8 code;
  do
  {
    s2 = 0;
    do
    {
      s0 = s2;
      s1 = 4;
      s1 = s0 << s1;
      arg1 = func_8006B924((void *) ((((s32) (&D_800C3650)) + s1) + (s3 << 6)), arg1);
      code = arg1;
      if (code == 5)
      {
        s7[(s3 * 3) + s0] = 65535;
      }
      else
      {
        diff = s6[s3];
        diff = diff - (*((s32 *) ((((s32) (&D_800C3650)) + s1) + (s3 << 6))));
__repair_literal = 0;

        if (diff >= __repair_literal)
        {
          if ((double) (diff >= 16384))
          {
            diff = 16382;
          }
          if ((s32 *) (&D_800ADF30))
          {
            diff &= -2;
          }
          else
          {
            diff &= -2;
          }
        }
        else
        {
          diff = -diff;
          if (diff >= 16384)
          {
            diff = 16382;
          }
          diff |= 1;
        }
        s7[(s3 * 3) + s2] = (unsigned long long) (diff | ((arg1 & 255) << 14));
      }
      s2++;
    }
    while (s2 < 3);
    s3 = (u8) (s3 + 1);
  }
  while (s3 < 4);
}
