s32 func_8005C198(void);
s32 func_8005E28C(s32, s32);
s32 func_8005E470(s32, s32);
extern s8 gStreamPhase;

/* Restarts the stream: resets the two subsystems, marks the stream phase as
 * active (1), then runs the second reset. Always returns 1. */
s32 func_8006632C(s32 arg0, s32 arg1) {
    func_8005C198();
    func_8005E470(arg0, arg1);
    gStreamPhase = 1;
    func_8005E28C(0, 0);
    return 1;
}
