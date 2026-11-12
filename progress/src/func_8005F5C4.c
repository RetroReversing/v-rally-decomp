/* Record tables for the three classes (stride 40 bytes per record). */
#define RECORDS_A ((Rec5F *) (&stream_state + 0x37A2))
#define RECORDS_B ((Rec5F *) (&stream_state + 0x38A2))
#define RECORDS_C ((Rec5F *) (&stream_state + 0x3862))
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
extern u8 stream_state;
extern Rec5F D_800C3A50[];
extern Rec5F D_800C3B50[];
extern Rec5F D_800C3B10[];void *textObjGet(u32);
extern void func_80052E94(s32, char *);
extern void group_set_color(Obj5F *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
extern void select_draw_results_table(s32);
extern void memset(char *, s32, s32);
extern void appendString(char *, char *);
extern void format_to_buffer(char *, char *, ...);
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
    obj = textObjGet((i * 4) + 5);
    memset(buf, 0, 15);
    j = 0;
    do
    {
      if (i == 0)
      {
        format_to_buffer(buf, D_800A54FC, j + 1, RECORDS_A[j].name);
      }
      else
        if (i == 1)
      {
        format_to_buffer(buf, D_800A54FC, j + 1, RECORDS_B[j].name);
      }
      else
        if (i == 2)
      {
        format_to_buffer(buf, D_800A54FC, j + 1, RECORDS_C[j].name);
      }
      group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
      draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
      j++;
    }
    while (j < 3);
    obj = textObjGet((i * 4) + 7);
    obj2 = textObjGet((i * 4) + 6);
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
      draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
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
        appendString(p, D_800A5508);
        draw_palette_sprite((void *)(obj2), (s16)(obj2->x), (s16)(obj2->y + ((j - 1) * 22)), (void *)(p));
      }
      j++;
    }
    while (j < 3);
    i++;
  }
  while (i < 3);
  obj = textObjGet(17);
  group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  format_to_buffer(buf, D_800A5490, D_800A14E0);
  draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = textObjGet(18);
  group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  format_to_buffer(buf, D_800A5490, D_800A14E1);
  draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = textObjGet(19);
  group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  format_to_buffer(buf, D_800A5490, D_800A14E2);
  draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  obj = textObjGet(20);
  group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
  memset(buf, 0, 15);
  format_to_buffer(buf, D_800A5490, ((D_800A14E0 + D_800A14E1) + D_800A14E2) / 3);
  draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(buf));
  select_draw_results_table(-1);
}
