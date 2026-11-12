void alSynNew();
extern s32 D_800A2500;

/* Initialises the audio synth on the first call: saves the config pointer in D_800A2500, then creates the synth. */
void alInit(s32 config) {
    if (D_800A2500 == 0) {
        D_800A2500 = config;
        alSynNew();
    }
}
