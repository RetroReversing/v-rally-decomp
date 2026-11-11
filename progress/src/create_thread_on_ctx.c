s32 func_8007ED48();
s32 osCreateThread();
s32 osStartThread();

/* Carves a stack block out of ctx (its size is at +0x1B0), creates a thread that runs
   entry(arg) at priority pri on that stack, starts it and returns the thread. */
s32 create_thread_on_ctx(s32 entryArg, s32 ctx, s32 priArg, s32 argArg) {
    s32 thread;
    s32 stackTop;
    s32 entry;
    s32 pri;
    s32 arg;
    s32 aligned;

    entry = entryArg;
    pri = priArg;
    arg = argArg;
    stackTop = ctx + 0x1B0;
    aligned = stackTop;
    if (stackTop < 0) {
        aligned = ctx + 0x1B7;
    }
    stackTop += stackTop - ((aligned >> 3) * 8);
    thread = func_8007ED48(1, ctx + 0x1B0, 8);
    osCreateThread(thread, entry, entry, arg, thread + stackTop, pri);
    osStartThread(thread);
    return thread;
}
