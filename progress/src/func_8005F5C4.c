/* Record tables for the three classes (stride 40 bytes per record). */
#define RECORDS_A ((Rec5F *) (&D_800C02AE + 0x37A2))
#define RECORDS_B ((Rec5F *) (&D_800C02AE + 0x38A2))
#define RECORDS_C ((Rec5F *) (&D_800C02AE + 0x3862))
typedef struct Obj5F
{
  u8 p[6];
  s16 x;
  s16 y;
  u8 pA;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
} Obj5F;
typedef struct Rec5F
{
  s32 time;
  u8 pad[2];
  char name[10];
} Rec5F;
extern u8 D_800A14E0;
extern u8 D_800A14E1;
extern u8 D_800A14E2;
extern char D_800A5490[];
extern char D_800A54FC[];
extern char D_800A5508[];
extern s16 D_800A5504;
extern s8 D_800A5506;
extern u8 D_800C02AE;
extern Rec5F D_800C3A50[];
extern Rec5F D_800C3B50[];
extern Rec5F D_800C3B10[];void *text_obj_get(u32);
extern void func_80052E94(s32, char *);
extern void func_80059618(Obj5F *, u8, u8, u8, s32);
void func_800596F4(void *, s16, s16, void *);
extern void func_8006874C(s32);
extern void memset(char *, s32, s32);
extern void func_800980D0(char *, char *);
extern void func_80099DF8(char *, char *, ...);
/* Draws the best-times screen: for each of the three record classes, the names,
 * times and gaps to the best time; then the three stat values and their average. */
void func_8005F5C4(void)
{
  char buf[16];
  s32 t = 0;
  s32 best = 0;
  u8 i = 0;
  char *p = buf;
  u8 j;
  Obj5F *obj;
  Obj5F *obj2;
  do
  {
    obj = text_obj_get((i * 4) + 5);
    memset(buf, 0, 15);
    j = 0;
    do
    {
      if (i == 0)
      {
        func_80099DF8(buf, D_800A54FC, j + 1, RECORDS_A[j].name);
      }
      else
        if (i == 1)
      {
        func_80099DF8(buf, D_800A54FC, j + 1, RECORDS_B[j].name);
      }
      else
        if (i == 2)
      {
        func_80099DF8(buf, D_800A54FC, j + 1, RECORDS_C[j].name);
      }
      func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
      func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
      j++;
    }
    while (j < 3);
    obj = text_obj_get((i * 4) + 7);
    obj2 = text_obj_get((i * 4) + 6);
    j = 0;
    do
    {
      if (i == 0)
      {
        t = D_800C3A50[j].time;
      }
      else
        if (i == 1)
      {
        t = D_800C3B50[j].time;
      }
      else
        if (i == 2)
      {
        t = D_800C3B10[j].time;
      }
      memset(buf, 0, 15);
      func_80052E94(t, buf);
      func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
      if (j == 0)
      {
        best = t;
      }
      else
      {
        memset(buf, 0, 15);
        {
          s32 h = D_800A5504;
          s32 c = D_800A5506;
          do { *((s16 *) buf) = h; } while (0);
          buf[2] = c;
        }
        func_80052E94(t - best, buf + 2);
        func_800980D0(p, D_800A5508);
        func_800596F4((void *)(obj2), (s16)(obj2->x), (s16)(obj2->y + ((j - 1) * 22)), (void *)(p));
      }
      j++;
    }
    while (j < 3);
    i++;
  }
  while (i < 3);
  obj = text_obj_get(17);
  func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  func_80099DF8(buf, D_800A5490, D_800A14E0);
  func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = text_obj_get(18);
  func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  func_80099DF8(buf, D_800A5490, D_800A14E1);
  func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = text_obj_get(19);
  func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  func_80099DF8(buf, D_800A5490, D_800A14E2);
  func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = text_obj_get(20);
  func_80059618(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  func_80099DF8(buf, D_800A5490, ((D_800A14E0 + D_800A14E1) + D_800A14E2) / 3);
  func_800596F4((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  func_8006874C(-1);
}
