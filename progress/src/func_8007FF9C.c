s32 func_8007F278();
s32 osCreateThread(void *, s32, void *, s32, void *, s32);
s32 osStartThread(void *);
s32 func_80090250(s32, void *, void *, s32);
s32 game_main();
extern s32 gStreamBuf;
extern s32 D_800A19C4;
extern char D_800A73E0[];
extern char D_800A7400[];
extern char D_800A75C8[];
extern char gOrderState[];
extern char gStreamState[];
extern char D_800D0680[];

/* Boot thread entry. Sets up the heap (start at D_800D0680, size up to the top of the 4 MB
 * RAM at 0x80400000), runs the init call, starts game_main on a priority-3 thread with a
 * 0x5550-byte stack in gOrderState, then loops forever calling the per-frame hook at
 * gStreamState+0x7DFE. */
void func_8007FF9C(s32 arg0) {
    void *temp_s0;

    func_8007F278();
    gStreamBuf = (s32) D_800D0680;
    D_800A19C4 = 0x80400000 - (s32) D_800D0680;
    func_80090250(0x96, D_800A7400, D_800A73E0, 8);
    temp_s0 = D_800A75C8;
    osCreateThread(temp_s0, 3, game_main, arg0, gOrderState + 0x5550, 5);
    osStartThread(temp_s0);
    for (;;) {
        ((void (*)()) *(s32 *) (gStreamState + 0x7DFE))();
    }
}
