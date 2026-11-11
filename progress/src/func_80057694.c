s32 text_load_and_parse();
s32 buildFlagMasks();
s32 memset();
extern char D_800A5214[];
extern char gOrderState[];

void func_80057694(void) {
    memset(gOrderState + 0x1300, 0, 0x5B0);
    text_load_and_parse(&D_800A5214, 0);
    buildFlagMasks();
}
