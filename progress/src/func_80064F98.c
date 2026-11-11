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
char *pool_get_item(s32, s32);void *textObjGet(u32);
void group_set_color(Win64F98 *, u8, u8, u8, u8);
void draw_palette_sprite(void *, s16, s16, void *);void text_obj_set_enabled(u32);void func_8005A6E0(u32);
void memset(char *, s32, s32);
void appendString(char *, char *);
void formatString(char *, char *, s32, char *);
extern u8 *gSelectState;
extern char D_800A56C4[];
extern s16 D_800A56CC;
extern s8 D_800A56CE;
extern char D_800A56D0[];
extern Mgr64F98 *gRecords;
extern Rec64F98 D_800C3650[][4];
extern s32 gSelectStepHandle;
extern Tbl64F98 *gSlotTableB[];
/* Fills the best-times screen: three rows of names, then times and gaps to the
 * leader, then the track name and the next screen. Uses the built-in records
 * when the flag at gSelectState[0x245] is clear, otherwise the saved table. */
void func_80064F98(void)
{
  char line[16];
  char *textOut;
  Win64F98 *win;
  Win64F98 *win2;
  u8 row;
  s32 time;
  s32 firstTime;
  s32 nextScreen;
  Tbl64F98 **tbl;
  memset(line, 0, 15);
  firstTime = 0;
  if (gSelectState[0x245] == 0)
  {
    win = textObjGet(0x10);
    for (row = 0; row < 3; row++)
    {
      char *nm = D_800C3650[gRecords->x20][row].name;
      formatString(line, D_800A56C4, row + 1, nm);
      draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y + (row * 22)), (void *)(line));
    }

    win = textObjGet(0x12);
    win2 = textObjGet(0x11);
    for (row = 0, textOut = line; row < 3; row++)
    {
      time = D_800C3650[gRecords->x20][row].time;
      memset(line, 0, 15);
      func_80052E94(time, line);
      draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y + (row * 22)), (void *)(line));
      if (row == 0)
      {
        firstTime = time;
      }
      else
      {
        s32 c;
        s32 h;
        memset(line, 0, 15);
        h = D_800A56CC;
        c = D_800A56CE;
 do { *((s16 *) line) = h; line[2] = c; } while (0);
        func_80052E94(time - firstTime, line + 2);
        appendString(textOut, D_800A56D0);
        draw_palette_sprite((void *)(win2), (s16)(win2->x), (s16)(win2->y + ((row - 1) * 22)), (void *)(textOut));
      }
    }

    win = textObjGet(0x13);
    group_set_color(win, win->b, win->c, win->d, win->e);
    draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(pool_get_item(gSelectStepHandle, gRecords->x20 + 0x1CD)));
    func_8005A6E0(0x15);
    nextScreen = 0x14;
  }
  else
  {
    win = textObjGet(0x10);
    for (row = 0; row < 3; row++)
    {
      formatString(line, D_800A56C4, row + 1, gSlotTableB[gSelectState[0x23C]]->rec[gRecords->x22][row].name);
      draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y + (row * 22)), (void *)(line));
    }

    win = textObjGet(0x12);
    win2 = textObjGet(0x11);
    for (row = 0, tbl = gSlotTableB, textOut = line; row < 3; row++)
    {
      time = tbl[gSelectState[0x23C]]->rec[gRecords->x22][row].time;
      func_80052E94(time, line);
      draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y + (row * 22)), (void *)(line));
      if (row == 0)
      {
        firstTime = time;
      }
      else
      {
        s32 h;
        s32 c;
        memset(line, 0, 15);
        h = D_800A56CC;
        c = D_800A56CE;
 do { *((s16 *) line) = h; line[2] = c; } while (0);
        func_80052E94(time - firstTime, line + 2);
        appendString(textOut, D_800A56D0);
        draw_palette_sprite((void *)(win2), (s16)(win2->x), (s16)(win2->y + ((row - 1) * 22)), (void *)(textOut));
      }
    }

    win = textObjGet(0x13);
    group_set_color(win, win->b, win->c, win->d, win->e);
    draw_palette_sprite((void *)(win), (s16)(win->x), (s16)(win->y), (void *)(pool_get_item(gSelectStepHandle, gRecords->x22 + 0x21A)));
    func_8005A6E0(0x14);
    nextScreen = 0x15;
  }
  text_obj_set_enabled(nextScreen);
}
