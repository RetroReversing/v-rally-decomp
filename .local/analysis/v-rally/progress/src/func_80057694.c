s32 func_8002B618();
s32 func_80057490();
s32 memset();
extern char D_800A5214[];
extern char D_800AE850[];

void func_80057694(void) {
    memset(D_800AE850 + 0x1300, 0, 0x5B0);
    func_8002B618(&D_800A5214, 0);
    func_80057490();
}
