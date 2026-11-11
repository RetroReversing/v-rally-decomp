s32 func_800699E4();
s32 save_race_to_pak();
s32 func_8007A794();
extern void *gSceneSlot0;
extern s16 D_800A0370;
extern s16 D_800A0372;
extern u16 D_800A0374;
extern u16 D_800A0376;
extern void *gSelectState;

/* Resets the select screen's view state: clears D_800A0370/0372, copies the scene slot's
   fields at +4 and +6 into D_800A0374/0376, runs the reset at func_800699E4, marks the
   select state's entry at +0x2BD as unset (-1), then saves the race and releases the
   select buffer. */
void func_8007AA94(void) {
    D_800A0370 = 0;
    D_800A0372 = 0;
    D_800A0374 = *(u16 *)((char *)gSceneSlot0 + 4);
    D_800A0376 = *(u16 *)((char *)gSceneSlot0 + 6);
    func_800699E4();
    *(s8 *)((char *)gSelectState + 0x2BD) = -1;
    save_race_to_pak();
    func_8007A794();
}
