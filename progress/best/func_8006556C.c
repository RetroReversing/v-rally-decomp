#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
typedef struct Blob
{
  s32 words[177];
} Blob;
extern u8 *D_800A1468;
extern u8 *D_800C3508;
extern u8 *D_800C35A0;
extern u8 D_800A161C[];
extern u8 D_800A1620;
extern s32 D_800AFA58;
extern Blob *D_800D0634[];
extern void func_8005BC60(void);
extern void func_8005BB5C(void);
extern void func_80065860(void);
extern void func_80065C04(void);
extern void func_80062304(void *, s16);
extern void func_8005937C(s32, u16);
extern void func_8008A0D8(void *, u16, s32);
extern void func_8008A1CC(void *, s32, s32, void *);
extern u8 *func_800592AC(s32);
extern void func_80061740(Blob);
void func_8006556C(void)
{
  Blob blob;
  s32 i;
  s32 a;
  s32 b;
  unsigned int new_var2;
  s32 new_var;
  s32 j;
  s32 callbackIndex;
  s32 mask;
  s32 value;
  s16 selection;
  u8 *p;
  u8 *q;
  func_8005BC60();
  func_8005BB5C();
  p = D_800C35A0;
  q = D_800A1468;
  U(p, 0x20) = 0;
  q[0x23c] = D_800A1620;
  selection = H(D_800C3508, 2);
  if (selection == 2)
  {
    A(D_800C3508, 0x10)[0x36] = D_800C35A0[0x21] + 9;
  }
  else
  {
    p = A(D_800C3508, 0x10);
    do
    {
      p[(selection * 20) + 0xe] = D_800C35A0[0x21] + 4;
      func_80062304(p, selection);
    }
    while (0);
  }
  i = 0;
  a = 4;
  b = 9;
  D_800AFA58 = U(D_800C35A0, 0x20);
  do
  {
    j = a;
    new_var2 = 80;
    if (H(D_800C3508, 2) == 2)
    {
      value = U(D_800D0634[D_800A161C[(u32) a]], 0x14);
 do { j = b; } while (0);
    }
    else
      if (D_800C3508)
    {
      value = U(D_800D0634[D_800A161C[(u16) a]], 0x14);
    }
    else
    {
      value = U(D_800D0634[D_800A161C[(u16) a]], 0x14);
    }
    func_8005937C(j, value);
    if (i != 0)
    {
      mask = 0x1000 << (i - 1);
      if ((U(D_800C35A0, 0x2a) & mask) != mask)
      {
        func_8008A0D8(D_800C3508, (u16) b, 0);
        func_8008A0D8(D_800C3508, (u16) a, 0);
        p = func_800592AC(i);
        j = 3;
        new_var = j;
        p[0xf] = new_var2;
        if (i != 3)
        {
          if (D_800C3508 || a)
          {
            p[0x10] = new_var2;
            p[0x11] = new_var2;
          }
          else
          {
            p[0xf] = new_var2;
            p[0x10] = new_var2;
            p[0x11] = new_var2;
          }
        }
        else
        {
          q = p + 6;
          do
          {
            q[0x41] = 0;
            j--;
            q -= 2;
          }
          while ((--new_var) >= 0);
        }
      }
    }
    callbackIndex = (u16) a;
    if (H(D_800C3508, 2) == 2)
    {
      callbackIndex = (u16) b;
    }
    func_8008A1CC(D_800C3508, callbackIndex, 16, func_80065C04);
    a++;
    i++;
    b++;
  }
  while (i < 4);
  if (H(D_800C3508, 2) == 1)
  {
    *((void **) (D_800A1468 + 0x28c)) = func_80065860;
  }
  blob = *D_800D0634[D_800A1468[0x23c]];
  func_80061740(blob);
}
