extern s32 D_800A1CC8;

/* AI register addresses (physical; OR'ed with 0xA0000000 for the uncached view). */
#define AI_CONTROL_REG   0x04500008
#define AI_DACRATE_REG   0x04500010
#define AI_BITRATE_REG   0x04500014

/* Sets the audio DAC sample rate for the requested frequency and enables AI DMA. Returns the rate actually set, or -1 if the frequency is too low for the hardware. */
s32 osAiSetFrequency(u32 frequency) {
    register unsigned int dacRate;
    register unsigned char bitRate;
    register float f;

    f = D_800A1CC8 / (float)frequency + .5f;
    dacRate = f;

    if (dacRate < 132 ) {
        return -1;
    }

    bitRate = dacRate / 66;

    if (bitRate > 16 ) {
        bitRate = 16 ;
    }

    (*(vu32*)((u32)(  AI_DACRATE_REG)|0xA0000000) =(u32)(  dacRate - 1 )) ;
    (*(vu32*)((u32)(  AI_BITRATE_REG)|0xA0000000) =(u32)(  bitRate - 1 )) ;

    (*(vu32*)((u32)(  AI_CONTROL_REG)|0xA0000000) =(u32)(  1  )) ;

    return D_800A1CC8 / (s32)dacRate;
}
