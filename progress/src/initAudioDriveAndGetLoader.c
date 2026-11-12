extern char gGameState[];
extern s32 cacheVirtToPhys;

/* On first use, resets the audio drive state in gGameState (+0x4560) and copies its saved value; returns the loader slot and stores the state block address in *outDriveState. */ s32 *initAudioDriveAndGetLoader(void **outDriveState) {
    if (*(u8 *)(gGameState + 0x4560) == 0) {
        *(s32 *)(gGameState + 0x4564) = 0;
        *(u8 *)(gGameState + 0x4560) = 1U;
        *(s32 *)(gGameState + 0x4568) = (s32) *(s32 *)(gGameState + 0x456C);
    }
    *outDriveState = gGameState + 0x4560;
    return &cacheVirtToPhys;
}
