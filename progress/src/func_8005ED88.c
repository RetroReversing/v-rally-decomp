s32 func_8005EE50(s32 id, s16 value, s32 flags);
extern char gStreamState[];

/* Sends three f32 stream parameters to the mixer, each scaled by 8 and truncated to s16, under ids 0xC..0xE. */
void func_8005ED88(void) {
    func_8005EE50(0xC, (s16) (s32) (*(f32 *) (gStreamState + 0x3332) * 8.0f), 0);
    func_8005EE50(0xD, (s16) (s32) (*(f32 *) (gStreamState + 0x333A) * 8.0f), 0);
    func_8005EE50(0xE, (s16) (s32) (*(f32 *) (gStreamState + 0x332E) * 8.0f), 0);
}
