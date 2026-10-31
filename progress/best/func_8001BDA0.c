extern char D_800AE850[];
extern void *D_800C8054;
s32 func_8001BCE0(s32);
void func_8001BD44(void);
void func_8001BDA0(void)
{
  s32 *p = (s32 *) (D_800AE850 + 0x87D8);
  s32 v;
  unsigned short new_var;
  s32 a;
  s32 b;
  *p = func_8001BCE0(0x12C);
  v = func_8001BCE0(0x12C);
  a = p[0];
  b = *(&D_800C8054);
  p[1] = v;
  p[4] = 0;
  new_var = 5;
  p[3] = v;
  p[5] = 0x12C;
  D_800C8054 = func_8001BD44;
  p[new_var] = 0x12C;
  p[2] = a;
 do { } while (0);
  *((s32 *) (D_800AE850 + 0x6D9C)) = b;
}
