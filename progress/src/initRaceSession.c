extern int D_800B6B00;
extern int gCarList;
extern int D_800C7410;
extern int D_800B7040;
extern s32 D_8009D6B0;
extern char D_800A4950[];
extern char gOrderState[];
extern char stream_state[];
extern s32 flag_test_bit0();
extern s32 flag_set_then_call();
extern s32 named_entry_find_or_add();
extern s32 poolAllocHeadNode();
extern s32 func_800227AC;
extern s32 func_800227C8;
extern s32 heapReleaseBlock;

/* Starts a race session, unless the session object at 0x7320 is already set up
 * (flag_test_bit0 returns non-zero). The mode D_800B6B00 is 2 when the race
 * state is 7, otherwise 0; the session slot at 0x7162 is filled, then the car
 * list head is set and the session callbacks are registered. */
void initRaceSession(void) {
    s32 *slot;
    s32 count;
    if (flag_test_bit0(gOrderState + 0x7320) != 0) goto block_7;
    if (*(u16 *)(*(void **)(stream_state + 0x32F2) + 0x1E) != 7) goto block_3;
    D_800B6B00 = 2;
    count = 0;
    goto block_4;
block_3:
    D_800B6B00 = 0;
    count = 0;
block_4:
    slot = (s32 *)(stream_state + 0x7162);
loop_5:
    count += 1;
    *slot = poolAllocHeadNode();
    slot += 1;
    if (count == 0) goto loop_5;
    D_8009D6B0 = 0;
    gCarList = D_800C7410;
    flag_set_then_call(gOrderState + 0x7320, &func_800227C8);
    named_entry_find_or_add(D_800B7040, &func_800227AC, &heapReleaseBlock, &D_800A4950, 0);
block_7:
    return;
}
