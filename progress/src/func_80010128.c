extern char gStreamState[];
extern char gOrderState[];
extern char D_800A73E0[];
extern char D_15DB10[];
extern char D_BB9470[];
void streamReleaseEntry();
void func_80035A10();
void soundResetState();
void func_80022214();
void func_80005DEC();
void scene_teardown();
void race_ctx_free();
void reset_owner_slots();
void nodeListRunCallbacks();
void heapReleaseBlock();
void func_8001BAF4();
void func_80015C74();
void func_80081514();
void heap_free_stub();

/* Shuts down the subsystems in turn, passing each the handle it holds in gStreamState or gOrderState.
 * Last, calls func_80081514 on the block from D_15DB10 up to D_BB9470. */
void func_80010128(void)
{
  streamReleaseEntry(*((s32 *) (gStreamState + 0x103B2)));
  streamReleaseEntry(*((s32 *) (gStreamState + 0x103B6)));
  heap_free_stub(*((s32 *) (gStreamState + 0x103BA)));
  heap_free_stub(*((s32 *) (gOrderState + 0x72F8)));
  soundResetState();
  func_80035A10();
  func_80022214();
  func_80005DEC();
  scene_teardown();
  race_ctx_free();
  reset_owner_slots();
  nodeListRunCallbacks(*((s32 *) (gOrderState + 0x87F0)));
  heapReleaseBlock(*((s32 *) (gOrderState + 0x87F0)));
  func_8001BAF4(*((s32 *) (gStreamState + 0x80C6)));
  func_80015C74(D_800A73E0 + 0x6BD0, 0);
  func_80081514(D_15DB10, D_BB9470 - D_15DB10, 1);
}
