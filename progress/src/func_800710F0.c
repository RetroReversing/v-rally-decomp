typedef struct Obj71
{
  u8 p[6];
  s16 x;
  s16 y;
  u8 pA;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
} Obj71;
typedef struct Rec71
{
  s32 time;
  u8 pad[2];
  char name[10];
} Rec71;
typedef struct Cfg71
{
  u8 pad[0x20];
  u16 idx;
} Cfg71;
extern Cfg71 *D_800C35A0;
extern s32 D_800C8328;
extern u16 D_800A171C[];
extern Rec71 D_800C3750[][4];
extern Rec71 D_800C3A90[];
extern Rec71 D_800C3AD0[];
extern char D_800A5CFC[];
extern s16 D_800A5D04;
extern s8 D_800A5D06;
extern char D_800A5D08[];
extern Obj71 *func_800592D0(s32);
extern char *func_80057918(s32, u16);
extern void func_80052E94(s32, char *);
extern void func_80059618(Obj71 *, u8, u8, u8, s32);
extern void func_800596F4(Obj71 *, s16, s16, char *);
extern void func_80097E30(char *, s32, s32);
extern void func_800980D0(char *, char *);
extern void func_80099DF8(char *, char *, ...);
void func_800710F0(void)
{
  char buf[16];
  s32 best = 0;
  s32 t;
  u8 j;
  char *p;
  Obj71 *obj;
  Obj71 *obj2;
  char *s;
  obj = func_800592D0(0x13);
  j = 0;
  s = func_80057918(D_800C8328, D_800A171C[D_800C35A0->idx]);
  func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
  func_800596F4(obj, obj->x, obj->y, s);
  func_80097E30(buf, 0, 15);
  obj = func_800592D0(0x10);
  do
  {
    func_80099DF8(buf, D_800A5CFC, j + 1, D_800C3750[D_800C35A0->idx][j].name);
    func_800596F4(obj, obj->x, obj->y + (j * 22), buf);
    j++;
  }
  while (j < 3);
  obj = func_800592D0(0x12);
  obj2 = func_800592D0(0x11);
  j = 0;
  p = buf;
  do
  {
    t = D_800C3750[D_800C35A0->idx][j].time;
    func_80097E30(buf, 0, 15);
    func_80052E94(t, buf);
    func_800596F4(obj, obj->x, obj->y + (j * 22), buf);
    if (j == 0)
    {
      best = t;
    }
    else
    {
      func_80097E30(buf, 0, 15);
      {
        s32 h = D_800A5D04;
        s32 c = D_800A5D06;
        *((s16 *) buf) = h;
        *(&buf[2]) = c;
 do { } while (0);
      }
      func_80052E94(t - best, &buf[2]);
      func_800980D0(p, D_800A5D08);
      func_800596F4(obj2, obj2->x, obj2->y + ((j - 1) * 22), p);
    }
    j++;
  }
  while (j < 3);
  if (obj->b)
  {
    func_80097E30(buf, 0, 15);
    obj = func_800592D0(0x18);
    j = 0;
  }
  else
  {
    func_80097E30(buf, 0, 15);
    obj = func_800592D0(0x18);
    j = 0;
  }
  do
  {
    if (D_800C35A0->idx < 8)
    {
      func_80099DF8(buf, D_800A5CFC, j + 1, D_800C3A90[j].name);
    }
    else
    {
      func_80099DF8(buf, D_800A5CFC, j + 1, D_800C3A90[j + 4].name);
    }
    func_800596F4(obj, obj->x, obj->y + (j * 22), buf);
    j++;
  }
  while (j < 3);
  obj = func_800592D0(0x1A);
  obj2 = func_800592D0(0x19);
  j = 0;
  p = buf;
  do
  {
    func_80097E30(buf, 0, 15);
    if (D_800C35A0->idx < 8)
    {
      t = D_800C3A90[j].time;
    }
    else
    {
      t = D_800C3AD0[j].time;
    }
    func_80052E94(t, buf);
    func_800596F4(obj, obj->x, obj->y + (j * 22), buf);
    if (j == 0)
    {
      best = t;
    }
    else
    {
      func_80097E30(buf, 0, 15);
      {
        s32 h = D_800A5D04;
        s32 c = D_800A5D06;
        *((s16 *) buf) = h;
        *(&buf[2]) = c;
 do { } while (0);
      }
      func_80052E94(t - best, &buf[2]);
      func_800980D0(p, D_800A5D08);
      func_800596F4(obj2, obj2->x, obj2->y + ((j - 1) * 22), p);
    }
    j++;
  }
  while (j < 3);
}
