s32 osSetThreadPri(void *thread, s32 pri);
extern void (*D_800A1BA0)(void);
extern char gOrderState[];

/* Calls the hook in D_800A1BA0, then raises the thread stored at gOrderState+0x2290 to priority 4. */
void func_8008743C(void) {
    D_800A1BA0();
    osSetThreadPri(*(void **)(gOrderState + 0x2290), 4);
}
