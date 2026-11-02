void *func_800056FC(s32);
s32 func_8004C98C(s32, void *, void *, u8, u8, u8, u8, u8, u8);
void func_8004CEB4(s32 a0, void *a1, void *a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7, u8 a8)
{
  void *v;
  s32 *p;
  v = func_800056FC(a0);
  p = *((s32 **) (((char *) v) + 0x14));
  *((s32 **) (((char *) v) + 0x14)) = p + 2;
  p[0] = 0xFB000000;
  p[1] = -1;
  func_8004C98C(a0, a1, a2, a3, a4, a5, a6, a7, a8);
}
