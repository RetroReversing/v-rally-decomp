extern char gGameState[];
void func_80015C74(char *state, int value);

/* Clears the byte-sized field at gGameState+0x6BD0 by calling func_80015C74 with 0. */
void func_800699E4(void)
{
    func_80015C74(gGameState + 0x6BD0, 0);
}
