/* Remove thread from its queue. */
void __osDequeueThread(void **queue, void *thread) { void *cur = *queue; while (cur) { if (cur == thread) { *queue = *(void **)cur; return; } queue = cur; cur = *(void **)cur; } }
