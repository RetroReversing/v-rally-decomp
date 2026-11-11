s32 osRecvMesg();

/* Receives one message from the task's queue (at +0x10), blocking, and returns its first word.
 * Bit 0 of the flags at +0xE is held set while waiting. Returns 0 if no message arrived. */
s32 taskRecvMsg(void *task)
{
    int waitBlock;
    s32 *msg;
    void *queue;
    s32 *sp10;
    *((u16 *) (((char *) task) + 0xE)) |= 1;
    waitBlock = 0x10;
    queue = task;
    queue = queue + waitBlock;
    osRecvMesg(queue, &sp10, 1);
    msg = sp10;
    *((u16 *) (((char *) task) + 0xE)) &= 0xFFFE;
    if (msg != NULL)
    {
        return *msg;
    }
    return 0;
}
