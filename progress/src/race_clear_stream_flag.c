extern void (*D_8009BBB8)(void);
extern void *gRaceCtx;
extern u8 gStreamState[];

/* Calls the D_8009BBB8 hook, then, when a race context exists and its byte at 0x384 is
 * clear, zeroes the halfword at gStreamState+0x5A4A. */
void race_clear_stream_flag(void) {
    D_8009BBB8();
    if ((gRaceCtx != NULL) && (*(u8 *) ((u8 *) gRaceCtx + 0x384) == 0)) {
        *(s16 *) (gStreamState + 0x5A4A) = 0;
    }
}
