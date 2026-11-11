s32 osDisableInt();
s32 osRestoreInt();
extern void *__osViCurr;

/* Makes `mode` the current VI mode: stores it in the VI context (+8), flags the context for update
 * (+0), and copies the mode's control word (mode+4) into the context at +0xC. Restores the interrupt state. */
void osViSetMode(void *mode)
{
  void *modePtr;
  void **modeSlot;
  char *ctx;
  s32 savedInt;
  void *temp_a1;
  savedInt = osDisableInt();
  ctx = (char *) __osViCurr;
  *((void **) (((char *) __osViCurr) + 8)) = mode;
  ;
  modeSlot = (void **) (((char *) __osViCurr) + 8);
  *((s16 *) (ctx + 0)) = 1;
  modePtr = *modeSlot;
  *((s32 *) (ctx + 0xC)) = (s32) (*((s32 *) (((char *) (*modeSlot)) + 4)));
  osRestoreInt(savedInt, modePtr);
}
