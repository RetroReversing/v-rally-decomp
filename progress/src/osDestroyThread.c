s32 func_8008B634();
s32 osDisableInt();
s32 osRestoreInt();
s32 __osDequeueThread();
extern void *D_800A251C;
extern void *D_800A2520;

typedef struct OSThread
{
  u8 pad00[4];
  s32 priority;
  void *queue;
  struct OSThread *next;
  u16 state;
} OSThread;

/* Removes a thread (the running thread when arg is NULL) from the thread list and the
 * run queue, then restores the interrupt level saved on entry. The running thread is
 * cleared when it is destroyed. */
void osDestroyThread(void *thread)
{
  s32 savedIntLevel;
  OSThread *cur;
  OSThread *prev;
  OSThread *walk;

  cur = thread;
  savedIntLevel = osDisableInt();
  if (thread == NULL)
  {
    cur = D_800A2520;
  }
  else if (((OSThread *)cur)->state != 1)
  {
    __osDequeueThread(((OSThread *)cur)->queue, cur);
  }

  if (D_800A251C == cur)
  {
    D_800A251C = ((OSThread *)cur)->next;
    goto done;
  }
  goto walk;
unlink:
  prev->next = ((OSThread *)cur)->next;
  goto done;
walk:
  prev = D_800A251C;
  walk = prev->next;
  if (walk != NULL)
  {
    do
    {
      if (walk == cur)
      {
        goto unlink;
      }
      prev = walk;
      walk = walk->next;
    }
    while (walk != NULL);
  }
done:
  if (cur == D_800A2520)
  {
    func_8008B634();
  }
  osRestoreInt(savedIntLevel);
}
