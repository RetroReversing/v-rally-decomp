extern char *gRecords;
extern int gRaceState;

/* Clears the record's lap-time word, sets the race state to 1 and clears bit 0x200 in the object flags. */
void func_80043124(char *obj) {
    *(short *)(gRecords + 0x36) = 0;
    {
        int flags = *(int *)(obj + 0x14);
        gRaceState = 1;
        *(int *)(obj + 0x14) = flags & ~0x200;
    }
}
