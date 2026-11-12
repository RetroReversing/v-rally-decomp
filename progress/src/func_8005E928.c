typedef struct { s32 pad10[4]; s32 w20,w24,w28,w2C,w30,w34,w38,w3C,w40,w44,w48,w4C; u8 b50[12]; u8 b5C[4]; s32 pad60[2]; } FuncBuf;
void func_8004C370(s32, FuncBuf *, s32, s32);
void drawEdgeSegment(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,u8 arg5) ;

extern int gSelectStep;
extern int gSelectStepHandle;
s32 setSoundEntryTable();
s32 func_80057810();
s32 object_free_blocks();
s32 select_reset_text();
s32 func_8006ECB4();
s32 save_race_to_pak();
s32 stream_refresh_car_flags();
extern u8 *gSelectState;
extern s32 D_800A14C0;
extern u8 stream_state[];
extern s32 func_8005DC40;
extern s32 func_8005DD2C;

/* Stream frame setup: refreshes the car flags and the sound entry table for the stream's set,
 * reloads the sound handle when the stream's counter is zero, then installs the two
 * select-state callbacks. */
s32 func_8005E928(s32 arg0, s32 arg1)
{
  u8 *setId;
  char *streamSet;
  char *streamBase;
  streamSet = stream_state + 0x32AA;
  stream_refresh_car_flags();
  setId = (u8 *) (((char *) streamSet) + 3);
  setSoundEntryTable(*setId);
  func_8006ECB4();
  save_race_to_pak();
  if (*(s32 *)streamSet == 0)
  {
    streamBase = stream_state;
    if (streamBase)
    {
      object_free_blocks(gSelectStepHandle);
      gSelectStepHandle = func_80057810(D_800A14C0);
    }
    else
    {
      object_free_blocks(gSelectStepHandle);
      gSelectStepHandle = func_80057810(D_800A14C0);
    }
  }
  select_reset_text(arg0, arg1);
  *((s32 **) (((char *) gSelectState) + 0x288)) = &func_8005DC40;
  setId = &func_8005DD2C;
  *((s32 **) (((char *) gSelectState) + 0x28C)) = setId;
  return 0;
}
