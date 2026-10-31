extern u8 D_800C78A8;
extern s32 D_800A2518;
extern s32 func_8008B624(void *);
extern s32 func_8008B5DC(s32, s32);
long long func_8008B3E4(s32 arg0)
{
  s32 *new_var;
  s32 *p = *((s32 **) (D_800C78A8 + arg0));
 do { } while (0);
  if (p && (p[2] < p[4]))
  {
    s32 x = p[3] + p[2];
    s32 y = x % p[4];
    new_var = (s32 *) ((D_800C78A8 + arg0) + 4);
    ((s32 *) p[5])[y] = *new_var;
    if (*(*((s32 **) p)))
    {
      s32 a = func_8008B624(p);
      func_8008B5DC((s32) (&D_800A2518), a);
      return 0;
    }
    p[2]++;
  }
}
