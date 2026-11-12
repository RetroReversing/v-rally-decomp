void func_80084AD8(void);
void func_8002FB64(void);

/* Reset audio/subsystem and initialize controller slots */
s32 func_8005E7F8(void) {
    func_80084AD8();
    func_8002FB64();
    return 0;
}
