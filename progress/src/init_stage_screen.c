typedef struct SceneState
{
  u8 pad0[0xE];
  u16 unkE;
  u8 pad10[0xE];
  u16 unk1E;
  u16 unk20;
  u16 unk22;
  u8 pad24[0xA];
  u8 unk2E;
} SceneState;
typedef struct WorldObj
{
  u8 pad[0x228];
  u8 unk228;
  u8 pad229[0x13];
  u8 unk23C;
  u8 pad23D[0x4F];
  void (*unk28C)(void);
} WorldObj;
typedef struct S41
{
  u8 pad[0x41];
  u8 unk41;
} S41;
extern WorldObj *gSelectState;
extern SceneState *gRecords;
extern void *gLeague;
extern u8 *gSlotTableB[];
extern u8 gStreamPhase;
extern u8 D_8009E260;
extern u8 D_800A14D6;
extern u8 D_800A14D7;
extern u8 D_800A14D8;
void func_80066384(void);
s32 stage_stub_return_true(void);
void func_80061F34(void *sc, void *base);
void setRecordSlotValue(void *p, s32 a, s32 b);
void league_set_hook_entry(void *p, s32 a, s32 b, s32 (*fn)(void));
void stream_state_update(void);
void record_set_byte9(void *p, s32 a, char b);
void *select_get_entry(u32);
void select_propagate_values(s32, u32, u32);
void hud_setup_stage_results(void);
void func_80057B40(s32, u16, u8, u8);
inline static u16 inline_fn(SceneState *arg0)
{
  return arg0->unk22;
}

inline static u16 inline_fn23(SceneState *arg0)
{
  return arg0->unk1E;
}

/* Sets up the stage results screen: clears the world object's flags, points the
 * track row at the current track's data, installs the update callback and HUD,
 * then applies the league's first-race position overrides before showing the screen. */
void init_stage_screen(void)
{
  int is_first;
  SceneState *scene;
  u8 *track_base;
  u8 *track_row;
  u16 saved_num;
  u16 saved_1E;
  u16 saved_22;
  u8 saved_22_u8;
  s32 one;
  s32 limit;
  u8 saved_1E_u8;
  gSelectState->unk228 = 0;
  gSelectState->unk23C = gRecords->unk1E;
  scene = gRecords;
  track_base = gSlotTableB[inline_fn23(scene)];
#ifdef PORT
  track_row = track_base + scene->unk20 * 0x2C4;
#else
  track_row = (u8 *)(scene->unk20 * 0x2C4 + (u32)track_base);
#endif
  scene->unk2E = *((track_row + ((inline_fn(scene) << 1) << 5)) + 0x37);
  func_80061F34(scene, track_base);
  gSelectState->unk28C = func_80066384;
  setRecordSlotValue(gLeague, 3, 0x14);
  league_set_hook_entry(gLeague, 3, 0x10000, stage_stub_return_true);
  stream_state_update();
  if ((*gRecords).unkE < 2)
  {
    S41 *p;
    record_set_byte9(gLeague, 0x10, 0);
    p = select_get_entry(2);
    p->unk41 = 0;
    select_propagate_values(2, 1, 4);
  }
  hud_setup_stage_results();
  limit = 3;
  if (gStreamPhase < limit)
  {
    is_first = gStreamPhase == 0;
    if (is_first)
    {
      if (gStreamPhase == 0)
      {
        scene = gRecords;
        saved_num = scene->unkE;
        saved_1E = scene->unk1E;
        saved_22 = scene->unk22;
        D_8009E260 = 4;
        one = 1;
        saved_1E_u8 = (u8) saved_1E;
        scene->unkE = one;
        saved_22_u8 = (u8) saved_22;
        if (((u16)saved_1E) != 2) goto alternate;
        if (((u16)saved_22) != 4) goto alternate;

        {
          scene->unk1E = 5;
          scene->unk20 = one;
          scene->unk22 = 2;
        }
        goto finished_selection;
alternate:
        {
          SceneState *alt;
          alt = gRecords;
          if ((inline_fn23(alt) == 3) && (inline_fn(alt) == 5))
          {
            alt->unk1E = 5;
            alt->unk20 = 6;
            alt->unk22 = 0;
          }
        }
finished_selection:;
        D_800A14D6 = gRecords->unk1E;
        D_800A14D7 = gRecords->unk20;
        D_800A14D8 = inline_fn(gRecords);
        func_800416EC();
        D_8009E260 = 1;
        ;
        gRecords->unk1E = saved_1E_u8;
        gRecords->unk20 = 0;
        gRecords->unk22 = saved_22_u8;
        gRecords->unkE = saved_num;
      }
    }
  }
  func_80057B40(0x12, 2, 0, 0);
}
