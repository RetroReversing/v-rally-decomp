extern char *gRecords;
extern int gRaceState;

/* Clears the race record's word at 0x36, marks the race as running (state 1), and clears bit 0x200 in the car's flags. */
void race_set_running(char *car)
{
    *(short *)(gRecords + 0x36) = 0;
    {
        int flags = *(int *)(car + 0x14);
        gRaceState = 1;
        *(int *)(car + 0x14) = flags & ~0x200;
    }
}
