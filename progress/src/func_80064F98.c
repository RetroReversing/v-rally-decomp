typedef struct 
{
  s32 time;
  s16 pad;
  char name[10];
} Rec64F98;
typedef struct 
{
  u8 pad[0x2C];
  Rec64F98 rec[1][4];
} Tbl64F98;
typedef struct 
{
  u8 pad[0x20];
  u16 x20;
  u16 x22;
} Mgr64F98;
typedef struct 
{
  u8 pad[6];
  s16 x;
  s16 y;
  u8 pad2;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
} Win64F98;
void func_80052E94(u16, char *);
char *func_80057918(s32, s32);
Win64F98 *func_800592D0(s32);
void func_80059618(Win64F98 *, u8, u8, u8, u8);
void func_800596F4(Win64F98 *, s16, s16, char *);
void func_8005A6BC(s32);
void func_8005A6E0(s32);
void memset(char *, s32, s32);
void func_800980D0(char *, char *);
void func_80099DF8(char *, char *, s32, char *);
extern u8 *D_800A1468;
extern char D_800A56C4[];
extern s16 D_800A56CC;
extern s8 D_800A56CE;
extern char D_800A56D0[];
extern Mgr64F98 *D_800C35A0;
extern Rec64F98 D_800C3650[][4];
extern s32 D_800C8328;
extern Tbl64F98 *D_800D0634[];
void func_80064F98(void)
{
  char buf[16];
  char *text;
  Win64F98 *w;
  Win64F98 *w2;
  u8 i;
  s32 t;
  s32 first;
  s32 a;
  Tbl64F98 **tbl;
  memset(buf, 0, 15);
  first = 0;
  if (D_800A1468[0x245] == 0)
  {
    w = func_800592D0(0x10);
    for (i = 0; i < 3; i++)
    {
      char *nm = D_800C3650[D_800C35A0->x20][i].name;
      func_80099DF8(buf, D_800A56C4, i + 1, nm);
      func_800596F4(w, w->x, w->y + (i * 22), buf);
    }

    w = func_800592D0(0x12);
    w2 = func_800592D0(0x11);
    for (i = 0, text = buf; i < 3; i++)
    {
      t = D_800C3650[D_800C35A0->x20][i].time;
      memset(buf, 0, 15);
      func_80052E94(t, buf);
      func_800596F4(w, w->x, w->y + (i * 22), buf);
      if (i == 0)
      {
        first = t;
      }
      else
      {
        s32 c;
        s32 h;
        memset(buf, 0, 15);
        h = D_800A56CC;
        c = D_800A56CE;
 do { *((s16 *) buf) = h; buf[2] = c; } while (0);
        func_80052E94(t - first, buf + 2);
        func_800980D0(text, D_800A56D0);
        func_800596F4(w2, w2->x, w2->y + ((i - 1) * 22), text);
      }
    }

    w = func_800592D0(0x13);
    func_80059618(w, w->b, w->c, w->d, w->e);
    func_800596F4(w, w->x, w->y, func_80057918(D_800C8328, D_800C35A0->x20 + 0x1CD));
    func_8005A6E0(0x15);
    a = 0x14;
  }
  else
  {
    w = func_800592D0(0x10);
    for (i = 0; i < 3; i++)
    {
      func_80099DF8(buf, D_800A56C4, i + 1, D_800D0634[D_800A1468[0x23C]]->rec[D_800C35A0->x22][i].name);
      func_800596F4(w, w->x, w->y + (i * 22), buf);
    }

    w = func_800592D0(0x12);
    w2 = func_800592D0(0x11);
    for (i = 0, tbl = D_800D0634, text = buf; i < 3; i++)
    {
      t = tbl[D_800A1468[0x23C]]->rec[D_800C35A0->x22][i].time;
      func_80052E94(t, buf);
      func_800596F4(w, w->x, w->y + (i * 22), buf);
      if (i == 0)
      {
        first = t;
      }
      else
      {
        s32 h;
        s32 c;
        memset(buf, 0, 15);
        h = D_800A56CC;
        c = D_800A56CE;
 do { *((s16 *) buf) = h; buf[2] = c; } while (0);
        func_80052E94(t - first, buf + 2);
        func_800980D0(text, D_800A56D0);
        func_800596F4(w2, w2->x, w2->y + ((i - 1) * 22), text);
      }
    }

    w = func_800592D0(0x13);
    func_80059618(w, w->b, w->c, w->d, w->e);
    func_800596F4(w, w->x, w->y, func_80057918(D_800C8328, D_800C35A0->x22 + 0x21A));
    func_8005A6E0(0x14);
    a = 0x15;
  }
  func_8005A6BC(a);
}
