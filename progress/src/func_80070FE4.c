void func_800580D0(s32, s32);
s32 league_set_flag14(s32);
extern void *gSelectState;
extern u8 gStreamState[];

/* Clears selection entry 0 and the select state's byte at +0x24D, sets league flag 14 from the stream word at +0x325A, and returns the code at +0x32F2->+0x20 plus 0x15. */
s32 func_80070FE4(void) {
    func_800580D0(0, 0);
    *(s8 *)((char *)gSelectState + 0x24D) = 0;
    league_set_flag14(*(s32 *)(gStreamState + 0x325A));
    return *(u16 *)((char *)*(void **)(gStreamState + 0x32F2) + 0x20) + 0x15;
}
