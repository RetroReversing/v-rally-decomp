typedef struct { s32 a,b; s16 c; s8 d; } S_D800A54A4;
typedef void (*Fn)(void);
extern u8 gStreamState[]; extern S_D800A54A4 *gSelectState; extern S_D800A54A4 D_800A54A4;
extern s32 func_8005A2F4(s32); extern s32 func_8005A474(u8,s32,void*); extern void func_80062B70(void),func_80064E48(void),func_80070A34(void);

/* Stage select entry: reads the stream mode, resets the select state, copies the
 * default record when mode 3 is active, and installs the handler for the mode. */
s32 func_8005E38C(void)
{
  s32 mode;
  S_D800A54A4 *state;
  s32 three;

  mode = gStreamState[0x5D56];
  func_8005A2F4(0);
  state = gSelectState;
  three = 3;
  *(void **)((u8 *)state + 0x1F4) = (u8 *)state + 0x204;
  if (mode == three)
  {
    __builtin_memcpy((S_D800A54A4 *)((u8 *)state + 0x204), &D_800A54A4, 11);
  }
  func_8005A474(mode, 0, state);
  if (mode == 2)
  {
    *(Fn *)((u8 *)gSelectState + 0x288) = func_80062B70;
  }
  else if (mode == 1)
  {
    *(Fn *)((u8 *)gSelectState + 0x288) = func_80064E48;
  }
  else if (mode == three)
  {
    *(Fn *)((u8 *)gSelectState + 0x288) = func_80070A34;
  }
  return 0;
}
