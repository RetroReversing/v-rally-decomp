typedef s32 M2C_UNK;
s32 func_80086A94(void);
s32 MusSetMasterVolume(s32, s32);
extern s32 (*D_800A1B90)(void);

/* Music shutdown step: runs the driver hook, mutes master volume, then calls func_80086A94. */
void func_800864C0(void)
{
    D_800A1B90();
    MusSetMasterVolume(3, 0);
    func_80086A94();
}
