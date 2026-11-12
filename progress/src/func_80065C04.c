#define CFG32 ((Cfg *)(*(void **)(stream_state + 0x32F2)))
#define CFG25 ((Cfg *)(*(void **)(stream_state + 0x325A)))
typedef struct
{
  unsigned char b[0x2E];
} Cfg;
typedef struct
{
  unsigned char b[0x250];
} State;
typedef struct { u32 w[40]; } Blk;
extern State *gSelectState;
extern s32 gSelectBuffer;
extern u8 stream_state[];
extern unsigned char gOrderState[];
extern void select_copy_entry_state(s32, s32);
extern void select_set_active_sub(s32, s32);
extern int select_copy_entry_label(int, int);
extern void select_arm_if_clear(void);
extern void heapFreeBlock(s32);
extern void init_stage_screen(void);
extern void func_80066384(void);
extern void select_shutdown_pending_stub(void);

/* Select-screen step: when the chosen entry is confirmed (flag bit 0x100 clear and the
 * second config's mode is 2), it saves the entry's block, switches the screen to its stage
 * callbacks and clears the pending stage id. Otherwise it shows the prompt for the mode. */
s32 func_80065C04(s32 ctx, s32 arg)
{
  s16 ver;
  ver = gSelectState->b[0x23c];
  *((u16 *) (CFG32->b + 0x22)) = 0;
  *((s16 *) (CFG32->b + 0x1e)) = ver;
  if ((((*((u16 *) (CFG32->b + 0x2c))) & 0x100) == 0) && ((*((s16 *) (CFG25->b + 2))) == 2))
  {
    *((Blk *) (gOrderState + 0x7F28)) = *((Blk *) (CFG32->b + 0x44));
    gSelectState->b[0x245] = 0;
    select_copy_entry_label(ctx, arg);
    *((void (**)(void)) (gSelectState->b + 0x288)) = init_stage_screen;
    *((void (**)(void)) (gSelectState->b + 0x28c)) = func_80066384;
    *((void (**)(void)) (gSelectState->b + 0x290)) = select_shutdown_pending_stub;
    select_arm_if_clear();
    if (gSelectBuffer)
    {
      heapFreeBlock(gSelectBuffer);
      gSelectBuffer = 0;
    }
    *((s16 *) (CFG32->b + 0x20)) = 0;
  }
  else
  {
    gSelectState->b[0x245] = 1;
    if (*((s16 *) (CFG25->b + 2)) == 2)
    {
      select_copy_entry_state(ctx, 13);
    }
    else
    {
      select_copy_entry_state(ctx, 8);
    }
    select_set_active_sub(ctx, *((u16 *) (CFG32->b + 0x22)));
  }
  return 1;
}
