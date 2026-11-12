void AddObjectEntry(void);
extern u32 gSelectStep;

/* If selection step mode is less than 2 (mode 0 or 1), calls AddObjectEntry. */
void func_80058674(void) {
    if (gSelectStep < 2U) {
        AddObjectEntry();
    }
}
