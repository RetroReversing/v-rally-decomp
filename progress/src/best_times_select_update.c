#define U(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define A(p,o) (*(u8 **)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
typedef struct Blob
{
  s32 w[175];
  u8 tab[8];
} Blob;
extern u8 *gLeague;
extern u8 *gRecords;
extern u8 *gSelectState;
extern u8 *gSelectBuffer;
extern Blob *D_800D0648;
extern s32 *gStreamList;
extern s32 D_800B0548;
extern s32 D_800D05D8;
extern const f64 D_800A5D10;
extern void func_8005937C(s32, s32);
extern void select_arm_if_clear(void);
extern void func_80061740(Blob);
extern void menu_draw_text_objs(Blob, s32);void *select_get_entry(u32);
extern void func_8006185C(void *, s32);
extern void draw_best_times_screen(void);
extern void func_8004D08C(s32, s32, s16, s16, f32, f32, u8, u8);

/* Best-times screen tick: picks the selected entry's scene from the entry
 * table, updates the cursor and draws the scene's icons when the row is idle. */
void best_times_select_update(void)
{
  u8 *entry = A(gLeague, 16) + H(gLeague, 2) * 20;
  s32 selected = entry[14];
  Blob scene;
  u8 idx;
  if (selected < 34)
  {
    if (gSelectState[0x245] == 0)
    {
      selected -= entry[13];
      U(gRecords, 32) = selected;
      func_8005937C(entry[14], U(&D_800D0648[selected], 20));
      if (selected != D_800B0548)
      {
        if (*gStreamList)
        {
          select_arm_if_clear();
        }
        if (gSelectState[0x2be] == 0)
        {
          func_80061740(D_800D0648[U(gRecords, 32)]);
          D_800B0548 = selected;
        }
      }
    }
    else
    {
      func_8006185C(select_get_entry(U(gRecords, 32)), 0);
    }
    if (H(gLeague, 2) == 2)
    {
      draw_best_times_screen();
    }
    scene = D_800D0648[U(gRecords, 32)];
    menu_draw_text_objs(scene, 0);
    if (gSelectState[0x24d] == 0 && gSelectState[0x2be] == 0)
    {
      for (idx = 0; idx < U(&scene, 20); idx++)
      {
        func_8004D08C(D_800D05D8, idx, H(gSelectBuffer, 0), U(gSelectBuffer, 2) + idx * gSelectBuffer[8], F(gSelectBuffer, 4) - D_800A5D10, F(gSelectBuffer, 4), scene.tab[idx], 255);
      }
    }
  }
}
