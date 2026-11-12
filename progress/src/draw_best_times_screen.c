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
extern Cfg71 *gRecords;
extern s32 gSelectStepHandle;
extern u16 D_800A171C[];
extern Rec71 g_split_times[][4];
extern Rec71 D_800C3A90[];
extern Rec71 D_800C3AD0[];
extern char D_800A5CFC[];
extern s16 D_800A5D04;
extern s8 D_800A5D06;
extern char D_800A5D08[];
void *textObjGet(u32);
extern char *pool_get_item(s32, u16);
extern void func_80052E94(s32, char *);
extern void group_set_color(Obj71 *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
extern void memset(char *, s32, s32);
extern void appendString(char *, char *);
extern void format_to_buffer(char *, char *, ...);

/* Draws the best-times screen for the current track: the track name, the
 * top three times of the selected set (with gap to the best), and the
 * player's own list. Track indices 8 and up use the second table. */
void draw_best_times_screen(void)
{
  char buf[16];
  s32 best = 0;
  s32 t;
  u8 j;
  char *p;
  Obj71 *obj;
  Obj71 *obj2;
  char *s;
  obj = textObjGet(0x13);
  j = 0;
  s = pool_get_item(gSelectStepHandle, D_800A171C[gRecords->idx]);
  group_set_color(obj, obj->b, obj->c, obj->d, obj->e);
  draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y), (void *)(s));
  memset(buf, 0, 15);
  obj = textObjGet(0x10);
  do
  {
    format_to_buffer(buf, D_800A5CFC, j + 1, g_split_times[gRecords->idx][j].name);
    draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
    j++;
  }
  while (j < 3);
  obj = textObjGet(0x12);
  obj2 = textObjGet(0x11);
  j = 0;
  p = buf;
  do
  {
    t = g_split_times[gRecords->idx][j].time;
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
        s32 h = D_800A5D04;
        s32 c = D_800A5D06;
        *((s16 *) buf) = h;
        *(&buf[2]) = c;
 do { } while (0);
      }
      func_80052E94(t - best, &buf[2]);
      appendString(p, D_800A5D08);
      draw_palette_sprite((void *)(obj2), (s16)(obj2->x), (s16)(obj2->y + ((j - 1) * 22)), (void *)(p));
    }
    j++;
  }
  while (j < 3);
  if (obj->b)
  {
    memset(buf, 0, 15);
    obj = textObjGet(0x18);
    j = 0;
  }
  else
  {
    memset(buf, 0, 15);
    obj = textObjGet(0x18);
    j = 0;
  }
  do
  {
    if (gRecords->idx < 8)
    {
      format_to_buffer(buf, D_800A5CFC, j + 1, D_800C3A90[j].name);
    }
    else
    {
      format_to_buffer(buf, D_800A5CFC, j + 1, D_800C3A90[j + 4].name);
    }
    draw_palette_sprite((void *)(obj), (s16)(obj->x), (s16)(obj->y + (j * 22)), (void *)(buf));
    j++;
  }
  while (j < 3);
  obj = textObjGet(0x1A);
  obj2 = textObjGet(0x19);
  j = 0;
  p = buf;
  do
  {
    memset(buf, 0, 15);
    if (gRecords->idx < 8)
    {
      t = D_800C3A90[j].time;
    }
    else
    {
      t = D_800C3AD0[j].time;
    }
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
        s32 h = D_800A5D04;
        s32 c = D_800A5D06;
        *((s16 *) buf) = h;
        *(&buf[2]) = c;
 do { } while (0);
      }
      func_80052E94(t - best, &buf[2]);
      appendString(p, D_800A5D08);
      draw_palette_sprite((void *)(obj2), (s16)(obj2->x), (s16)(obj2->y + ((j - 1) * 22)), (void *)(p));
    }
    j++;
  }
  while (j < 3);
}
