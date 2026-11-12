extern u8 gGameState[];

/* Sets three s16 range parameters in the gGameState state block: +0x6BD4 = 700, +0x6BE2 = 500, +0x6BE4 = -500. */
void initRangeParams(void) {
    *(s16 *)(gGameState + 0x6BD4) = 0x2BC;
    *(s16 *)(gGameState + 0x6BE2) = 0x1F4;
    *(s16 *)(gGameState + 0x6BE4) = -0x1F4;
}
