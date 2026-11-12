extern char stream_state[];
extern f32 D_800C35D8;
extern void *gSoundState;
extern s32 D_800B0BC4;
extern char gOrderState[];
extern s32 D_8009FBCC;
extern s32 D_8009FCE4;
extern char D_A7FE0[];
extern char D_ABE70[];
extern s32 setSoundEntryTable(u8);
extern void *poolAlloc(s32, s32, s32, s32);
extern s32 func_8007ED48(s32, s32, s32);
typedef struct
{
  s32 w[5];
} Args5;
extern s32 dmaCopyChunks(s32 *, s32, s32, s32, Args5);
extern s32 MusInitialize(s32 *);
extern s32 MusSetMasterVolume(s32, s32);
extern s32 func_80089980(void);

/* Audio bring-up: sets default channel volumes and pan in the sound state block,
 * allocates the sequence/sound heap, fills the MusInitialize parameter block and
 * the per-track table, then starts the music driver. Returns MusInitialize's result. */
#ifdef PORT
typedef unsigned long uintptr_t;
#define PARAM_T uintptr_t
#else
#define PARAM_T s32
#endif
s32 func_80037AA4(s32 musicVoices, s32 sfxVoices)
{
  s32 i;
  s32 *cfg;
  PARAM_T initParams[16];
  f32 volume = 0.625f;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331A)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331C)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331D)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331E)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331F)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x3320)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x3321)) = 255;
  *((u8 *) (((s8 *) (&stream_state)) + 0x331B)) = 0;
  *((u8 *) (((s8 *) (&stream_state)) + 0x333E)) = 1;
  *((f32 *) (((s8 *) (&stream_state)) + 0x332A)) = volume;
  *((f32 *) (((s8 *) (&stream_state)) + 0x332E)) = volume;
  *((f32 *) (((s8 *) (&stream_state)) + 0x3332)) = volume;
  *((f32 *) (((s8 *) (&stream_state)) + 0x3336)) = 70.0f;
  *((f32 *) (((s8 *) (&stream_state)) + 0x333A)) = volume;
  {
    s32 allocation = func_8007ED48(1, 0x4650, 8);
    dmaCopyChunks((s32 *) (&D_A7FE0), D_800B0BC4 = allocation, ((char *) (&D_ABE70)) - ((char *) (&D_A7FE0)), *((s32 *) (((s8 *) (&gOrderState)) + 0x2358)), *((Args5 *) (gOrderState + 0x235C)));
  }
  initParams[0] = 0;
  initParams[1] = musicVoices & 255;
  initParams[2] = 6;
  initParams[3] = *((s32 *) (stream_state + 0x325E));
  initParams[4] = 0x48440;
  initParams[5] = D_800B0BC4;
  {
    extern char D_000ABE70[];
    initParams[6] = (PARAM_T) D_000ABE70;
  }
  initParams[7] = (PARAM_T) (&D_8009FBCC);
  initParams[8] = (PARAM_T) (&D_8009FCE4);
  initParams[10] = 0x5622;
  initParams[9] = 0x100;
  initParams[11] = 0x1000;
  initParams[12] = 1;
  initParams[13] = sfxVoices & 255;
  initParams[14] = 0x1000;
  ((u8 *) initParams)[60] = 28;
  ((u8 *) initParams)[61] = 50;
  *((void **) (stream_state + 0x7F26)) = poolAlloc(1, 0x1D4, initParams[3], initParams[5]);
  i = 0;
  setSoundEntryTable(*((u8 *) (((s8 *) (&stream_state)) + 0x32AD)));
  cfg = (s32 *) (*((void **) (((s8 *) (&stream_state)) + 0x7F26)));
  cfg[0x6C / 4] = 0x10;
  cfg[0x60 / 4] = 0x11;
  cfg[0x54 / 4] = 0x12;
  cfg[0x84 / 4] = 0x16;
  cfg[0x90 / 4] = 0x14;
  cfg[0x9C / 4] = 0x17;
  cfg[0xA8 / 4] = 0x18;
  cfg[0xB4 / 4] = 0x15;
  cfg[0xC0 / 4] = 0x19;
  cfg[0x78 / 4] = 0x1A;
  cfg[0xF0 / 4] = 0x22;
  cfg[0xFC / 4] = 0x13;
  cfg[0x108 / 4] = 0x23;
  cfg[0x114 / 4] = 0x24;
  cfg[0x120 / 4] = 0x1B;
  cfg[0x12C / 4] = 0x1E;
  cfg[0x138 / 4] = 0x26;
  cfg[0x144 / 4] = 0x27;
  cfg[0x150 / 4] = 0x28;
  cfg[0x15C / 4] = 0x29;
  cfg[0x168 / 4] = 0x2A;
  cfg[0x174 / 4] = 0x2B;
  cfg[0x180 / 4] = 0x2C;
  cfg[0x18C / 4] = 0x2D;
  cfg[0x198 / 4] = 0x2E;
  cfg[0x1A4 / 4] = 0x2F;
  cfg[0x1B0 / 4] = 0x30;
  cfg[0x1BC / 4] = 5;
  cfg[0x1C8 / 4] = 0x45;
  for (; i < 0x27; i++)
  {
    *((((u8 *) gSoundState) + (i * 12)) + 8) = 0;
  }

  i = MusInitialize((s32 *) initParams);
  MusSetMasterVolume(3, (s32) (D_800C35D8 * 32767.0f));
  func_80089980();
  return i;
}
