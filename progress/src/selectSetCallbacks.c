s32 selectCopyEntryLabel();
extern void *gSelectState;
extern void func_8005EB48();
extern void func_8005ED88();
extern void func_8005EE34();

/* Copies the select screen's entry label, then stores the three select-screen callbacks in gSelectState (at +0x288, +0x28C, +0x290). Returns 0. */
s32 selectSetCallbacks(void) {
    selectCopyEntryLabel();
    *(void **)((char *)gSelectState + 0x288) = &func_8005EB48;
    *(void **)((char *)gSelectState + 0x28C) = &func_8005ED88;
    *(void **)((char *)gSelectState + 0x290) = &func_8005EE34;
    return 0;
}
