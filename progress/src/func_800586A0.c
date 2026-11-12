void AddObjectEntry(void);
extern s32 gSelectStep;

/* If selection step mode is 2, calls AddObjectEntry. */
void func_800586A0(void) {
    if (gSelectStep == 2) {
        AddObjectEntry();
    }
}
