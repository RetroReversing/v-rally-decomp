extern char gGameState[];
void runEntryList(char *a, int b, int c);

/* Runs the entry list at a fixed base offset with the given parameters. */
void func_8001B854(int entry, int arg2)
{
    runEntryList(gGameState + 0x6BD0, entry, arg2);
}
