void func_8001D1A4(void);
extern s32 gSelectStep;

/* If selection step mode is 2, updates the order-state stream object. */
void func_8001D14C(void) {
    if (gSelectStep == 2) {
        func_8001D1A4();
    }
}
