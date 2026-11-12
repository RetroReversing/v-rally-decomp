extern char gOrderState[];
s32 flag_test_bit0(void *ptr);
s32 func_80037AA4(s32 musicVoices, s32 sfxVoices);

/* Initializes the audio system with 24 music and 36 sound effect voices
 * if the flag at gOrderState+0x7378 bit 0 is not set. */
void func_800388CC(void) {
    if (flag_test_bit0(gOrderState + 0x7378) == 0) {
        func_80037AA4(0x18, 0x24);
    }
}
