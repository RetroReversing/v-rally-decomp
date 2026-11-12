extern s16 D_8009BBB4;
extern s32 D_8009BBB8;
extern s16 D_8009CEBC;
extern s32 stream_state;

/* Resets the stream's pending-state globals and copies the saved value into stream_state. */
void func_80015B00(void) {
    D_8009CEBC = 0x1C;
    D_8009BBB4 = 0;
    *(s32 *)((s8 *)&stream_state + 0x7DA6) = D_8009BBB8;
}
