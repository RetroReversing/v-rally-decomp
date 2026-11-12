extern u8 stream_state[];
typedef struct
{
  u16 b15 : 1;
  u16 b14 : 1;
  u16 b13 : 1;
  u16 b12 : 1;
  u16 b10 : 2;
  u16 b8 : 2;
  u16 b4 : 4;
  u16 b0 : 4;
} Flags;
typedef struct
{
  Flags f;
  u16 h2;
  s16 h4;
} State;
typedef struct
{
  u32 hi : 4;
  u32 f24 : 4;
  u32 lo : 24;
} Word;
void stream_refresh_car_flags(void);
#define WD (*(Word *)(stream_state + 0x6E76))
#define OBJ (*(u8 **)(stream_state + 0x32F2))

/* Copies the current object and scale-float state into the packed State record and the Word
 * register, then calls stream_refresh_car_flags to apply it. Float values are scaled by 8 and truncated. */
void func_8006ECB4(void)
{
  f32 scale = 8.0f;
  State *state = (State *)(stream_state + 0x6E5E);
  Word word = WD;
  word.f24 = (s32)(*(f32 *)(stream_state + 0x3332) * scale);
  state->f.b4 = (s32)(*(f32 *)(stream_state + 0x333A) * scale);
  state->f.b0 = (s32)(*(f32 *)(stream_state + 0x332E) * scale);
  WD = word;
  state->f.b12 = *(u16 *)(OBJ + 0x50);
  state->h2 = *(u16 *)(OBJ + 0x2A);
  if (*(u16 *)(OBJ + 0x38))
    state->f.b15 = 1;
  else
    state->f.b15 = 0;
  state->h4 = OBJ[0x2F];
  state->f.b14 = *(u16 *)(stream_state + 0x32A8);
  state->f.b13 = *(u16 *)(OBJ + 0x12);
  state->f.b10 = *(u16 *)(OBJ + 0x16);
  state->f.b8 = *(u32 *)(stream_state + 0x32AA);
  stream_refresh_car_flags();
}
