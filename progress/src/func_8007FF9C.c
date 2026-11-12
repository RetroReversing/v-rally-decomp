s32 stream_slots_init();
s32 osCreateThread(void *, s32, void *, s32, void *, s32);
s32 osStartThread(void *);
s32 osCreatePiManager(s32, void *, void *, s32);
s32 game_main();
extern char *gStreamBuf;
extern s32 D_800A19C4;
extern char gGameState[];
extern char D_800A7400[];
extern char D_800A75C8[];
extern char gOrderState[];
extern char stream_state[];
extern char D_800D0680[];

/* Boot thread entry. Sets up the heap (start at D_800D0680, size up to the top of the 4 MB
 * RAM at 0x80400000), runs the init call, starts game_main on a priority-3 thread with a
 * 0x5550-byte stack in gOrderState, then loops forever calling the per-frame hook at
 * stream_state+0x7DFE. */
void func_8007FF9C(s32 arg0) {
    void *temp_s0;

    stream_slots_init();
    gStreamBuf = D_800D0680;
    D_800A19C4 = (char *) 0x80400000 - D_800D0680;
    osCreatePiManager(0x96, D_800A7400, gGameState, 8);
    temp_s0 = D_800A75C8;
    osCreateThread(temp_s0, 3, game_main, arg0, gOrderState + 0x5550, 5);
    osStartThread(temp_s0);
    for (;;) {
        ((void (*)()) *(void **) (stream_state + 0x7DFE))();
    }
}
