s32 game_state_clear_6bf8();
s32 flag_test_bit0(void *);
s32 flag_set_then_call(void *, s32 *);
s32 memset(void *, s32, s32);
extern s32 D_8009BBA4;
extern s16 D_8009BBB4;
extern s16 g_obj_state_copy;
extern s32 *D_8009BBB8;
extern s16 D_8009CEBC;
extern s32 D_8009E250;
extern s32 D_8009E254;
extern s32 D_8009E258;
extern s32 gShadeMode;
extern f32 sSavedCosX;
extern f32 sSavedCosY;
extern s32 D_800A1884;
extern s32 D_800A188C;
extern s32 D_800A1894;
extern s32 D_800A189C;
extern s32 sSavedFlag0;
extern s32 sSavedFlag1;
extern s32 sSavedFlag2;
extern s32 D_800A18BC;
extern s32 sSavedAngleX;
extern s32 sSavedAngleY;
extern f64 D_800A4178;
extern s32 gGameState;
extern s32 gOrderState;
extern s32 stream_state;
extern s32 race_clear_stream_flag;
extern s32 order_handle_pending_flag;
typedef struct { u8 pad[0xE]; u16 mode; u8 pad10[2]; u16 x12; u8 pad14[0xA]; u16 x1E; u8 pad20[0xC]; u16 x2C; } R15780;
typedef struct { u8 p0[2]; s8 state; u8 p3[2]; s8 x5; u8 p6[2]; u16 x8; s8 xA; u8 pB; } S7676;
#define G(t, base, off) (*(t *) ((char *) &base + (off)))
#define RACE (*(R15780 **) ((char *) &stream_state + 0x32F2))
#define ST ((S7676 *) ((char *) &stream_state + 0x7676))
struct Copy12 { s32 a; s32 b; s32 c; } __attribute__((packed));
struct Copy6 { s32 a; s16 b; } __attribute__((packed, aligned(2)));

/* Starts a race-state session. The first call per session (the manager is not yet
   initialised) sets the start parameters from the race record: the state and
   volume for the player, or the opening sequence when is_start is 0. Every call
   then resets the sound tables and the timing constants. */
void func_80015780(s32 is_start, s32 arg1, s32 arg2, u32 speed, s32 arg4, s32 param)
{
  s32 *saved_cb;
  f64 angle_scale;
  void *mgr;
  mgr = (char *) &gOrderState + 0x7368;
  if (flag_test_bit0(mgr) == 0)
  {
    flag_set_then_call(mgr, &order_handle_pending_flag);
    D_8009BBB4 = param;
    G(s32, gGameState, 0x6BD0) = 0x1000;
    G(s16, gGameState, 0x6BEE) = speed;
    game_state_clear_6bf8();
    G(struct Copy12, stream_state, 0x7676) = *(struct Copy12 *) &D_8009BBA4;
    D_8009CEBC = 4;
    if (is_start == 0)
    {
      if ((RACE->x2C & 1) || (RACE->x1E == 7))
      {
        ST->state = 0;
        if (G(u8, gGameState, 0x6C02))
          ST->x8 = 0x8000;
        else
          ST->x8 = 0x4000;
      }
      else if (RACE->mode == 1)
      {
        ST->state = 0;
        if (G(u8, gGameState, 0x6C02))
          ST->x8 = 0x8000;
        else
          ST->x8 = 0x4000;
      }
      else
      {
        ST->xA = 1;
        if (RACE->mode == 2)
        {
          ST->x5 = RACE->x12;
          if (RACE->x12)
          {
            ST->state = 2;
            ST->x8 = 0xC000;
          }
          else
          {
            ST->state = 1;
            ST->x8 = 0xC000;
            G(s16, gGameState, 0x6BEE) = (speed * 2) / 3;
          }
        }
        else
        {
          ST->state = 3;
          ST->x8 = 0xF400;
        }
      }
    }
    else
    {
      G(s32, gOrderState, 0x72F4) = 0;
      ST->state = 0;
      ST->x8 = 0xC000;
    }
    G(s16, gGameState, 0x6BE6) = 0xFF;
    G(s16, gGameState, 0x6BE8) = 0xFF;
    G(s16, gGameState, 0x6BEA) = 0xFF;
    G(s16, gGameState, 0x6BEC) = 0xFF;
  }
  D_8009E250 = 2;
  D_8009E254 = 2;
  gShadeMode = 0;
  D_8009E258 = 7;
  memset((u8 *) &stream_state + 0x5A4A, 0, 0x24);
  *(struct Copy6 *) &sSavedFlag0 = *(struct Copy6 *) &D_800A1884;
  *(struct Copy6 *) &sSavedFlag1 = *(struct Copy6 *) &D_800A188C;
  angle_scale = D_800A4178;
  saved_cb = G(s32 *, stream_state, 0x7DA6);
  *(struct Copy6 *) &sSavedFlag2 = *(struct Copy6 *) &D_800A1894;
  *(struct Copy6 *) &D_800A18BC = *(struct Copy6 *) &D_800A189C;
  G(s16, gOrderState, 0x7300) = 0;
  G(s32 *, stream_state, 0x7DA6) = &race_clear_stream_flag;
  G(s32, gOrderState, 0x82AC) = 0;
  D_8009BBB8 = saved_cb;
  sSavedCosX = __cosf((f32) (((f64) sSavedAngleX) * angle_scale));
  sSavedCosY = __cosf((f32) (((f64) sSavedAngleY) * angle_scale));
  g_obj_state_copy = 0xA;
}
