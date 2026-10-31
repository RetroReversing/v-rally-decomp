void *func_800056FC(void);
s32 func_8004C98C(s32, void *, void *, s32, s32, s32, s32, s32, s32);
void func_8004CEB4(s32 a0, void *a1, void *a2, s32 a3, u8 a4, u8 a5, u8 a6, u8 a7, u8 a8)
{
  s32 n7 = a7;
  unsigned char new_var;
  void *v;
  void *p;
  new_var = a3 & 255;
  v = func_800056FC();
  p = *((void **) (((char *) v) + 0x14));
  *((void **) (((char *) v) + 0x14)) = ((char *) p) + 8;
  *((s32 *) p) = 0xFB000000;
  *((s32 *) (((char *) p) + 4)) = -1;
  func_8004C98C(a0, a1, a2, new_var, a4, a5, a6, n7, a8);
}
