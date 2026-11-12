s32 select_copy_entry_label();
extern void *gSelectState;
extern s8 gStreamPhase;
extern void func_800724A4();
extern void func_80072984();

/* Copies the select screen's entry label, sets the stream phase to 3, and installs two select-screen callbacks in gSelectState (+0x288, +0x28C). Returns 0. */
s32 selectEnterPhase3(void) {
    select_copy_entry_label();
    gStreamPhase = 3;
    *(void **)((char *)gSelectState + 0x288) = &func_800724A4;
    *(void **)((char *)gSelectState + 0x28C) = &func_80072984;
    return 0;
}
