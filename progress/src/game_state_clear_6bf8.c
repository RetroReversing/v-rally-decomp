extern s32 gGameState;

/* Clears the 32-bit word at offset 0x6BF8 in the game state block. */
void game_state_clear_6bf8(void) {
    *(s32 *)((s8 *)&gGameState + 0x6BF8) = 0;
}
