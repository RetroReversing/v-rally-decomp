extern s32 D_800A19B0;
extern s32 D_800B5B40;
extern s32 D_800C5BB0[];
extern s32 D_800C72D8[];
extern s32 D_800C8090;
extern s32 D_800C80A8;
s32 func_8007F12C(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, ...)
{
  volatile s32 pad[2];
  s32 sp10;
  s32 t2;
  s32 t3;
  s32 var_a0;
  s32 new_var;
  if (D_800A19B0 == 1)
  {
    ((s32 (*)(s32)) D_800C80A8)(D_800B5B40 - 4);
  }
  D_800A19B0 = 1;
  D_800B5B40 = 0;
  do
  {
    t3 = (t3 + 3) & (~3u);
    t3 = *((s32 *) t3);
    t3 = (t3 + 7) & (~3u);
    t2 = *((s32 *) t3);
  }
  while (0);
  if (arg0 & 0xffff0000)
  {
    sp10 = 1;
    var_a0 = arg0;
  }
  else
  {
    ;
    new_var = D_800C72D8[arg0];
    var_a0 = new_var;
  }
  if (new_var == 0)
  {
    ((s32 (*)(s32)) D_800C8090)(D_800B5B40 - 4);
    var_a0 = 0;
  }
  else
  {
    var_a0 -= 8;
  }
  if (var_a0)
  {
    s32 *q = (s32 *) D_800C5BB0[arg0];
 do { if (q) { s32 (*fn)(s32, s32, s32, s32) = *((void **) (q + 3)); *arg1 = fn(var_a0 + 8, arg2, t3, t2); } } while (0);
  }
  D_800A19B0 = 0;
  return 0;
}
