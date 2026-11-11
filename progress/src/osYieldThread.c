s32 func_8008B4D4();
s32 osDisableInt();
s32 osRestoreInt();
extern char D_800A2518[];
extern void *D_800A2520;
static inline char *inline_fn()
{
  return ((char *) D_800A2520) + 0x10;
}

/* Marks the current thread as yielding (state 2 at the thread's +0x10 field) and
 * hands the run queue at D_800A2518 to func_8008B4D4, with interrupts masked. */
void osYieldThread(void)
{
  int new_var;
  s32 saved;
  saved = osDisableInt();
  new_var = 2;
  *((s16 *) inline_fn()) = new_var;
  func_8008B4D4(&D_800A2518, 2);
  osRestoreInt(saved);
}
